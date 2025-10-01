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
#include "GameLogic/Module/ActiveBody.h"
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

	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Process component-based EW damage healing
	processComponentEWDamageHealing();

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
	XferVersion currentVersion = 2; // TheSuperHackers @feature Ahmed Salah 15/01/2025 Incremented for component EW damage support
	XferVersion version = currentVersion;
	xfer->xferVersion(&version, currentVersion);

	// object helper base class
	ObjectHelper::xfer(xfer);

	xfer->xferUnsignedInt(&m_healingStepCountdown);
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component EW damage countdown tracking
	if (version >= 2)
	{
		// Xfer component EW heal countdown map
		UnsignedInt countdownSize = m_componentEWHealCountdown.size();
		xfer->xferUnsignedInt(&countdownSize);
		
		if (xfer->getXferMode() == XFER_LOAD)
		{
			m_componentEWHealCountdown.clear();
			for (UnsignedInt i = 0; i < countdownSize; i++)
			{
				AsciiString componentName;
				UnsignedInt countdown;
				xfer->xferAsciiString(&componentName);
				xfer->xferUnsignedInt(&countdown);
				m_componentEWHealCountdown[componentName] = countdown;
			}
		}
		else
		{
			for (std::map<AsciiString, UnsignedInt>::iterator it = m_componentEWHealCountdown.begin();
				 it != m_componentEWHealCountdown.end(); ++it)
			{
				AsciiString componentName = it->first;
				UnsignedInt countdown = it->second;
				xfer->xferAsciiString(&componentName);
				xfer->xferUnsignedInt(&countdown);
			}
		}
	}

}

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
void EWDamageHelper::loadPostProcess(void)
{

	// object helper base class
	ObjectHelper::loadPostProcess();

}

// ------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based EW damage management
// ------------------------------------------------------------------------------------------------
void EWDamageHelper::notifyComponentEWDamage(const AsciiString& componentName, Real amount)
{
	if (componentName.isEmpty() || amount <= 0.0f)
		return;
		
	// Get the ActiveBody module to add component EW damage
	ActiveBody* activeBody = static_cast<ActiveBody*>(getObject()->getBodyModule());
	if (!activeBody)
		return;
		
	// Add EW damage to the component
	activeBody->addComponentEWDamage(componentName, amount);
	
	// Set up healing countdown for this component
	UnsignedInt healRate = activeBody->getComponentEWDamageHealRate(componentName);
	if (healRate > 0)
	{
		m_componentEWHealCountdown[componentName] = healRate;
		setWakeFrame(getObject(), UPDATE_SLEEP_NONE);
	}
}

// ------------------------------------------------------------------------------------------------
void EWDamageHelper::processComponentEWDamageHealing()
{
	ActiveBody* activeBody = static_cast<ActiveBody*>(getObject()->getBodyModule());
	if (!activeBody)
		return;
		
	// Process each component's EW damage healing
	for (std::map<AsciiString, UnsignedInt>::iterator it = m_componentEWHealCountdown.begin();
		 it != m_componentEWHealCountdown.end(); )
	{
		const AsciiString& componentName = it->first;
		UnsignedInt& countdown = it->second;
		
		// Decrement countdown
		if (countdown > 0)
		{
			countdown--;
		}
		
		// Check if it's time to heal
		if (countdown == 0)
		{
			Real healAmount = activeBody->getComponentEWDamageHealAmount(componentName);
			if (healAmount > 0.0f)
			{
				activeBody->healComponentEWDamage(componentName, healAmount);
				
				// Reset countdown if there's still damage
				Real currentDamage = activeBody->getComponentEWDamage(componentName);
				if (currentDamage > 0.0f)
				{
					UnsignedInt healRate = activeBody->getComponentEWDamageHealRate(componentName);
					countdown = healRate;
				}
				else
				{
					// No more damage, remove from tracking
					it = m_componentEWHealCountdown.erase(it);
					continue;
				}
			}
			else
			{
				// No healing amount, remove from tracking
				it = m_componentEWHealCountdown.erase(it);
				continue;
			}
		}
		
		++it;
	}
}

