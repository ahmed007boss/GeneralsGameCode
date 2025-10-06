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
#include "Lib/BaseType.h"
#include "Common/GameMemory.h"
#include "Common/GameCommon.h"
#include "Common/Science.h"
#include "Common/PlayerPrerequisite.h"
//#include "GameClient/ControlBar.h"

//-----------------------------------------------------------------------------
class ThingTemplate;
class Player;

//-----------------------------------------------------------------------------
// TheSuperHackers @refactor author 15/01/2025 ProductionPrerequisite now inherits from PlayerPrerequisite base class
class ProductionPrerequisite : public PlayerPrerequisite
{
public:

	ProductionPrerequisite();
	~ProductionPrerequisite();

	// All functionality is now inherited from PlayerPrerequisite base class
	// Static parsing functions delegate to base class
	static void parsePrerequisites(INI* ini, void* instance, void* store, const void* userData);

private:
	static void parsePrerequisiteScience(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUnit(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteScienceConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUnitConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUpgrade(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void parsePrerequisiteUpgradeConflict(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
};

//-----------------------------------------------------------------------------

#endif
