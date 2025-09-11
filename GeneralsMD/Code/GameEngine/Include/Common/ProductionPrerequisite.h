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

// FILE: ProductionPrerequisite.h //////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//
//                       Westwood Studios Pacific.
//
//                       Confidential Information
//                Copyright (C) 2001 - All Rights Reserved
//
//-----------------------------------------------------------------------------
//
// Project:    RTS3
//
// File name:  ProductionPrerequisite.h
//
// Created:    Steven Johnson, October 2001
//
//-----------------------------------------------------------------------------

#pragma once

#ifndef __ProductionPrerequisite_H_
#define __ProductionPrerequisite_H_

//-----------------------------------------------------------------------------
//           Includes
//-----------------------------------------------------------------------------
#include "Common/GameMemory.h"
#include "Common/GameCommon.h"
#include "Common/Science.h"
//#include "GameClient/ControlBar.h"

//-----------------------------------------------------------------------------
class ThingTemplate;
class Player;

//-----------------------------------------------------------------------------
class ProductionPrerequisite
{
public:

	ProductionPrerequisite();
	~ProductionPrerequisite();

	/// init to safe default values.
	void init();

	void resetSciences(void) { m_prereqSciences.clear(); }
	void addSciencePrereq(ScienceType science) { m_prereqSciences.push_back(science); }

	void resetUnits(void) { m_prereqUnits.clear(); }
	void addUnitPrereq(AsciiString units, Bool orUnitWithPrevious);
	void addUnitPrereq(const std::vector<AsciiString>& units);


	void resetSciencesConflict(void) { m_prereqSciencesConflict.clear(); }
	void addSciencePrereqConflict(ScienceType science) { m_prereqSciencesConflict.push_back(science); }

	void resetUnitsConflict(void) { m_prereqUnitsConflict.clear(); }
	void addUnitPrereqConflict(AsciiString units, Bool orUnitWithPrevious);
	void addUnitPrereqConflict(const std::vector<AsciiString>& units);

	void resetUpgrades(void) { m_prereqUpgradesNames.clear(); m_prereqUpgradesMask.clear(); }
	void addUpgradePrereq(AsciiString upgrade);

	void resetUpgradesConflict(void) { m_prereqUpgradesNamesConflict.clear(); m_prereqUpgradesMaskConflict.clear(); }
	void addUpgradePrereqConflict(AsciiString upgrade);


	/// called after all ThingTemplates have been loaded.
	void resolveNames();

	/// returns an asciistring which is a list of all the prerequisites
	/// not satisfied yet
	UnicodeString getRequiresList(const Player *player) const;

	/// returns an asciistring which is a list of all the conflict prerequisites
	/// that are currently satisfied (and thus blocking this prerequisite)
	UnicodeString getConflictList(const Player *player) const;

	/// return true iff the player satisfies our set of prerequisites
	Bool isSatisfied(const Player *player) const;

	/**
		return the BuildFacilityTemplate, if any.

		if this template needs no build facility, null is returned.

		if the template needs a build facility but the given player doesn't have any in existence,
		null will be returned.

		you may not pass 'null' for player.
	*/
	const ThingTemplate *getExistingBuildFacilityTemplate( const Player *player ) const;

	Int getAllPossibleBuildFacilityTemplates(const ThingTemplate* tmpls[], Int maxtmpls) const;

	static void parsePrerequisiteScience(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUnit(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteScienceConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUnitConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUpgrade(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUpgradeConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);

private:

	enum
	{
		UNIT_OR_WITH_PREV = 0x01	// if set, unit is "or-ed" with prev unit, so that either one's presence satisfies
	};

	struct PrereqUnitRec
	{
		const ThingTemplate*	unit;
		Int										flags;
		AsciiString						name;
	};

	enum { MAX_PREREQ = 32 };
	Int calcNumPrereqUnitsOwned(const Player *player, Int counts[MAX_PREREQ]) const;

	std::vector<PrereqUnitRec>	m_prereqUnits;
	ScienceVec									m_prereqSciences;

	std::vector<PrereqUnitRec>	m_prereqUnitsConflict;
	ScienceVec									m_prereqSciencesConflict;

	mutable std::vector<AsciiString>	m_prereqUpgradesNames;
	mutable UpgradeMaskType						m_prereqUpgradesMask;

	mutable std::vector<AsciiString>	m_prereqUpgradesNamesConflict;
	mutable UpgradeMaskType						m_prereqUpgradesMaskConflict;
};

//-----------------------------------------------------------------------------

#endif
