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

// FILE: WarningBehavior.h /////////////////////////////////////////////////////////////////////////
// Created: TheSuperHackers, January 2025
// Desc:    Warning system that detects enemy commands near the object
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _WARNING_BEHAVIOR_H_
#define _WARNING_BEHAVIOR_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "Common/INI.h"
#include "GameLogic/Module/BehaviorModule.h"
#include "Common/MessageStream.h"

//-------------------------------------------------------------------------------------------------
// WarningBehaviorModuleData
//-------------------------------------------------------------------------------------------------
class WarningBehaviorModuleData : public BehaviorModuleData
{
public:
	Real m_warningRadius;		///< Radius to detect enemy commands near this object
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Configurable warning sound names
	AsciiString m_attackWarningSound;		///< Sound for attack/attackmove commands
	AsciiString m_moveWarningSound;			///< Sound for move commands
	AsciiString m_abilityWarningSound;		///< Sound for special ability commands
	AsciiString m_defaultWarningSound;		///< Default warning sound for unknown commands
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Air warning sounds for aircraft aggressors
	AsciiString m_airAttackWarningSound;	///< Sound for air attack commands
	AsciiString m_airMoveWarningSound;		///< Sound for air move commands
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Visual warning effects
	Bool m_enableVisualWarning;				///< Enable visual warning effects
	Real m_visualWarningIntensity;			///< Intensity of visual warning (0.0-1.0)
	UnsignedInt m_visualWarningDuration;	///< Duration of visual warning in frames

	WarningBehaviorModuleData()
	{
		m_warningRadius = 1500.0f;		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Default warning radius of 1500 units (approximately 15 tiles)
		
		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Default warning sound names
		m_attackWarningSound = "";
		m_moveWarningSound = "";
		m_abilityWarningSound = "";
		m_defaultWarningSound = "";
		
		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Default air warning sound names
		m_airAttackWarningSound = "";
		m_airMoveWarningSound = "";
		
		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Default visual warning settings
		m_enableVisualWarning = TRUE;
		m_visualWarningIntensity = 1.0f;
		m_visualWarningDuration = 300;		// 10 seconds at 30 FPS
	}

	static void buildFieldParse(MultiIniFieldParse& p)
	{
		BehaviorModuleData::buildFieldParse(p);
		static const FieldParse dataFieldParse[] =
		{
			{ "WarningRadius", INI::parseReal, NULL, offsetof( WarningBehaviorModuleData, m_warningRadius ) },
			{ "AttackWarningSound", INI::parseAsciiString, NULL, offsetof( WarningBehaviorModuleData, m_attackWarningSound ) },
			{ "MoveWarningSound", INI::parseAsciiString, NULL, offsetof( WarningBehaviorModuleData, m_moveWarningSound ) },
			{ "AbilityWarningSound", INI::parseAsciiString, NULL, offsetof( WarningBehaviorModuleData, m_abilityWarningSound ) },
			{ "DefaultWarningSound", INI::parseAsciiString, NULL, offsetof( WarningBehaviorModuleData, m_defaultWarningSound ) },
			{ "AirAttackWarningSound", INI::parseAsciiString, NULL, offsetof( WarningBehaviorModuleData, m_airAttackWarningSound ) },
			{ "AirMoveWarningSound", INI::parseAsciiString, NULL, offsetof( WarningBehaviorModuleData, m_airMoveWarningSound ) },
			{ "EnableVisualWarning", INI::parseBool, NULL, offsetof( WarningBehaviorModuleData, m_enableVisualWarning ) },
			{ "VisualWarningIntensity", INI::parseReal, NULL, offsetof( WarningBehaviorModuleData, m_visualWarningIntensity ) },
			{ "VisualWarningDuration", INI::parseUnsignedInt, NULL, offsetof( WarningBehaviorModuleData, m_visualWarningDuration ) },
			{ 0, 0, 0, 0 }
		};
		p.add(dataFieldParse);
	}
};

//-------------------------------------------------------------------------------------------------
// WarningBehavior
//-------------------------------------------------------------------------------------------------
class WarningBehavior : public BehaviorModule
{
	MEMORY_POOL_GLUE_WITH_USERLOOKUP_CREATE( WarningBehavior, "WarningBehavior" )
	MAKE_STANDARD_MODULE_MACRO_WITH_MODULE_DATA( WarningBehavior, WarningBehaviorModuleData )

public:
	WarningBehavior( Thing *thing, const ModuleData* moduleData );
	// virtual destructor prototype provided by memory pool declaration

	/// Called when enemy commands are detected near this object
	void doWarning( GameMessage::Type commandType, const Coord3D *commandPos, Object *attackerObject, Object *targetObject );

	/// Check if an enemy command should trigger a warning for this object
	Bool shouldTriggerWarning( const Coord3D *commandPos, Object *attackerObject ) const;

	/// Check if an object is an enemy of this object's controlling player
	Bool isEnemy( Object *other ) const;

	/// Check if a command target is within warning radius
	Bool isCommandTargetInRange( const Coord3D *targetPos ) const;
	
	/// Check if an enemy unit is actively moving or attacking
	Bool isEnemyUnitActive( Object *enemy ) const;

	/// Trigger visual warning effect (red flashing) on target object
	void triggerVisualWarning( GameMessage::Type commandType, Object *targetObject );
	
	/// Check if the attacking object is an aircraft
	Bool isAttackingObjectAircraft( Object *attackerObject ) const;

private:
	/// Minimum frames between warning sounds (10 seconds at 30 FPS = 300 frames)
	static const UnsignedInt WARNING_SOUND_COOLDOWN_FRAMES = 300;
	
	/// Check if enough time has passed since the last warning sound for this player
	Bool isWarningSoundCooldownReady( const Player *player ) const;
};

#endif // _WARNING_BEHAVIOR_H_
