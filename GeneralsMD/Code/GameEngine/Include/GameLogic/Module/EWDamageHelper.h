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

// FILE: EWDamageHelper.h ////////////////////////////////////////////////////////////////////////
// Author: Graham Smallwood, June 2003
// Desc:   Object helper - Clears ew status and heals ew damage since Body modules can't have Updates
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __EWDamageHelper_H_
#define __EWDamageHelper_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "GameLogic/Module/ObjectHelper.h"
#include "Common/AsciiString.h"
#include <map>

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
class EWDamageHelperModuleData : public ModuleData
{

};

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
class EWDamageHelper : public ObjectHelper
{

	MAKE_STANDARD_MODULE_MACRO_WITH_MODULE_DATA(EWDamageHelper, EWDamageHelperModuleData)
		MEMORY_POOL_GLUE_WITH_USERLOOKUP_CREATE(EWDamageHelper, "EWDamageHelper")

public:

	EWDamageHelper(Thing* thing, const ModuleData* modData);
	// virtual destructor prototype provided by memory pool object

	virtual DisabledMaskType getDisabledTypesToProcess() const { return DISABLEDMASK_ALL; }
	virtual UpdateSleepTime update();

	void notifyEWDamage(Real amount);

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based EW damage management
	void notifyComponentEWDamage(const AsciiString& componentName, Real amount);
	void processComponentEWDamageHealing();

protected:
	UnsignedInt m_healingStepCountdown;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component EW damage tracking
	std::map<AsciiString, UnsignedInt> m_componentEWHealCountdown;	///< Countdown for each component's EW damage healing
};


#endif  // end __EWDamageHelper_H_
