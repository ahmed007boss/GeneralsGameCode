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

// FILE: AutoSupplyItemBehavior.h ///////////////////////////////////////////////
// Created: TheSuperHackers, January 2025
// Desc:    Auto supply item behavior for automatically supplying items to nearby units
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __AutoSupplyItemBehavior_H_
#define __AutoSupplyItemBehavior_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "GameLogic/Module/UpdateModule.h"
#include "Common/AsciiString.h"
#include "Common/UnicodeString.h"
// #include "Common/ObjectPrerequisite.h" // Forward declaration used instead
// #include "GameLogic/Coord.h" // Not needed for now

// FORWARD DECLARATIONS ///////////////////////////////////////////////////////////////////////////
class Object;
class INI;
class InventoryBehavior;
class ObjectPrerequisite;

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Auto supply item module data for configuration
//-------------------------------------------------------------------------------------------------
class AutoSupplyItemBehaviorModuleData : public UpdateModuleData
{
public:
	AsciiString m_supplyItemKey;           ///< Item key to supply (e.g., "Ammo", "Fuel")
	Real m_supplyAmount;                   ///< Amount of item to supply per cycle
	Real m_supplyRadius;                   ///< Radius to search for units to supply
	UnsignedInt m_supplyDelay;             ///< Delay between supply attempts in milliseconds
	Bool m_supplyAllUnits;                 ///< If true, supply all units in range; if false, supply only best match
	ObjectPrerequisite* m_targetPrerequisite; ///< Prerequisites for target units

	AutoSupplyItemBehaviorModuleData();

	virtual UnicodeString getModuleDescription() const;
	virtual Int getModuleOrder() const { return 2000; } // Medium priority

	static void buildFieldParse(MultiIniFieldParse& p);
};

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Auto supply item behavior for automatic item distribution
//-------------------------------------------------------------------------------------------------
class AutoSupplyItemBehavior : public UpdateModule
{
	MEMORY_POOL_GLUE_WITH_USERLOOKUP_CREATE( AutoSupplyItemBehavior, "AutoSupplyItemBehavior" )
	MAKE_STANDARD_MODULE_MACRO_WITH_MODULE_DATA( AutoSupplyItemBehavior, AutoSupplyItemBehaviorModuleData )

public:

	AutoSupplyItemBehavior( Thing *thing, const ModuleData* moduleData );
	// virtual destructor prototype provided by memory pool declaration

	// module methods
	static Int getInterfaceMask() { return MODULEINTERFACE_UPDATE; }

	// UpdateModule
	virtual UpdateSleepTime update();

	// Auto supply methods
	Bool canSupplyUnit(Object* targetUnit) const;
	Bool supplyUnit(Object* targetUnit);

private:
	UnsignedInt m_lastSupplyFrame;         ///< Frame of last supply attempt
	Object* m_lastSuppliedUnit;            ///< Last unit that was supplied (for effect targeting)
};

#endif // __AutoSupplyItemBehavior_H_
