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

// FILE: ActiveBodyEW.cpp ///////////////////////////////////////////////////////////////////////////
// Author: Ahmed Salah, January 2025
// Desc:   Component-based Electronic Warfare (EW) damage functionality for ActiveBody
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine
#include "GameLogic/Module/ActiveBody.h"
#include "GameLogic/Component.h"
#include "GameLogic/Object.h"

// FORWARD REFERENCES /////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
// COMPONENT-BASED EW DAMAGE METHODS /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based global EW damage management
//-------------------------------------------------------------------------------------------------
void ActiveBody::internalAddEWDamage(Real delta)
{
	const ActiveBodyModuleData* data = getActiveBodyModuleData();

	m_currentEWDamage += delta;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Use component-based EW damage cap
	// Calculate total EW damage cap from all components
	Real totalComponentCap = 0.0f;
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageCap > 0.0f)
		{
			totalComponentCap += it->ewDamageCap;
		}
	}
	
	// Use the most restrictive cap (global or component-based)
	Real effectiveCap = data->m_ewDamageCap;
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
	
	m_currentEWDamage = min(m_currentEWDamage, effectiveCap);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware EW jamming capability check
//-------------------------------------------------------------------------------------------------
Bool ActiveBody::canBeEWJammed() const
{
	// Check global EW damage cap first
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	if (data->m_ewDamageCap > 0)
		return true;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if any components can be EW jammed
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageCap > 0.0f)
			return true;
	}
	
	return false;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware EW state change handler
//-------------------------------------------------------------------------------------------------
void ActiveBody::onEWChange(Bool isNowSubdued)
{
	//if (!getObject()->isKindOf(KINDOF_PROJECTILE))
	{
		Object* me = getObject();

		if (isNowSubdued)
		{
			me->setDisabled(DISABLED_EW);

		}
		else
		{
			me->clearDisabled(DISABLED_EW);

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
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware EW jammed status check
//-------------------------------------------------------------------------------------------------
Bool ActiveBody::isEWJammed() const
{
	// Check global EW damage first
	if (m_maxHealth <= m_currentEWDamage)
		return true;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if any components are EW jammed
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		Real componentMaxHealth = getComponentMaxHealth(it->name);
		Real componentEWDamage = getComponentEWDamage(it->name);
		
		// Component is EW jammed if its EW damage reaches its max health
		if (componentMaxHealth > 0.0f && componentMaxHealth <= componentEWDamage)
			return true;
	}
	
	return false;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based EW damage healing rate
//-------------------------------------------------------------------------------------------------
UnsignedInt ActiveBody::getEWDamageHealRate() const
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Use component-based healing rate
	// Find the component with the fastest healing rate (lowest value = fastest)
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	UnsignedInt fastestRate = 0;
	
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageHealRate > 0)
		{
			if (fastestRate == 0 || it->ewDamageHealRate < fastestRate)
			{
				fastestRate = it->ewDamageHealRate;
			}
		}
	}
	
	// If no components have healing rate, fall back to global value
	if (fastestRate == 0)
	{
		return data->m_ewDamageHealRate;
	}
	
	return fastestRate;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based EW damage healing amount
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getEWDamageHealAmount() const
{
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Use component-based healing amount
	// Sum up all component healing amounts
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real totalHealAmount = 0.0f;
	
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageHealAmount > 0.0f)
		{
			totalHealAmount += it->ewDamageHealAmount;
		}
	}
	
	// If no components have healing amount, fall back to global value
	if (totalHealAmount <= 0.0f)
	{
		return data->m_ewDamageHealAmount;
	}
	
	return totalHealAmount;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware global EW damage status check
//-------------------------------------------------------------------------------------------------
Bool ActiveBody::hasAnyEWDamage() const
{
	// Check global EW damage first
	if (m_currentEWDamage > 0)
		return true;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Check if any components have EW damage
	return hasAnyComponentEWDamage();
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-aware total EW damage calculation
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getTotalEWDamage() const
{
	Real totalEWDamage = m_currentEWDamage;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Add all component EW damage to total
	for (std::map<AsciiString, Real>::const_iterator it = m_componentEWDamage.begin();
		 it != m_componentEWDamage.end(); ++it)
	{
		totalEWDamage += it->second;
	}
	
	return totalEWDamage;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component-based EW damage percentage calculation
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getEWDamagePercentage() const
{
	Real totalEWDamage = getTotalEWDamage();
	Real maxEWDamage = 0.0f;
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Calculate maximum possible EW damage using component-based caps
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	
	// Add global EW damage cap if it exists
	if (data->m_ewDamageCap > 0.0f)
	{
		maxEWDamage += data->m_ewDamageCap;
	}
	
	// Add component EW damage caps
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageCap > 0.0f)
		{
			maxEWDamage += it->ewDamageCap;
		}
	}
	
	if (maxEWDamage <= 0.0f)
		return 0.0f;
		
	return (totalEWDamage / maxEWDamage) * 100.0f;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// COMPONENT-BASED EW DAMAGE PROPERTY METHODS //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Get total component-based EW damage cap
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getTotalComponentEWDamageCap() const
{
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real totalCap = 0.0f;
	
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageCap > 0.0f)
		{
			totalCap += it->ewDamageCap;
		}
	}
	
	return totalCap;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Get effective EW damage cap (global + components)
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getEffectiveEWDamageCap() const
{
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real globalCap = data->m_ewDamageCap;
	Real componentCap = getTotalComponentEWDamageCap();
	
	// If both exist, use the most restrictive
	if (globalCap > 0.0f && componentCap > 0.0f)
	{
		return min(globalCap, componentCap);
	}
	// If only one exists, use that one
	else if (globalCap > 0.0f)
	{
		return globalCap;
	}
	else if (componentCap > 0.0f)
	{
		return componentCap;
	}
	
	return 0.0f;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Get fastest component EW damage heal rate
//-------------------------------------------------------------------------------------------------
UnsignedInt ActiveBody::getFastestComponentEWHealRate() const
{
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	UnsignedInt fastestRate = 0;
	
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageHealRate > 0)
		{
			if (fastestRate == 0 || it->ewDamageHealRate < fastestRate)
			{
				fastestRate = it->ewDamageHealRate;
			}
		}
	}
	
	return fastestRate;
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Get total component EW damage heal amount
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getTotalComponentEWHealAmount() const
{
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real totalAmount = 0.0f;
	
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->ewDamageHealAmount > 0.0f)
		{
			totalAmount += it->ewDamageHealAmount;
		}
	}
	
	return totalAmount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// COMPONENT-SPECIFIC EW DAMAGE METHODS /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Component EW damage management
//-------------------------------------------------------------------------------------------------
Real ActiveBody::getComponentEWDamage(const AsciiString& componentName) const
{
	if (componentName.isEmpty())
		return 0.0f;
		
	std::map<AsciiString, Real>::const_iterator it = m_componentEWDamage.find(componentName);
	if (it != m_componentEWDamage.end())
		return it->second;
		
	return 0.0f;
}

//-------------------------------------------------------------------------------------------------
Real ActiveBody::getComponentEWDamageCap(const AsciiString& componentName) const
{
	if (componentName.isEmpty())
		return 0.0f;
		
	// Get component data from module data
	const ActiveBodyModuleData* data = static_cast<const ActiveBodyModuleData*>(getModuleData());
	if (!data)
		return 0.0f;
		
	// Find the component definition
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->name == componentName)
			return it->ewDamageCap;
	}
	
	return 0.0f;
}

//-------------------------------------------------------------------------------------------------
UnsignedInt ActiveBody::getComponentEWDamageHealRate(const AsciiString& componentName) const
{
	if (componentName.isEmpty())
		return 0;
		
	// Get component data from module data
	const ActiveBodyModuleData* data = static_cast<const ActiveBodyModuleData*>(getModuleData());
	if (!data)
		return 0;
		
	// Find the component definition
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->name == componentName)
			return it->ewDamageHealRate;
	}
	
	return 0;
}

//-------------------------------------------------------------------------------------------------
Real ActiveBody::getComponentEWDamageHealAmount(const AsciiString& componentName) const
{
	if (componentName.isEmpty())
		return 0.0f;
		
	// Get component data from module data
	const ActiveBodyModuleData* data = static_cast<const ActiveBodyModuleData*>(getModuleData());
	if (!data)
		return 0.0f;
		
	// Find the component definition
	for (std::vector<Component>::const_iterator it = data->m_components.begin();
		 it != data->m_components.end(); ++it)
	{
		if (it->name == componentName)
			return it->ewDamageHealAmount;
	}
	
	return 0.0f;
}

//-------------------------------------------------------------------------------------------------
Bool ActiveBody::setComponentEWDamage(const AsciiString& componentName, Real damage)
{
	if (componentName.isEmpty())
		return false;
		
	Real componentCap = getComponentEWDamageCap(componentName);
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Apply global EW damage cap to components
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real globalCap = data->m_ewDamageCap;
	
	// Apply component-specific cap first
	if (componentCap > 0.0f)
	{
		damage = min(damage, componentCap);
	}
	
	// Apply global EW damage cap to components
	if (globalCap > 0.0f)
	{
		damage = min(damage, globalCap);
	}
	
	m_componentEWDamage[componentName] = max(0.0f, damage);
	return true;
}

//-------------------------------------------------------------------------------------------------
Bool ActiveBody::addComponentEWDamage(const AsciiString& componentName, Real damage)
{
	if (componentName.isEmpty() || damage <= 0.0f)
		return false;
		
	Real currentDamage = getComponentEWDamage(componentName);
	Real componentCap = getComponentEWDamageCap(componentName);
	
	// TheSuperHackers @feature Ahmed Salah 15/01/2025 Apply global EW damage cap to components
	const ActiveBodyModuleData* data = getActiveBodyModuleData();
	Real globalCap = data->m_ewDamageCap;
	
	Real newDamage = currentDamage + damage;
	
	// Apply component-specific cap first
	if (componentCap > 0.0f)
	{
		newDamage = min(newDamage, componentCap);
	}
	
	// Apply global EW damage cap to components
	if (globalCap > 0.0f)
	{
		newDamage = min(newDamage, globalCap);
	}
	
	return setComponentEWDamage(componentName, newDamage);
}

//-------------------------------------------------------------------------------------------------
Bool ActiveBody::hasAnyComponentEWDamage() const
{
	for (std::map<AsciiString, Real>::const_iterator it = m_componentEWDamage.begin();
		 it != m_componentEWDamage.end(); ++it)
	{
		if (it->second > 0.0f)
			return true;
	}
	
	return false;
}

//-------------------------------------------------------------------------------------------------
void ActiveBody::healComponentEWDamage(const AsciiString& componentName, Real healing)
{
	if (componentName.isEmpty() || healing <= 0.0f)
		return;
		
	Real currentDamage = getComponentEWDamage(componentName);
	if (currentDamage > 0.0f)
	{
		Real newDamage = max(0.0f, currentDamage - healing);
		setComponentEWDamage(componentName, newDamage);
	}
}
