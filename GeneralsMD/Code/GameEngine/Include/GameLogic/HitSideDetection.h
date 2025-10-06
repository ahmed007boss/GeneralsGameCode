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

// FILE: HitSideDetection.h /////////////////////////////////////////////////////////////////////////////////
// Author: TheSuperHackers, January 2025
// Desc:   Hit side detection for side-specific armor
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _HitSideDetection_H_
#define _HitSideDetection_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "GameLogic/Damage.h"
#include "Common/GameType.h"

// FORWARD REFERENCES /////////////////////////////////////////////////////////////////////////////
class Object;

//-------------------------------------------------------------------------------------------------
/** Hit side detection utility functions */
//-------------------------------------------------------------------------------------------------
class HitSideDetection
{
public:
	/**
		Determines which side of an object was hit based on the damage direction vector
		and the object's orientation.
		
		@param target The object that was hit
		@param damageDirection The direction vector from source to target
		@return The side that was hit (HIT_SIDE_FRONT, HIT_SIDE_BACK, etc.)
	*/
	static HitSide determineHitSide(const Object* target, const Coord3D& damageDirection);
	
	/**
		Determines hit side using object positions instead of direction vector
		
		@param target The object that was hit
		@param source The object that caused the damage
		@return The side that was hit
	*/
	static HitSide determineHitSide(const Object* target, const Object* source);
	
private:
	/**
		Helper function to determine hit side from normalized direction vector
		and object's transform matrix
	*/
	static HitSide calculateHitSideFromDirection(const Object* target, const Coord3D& normalizedDirection);
};

#endif // _HitSideDetection_H_
