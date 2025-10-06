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

// Core includes - only what we actually use
#include "Common/GameAudio.h"        // AudioEventRTS, TheAudio
#include "GameLogic/Object.h"        // Object class
#include "GameLogic/Module/WarningBehavior.h"  // WarningBehavior class
#include "Common/Player.h"           // Player class
#include "GameLogic/PartitionManager.h"  // ThePartitionManager, FROM_CENTER_2D
#include "GameLogic/GameLogic.h"     // TheGameLogic
#include "GameClient/Drawable.h"     // Drawable class for visual effects
#include <map>                       // std::map for static data

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
void WarningBehavior::doWarning(GameMessage::Type commandType, const Coord3D* commandPos, Object* commandingObject, Object* targetObject)
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Warning behavior only works for the player who owns this unit
	const Object* thisObject = getObject();
	if (!thisObject)
		return;

	// Get the player who owns this unit - this is who will receive the warning
	const Player* unitOwner = thisObject->getControllingPlayer();
	if (!unitOwner)
		return;

	if (targetObject)
	{
		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Trigger visual warning effect on target object (immediate feedback)
		triggerVisualWarning(commandType, targetObject);
	}


	// Check if this player is ready for a warning sound (cooldown system)
	if (!isWarningSoundCooldownReady(unitOwner))
		return;

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Get configurable warning sounds from module data
	const WarningBehaviorModuleData* md = getWarningBehaviorModuleData();
	if (!md)
		return;

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if the commanding object is an aircraft
	Bool isAircraft = isCommandingObjectAircraft(commandingObject);

	AsciiString soundName;

	switch (commandType)
	{
	case GameMessage::MSG_DO_ATTACK_OBJECT:
	case GameMessage::MSG_DO_ATTACKSQUAD:
	case GameMessage::MSG_DO_ATTACKMOVETO:
	case GameMessage::MSG_DO_GROUPATTACKMOVETO:
	case GameMessage::MSG_DO_FORCE_ATTACK_OBJECT:
	case GameMessage::MSG_DO_FORCE_ATTACK_GROUND:
		// Attack/Attack Move commands - use air or ground attack warning sound
		if (isAircraft)
		{
			soundName = md->m_airAttackWarningSound;
			// Fall back to ground attack sound if air sound is empty
			if (soundName.isEmpty())
				soundName = md->m_attackWarningSound;
		}
		else
		{
			soundName = md->m_attackWarningSound;
		}
		break;

	case GameMessage::MSG_DO_MOVETO:
	case GameMessage::MSG_DO_FORCEMOVETO:
	case GameMessage::MSG_DO_GROUPMOVETO:
		// Move commands - use air or ground movement warning sound
		if (isAircraft)
		{
			soundName = md->m_airMoveWarningSound;
			// Fall back to ground move sound if air sound is empty
			if (soundName.isEmpty())
				soundName = md->m_moveWarningSound;
		}
		else
		{
			soundName = md->m_moveWarningSound;
		}
		break;

	case GameMessage::MSG_DO_SPECIAL_POWER:
	case GameMessage::MSG_DO_SPECIAL_POWER_AT_LOCATION:
	case GameMessage::MSG_DO_SPECIAL_POWER_AT_OBJECT:
		// Special ability commands - use configurable ability warning sound (no air variant)
		soundName = md->m_abilityWarningSound;
		break;

	default:
		// Default warning sound for unknown commands (no air variant)
		soundName = md->m_defaultWarningSound;
		break;
	}

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if sound name is not empty before playing
	if (soundName.isEmpty())
	{
		// No sound configured, skip playing warning sound
		return;
	}

	AudioEventRTS warningSound(soundName);
	warningSound.setIsLogicalAudio(true);
	warningSound.setPosition(thisObject->getPosition());
	warningSound.setPlayerIndex(unitOwner->getPlayerIndex());

	TheAudio->addAudioEvent(&warningSound);

	// Update cooldown for this specific player
	UnsignedInt currentFrame = TheGameLogic->getFrame();
	s_playerLastWarningFrame[unitOwner->getPlayerIndex()] = currentFrame;





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
		return FALSE;
	}

	const Object* thisObject = getObject();
	if (!thisObject)
	{
		return FALSE;
	}

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if this unit is under construction
	if (thisObject->testStatus(OBJECT_STATUS_UNDER_CONSTRUCTION))
	{
		return FALSE;
	}

	//Check if the commanding object can send radio messages
	if (!commandingObject->shouldSendRadioMessage())
	{
		return FALSE;
	}

	//Check if the commanding object is an enemy of this object
	if (!isEnemy(commandingObject))
	{
		return FALSE;
	}

	//Check if the command position is within the warning radius
	if (!isCommandTargetInRange(commandPos))
	{
		return FALSE;
	}

	// Check if the commanding object is active (moving/attacking)
	if (!isEnemyUnitActive(commandingObject))
	{
		return FALSE;
	}

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

		return FALSE;
	}

	// Check if players are enemies
	// For now, simple check: different players are enemies
	Bool isEnemy = thisPlayer != otherPlayer;

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
		return FALSE;
	}

	// Calculate 2D distance between this object and the command target (ignore Z for ground units)
	Real distanceSquared = ThePartitionManager->getDistanceSquared(thisObject, targetPos, FROM_CENTER_2D);
	Real distance = sqrt(distanceSquared);

	Bool inRange = distance <= md->m_warningRadius;

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

//-------------------------------------------------------------------------------------------------
void WarningBehavior::triggerVisualWarning(GameMessage::Type commandType, Object* targetObject)
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Trigger red flashing visual warning effect on target object
	const WarningBehaviorModuleData* md = getWarningBehaviorModuleData();
	if (!md || !md->m_enableVisualWarning)
		return;

	if (!targetObject)
		return;



	// Get the drawable of the target object and trigger red flashing effect
	Drawable* drawable = targetObject->getDrawable();
	if (drawable)
	{
		RGBColor redColor;
		redColor.red = 1.0f;    // Maximum red
		redColor.green = 0.0f;  // No green
		redColor.blue = 0.0f;   // No blue

		// Apply red color flash with duration and intensity
		drawable->colorFlash(&redColor, md->m_visualWarningDuration);
		
		// Set the second material pass opacity to create flashing effect
		// This warns the player that THIS target object is in danger of being attacked
		drawable->setSecondMaterialPassOpacity(md->m_visualWarningIntensity);

	}

}

//-------------------------------------------------------------------------------------------------
Bool WarningBehavior::isCommandingObjectAircraft(Object* commandingObject) const
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if the commanding object is an aircraft
	if (!commandingObject)
		return FALSE;

	// Check if the object is an aircraft using the KINDOF_AIRCRAFT flag
	// This is the most reliable way to detect aircraft in the game engine
	return commandingObject->isKindOf(KINDOF_AIRCRAFT);
}
