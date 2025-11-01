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

// WeaponComponent.h ///////////////////////////////////////////////////////////////////
// Weapon-specific component with additional weapon-related properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _WEAPON_COMPONENT_H_
#define _WEAPON_COMPONENT_H_

#include "GameLogic/Components/Component.h"
#include "Common/AsciiString.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Weapon-specific component with additional properties
//-------------------------------------------------------------------------------------------------
class WeaponComponent : public Component
{
public:
	WeaponComponent() {}
	
	// TheSuperHackers @feature author 15/01/2025 Static parse method for WeaponComponent inheritance support
	static void parseWeaponComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	
	// TheSuperHackers @feature author 15/01/2025 Build field parse method for WeaponComponent inheritance support
	static void buildFieldParse(MultiIniFieldParse& p);

	// TheSuperHackers @feature author 15/01/2025 Virtual clone method for polymorphic copying
	virtual Component* clone() const;

	// Save/Load/CRC hooks
	virtual void crc( Xfer *xfer );
	virtual void xfer( Xfer *xfer );
	virtual void loadPostProcess( void );
};

#endif
