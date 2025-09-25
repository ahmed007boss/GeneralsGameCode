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

// FILE: InventoryBehavior.cpp ///////////////////////////////////////////////////////////////////////
// Created: TheSuperHackers, January 2025
// Desc:    Inventory behavior module for managing limited resources
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include "Common/INI.h"
#include "Common/Xfer.h"
#include "GameLogic/Module/InventoryBehavior.h"
#include "GameLogic/Object.h"
#include "GameClient/GameText.h"

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

InventoryBehaviorModuleData::InventoryBehaviorModuleData()
{
	m_inventoryItems.clear();
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Parse Item sub-region
//-------------------------------------------------------------------------------------------------
static void parseItem(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	InventoryBehaviorModuleData* data = static_cast<InventoryBehaviorModuleData*>(instance);
	
	// Get the item key from the INI token (e.g., "Item = Ammo" -> "Ammo")
	AsciiString itemKey = ini->getNextToken();
	
            // Create a temporary structure to hold the parsed values
            struct TempItemData {
                UnicodeString m_displayName;
                Int m_maxStorageCount;
                Int m_initialAvailableAmount;
                Int m_costPerItem;
            } tempData;
	
            static const FieldParse tempItemFieldParse[] =
            {
                { "DisplayName", INI::parseAndTranslateLabel, NULL, offsetof(TempItemData, m_displayName) },
                { "MaxStorageCount", INI::parseInt, NULL, offsetof(TempItemData, m_maxStorageCount) },
                { "InitialAvailableAmount", INI::parseInt, NULL, offsetof(TempItemData, m_initialAvailableAmount) },
                { "CostPerItem", INI::parseInt, NULL, offsetof(TempItemData, m_costPerItem) },
                { 0, 0, 0, 0 }
            };
	
	ini->initFromINI(&tempData, tempItemFieldParse);
	
            // Store the parsed data in the module data
            if (!itemKey.isEmpty())
            {
                InventoryItemConfig config;
                config.displayName = tempData.m_displayName;
                config.maxStorageCount = tempData.m_maxStorageCount;
                config.initialAvailableAmount = tempData.m_initialAvailableAmount;
                config.costPerItem = tempData.m_costPerItem;
                
                data->m_inventoryItems[itemKey] = config;
            }
}

//-------------------------------------------------------------------------------------------------
void InventoryBehaviorModuleData::buildFieldParse(MultiIniFieldParse& p)
{
	ModuleData::buildFieldParse(p);
	static const FieldParse inventoryFieldParse[] =
	{
		{ "Item", parseItem, NULL, 0 },
		{ 0, 0, 0, 0 }
	};

	p.add(inventoryFieldParse);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Helper methods for InventoryBehaviorModuleData
//-------------------------------------------------------------------------------------------------
Int InventoryBehaviorModuleData::getMaxStorageCount(const AsciiString& itemKey) const
{
	std::map<AsciiString, InventoryItemConfig>::const_iterator it = m_inventoryItems.find(itemKey);
	return (it != m_inventoryItems.end()) ? it->second.maxStorageCount : 0;
}

Int InventoryBehaviorModuleData::getInitialAvailableAmount(const AsciiString& itemKey) const
{
	std::map<AsciiString, InventoryItemConfig>::const_iterator it = m_inventoryItems.find(itemKey);
	return (it != m_inventoryItems.end()) ? it->second.initialAvailableAmount : 0;
}

const UnicodeString& InventoryBehaviorModuleData::getDisplayName(const AsciiString& itemKey) const
{
    static UnicodeString emptyString;
    std::map<AsciiString, InventoryItemConfig>::const_iterator it = m_inventoryItems.find(itemKey);
    return (it != m_inventoryItems.end()) ? it->second.displayName : emptyString;
}

Int InventoryBehaviorModuleData::getCostPerItem(const AsciiString& itemKey) const
{
    std::map<AsciiString, InventoryItemConfig>::const_iterator it = m_inventoryItems.find(itemKey);
    return (it != m_inventoryItems.end()) ? it->second.costPerItem : 0;
}

//-------------------------------------------------------------------------------------------------
UnicodeString InventoryBehaviorModuleData::getModuleDescription() const
{
	if (m_inventoryItems.empty())
		return L"";

	UnicodeString result;
	bool first = true;
	bool hasAnyItems = false;
	
	for (std::map<AsciiString, InventoryItemConfig>::const_iterator it = m_inventoryItems.begin(); 
		 it != m_inventoryItems.end(); ++it)
	{
		const InventoryItemConfig& config = it->second;
		
		// Only include items with initialAvailableAmount > 0
		if (config.initialAvailableAmount > 0)
		{
			if (!first)
				result += L" and ";
			
			// Use += to append instead of format which overwrites
			UnicodeString itemText;
			itemText.format(L"%d %s", config.initialAvailableAmount, config.displayName.str());
			result += itemText;
			first = false;
			hasAnyItems = true;
		}
	}
	
	// Return empty string if no items have initial amounts > 0
	if (!hasAnyItems)
		return L"";
	
	// Add "Comes with" prefix
	UnicodeString finalResult;
	finalResult.format(L"Comes with %s", result.str());
	return finalResult;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

InventoryBehavior::InventoryBehavior(Thing* thing, const ModuleData* moduleData) : BehaviorModule(thing, moduleData)
{
}

//-------------------------------------------------------------------------------------------------
InventoryBehavior::~InventoryBehavior()
{
}

//-------------------------------------------------------------------------------------------------
void InventoryBehavior::onObjectCreated()
{
	// Initialize runtime state from module data
	const InventoryBehaviorModuleData* data = static_cast<const InventoryBehaviorModuleData*>(getModuleData());
	if (data)
	{
		// Initialize current amounts from initial available amounts
		for (std::map<AsciiString, InventoryItemConfig>::const_iterator it = data->m_inventoryItems.begin(); 
			 it != data->m_inventoryItems.end(); ++it)
		{
			const AsciiString& itemKey = it->first;
			Int initialAmount = it->second.initialAvailableAmount;
			if (!itemKey.isEmpty() && initialAmount > 0)
			{
				// Use setter method to ensure proper validation
				setItemCount(itemKey, initialAmount);
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------
void InventoryBehavior::update(Object* object)
{
	// Inventory behavior doesn't need per-frame updates
	// Consumption is handled by command buttons and weapons
}

//-------------------------------------------------------------------------------------------------
void InventoryBehavior::destroy(Object* object)
{
	m_currentAmounts.clear();
}

//-------------------------------------------------------------------------------------------------
Bool InventoryBehavior::consumeItem(const AsciiString& itemKey, Int amount)
{
	if (itemKey.isEmpty() || amount <= 0)
		return false;

	std::map<AsciiString, Int>::iterator it = m_currentAmounts.find(itemKey);
	if (it == m_currentAmounts.end())
		return false;

	if (it->second < amount)
		return false;

	it->second -= amount;
	if (it->second <= 0)
	{
		m_currentAmounts.erase(it);
	}
	return true;
}

Bool InventoryBehavior::hasItem(const AsciiString& itemKey, Int amount) const
{
	if (itemKey.isEmpty() || amount <= 0)
		return false;

	std::map<AsciiString, Int>::const_iterator it = m_currentAmounts.find(itemKey);
	if (it == m_currentAmounts.end())
		return false;

	return it->second >= amount;
}

Int InventoryBehavior::getItemCount(const AsciiString& itemKey) const
{
	if (itemKey.isEmpty())
		return 0;

	std::map<AsciiString, Int>::const_iterator it = m_currentAmounts.find(itemKey);
	if (it == m_currentAmounts.end())
		return 0;

	return it->second;
}

Bool InventoryBehavior::addItem(const AsciiString& itemKey, Int amount)
{
	if (itemKey.isEmpty() || amount <= 0)
		return false;

	// Get current amount and add to it
	Int currentAmount = getItemCount(itemKey);
	Int newAmount = currentAmount + amount;
	
	// Use setter method to ensure proper validation against max storage
	return setItemCount(itemKey, newAmount);
}

Bool InventoryBehavior::setItemCount(const AsciiString& itemKey, Int count)
{
	if (itemKey.isEmpty() || count < 0)
		return false;

	// Get max storage from module data
	const InventoryBehaviorModuleData* data = static_cast<const InventoryBehaviorModuleData*>(getModuleData());
	Int maxStorage = data ? data->getMaxStorageCount(itemKey) : 0;

	if (count == 0)
	{
		m_currentAmounts.erase(itemKey);
		return true;
	}

	m_currentAmounts[itemKey] = count;
	
	// Cap at max storage
	if (maxStorage > 0 && m_currentAmounts[itemKey] > maxStorage)
		m_currentAmounts[itemKey] = maxStorage;
	
	return true;
}

Bool InventoryBehavior::isEmpty() const
{
	return m_currentAmounts.empty();
}

Int InventoryBehavior::getTotalItems() const
{
	Int total = 0;
	for (std::map<AsciiString, Int>::const_iterator it = m_currentAmounts.begin(); 
		 it != m_currentAmounts.end(); ++it)
	{
		total += it->second;
	}
	return total;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 CRC method for save/load compatibility
//-------------------------------------------------------------------------------------------------
void InventoryBehavior::crc( Xfer *xfer )
{
	// extend base class
	BehaviorModule::crc( xfer );
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Xfer method for save/load compatibility
//-------------------------------------------------------------------------------------------------
void InventoryBehavior::xfer( Xfer *xfer )
{
	// version
	XferVersion currentVersion = 1;
	XferVersion version = currentVersion;
	xfer->xferVersion( &version, currentVersion );

	if (version >= 1)
	{
		// Serialize current amounts map
		Int inventorySize = static_cast<Int>(m_currentAmounts.size());
		xfer->xferInt( &inventorySize );

		if (xfer->getXferMode() == XFER_LOAD)
		{
			m_currentAmounts.clear();
			for (Int i = 0; i < inventorySize; ++i)
			{
				AsciiString itemKey;
				Int itemCount;
				xfer->xferAsciiString( &itemKey );
				xfer->xferInt( &itemCount );
				m_currentAmounts[itemKey] = itemCount;
			}
		}
		else
		{
			for (std::map<AsciiString, Int>::const_iterator it = m_currentAmounts.begin(); 
				 it != m_currentAmounts.end(); ++it)
			{
				AsciiString itemKey = it->first;
				Int itemCount = it->second;
				xfer->xferAsciiString( &itemKey );
				xfer->xferInt( &itemCount );
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Load post-process method
//-------------------------------------------------------------------------------------------------
void InventoryBehavior::loadPostProcess( void )
{
	// extend base class
	BehaviorModule::loadPostProcess();
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Interface method for external access
//-------------------------------------------------------------------------------------------------
InventoryBehavior* InventoryBehavior::getInventoryBehavior(BehaviorModule* module)
{
	// Simple type check - if it's an InventoryBehavior, return it
	InventoryBehavior* inventoryBehavior = dynamic_cast<InventoryBehavior*>(module);
	return inventoryBehavior;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Getter for module data
//-------------------------------------------------------------------------------------------------
const InventoryBehaviorModuleData* InventoryBehavior::getInventoryModuleData() const
{
	return static_cast<const InventoryBehaviorModuleData*>(getModuleData());
}
