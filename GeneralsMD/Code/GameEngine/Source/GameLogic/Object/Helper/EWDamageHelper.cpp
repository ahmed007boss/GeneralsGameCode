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

// FILE: EWDamageHelper.cpp ////////////////////////////////////////////////////////////////////////
// Author: Graham Smallwood, June 2003
// Desc:   Object helper - Clears ew status and heals ew damage since Body modules can't have Updates
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"
#include "Common/Xfer.h"

#include "GameLogic/Object.h"
#include "GameLogic/Module/BodyModule.h"
#include "GameLogic/Module/EWDamageHelper.h"

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
EWDamageHelper::EWDamageHelper(Thing* thing, const ModuleData* modData) : ObjectHelper(thing, modData)
{
	m_healingStepCountdown = 0;

	setWakeFrame(getObject(), UPDATE_SLEEP_FOREVER);
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
EWDamageHelper::~EWDamageHelper(void)
{

}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
UpdateSleepTime EWDamageHelper::update()
{
	BodyModuleInterface* body = getObject()->getBodyModule();

	m_healingStepCountdown--;
	if (m_healingStepCountdown > 0)
		return UPDATE_SLEEP_NONE;

	m_healingStepCountdown = body->getEWDamageHealRate();

	DamageInfo removeEWDamage;
	removeEWDamage.in.m_damageType = DAMAGE_EW_UNRESISTABLE;
	removeEWDamage.in.m_amount = -body->getEWDamageHealAmount();
	body->attemptDamage(&removeEWDamage);

	if (body->hasAnyEWDamage())
		return UPDATE_SLEEP_NONE;
	else
		return UPDATE_SLEEP_FOREVER;
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void EWDamageHelper::notifyEWDamage(Real amount)
{
	if (amount > 0)
	{
		m_healingStepCountdown = getObject()->getBodyModule()->getEWDamageHealRate();
		setWakeFrame(getObject(), UPDATE_SLEEP_NONE);
	}
}

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------
void EWDamageHelper::crc(Xfer* xfer)
{

	// object helper crc
	ObjectHelper::crc(xfer);

}

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info;
	* 1: Initial version */
	// ------------------------------------------------------------------------------------------------
void EWDamageHelper::xfer(Xfer* xfer)
{

	// version
	XferVersion currentVersion = 1;
	XferVersion version = currentVersion;
	xfer->xferVersion(&version, currentVersion);

	// object helper base class
	ObjectHelper::xfer(xfer);

	xfer->xferUnsignedInt(&m_healingStepCountdown);

}

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
void EWDamageHelper::loadPostProcess(void)
{

	// object helper base class
	ObjectHelper::loadPostProcess();

}

