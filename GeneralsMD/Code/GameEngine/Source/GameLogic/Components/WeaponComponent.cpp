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

// WeaponComponent.cpp ///////////////////////////////////////////////////////////////////
// Weapon-specific component with additional weapon-related properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/WeaponComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for WeaponComponent inheritance support
//-------------------------------------------------------------------------------------------------
void WeaponComponent::parseWeaponComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "MainGun", "SecondaryWeapon", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	WeaponComponent* component = new WeaponComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	WeaponComponent::buildFieldParse(p);
	
	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_componentsData.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for WeaponComponent inheritance support
//-------------------------------------------------------------------------------------------------
void WeaponComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// First add all base Component fields
	Component::buildFieldParse(p);
	
	// Then add WeaponComponent-specific fields (empty for now, will be added later)
	static const FieldParse weaponComponentFieldParse[] = {
		{ 0, 0, 0, 0 }
	};
	
	p.add(weaponComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Virtual clone method for polymorphic copying
//-------------------------------------------------------------------------------------------------
Component* WeaponComponent::clone() const
{
	// Create a new WeaponComponent
	WeaponComponent* copy = new WeaponComponent();
	
	// Copy base Component members using helper method (WeaponComponent has no additional members)
	copyBaseComponentMembers(copy);
	
	return copy;
}

//-------------------------------------------------------------------------------------------------
void WeaponComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void WeaponComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void WeaponComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}