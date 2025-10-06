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

// FILE: HitSideDetection.cpp /////////////////////////////////////////////////////////////////////////////////
// Author: TheSuperHackers, January 2025
// Desc:   Hit side detection for side-specific armor
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "GameLogic/HitSideDetection.h"
#include "GameLogic/Object.h"
#include "WWMath/vector3.h"

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
HitSide HitSideDetection::determineHitSide(const Object* target, const Coord3D& damageDirection)
{
	if (!target || damageDirection.length() < 0.001f)
		return HIT_SIDE_UNKNOWN;
		
	// Normalize the damage direction vector
	Coord3D normalizedDirection = damageDirection;
	normalizedDirection.normalize();
	
	return calculateHitSideFromDirection(target, normalizedDirection);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
HitSide HitSideDetection::determineHitSide(const Object* target, const Object* source)
{
	if (!target || !source)
		return HIT_SIDE_UNKNOWN;
		
	// Calculate direction vector from target to source (where the hit came from)
	Coord3D damageDirection;
	damageDirection.x = source->getPosition()->x - target->getPosition()->x;
	damageDirection.y = source->getPosition()->y - target->getPosition()->y;
	damageDirection.z = source->getPosition()->z - target->getPosition()->z;
	
	return determineHitSide(target, damageDirection);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
HitSide HitSideDetection::calculateHitSideFromDirection(const Object* target, const Coord3D& normalizedDirection)
{
	// Get the object's transform matrix to determine its orientation
	const Matrix3D* transform = target->getTransformMatrix();
	if (!transform)
		return HIT_SIDE_UNKNOWN;
	
	// Get the object's local coordinate system vectors
	Vector3 forward = transform->Get_X_Vector();  // Forward direction (X-axis)
	Vector3 right = transform->Get_Y_Vector();    // Right direction (Y-axis)  
	Vector3 up = transform->Get_Z_Vector();       // Up direction (Z-axis)
	
	// Normalize the vectors
	forward.Normalize();
	right.Normalize();
	up.Normalize();
	
	// Convert Coord3D to Vector3 for dot product calculations
	Vector3 hitDirection(normalizedDirection.x, normalizedDirection.y, normalizedDirection.z);
	
	// Calculate dot products to determine which side was hit
	Real forwardDot = Vector3::Dot_Product(forward, hitDirection);
	Real rightDot = Vector3::Dot_Product(right, hitDirection);
	
	// Determine the side with the highest absolute dot product
	// Only consider front/back and left/right - ignore top/bottom for automatic detection
	Real absForwardDot = fabs(forwardDot);
	Real absRightDot = fabs(rightDot);
	
	if (absForwardDot >= absRightDot)
	{
		// Hit is primarily along the forward/backward axis
		// If forwardDot > 0, the hit direction aligns with the target's forward direction
		// This means the hit came from the target's front, so it hit the front side
		return (forwardDot > 0) ? HIT_SIDE_FRONT : HIT_SIDE_BACK;
	}
	else
	{
		// Hit is primarily along the left/right axis
		// If rightDot > 0, the hit direction aligns with the target's right direction
		// This means the hit came from the target's left, so it hit the left side
		return (rightDot > 0) ? HIT_SIDE_LEFT : HIT_SIDE_RIGHT;
	}
}
