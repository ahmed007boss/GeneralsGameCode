/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// FILE: WarningBehavior.cpp /////////////////////////////////////////////////////////////////////////
// Created: TheSuperHackers, January 2025
// Desc:    Warning system that detects enemy commands near the object
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include "Common/Xfer.h"
#include "Common/MessageStream.h"
#include "Common/GameAudio.h"
#include "GameLogic/Object.h"
#include "GameLogic/Module/WarningBehavior.h"
#include "Common/Player.h"
#include "GameLogic/PartitionManager.h"
#include "GameLogic/Locomotor.h"
#include "GameLogic/Module/AIUpdate.h"
#include "GameLogic/GameLogic.h"
#include "Common/ThingTemplate.h"
#include <map>

//-------------------------------------------------------------------------------------------------
// Static data for player-based cooldown tracking
//-------------------------------------------------------------------------------------------------
static std::map<Int, UnsignedInt> s_playerLastWarningFrame;

//-------------------------------------------------------------------------------------------------
// WarningBehaviorModuleData
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// WarningBehavior
//-------------------------------------------------------------------------------------------------

WarningBehavior::WarningBehavior(Thing* thing, const ModuleData* moduleData) :
	BehaviorModule(thing, moduleData)
{
}

//-------------------------------------------------------------------------------------------------
WarningBehavior::~WarningBehavior(void)
{
}

//-------------------------------------------------------------------------------------------------
void WarningBehavior::doWarning(GameMessage::Type commandType, const Coord3D* commandPos, Object* commandingObject)
{
	// Implement warning behavior
	const Object* thisObject = getObject();
	if (!thisObject)
		return;

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check player-based cooldown to prevent sound spam
	const Player* thisPlayer = thisObject->getControllingPlayer();
	if (!thisPlayer)
		return;

	if (isWarningSoundCooldownReady(thisPlayer))
	{
		
		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Play warning sound effect
		AudioEventRTS warningSound("preAttackSiren");
		warningSound.setIsLogicalAudio(true);
		warningSound.setPosition(thisObject->getPosition());
		warningSound.setPlayerIndex(thisPlayer->getPlayerIndex());

		TheAudio->addAudioEvent(&warningSound);

		// Update the last warning sound frame for this player
		UnsignedInt currentFrame = TheGameLogic->getFrame();
		s_playerLastWarningFrame[thisPlayer->getPlayerIndex()] = currentFrame;

	}





	// TODO: Implement more sophisticated warning behavior based on command type:
	// - Different warning sounds for move vs attack commands
	// - Different visual indicators (red for attack, yellow for move)
	// - Different warning messages/notifications
	// - Command-specific effects (particles, animations, etc.)
}

//-------------------------------------------------------------------------------------------------
Bool WarningBehavior::shouldTriggerWarning(const Coord3D* commandPos, Object* commandingObject) const
{
	if (!commandPos || !commandingObject)
	{
		DEBUG_LOG(("WarningBehavior: Invalid parameters - commandPos: %p, commandingObject: %p", commandPos, commandingObject));
		return FALSE;
	}

	const Object* thisObject = getObject();
	if (!thisObject)
	{
		DEBUG_LOG(("WarningBehavior: No thisObject"));
		return FALSE;
	}

	//Check if the commanding object can send radio messages
	if (!commandingObject->shouldSendRadioMessage())
	{
		DEBUG_LOG(("WarningBehavior: Commanding object cannot send radio messages (not infantry/vehicle/aircraft or stealth/undetected)"));
		return FALSE;
	}

	//Check if the commanding object is an enemy of this object
	if (!isEnemy(commandingObject))
	{
		DEBUG_LOG(("WarningBehavior: Commanding object is not an enemy"));
		return FALSE;
	}

	//Check if the command position is within the warning radius
	if (!isCommandTargetInRange(commandPos))
	{
		DEBUG_LOG(("WarningBehavior: Command position not in range"));
		return FALSE;
	}

	// Check if the commanding object is active (moving/attacking)
	if (!isEnemyUnitActive(commandingObject))
	{
		DEBUG_LOG(("WarningBehavior: Enemy unit not active"));
		return FALSE;
	}

	//All conditions met, should trigger warning
	DEBUG_LOG(("WarningBehavior: All conditions met, should trigger warning!"));
	return TRUE;
}

//-------------------------------------------------------------------------------------------------
Bool WarningBehavior::isEnemy(Object* other) const
{
	if (!other)
		return FALSE;

	const Object* thisObject = getObject();
	if (!thisObject)
		return FALSE;

	const Player* thisPlayer = thisObject->getControllingPlayer();
	const Player* otherPlayer = other->getControllingPlayer();

	if (!thisPlayer || !otherPlayer)
	{
		DEBUG_LOG(("WarningBehavior: Missing players - thisPlayer: %p, otherPlayer: %p", thisPlayer, otherPlayer));
		return FALSE;
	}

	// Check if players are enemies
	// For now, simple check: different players are enemies
	Bool isEnemy = thisPlayer != otherPlayer;
	DEBUG_LOG(("WarningBehavior: Enemy check - thisPlayer: %d, otherPlayer: %d, isEnemy: %s", 
		thisPlayer->getPlayerIndex(), 
		otherPlayer->getPlayerIndex(), 
		isEnemy ? "YES" : "NO"));
	
	return isEnemy;
}

//-------------------------------------------------------------------------------------------------
Bool WarningBehavior::isCommandTargetInRange(const Coord3D* targetPos) const
{
	if (!targetPos)
		return FALSE;

	const Object* thisObject = getObject();
	if (!thisObject)
		return FALSE;

	const WarningBehaviorModuleData* md = getWarningBehaviorModuleData();
	if (!md || md->m_warningRadius <= 0.0f)
	{
		DEBUG_LOG(("WarningBehavior: No module data or invalid warning radius (%f)", md ? md->m_warningRadius : -1.0f));
		return FALSE;
	}

	// Calculate 2D distance between this object and the command target (ignore Z for ground units)
	Real distanceSquared = ThePartitionManager->getDistanceSquared(thisObject, targetPos, FROM_CENTER_2D);
	Real distance = sqrt(distanceSquared);

	Bool inRange = distance <= md->m_warningRadius;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Debug logging for range checking
	DEBUG_LOG(("WarningBehavior: Distance check - Object: %s, Distance: %f, Radius: %f, InRange: %s", 
		thisObject->getTemplate()->getName().str(), 
		distance, 
		md->m_warningRadius, 
		inRange ? "YES" : "NO"));

	return inRange;
}

//-------------------------------------------------------------------------------------------------
Bool WarningBehavior::isEnemyUnitActive(Object* enemy) const
{
	if (!enemy)
		return FALSE;

	// Check if the enemy unit is moving or attacking
	// We'll use a simpler approach - check if the unit is not idle
	// This is a basic implementation that can be enhanced

	// Check if the unit is disabled
	if (enemy->isDisabled())
		return FALSE;

	// For now, we'll consider any non-idle enemy unit as "active"
	// This is a simplified approach that can be enhanced with more sophisticated detection
	return TRUE;
}

//-------------------------------------------------------------------------------------------------
Bool WarningBehavior::isWarningSoundCooldownReady(const Player* player) const
{
	if (!player)
		return FALSE;

	UnsignedInt currentFrame = TheGameLogic->getFrame();
	Int playerIndex = player->getPlayerIndex();

	// Check if this player has a last warning frame recorded
	std::map<Int, UnsignedInt>::iterator it = s_playerLastWarningFrame.find(playerIndex);
	if (it == s_playerLastWarningFrame.end())
	{
		// No previous warning for this player, cooldown is ready
		return TRUE;
	}

	// Check if enough time has passed
	UnsignedInt lastFrame = it->second;
	return (currentFrame - lastFrame) >= WARNING_SOUND_COOLDOWN_FRAMES;
}

//-------------------------------------------------------------------------------------------------
void WarningBehavior::crc(Xfer* xfer)
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 CRC for WarningBehavior
	BehaviorModule::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void WarningBehavior::xfer(Xfer* xfer)
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Xfer for WarningBehavior
	BehaviorModule::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void WarningBehavior::loadPostProcess(void)
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Load post-process for WarningBehavior
	BehaviorModule::loadPostProcess();
}
