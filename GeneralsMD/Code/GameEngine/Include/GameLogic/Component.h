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

// Component.h ///////////////////////////////////////////////////////////////////
// Component health system for detailed damage modeling
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Lib/BaseType.h"
#include "Common/AsciiString.h"
#include "GameLogic/Damage.h"

// TheSuperHackers @feature author 15/01/2025 Component functionality status
enum ComponentStatus
{
	COMPONENT_STATUS_NONE = 0,           // Component does not exist
	COMPONENT_STATUS_FULLY_FUNCTIONAL,   // 50% - 100% health
	COMPONENT_STATUS_PARTIALLY_FUNCTIONAL, // 10% - 50% health  
	COMPONENT_STATUS_DOWNED              // 0% - 10% health
};
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Component healing behavior types
//-------------------------------------------------------------------------------------------------
enum ComponentHealingType CPP_11(: Int)
{
	COMPONENT_HEALING_NORMAL,					///< Can be healed from destroyed to max normally
	COMPONENT_HEALING_PARTIAL_ONLY,				///< Can be healed if not destroyed to max normally
	COMPONENT_HEALING_PARTIAL_DESTROYED,		///< Can be healed from destroyed to partially working normally, but to max needs replacement
	COMPONENT_HEALING_PARTIAL_LIMITED,			///< Can be healed if not destroyed to partially working normally, but to max needs replacement
	COMPONENT_HEALING_REPLACEMENT_ONLY,		///< Cannot be healed normally, needs replacement
	
	COMPONENT_HEALING_COUNT
};

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Component health system for detailed damage modeling
//-------------------------------------------------------------------------------------------------
struct Component
{
	AsciiString name;							///< Component name (Engine, Turret, Wheels, Gun, etc.)
	Real maxHealth;								///< Maximum health for this component
	Real initialHealth;						///< Initial health for this component
	ComponentHealingType healingType;			///< How this component can be healed
	HitSideFlags damageOnSides;					///< TheSuperHackers @feature author 15/01/2025 Which hit sides can damage this component (empty = all sides)
	UnsignedInt replacementCost;				///< TheSuperHackers @feature author 15/01/2025 Cost to replace this component (0 = cannot be replaced)
	Bool forceReturnOnDestroy;					///< TheSuperHackers @feature Ahmed Salah 30/09/2025 Force jet to return to parking when this component is destroyed
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 EW damage properties for components
	Real ewDamageCap;							///< Maximum EW damage this component can accumulate
	UnsignedInt ewDamageHealRate;				///< How often EW damage heals (in frames)
	Real ewDamageHealAmount;					///< How much EW damage heals per cycle
	
	Component() : maxHealth(0.0f), initialHealth(0.0f), healingType(COMPONENT_HEALING_NORMAL), damageOnSides(), replacementCost(0), forceReturnOnDestroy(FALSE), ewDamageCap(0.0f), ewDamageHealRate(0), ewDamageHealAmount(0.0f) {}
};

#endif // _COMPONENT_H_
