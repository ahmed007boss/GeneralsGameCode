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

// FILE: JammingDamageHelper.h ////////////////////////////////////////////////////////////////////////
// Author: Graham Smallwood, June 2003
// Desc:   Object helper - Clears ew status and heals ew damage since Body modules can't have Updates
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __JammingDamageHelper_H_
#define __JammingDamageHelper_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "GameLogic/Module/ObjectHelper.h"
#include "Common/AsciiString.h"
#include <map>

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
class JammingDamageHelperModuleData : public ModuleData
{

};

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
class JammingDamageHelper : public ObjectHelper
{

	MAKE_STANDARD_MODULE_MACRO_WITH_MODULE_DATA(JammingDamageHelper, JammingDamageHelperModuleData)
	MEMORY_POOL_GLUE_WITH_USERLOOKUP_CREATE(JammingDamageHelper, "JammingDamageHelper")

public:

	JammingDamageHelper(Thing* thing, const ModuleData* modData);
	// virtual destructor prototype provided by memory pool object

	virtual DisabledMaskType getDisabledTypesToProcess() const { return DISABLEDMASK_ALL; }
	virtual UpdateSleepTime update();

	void notifyJammingDamage(Real amount);

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based Jamming damage management
	void notifyComponentJammingDamage(const AsciiString& componentName, Real amount);
	void processComponentJammingDamageHealing();

protected:
	UnsignedInt m_healingStepCountdown;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component Jamming damage tracking
	std::map<AsciiString, UnsignedInt> m_componentJammingHealCountdown;	///< Countdown for each component's Jamming damage healing
};


#endif  // end __JammingDamageHelper_H_
