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

// FILE: ProductionPrerequisite.cpp /////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//
//                       Westwood Studios Pacific.
//
//                       Confidential Information
//                Copyright (C) 2001 - All Rights Reserved
//
//-----------------------------------------------------------------------------
//
// Project:   RTS3
//
// File name: ProductionPrerequisite.cpp
//
// Created:   Steven Johnson, October 2001
//
// Desc:      @todo
//
//-----------------------------------------------------------------------------

#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include "Common/ProductionPrerequisite.h"
#include "Common/Player.h"
#include "Common/ThingFactory.h"
#include "Common/ThingTemplate.h"
#include "GameLogic/Object.h"
#include "GameClient/Drawable.h"
#include "GameClient/GameText.h"


//-----------------------------------------------------------------------------
ProductionPrerequisite::ProductionPrerequisite()
{
	init();
}

//-----------------------------------------------------------------------------
ProductionPrerequisite::~ProductionPrerequisite()
{
}

//-----------------------------------------------------------------------------
void ProductionPrerequisite::init()
{
	m_prereqUnits.clear();
	m_prereqSciences.clear();
	m_prereqUnitsConflict.clear();
	m_prereqSciencesConflict.clear();
}

//=============================================================================
void ProductionPrerequisite::resolveNames()
{
	// Resolve regular prerequisite units
	for (size_t i = 0; i < m_prereqUnits.size(); i++)
	{
		//
		// note that this will find the template at the "top most" level (not override
		// sub-temlates), which is what we want ... we conceptually only have one
		// template for any given thing, it's only the *data* that is overridden
		//
		if( m_prereqUnits[ i ].name.isNotEmpty() )
		{
			m_prereqUnits[i].unit = TheThingFactory->findTemplate(m_prereqUnits[i].name);	// might be null

 			/** @todo for now removing this assert until we can completely remove
 			the GDF stuff, the problem is that some INI files refer to GDF names, and they
 			aren't yet loaded in the world builder but will all go away later anyway etc */
			DEBUG_ASSERTCRASH(m_prereqUnits[i].unit,("could not find prereq %s",m_prereqUnits[i].name.str()));

			m_prereqUnits[i].name.clear(); // we're done with it
		}
	}

	// Resolve conflict prerequisite units
	for (size_t i = 0; i < m_prereqUnitsConflict.size(); i++)
	{
		if (m_prereqUnitsConflict[i].name.isNotEmpty())
		{
			m_prereqUnitsConflict[i].unit = TheThingFactory->findTemplate(m_prereqUnitsConflict[i].name);	// might be null

			/** @todo for now removing this assert until we can completely remove
			the GDF stuff, the problem is that some INI files refer to GDF names, and they
			aren't yet loaded in the world builder but will all go away later anyway etc */
			DEBUG_ASSERTCRASH(m_prereqUnitsConflict[i].unit, ("could not find prereq %s", m_prereqUnitsConflict[i].name.str()));

			m_prereqUnitsConflict[i].name.clear(); // we're done with it
		}
	}


	// Resolve prerequisite upgrades
	std::vector<AsciiString>::const_iterator it;
	for (it = m_prereqUpgradesNames.begin(); it != m_prereqUpgradesNames.end(); ++it)
	{
		const UpgradeTemplate* theTemplate = TheUpgradeCenter->findUpgrade(*it);
		if (!theTemplate)
		{
			DEBUG_CRASH(("An upgrade module references '%s', which is not an Upgrade", it->str()));
			throw INI_INVALID_DATA;
		}
		m_prereqUpgradesMask.set(theTemplate->getUpgradeMask());
	}

	// Resolve conflict prerequisite upgrades
	for (it = m_prereqUpgradesNamesConflict.begin(); it != m_prereqUpgradesNamesConflict.end(); ++it)
	{
		const UpgradeTemplate* theTemplate = TheUpgradeCenter->findUpgrade(*it);
		if (!theTemplate)
		{
			DEBUG_CRASH(("An upgrade module references '%s', which is not an Upgrade", it->str()));
			throw INI_INVALID_DATA;
		}
		m_prereqUpgradesMaskConflict.set(theTemplate->getUpgradeMask());
	}
}

//-----------------------------------------------------------------------------
Int ProductionPrerequisite::calcNumPrereqUnitsOwned(const Player *player, Int counts[MAX_PREREQ]) const
{
	const ThingTemplate *tmpls[MAX_PREREQ];
	Int cnt = m_prereqUnits.size();
	if (cnt > MAX_PREREQ)
		cnt = MAX_PREREQ;
	for (int i = 0; i < cnt; i++)
		tmpls[i] = m_prereqUnits[i].unit;
	player->countObjectsByThingTemplate(cnt, tmpls, false, counts);
	return cnt;
}

//-----------------------------------------------------------------------------
Int ProductionPrerequisite::getAllPossibleBuildFacilityTemplates(const ThingTemplate* tmpls[], Int maxtmpls) const
{
	Int count = 0;
	for (size_t i = 0; i < m_prereqUnits.size(); i++)
	{
		if (i > 0 && !(m_prereqUnits[i].flags & UNIT_OR_WITH_PREV))
			break;
		if (count >= maxtmpls)
			break;
		tmpls[count++] = m_prereqUnits[i].unit;
	}
	return count;
}

//-----------------------------------------------------------------------------
const ThingTemplate *ProductionPrerequisite::getExistingBuildFacilityTemplate( const Player *player ) const
{
	DEBUG_ASSERTCRASH(player, ("player may not be null"));
	if (m_prereqUnits.size())
	{
		Int ownCount[MAX_PREREQ];
		Int cnt = calcNumPrereqUnitsOwned(player, ownCount);
		for (int i = 0; i < cnt; i++)
		{
			if (i > 0 && !(m_prereqUnits[i].flags & UNIT_OR_WITH_PREV))
				break;
			if (ownCount[i])
				return m_prereqUnits[i].unit;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------
Bool ProductionPrerequisite::isSatisfied(const Player *player) const
{
	Int i;

	if (!player)
		return false;

	// gotta have all the prereq sciences.
	for (i = 0; i < m_prereqSciences.size(); i++)
	{
		if (!player->hasScience(m_prereqSciences[i]))
			return false;
	}

	// gotta have all the prereq sciences.
	for (i = 0; i < m_prereqSciencesConflict.size(); i++)
	{
		if (player->hasScience(m_prereqSciencesConflict[i]))
			return false;
	}

	// the player must have at least one instance of each prereq unit.
	Int ownCount[MAX_PREREQ];
	Int cnt = calcNumPrereqUnitsOwned(player, ownCount);

	// fix up the "or" cases. (start at 1!)
	for (i = 1; i < cnt; i++)
	{
		if (m_prereqUnits[i].flags & UNIT_OR_WITH_PREV)
		{
			ownCount[i] += ownCount[i-1];	// lump 'em together for prereq purposes
			ownCount[i-1] = -1;						// flag for "ignore me"
		}
	}

	for (i = 0; i < cnt; i++)
	{
		if (ownCount[i] == -1)	// the magic "ignore me" flag
			continue;
		if (ownCount[i] == 0)		// everything not ignored, is required
			return false;
	}


	// the player must NOT have any of the conflicting units
	Int ownCount2[MAX_PREREQ];
	Int cnt2 = m_prereqUnitsConflict.size();
	if (cnt2 > MAX_PREREQ)
		cnt2 = MAX_PREREQ;
	
	// Count owned conflicting units
	for (int j = 0; j < cnt2; j++)
	{
		ownCount2[j] = 0;
		if (m_prereqUnitsConflict[j].unit)
		{
			player->countObjectsByThingTemplate(1, &m_prereqUnitsConflict[j].unit, false, &ownCount2[j]);
		}
	}

	// fix up the "or" cases. (start at 1!)
	for (i = 1; i < cnt2; i++)
	{
		if (m_prereqUnitsConflict[i].flags & UNIT_OR_WITH_PREV)
		{
			ownCount2[i] += ownCount2[i - 1];	// lump 'em together for conflict purposes
			ownCount2[i - 1] = -1;						// flag for "ignore me"
		}
	}

	for (i = 0; i < cnt2; i++)
	{
		if (ownCount2[i] == -1)	// the magic "ignore me" flag
			continue;
		if (ownCount2[i] > 0)		// player owns a conflicting unit
			return false;
	}

	// Check upgrade prerequisites
	UpgradeMaskType playerMask = player->getCompletedUpgradeMask();
	if (m_prereqUpgradesMask.any())
	{
		if (!playerMask.testForAll(m_prereqUpgradesMask))
			return false;
	}

	// Check conflicting upgrade prerequisites
	if (m_prereqUpgradesMaskConflict.any())
	{
		if (playerMask.testForAny(m_prereqUpgradesMaskConflict))
			return false;
	}

	return true;
}

//-------------------------------------------------------------------------------------------------
/** Add a unit prerequisite, if 'orWithPrevious' is set then this unit is said
	* to be an alternate prereq to the previously added unit, otherwise this becomes
	* a new 'block' and is required in ADDDITION to other entries.
	* Return FALSE if no space left to add unit */
//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::addUnitPrereq( AsciiString unit, Bool orUnitWithPrevious )
{
	PrereqUnitRec info;
	info.name = unit;
	info.flags = orUnitWithPrevious ? UNIT_OR_WITH_PREV : 0;
	info.unit = NULL;
	m_prereqUnits.push_back(info);

}  // end addUnitPrereq

//-------------------------------------------------------------------------------------------------
/** Add a unit prerequisite, if 'orWithPrevious' is set then this unit is said
	* to be an alternate prereq to the previously added unit, otherwise this becomes
	* a new 'block' and is required in ADDDITION to other entries.
	* Return FALSE if no space left to add unit */
//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::addUnitPrereq( const std::vector<AsciiString>& units )
{
	Bool orWithPrevious = false;
	for (size_t i = 0; i < units.size(); ++i)
	{
		addUnitPrereq(units[i], orWithPrevious);
		orWithPrevious = true;
	}

}  // end addUnitPrereq



//-------------------------------------------------------------------------------------------------
/** Add a unit prerequisite, if 'orWithPrevious' is set then this unit is said
	* to be an alternate prereq to the previously added unit, otherwise this becomes
	* a new 'block' and is required in ADDDITION to other entries.
	* Return FALSE if no space left to add unit */
	//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::addUnitPrereqConflict(AsciiString unit, Bool orUnitWithPrevious)
{
	PrereqUnitRec info;
	info.name = unit;
	info.flags = orUnitWithPrevious ? UNIT_OR_WITH_PREV : 0;
	info.unit = NULL;
	m_prereqUnitsConflict.push_back(info);

}  // end addUnitPrereqConflict

//-------------------------------------------------------------------------------------------------
/** Add a unit prerequisite, if 'orWithPrevious' is set then this unit is said
	* to be an alternate prereq to the previously added unit, otherwise this becomes
	* a new 'block' and is required in ADDDITION to other entries.
	* Return FALSE if no space left to add unit */
	//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::addUnitPrereqConflict(const std::vector<AsciiString>& units)
{
	Bool orWithPrevious = false;
	for (size_t i = 0; i < units.size(); ++i)
	{
		addUnitPrereqConflict(units[i], orWithPrevious);
		orWithPrevious = true;
	}

}  // end addUnitPrereq

//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::addUpgradePrereq(AsciiString upgrade)
{
	m_prereqUpgradesNames.push_back(upgrade);
}

//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::addUpgradePrereqConflict(AsciiString upgrade)
{
	m_prereqUpgradesNamesConflict.push_back(upgrade);
}

//-------------------------------------------------------------------------------------------------
// returns an asciistring which is a list of all the prerequisites
// not satisfied yet
UnicodeString ProductionPrerequisite::getRequiresList(const Player *player) const
{

	// if player is invalid, return empty string
	if (!player)
		return UnicodeString::TheEmptyString;

	UnicodeString requiresList = UnicodeString::TheEmptyString;

	// check the prerequired units
	Int ownCount[MAX_PREREQ];
	Int cnt = calcNumPrereqUnitsOwned(player, ownCount);
	Int i;

	Bool orRequirements[MAX_PREREQ];
	//Added for fix below in getRequiresList
	//By Sadullah Nader
	//Initializes the OR_WITH_PREV structures
	for (i = 0; i < MAX_PREREQ; i++)
	{
		orRequirements[i] = FALSE;
	}
	//
	// account for the "or" unit cases, start for loop at 1
	for (i = 1; i < cnt; i++)
	{
		if (m_prereqUnits[i].flags & UNIT_OR_WITH_PREV)
		{
			orRequirements[i] = TRUE;     // set the flag for this unit to be "ored" with previous
			ownCount[i] += ownCount[i-1];	// lump 'em together for prereq purposes
			ownCount[i-1] = -1;						// flag for "ignore me"
		}
	}

	// check to see if anything is required
	const ThingTemplate *unit;
	UnicodeString unitName;
	Bool firstRequirement = true;
	for (i = 0; i < cnt; i++)
	{
		// we have an unfulfilled requirement
		if (ownCount[i] == 0) {

			if(orRequirements[i])
			{
				unit = m_prereqUnits[i-1].unit;
				unitName = unit->getDisplayName();
				unitName.concat( L" " );
				unitName.concat(TheGameText->fetch("CONTROLBAR:OrRequirement", NULL));
				unitName.concat( L" " );
				requiresList.concat(unitName);
			}

			// get the requirement and then its name
			unit = m_prereqUnits[i].unit;
			unitName = unit->getDisplayName();

			// gets command button, and then modifies unitName
			//CommandButton *cmdButton = TheControlBar->findCommandButton(unit->getName());
			//if (cmdButton)
				//unitName.translate(TheGameText->fetch(cmdButton->m_textLabel.str()));

			// format name appropriately with 'returns' if necessary
			if (firstRequirement)
				firstRequirement = false;
			else
				unitName.concat(L"\n");

			// add it to the list
			requiresList.concat(unitName);
		}
	}

	// gotta have all the prereq sciences.
	for (i = 0; i < m_prereqSciences.size(); i++)
	{
		if (!player->hasScience(m_prereqSciences[i]))
		{
			UnicodeString scienceName, scienceDesc;
			if (TheScienceStore->getNameAndDescription(m_prereqSciences[i], scienceName, scienceDesc))
			{
				// format name appropriately with 'returns' if necessary
				if (firstRequirement)
					firstRequirement = false;
				else
					scienceName.concat(L"\n");

				// add it to the list
				requiresList.concat(scienceName);
			}
		}
	}

	// Check upgrade prerequisites
	UpgradeMaskType playerMask = player->getCompletedUpgradeMask();
	if (m_prereqUpgradesMask.any())
	{
		if (!playerMask.testForAll(m_prereqUpgradesMask))
		{
			// Check each upgrade individually to show specific names
			for (std::vector<AsciiString>::const_iterator it = m_prereqUpgradesNames.begin(); it != m_prereqUpgradesNames.end(); ++it)
			{
				const UpgradeTemplate* upgradeTemplate = TheUpgradeCenter->findUpgrade(*it);
				if (upgradeTemplate)
				{
					UpgradeMaskType upgradeMask = upgradeTemplate->getUpgradeMask();
					if (!playerMask.testForAll(upgradeMask))
					{
						UnicodeString upgradeName = TheGameText->fetch(upgradeTemplate->getDisplayNameLabel().str());
						
						// format name appropriately with 'returns' if necessary
						if (firstRequirement)
							firstRequirement = false;
						else
							upgradeName.concat(L"\n");

						// add it to the list
						requiresList.concat(upgradeName);
					}
				}
			}
		}
	}

	// return final list
	return requiresList;
}

//-------------------------------------------------------------------------------------------------
// returns an asciistring which is a list of all the conflict prerequisites
// that are currently satisfied (and thus blocking this prerequisite)
UnicodeString ProductionPrerequisite::getConflictList(const Player *player) const
{
	// if player is invalid, return empty string
	if (!player)
		return UnicodeString::TheEmptyString;

	UnicodeString conflictList = UnicodeString::TheEmptyString;

	// check the conflicting units
	Int ownCount[MAX_PREREQ];
	Int cnt = m_prereqUnitsConflict.size();
	if (cnt > MAX_PREREQ)
		cnt = MAX_PREREQ;
	
	// Count owned conflicting units
	for (int i = 0; i < cnt; i++)
	{
		ownCount[i] = 0;
		if (m_prereqUnitsConflict[i].unit)
		{
			player->countObjectsByThingTemplate(1, &m_prereqUnitsConflict[i].unit, false, &ownCount[i]);
		}
	}

	Int i;
	Bool orRequirements[MAX_PREREQ];
	// Initialize the OR_WITH_PREV structures
	for (i = 0; i < MAX_PREREQ; i++)
	{
		orRequirements[i] = FALSE;
	}

	// account for the "or" unit cases, start for loop at 1
	for (i = 1; i < cnt; i++)
	{
		if (m_prereqUnitsConflict[i].flags & UNIT_OR_WITH_PREV)
		{
			orRequirements[i] = TRUE;     // set the flag for this unit to be "ored" with previous
			ownCount[i] += ownCount[i-1];	// lump 'em together for conflict purposes
			ownCount[i-1] = -1;						// flag for "ignore me"
		}
	}

	// check to see if anything is conflicting
	const ThingTemplate *unit;
	UnicodeString unitName;
	Bool firstConflict = true;
	for (i = 0; i < cnt; i++)
	{
		// we have a conflicting requirement (player owns this unit)
		if (ownCount[i] > 0) {

			if(orRequirements[i])
			{
				unit = m_prereqUnitsConflict[i-1].unit;
				unitName = unit->getDisplayName();
				unitName.concat( L" " );
				unitName.concat(TheGameText->fetch("CONTROLBAR:OrRequirement", NULL));
				unitName.concat( L" " );
				conflictList.concat(unitName);
			}

			// get the conflicting unit and then its name
			unit = m_prereqUnitsConflict[i].unit;
			unitName = unit->getDisplayName();

			// format name appropriately with 'returns' if necessary
			if (firstConflict)
				firstConflict = false;
			else
				unitName.concat(L"\n");

			// add it to the list
			conflictList.concat(unitName);
		}
	}

	// check for conflicting sciences
	for (i = 0; i < m_prereqSciencesConflict.size(); i++)
	{
		if (player->hasScience(m_prereqSciencesConflict[i]))
		{
			UnicodeString scienceName, scienceDesc;
			if (TheScienceStore->getNameAndDescription(m_prereqSciencesConflict[i], scienceName, scienceDesc))
			{
				// format name appropriately with 'returns' if necessary
				if (firstConflict)
					firstConflict = false;
				else
					scienceName.concat(L"\n");

				// add it to the list
				conflictList.concat(scienceName);
			}
		}
	}

	// Check conflicting upgrade prerequisites
	UpgradeMaskType playerMask = player->getCompletedUpgradeMask();
	if (m_prereqUpgradesMaskConflict.any())
	{
		if (playerMask.testForAny(m_prereqUpgradesMaskConflict))
		{
			// Check each upgrade individually to show specific names
			for (std::vector<AsciiString>::const_iterator it = m_prereqUpgradesNamesConflict.begin(); it != m_prereqUpgradesNamesConflict.end(); ++it)
			{
				const UpgradeTemplate* upgradeTemplate = TheUpgradeCenter->findUpgrade(*it);
				if (upgradeTemplate)
				{
					UpgradeMaskType upgradeMask = upgradeTemplate->getUpgradeMask();
					if (playerMask.testForAny(upgradeMask))
					{
						UnicodeString upgradeName = TheGameText->fetch(upgradeTemplate->getDisplayNameLabel().str());
						
						// format name appropriately with 'returns' if necessary
						if (firstConflict)
							firstConflict = false;
						else
							upgradeName.concat(L"\n");

						// add it to the list
						conflictList.concat(upgradeName);
					}
				}
			}
		}
	}

	// return final list
	return conflictList;
}


void ProductionPrerequisite::parsePrerequisiteUnit(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	std::vector<ProductionPrerequisite>* v = (std::vector<ProductionPrerequisite>*)instance;

	ProductionPrerequisite prereq;
	Bool orUnitWithPrevious = FALSE;
	for (const char* token = ini->getNextToken(); token != NULL; token = ini->getNextTokenOrNull())
	{
		prereq.addUnitPrereq(AsciiString(token), orUnitWithPrevious);
		orUnitWithPrevious = TRUE;
	}

	v->push_back(prereq);
}

//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::parsePrerequisiteScience(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	std::vector<ProductionPrerequisite>* v = (std::vector<ProductionPrerequisite>*)instance;

	ProductionPrerequisite prereq;
	prereq.addSciencePrereq(INI::scanScience(ini->getNextToken()));

	v->push_back(prereq);
}



void ProductionPrerequisite::parsePrerequisiteUnitConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	std::vector<ProductionPrerequisite>* v = (std::vector<ProductionPrerequisite>*)instance;

	ProductionPrerequisite prereq;
	Bool orUnitWithPrevious = FALSE;
	for (const char* token = ini->getNextToken(); token != NULL; token = ini->getNextTokenOrNull())
	{
		prereq.addUnitPrereqConflict(AsciiString(token), orUnitWithPrevious);
		orUnitWithPrevious = TRUE;
	}

	v->push_back(prereq);
}

//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::parsePrerequisiteScienceConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	std::vector<ProductionPrerequisite>* v = (std::vector<ProductionPrerequisite>*)instance;

	ProductionPrerequisite prereq;
	prereq.addSciencePrereqConflict(INI::scanScience(ini->getNextToken()));

	v->push_back(prereq);
}

//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::parsePrerequisiteUpgrade(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	std::vector<ProductionPrerequisite>* v = (std::vector<ProductionPrerequisite>*)instance;

	ProductionPrerequisite prereq;
	prereq.addUpgradePrereq(AsciiString(ini->getNextToken()));

	v->push_back(prereq);
}

//-------------------------------------------------------------------------------------------------
void ProductionPrerequisite::parsePrerequisiteUpgradeConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	std::vector<ProductionPrerequisite>* v = (std::vector<ProductionPrerequisite>*)instance;

	ProductionPrerequisite prereq;
	prereq.addUpgradePrereqConflict(AsciiString(ini->getNextToken()));

	v->push_back(prereq);
}
