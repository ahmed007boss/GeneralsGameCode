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

// FILE: BodyModule.cpp ///////////////////////////////////////////////////////////////////////////
// Author: Colin Day, September 2002
// Desc:   BodyModule base class
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"
#include "Common/Xfer.h"
#include "GameLogic/Module/BodyModule.h"
#include "GameClient/GameText.h"

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------
void BodyModule::crc( Xfer *xfer )
{

	// call base class
	BehaviorModule::crc( xfer );

}

// ------------------------------------------------------------------------------------------------
/** Xfer Method
	* Version Info:
	* 1: Initial version */
// ------------------------------------------------------------------------------------------------
void BodyModule::xfer( Xfer *xfer )
{

	// version
	XferVersion currentVersion = 1;
	XferVersion version = currentVersion;
	xfer->xferVersion( &version, currentVersion );

	// call base class
	BehaviorModule::xfer( xfer );

	// damage scalar
	xfer->xferReal( &m_damageScalar );

}

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
void BodyModule::loadPostProcess( void )
{

	// call base class
	BehaviorModule::loadPostProcess();

}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 01/01/2025 Override getModuleDescription for UI display
//-------------------------------------------------------------------------------------------------
UnicodeString BodyModuleData::getModuleDescription() const
{
	if (!m_description)
	{
		m_description = new UnicodeString(TheGameText->fetch("MODULE:BODYMODULE_DESCRIPTION"));
	}
	return *m_description;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Basic component name constants
//-------------------------------------------------------------------------------------------------
const AsciiString BodyModule::COMPONENT_ENGINE = "ENGINE";
const AsciiString BodyModule::COMPONENT_WHEELS = "WHEELS";
const AsciiString BodyModule::COMPONENT_TRACKS = "TRACKS";
const AsciiString BodyModule::COMPONENT_FUEL_TANK = "FUEL_TANK";
const AsciiString BodyModule::COMPONENT_TURRET_A = "TURRET_A";
const AsciiString BodyModule::COMPONENT_TURRET_B = "TURRET_B";
const AsciiString BodyModule::COMPONENT_TURRET_C = "TURRET_C";
const AsciiString BodyModule::COMPONENT_PRIMARY_WEAPON = "PRIMARY_WEAPON";
const AsciiString BodyModule::COMPONENT_SECONDARY_WEAPON = "SECONDARY_WEAPON";
const AsciiString BodyModule::COMPONENT_TERTIARY_WEAPON = "TERTIARY_WEAPON";
const AsciiString BodyModule::COMPONENT_WEAPON_FOUR = "WEAPON_FOUR";
const AsciiString BodyModule::COMPONENT_WEAPON_FIVE = "WEAPON_FIVE";
const AsciiString BodyModule::COMPONENT_WEAPON_SIX = "WEAPON_SIX";
const AsciiString BodyModule::COMPONENT_WEAPON_SEVEN = "WEAPON_SEVEN";
const AsciiString BodyModule::COMPONENT_WEAPON_EIGHT = "WEAPON_EIGHT";
const AsciiString BodyModule::COMPONENT_RADAR = "RADAR";
const AsciiString BodyModule::COMPONENT_VISION = "VISION";
const AsciiString BodyModule::COMPONENT_ELECTRONICS = "ELECTRONICS";
const AsciiString BodyModule::COMPONENT_POWER = "POWER";
const AsciiString BodyModule::COMPONENT_COMMUNICATION_A = "COMMUNICATION_A";
const AsciiString BodyModule::COMPONENT_COMMUNICATION_B = "COMMUNICATION_B";