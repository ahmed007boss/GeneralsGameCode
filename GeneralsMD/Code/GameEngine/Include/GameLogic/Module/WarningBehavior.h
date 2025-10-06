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

	WarningBehaviorModuleData()
	{
		m_warningRadius = 1500.0f;		// TheSuperHackers @feature Ahmed Salah 15/01/2025 Default warning radius of 1500 units (approximately 15 tiles)
	}

	static void buildFieldParse(MultiIniFieldParse& p)
	{
		BehaviorModuleData::buildFieldParse(p);
		static const FieldParse dataFieldParse[] =
		{
			{ "WarningRadius", INI::parseReal, NULL, offsetof( WarningBehaviorModuleData, m_warningRadius ) },
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
	void doWarning( GameMessage::Type commandType, const Coord3D *commandPos, Object *commandingObject );

	/// Check if an enemy command should trigger a warning for this object
	Bool shouldTriggerWarning( const Coord3D *commandPos, Object *commandingObject ) const;

	/// Check if an object is an enemy of this object's controlling player
	Bool isEnemy( Object *other ) const;

	/// Check if a command target is within warning radius
	Bool isCommandTargetInRange( const Coord3D *targetPos ) const;
	
	/// Check if an enemy unit is actively moving or attacking
	Bool isEnemyUnitActive( Object *enemy ) const;

private:
	/// Minimum frames between warning sounds (10 seconds at 30 FPS = 300 frames)
	static const UnsignedInt WARNING_SOUND_COOLDOWN_FRAMES = 300;
	
	/// Check if enough time has passed since the last warning sound for this player
	Bool isWarningSoundCooldownReady( const Player *player ) const;
};

#endif // _WARNING_BEHAVIOR_H_
