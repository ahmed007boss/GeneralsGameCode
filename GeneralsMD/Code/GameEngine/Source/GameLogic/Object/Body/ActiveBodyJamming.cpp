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

// FILE: ActiveBodyJamming.cpp ///////////////////////////////////////////////////////////////////////////
// Author: Ahmed Salah, January 2025
// Desc:   Component-based Electronic Warfare (Jamming) damage functionality for ActiveBody
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine
#include "GameLogic/Module/ActiveBody.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Components/ElectronicsComponentInterface.h"
#include "GameLogic/Object.h"

// FORWARD REFERENCES /////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
// COMPONENT-BASED Jamming DAMAGE METHODS /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based global Jamming damage management
//-------------------------------------------------------------------------------------------------
void ActiveBody::internalAddJammingDamage(Real delta)
{
	const ActiveBodyModuleData* data = getActiveBodyModuleData();

	m_currentJammingDamage += delta;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Use component-based Jamming damage cap
	// Calculate total Jamming damage cap from all components
	Real totalComponentCap = 0.0f;
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
	{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (ec && ec->getJammingDamageCap() > 0.0f)
		{
				totalComponentCap += ec->getJammingDamageCap();
			}
		}
	}
	
	// Use the most restrictive cap (global or component-based)
	Real effectiveCap = data->m_jammingDamageCap;
	if (totalComponentCap > 0.0f)
	{
		if (effectiveCap <= 0.0f)
		{
			effectiveCap = totalComponentCap;
		}
		else
		{
			effectiveCap = min(effectiveCap, totalComponentCap);
		}
	}
	
	m_currentJammingDamage = min(m_currentJammingDamage, effectiveCap);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware Jamming jamming capability check
//-------------------------------------------------------------------------------------------------
Bool ActiveBody::canBeJammed() const
{
	// Check global capability flags first
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	if (data && (data->m_canBeJammedByDirectJammers || data->m_canBeJammedByAreaJammers))
		return true;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if any components can be Jamming jammed
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
		{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (!ec) continue;
			if (ec->isJammableByDirect() || ec->isJammableByArea())
				return true;
		}
	}
	
	return false;
}

Bool ActiveBody::canBeJammedWithDirectJammers(const std::map<AsciiString, Real>& componentNames) const
{
	// If specific components are requested, only check those components
	if (!componentNames.empty())
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
		{
			if (componentNames.find((*it)->getName()) != componentNames.end())
			{
				IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
				if (ec && ec->isJammableByDirect())
					return TRUE;
			}
		}
		return FALSE;
	}

	// Existing behavior when no components are specified
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	if (data && data->m_canBeJammedByDirectJammers)
		return true;
	return false;
}

Bool ActiveBody::canBeJammedWithAreaJammers(const std::map<AsciiString, Real>& componentNames) const
{
	// If specific components are requested, only check those components
	if (!componentNames.empty())
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
		{
			if (componentNames.find((*it)->getName()) != componentNames.end())
			{
				IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
				if (ec && ec->isJammableByArea())
					return TRUE;
			}
		}
		return FALSE;
	}

	// Existing behavior when no components are specified
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	if (data && data->m_canBeJammedByAreaJammers)
		return true;
	return false;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware Jamming state change handler
//-------------------------------------------------------------------------------------------------
void ActiveBody::onJammingChange(Bool isNowSubdued)
{
	//if (!getObject()->isKindOf(KINDOF_PROJECTILE))
	{
		Object* me = getObject();

		if (isNowSubdued)
		{
			me->setDisabled(DISABLED_JAMMING);

		}
		else
		{
			me->clearDisabled(DISABLED_JAMMING);

		}
	}
	//else if (isNowSubdued)// There is no coming back from being jammed, and projectiles can't even heal, but this makes it clear.
	//{
	//	ProjectileUpdateInterface* pui = getObject()->getProjectileUpdateInterface();
	//	if (pui)
	//	{
	//		pui->projectileNowJammed();
	//	}
	//}
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware Jamming jammed status check
//-------------------------------------------------------------------------------------------------
Bool ActiveBody::isJammingJammed() const
{
	// Check global Jamming damage first
	if (m_maxHealth <= m_currentJammingDamage)
		return true;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if any components are Jamming jammed using getStatus()
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
		{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (!ec) continue;
			
			const Component* comp = *it;
			ComponentStatus status = comp->getStatus();
			
			// Component is Jamming jammed if its status is DOWNED and jamming damage >= max health
			// (getStatus() already checks this internally for electronics components)
			if (status == COMPONENT_STATUS_DOWNED)
			{
				Real componentMaxHealth = comp->getCurrentMaxHealth();
				Real componentJammingDamage = ec->getCurrentJammingDamage();
				// Verify jamming damage is sufficient (status could be DOWNED from health damage)
				if (componentMaxHealth > 0.0f && componentJammingDamage >= componentMaxHealth)
					return true;
			}
		}
	}
	
	return false;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based Jamming damage healing rate
//-------------------------------------------------------------------------------------------------
UnsignedInt ActiveBody::getJammingDamageHealRate() const
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Use component-based healing rate
	// Find the component with the fastest healing rate (lowest value = fastest)
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	UnsignedInt fastestRate = 0;
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
	{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (ec)
			{
				UnsignedInt rate = ec->getJammingDamageHealRate();
				if (rate > 0)
		{
					if (fastestRate == 0 || rate < fastestRate)
			{
						fastestRate = rate;
					}
				}
			}
		}
	}
	
	// If no components have healing rate, fall back to global value
	if (fastestRate == 0)
	{
		return data->m_jammingDamageHealRate;
	}
	
	return fastestRate;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based Jamming damage healing amount
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getJammingDamageHealAmount() const
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Use component-based healing amount
	// Sum up all component healing amounts
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real totalHealAmount = 0.0f;
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
	{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (ec && ec->getJammingDamageHealAmount() > 0.0f)
		{
				totalHealAmount += ec->getJammingDamageHealAmount();
			}
		}
	}
	
	// If no components have healing amount, fall back to global value
	if (totalHealAmount <= 0.0f)
	{
		return data->m_jammingDamageHealAmount;
	}
	
	return totalHealAmount;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware global Jamming damage status check
//-------------------------------------------------------------------------------------------------
Bool ActiveBody::hasAnyJammingDamage() const
{
	// Check global Jamming damage first
	if (m_currentJammingDamage > 0)
		return true;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if any components have Jamming damage
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	if (data)
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
		{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (ec && ec->hasAnyJammingDamage())
				return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware total Jamming damage calculation
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getTotalJammingDamage() const
{
	Real totalJammingDamage = m_currentJammingDamage;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Add all component Jamming damage to total
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	if (data)
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
	{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (ec)
				totalJammingDamage += ec->getCurrentJammingDamage();
		}
	}
	
	return totalJammingDamage;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based Jamming damage percentage calculation
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getJammingDamagePercentage() const
{
	Real totalJammingDamage = getTotalJammingDamage();
	Real maxJammingDamage = 0.0f;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Calculate maximum possible Jamming damage using component-based caps
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	
	// Add global Jamming damage cap if it exists
	if (data->m_jammingDamageCap > 0.0f)
	{
		maxJammingDamage += data->m_jammingDamageCap;
	}
	
	// Add component Jamming damage caps
	{
		std::vector<Component*> components = GetComponentsOfType<Component>();
		for (std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it)
	{
			IElectronicsComponent* ec = dynamic_cast<IElectronicsComponent*>(*it);
			if (ec && ec->getJammingDamageCap() > 0.0f)
		{
				maxJammingDamage += ec->getJammingDamageCap();
			}
		}
	}
	
	if (maxJammingDamage <= 0.0f)
		return 0.0f;
		
	return (totalJammingDamage / maxJammingDamage) * 100.0f;
}
