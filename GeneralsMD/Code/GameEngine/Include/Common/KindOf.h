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

// FILE: KindOf.h //////////////////////////////////////////////////////////////////////////
// Author: Steven Johnson, Dec 2001
// Desc:
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __KINDOF_H_
#define __KINDOF_H_

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "Lib/BaseType.h"
#include "Common/BitFlags.h"
#include "Common/BitFlagsIO.h"

//-------------------------------------------------------------------------------------------------
/** Kind of flags for determining groups of things that belong together
	* NOTE: You *MUST* keep this in the same order as the KindOfNames[] below */
	//-------------------------------------------------------------------------------------------------
enum KindOfType CPP_11(: Int)
{
	KINDOF_INVALID = -1,
	
	KINDOF_OBSTACLE,								///< an obstacle to land-based pathfinders
	KINDOF_SELECTABLE,							///< Actually means MOUSE-INTERACTABLE (doesn't mean you can select it!)
	KINDOF_IMMOBILE,								///< fixed in location
	KINDOF_CAN_ATTACK,							///< can attack
	KINDOF_STICK_TO_TERRAIN_SLOPE,	///< should be stuck at ground level, aligned to terrain slope. requires that IMMOBILE bit is also set.
	KINDOF_CAN_CAST_REFLECTIONS,		///< can cast reflections in water
	KINDOF_SHRUBBERY,								///< tree, bush, etc.
	KINDOF_STRUCTURE,								///< structure of some sort (buildable or not)
	KINDOF_INFANTRY,								///< unit like soldier etc
	KINDOF_VEHICLE,									///< unit like tank, jeep, plane, helicopter, etc.
	KINDOF_AIRCRAFT,								///< unit like plane, helicopter, etc., that is predominantly a flyer. (hovercraft are NOT aircraft)
	KINDOF_HUGE_VEHICLE,						///< unit that is, technically, a vehicle, but WAY larger than normal (eg, Overlord)
	KINDOF_DOZER,										///< a dozer
	KINDOF_HARVESTER,               ///< a harvester
	KINDOF_COMMANDCENTER,						///< a command center
#ifdef ALLOW_SURRENDER
		KINDOF_PRISON,									///< a prison detention center kind of thing
		KINDOF_COLLECTS_PRISON_BOUNTY,	///< when prisoners are delivered to these, the player gets money
		KINDOF_POW_TRUCK,								///< a pow truck can pick up and return prisoners
#endif
		KINDOF_LINEBUILD,								///< wall-type thing that is built in a line
		KINDOF_SALVAGER,								///< something that can create and use Salvage Crates
		KINDOF_WEAPON_SALVAGER,					///< subset of salvager that can get weapon upgrades from salvage
		KINDOF_TRANSPORT,								///< a true transport (has TransportContain)
		KINDOF_BRIDGE,									///< a Bridge. (special structure)
		KINDOF_LANDMARK_BRIDGE,					///< a landmark bridge (special bridge that isn't resizable)
		KINDOF_BRIDGE_TOWER,						///< a bridge tower that we can target for bridge destruction
		KINDOF_PROJECTILE,							///< Instead of being a ground or air unit, this object is special
		KINDOF_PRELOAD,									///< all model data will be preloaded even if not on map
		KINDOF_NO_GARRISON,							///< unit may not garrison bldgs, even if infantry bit is set
		KINDOF_WAVEGUIDE,								///< water wave object
		KINDOF_WAVE_EFFECT,							///< wave effect point
		KINDOF_NO_COLLIDE,							///< Never collide with or be collided with
		KINDOF_REPAIR_PAD,							///< is a repair pad object that can repair other machines
		KINDOF_HEAL_PAD,								///< is a heal pad object that can heal flesh and bone units
		KINDOF_STEALTH_GARRISON,				/** enemy teams can't tell that unit is in building.. and if they
																			garrison that building, they stealth unit will eject. */
		KINDOF_CASH_GENERATOR,					///< used to check if the unit generates cash... checked by cash hackers and whatever else comes up
		KINDOF_DRAWABLE_ONLY,						///< template is used only to create drawables (not Objects)
		KINDOF_MP_COUNT_FOR_VICTORY,		///< If a player loses all his buildings that have this kindof in a multiplayer game, he loses.
		KINDOF_REBUILD_HOLE,						///< a GLA rebuild hole
		KINDOF_SCORE,										///< Object counts for Multiplayer scores, and short-game calculations (for buildings)
		KINDOF_SCORE_CREATE,						///< Object only counts for multiplayer score for creation.
		KINDOF_SCORE_DESTROY,						///< Object only counts for multiplayer score for destruction.
		KINDOF_NO_HEAL_ICON,						///< do not ever display healing icons on these objects
		KINDOF_CAN_RAPPEL,							///< can rappel. duh.
		KINDOF_PARACHUTABLE,						///< parachutable object
#ifdef ALLOW_SURRENDER
		KINDOF_CAN_SURRENDER,						///< object that can surrender
#endif
		KINDOF_CAN_BE_REPULSED,					///< object that runs away from a repulsor object.
		KINDOF_MOB_NEXUS,					      ///< object that cooyrdinates the members of a mob (i.e. GLAInfantryAngryMob)
		KINDOF_IGNORED_IN_GUI,					///< object that is the members of a mob (i.e. GLAInfantryAngryMob)
		KINDOF_CRATE,										///< a bonus crate
		KINDOF_CAPTURABLE,							///< is "capturable" even if not an enemy (should generally be used only for structures, eg, Tech bldgs)
		KINDOF_CLEARED_BY_BUILD,				///< is auto-cleared from the map when built over via construction
		KINDOF_SMALL_MISSILE,						///< Missile object: ONLY USED FOR ANTI-MISSILE TARGETTING PURPOSES! Keep using PROJECTILE!
		KINDOF_ALWAYS_VISIBLE,					///< is never obscured by fog of war or shroud.  mostly for UI feedback objects.
		KINDOF_UNATTACKABLE,						///< You cannot target this thing, it probably doesn't really exist
		KINDOF_MINE,										///< a landmine. (possibly also extend to Col. Burton timed charges?)
		KINDOF_CLEANUP_HAZARD,					///< radiation and bio-poison are samples of area conditions that can be cleaned up (or avoided)
		KINDOF_PORTABLE_STRUCTURE,				///< Flag to identify building like subobjects an Overlord is allowed to Contain.
		KINDOF_ALWAYS_SELECTABLE,				///< is never unselectable (even if effectively dead).  mostly for UI feedback objects.
		KINDOF_ATTACK_NEEDS_LINE_OF_SIGHT,				///< Unit has to have clear line of sight (los) to attack.
		KINDOF_WALK_ON_TOP_OF_WALL, 		///< Units can walk on top of a wall made of these kind of objects.
		KINDOF_DEFENSIVE_WALL,					///< wall can't be driven thru, even if crusher, so pathfinder must path around it
		KINDOF_FS_POWER,								///< Faction structure power building
		KINDOF_FS_FACTORY,							///< Faction structure power building
		KINDOF_FS_BASE_DEFENSE,					///< Faction structure base defense
		KINDOF_FS_TECHNOLOGY,						///< Faction structure technology building
		KINDOF_AIRCRAFT_PATH_AROUND,		///< Tall enough that aircraft need to path around this.
		KINDOF_LOW_OVERLAPPABLE,				///< When overlapped, things always overlap at a 'low' height rather than our object geom
		KINDOF_FORCEATTACKABLE,					///< unit is always attackable via force-attack, even if not selectable
		KINDOF_AUTO_RALLYPOINT,					///< When immobile-structure-object is selected, left clicking on ground will set new rally point without requiring command button.
		KINDOF_TECH_BUILDING,						///< Neutral tech building - Oil derrick, Hospital, Radio Station, Refinery.
		KINDOF_POWERED,									///< This object gets the Underpowered disabled condition when its owning player has power consumption exceed supply
		KINDOF_PRODUCED_AT_HELIPAD,			///< ugh... hacky fix for comanche. (srj)
		KINDOF_DRONE,										///< Object drone type -- used for filtering them out of battle plan bonuses, making un-snipable, and whatever else may come up.
		KINDOF_CAN_SEE_THROUGH_STRUCTURE,///< Structure does not block line of sight.
		KINDOF_BALLISTIC_MISSILE,				///< Large ballistic missiles that are specifically large enough to be targetted by base defenses.
		KINDOF_CLICK_THROUGH,						///< Objects with this will never be picked by mouse interactions!
		KINDOF_SUPPLY_SOURCE_ON_PREVIEW,///< Any thing that we can get "supplies" from that we want to show up on the map preview
		KINDOF_PARACHUTE,								///< it's a parachute
		KINDOF_GARRISONABLE_UNTIL_DESTROYED, ///< Object is capable of garrisoning troops until completely destroyed.
		KINDOF_BOAT,										///< It's a boat!
		KINDOF_IMMUNE_TO_CAPTURE,				///< Under no circumstances can this building ever be captured.
		KINDOF_HULK,										///< Hulk types so we can do special things to them via scripts or other things that may come up.
		KINDOF_SHOW_PORTRAIT_WHEN_CONTROLLED,	///< Only shows portraits when controlled.
		KINDOF_SPAWNS_ARE_THE_WEAPONS,	///< Evaluate the spawn slaves as this object's weapons.
		KINDOF_CANNOT_BUILD_NEAR_SUPPLIES,	///< you can't be built "too close" to anything that provides supplies
		KINDOF_SUPPLY_SOURCE,						///< this object provides supplies
		KINDOF_REVEAL_TO_ALL,						///< this object reveals shroud for all players
		KINDOF_DISGUISER,								///< This object has the ability to disguise.
		KINDOF_INERT,										///< this object shouldn't be considered for any sort of interaction with any player.
		KINDOF_HERO,										///< Any of the single-instance infantry, JarmenKell, BlackLotus, ColonelBurton
		KINDOF_IGNORES_SELECT_ALL,			///< Too late to figure out intelligently if something should respond to a Select All command
		KINDOF_DONT_AUTO_CRUSH_INFANTRY,					///< These units don't try to crush the infantry if ai.
		KINDOF_CLIFF_JUMPER,						///< Can't climb cliffs, but can jump off of them.
		KINDOF_FS_SUPPLY_DROPZONE,						///< A supply dropzone.
		KINDOF_FS_SUPERWEAPON,					///< A superweapon structure like a nuke silo, particle uplink cannon, scudstorm.
		KINDOF_FS_BLACK_MARKET,					///< Is this object a black market?
		KINDOF_FS_SUPPLY_CENTER,				///< Is this object a supply center?
		KINDOF_FS_STRATEGY_CENTER,			///< Is this object a strategy center?
		KINDOF_MONEY_HACKER,	///< Unit that generates money from air.  Needed for things that directly power them up.
		KINDOF_ARMOR_SALVAGER,					///< subset of salvager that can get armor upgrades from salvage
		KINDOF_REVEALS_ENEMY_PATHS,     ///< like the listening outpost... when selected, any enemy drawable will draw show paths when moused over
		KINDOF_BOOBY_TRAP,							///< A sticky bomb that gets set off by 5 random and unrelated events.
		KINDOF_FS_FAKE,									///< Fake structure!
		KINDOF_FS_INTERNET_CENTER,			///< Internet Center.
		KINDOF_BLAST_CRATER,            ///< deeply gouges out the terrain under object footprint
		KINDOF_PROP,										///< A prop, visual only, doesn't interact with other objects (rock, street sign, inert fire hydrant)
		KINDOF_OPTIMIZED_TREE,					///< An optimized, client side only tree.  (The only good kind of tree. jba)
		KINDOF_FS_ADVANCED_TECH,				///< Represents each faction's advanced techtree building -- strategy center, propaganda center, and palace.
		KINDOF_FS_BARRACKS,							///< A barracks
		KINDOF_FS_WARFACTORY,						///< A war factory or arms dealer.
		KINDOF_FS_AIRFIELD,							///< An airfield.
		KINDOF_NO_SELECT,								///< Can't select it but you can mouse over it to see it's health (drones!)
		KINDOF_REJECT_UNMANNED,					///< Unit cannot enter an unmanned vehicle.
		KINDOF_CANNOT_RETALIATE,				///< Unit will not retaliate if asked.
		KINDOF_TECH_BASE_DEFENSE,				///< Tech Building that acts as base defence when captured
		KINDOF_EMP_HARDENED,            ///< Like a delivery plane (B52, B3, CargoPlane,etc.)  or a SpectreGunship, which sort-of IS the weapon...
		KINDOF_DEMOTRAP,								///< Added strictly only for disarming purposes. They don't act like mines which have rendering and selection implications!
		KINDOF_CONSERVATIVE_BUILDING,		///< Conservative structures aren't considered part of your base for sneak attack boundary calculations...
		KINDOF_IGNORE_DOCKING_BONES,		///< Structure will not look up docking bones. Patch 1.03 hack.

		// NEW KINDOFs

		KINDOF_TANK,									///< Main battle tank or armored fighting vehicle.
		KINDOF_APC,										///< Armored Personnel Carrier for transporting infantry.
		KINDOF_IFV,										///< Infantry Fighting Vehicle with troop transport and combat capabilities.
		KINDOF_TRUCK,									///< Utility truck for transport and logistics.
		KINDOF_VTOL,									///< Vertical Take-Off and Landing aircraft.
		KINDOF_JET,										///< Jet-powered aircraft.
		KINDOF_FIGHTER,									///< Air superiority fighter aircraft.
		KINDOF_TACTICAL_BOMBER,							///< Tactical bomber for battlefield targets.
		KINDOF_STRATEGIC_BOMBER,						///< Strategic bomber for long-range missions.
		KINDOF_MULTIROLE,								///< Multi-role aircraft capable of various missions.
		KINDOF_INTERCEPTOR,								///< Interceptor aircraft for air defense.
		KINDOF_HELICOPTER,								///< Helicopter aircraft.
		KINDOF_ATTACK_HELICOPTER,						///< Attack helicopter for ground targets.
		KINDOF_TRANSPORT_HELICOPTER,					///< Transport helicopter for troops and cargo.
		KINDOF_SCOUT_HELICOPTER,						///< Scout helicopter for reconnaissance.
		KINDOF_COMBAT_DRONE,							///< Combat drone for autonomous warfare.
		KINDOF_RECONNAISSANCE_DRONE,					///< Reconnaissance drone for surveillance.
		KINDOF_CARGO_DRONE,								///< Cargo drone for logistics and supply.
		KINDOF_HOT_AIR_BALLOON,							///< Hot air balloon aircraft.
		KINDOF_BLIMP,									///< Blimp or airship aircraft.
		KINDOF_LARGE_AIRCRAFT,							///< Large aircraft category.
		KINDOF_MEDIUM_AIRCRAFT,							///< Medium aircraft category.
		KINDOF_SMALL_AIRCRAFT,							///< Small aircraft category.
		KINDOF_ARTILLERY,								///< Artillery weapon system.
		KINDOF_ROCKET_ARTILLERY,						///< Rocket artillery system.
		KINDOF_MISSILE_ARTILLERY,						///< Missile artillery system.
		KINDOF_GUN_ARTILLERY,							///< Gun-based artillery system.
		KINDOF_BALLISTIC_MISSILE_LAUNCHER,			///< Ballistic missile launcher system.
		KINDOF_BATTLESHIP,								///< Large capital warship.
		KINDOF_CRUISER,									///< Medium-sized warship.
		KINDOF_DESTROYER,								///< Fast escort warship.
		KINDOF_FRIGATE,									///< Smaller escort warship.
		KINDOF_SUBMARINE,								///< Underwater combat vessel.
		KINDOF_AIRCRAFT_CARRIER,						///< An aircraft carrier.
		KINDOF_PATROL_BOAT,								///< Small patrol vessel.
		KINDOF_GUNBOAT,									///< Small armed patrol boat.
		KINDOF_ANTI_AIRCRAFT,							///< Anti-aircraft defense system.		
		KINDOF_ANTI_STRUCTURE,							///< Anti-structure weapon system.
		KINDOF_ANTI_TANK,								///< Anti-tank weapon system.
		KINDOF_ANTI_INFANTRY,							///< Anti-infantry weapon system.
		KINDOF_ANTI_NAVAL,								///< Anti-naval weapon system.
		KINDOF_TOWED,									///< Towed vehicle or weapon system.
		KINDOF_SELF_PROPELLED,							///< Self-propelled vehicle or weapon system.
		KINDOF_ANTI_AIRCRAFT_GUN,						///< Anti-aircraft gun weapon system.
		KINDOF_SAM,										///< Surface-to-Air Missile system.
		KINDOF_SCOUT,									///< Reconnaissance and scouting unit.
		KINDOF_COMMANDO,								///< Elite special forces unit.
		KINDOF_SPECIAL_FORCE_INFANTRY,					///< Special forces infantry unit.
		KINDOF_HEAVY_INFANTRY,							///< Heavy infantry unit with enhanced armor.
		KINDOF_LIGHT_VEHICLE,							///< Light weight category vehicle.
		KINDOF_MEDIUM_VEHICLE,							///< Medium weight category vehicle.
		KINDOF_HEAVY_VEHICLE,							///< Heavy weight category vehicle.
		KINDOF_SUPERHEAVY_VEHICLE,						///< Super heavy weight category vehicle.
		KINDOF_EW_RADAR,								///< Radar system.
		KINDOF_EW_RADAR_JAMMER,							///< Electronic Warfare radar jamming system.
		KINDOF_EW_RADIO_JAMMER,							///< Electronic Warfare radio jamming system.
		KINDOF_EW_JAMMABLE,								///< Object that can be jammed by electronic warfare systems.
		KINDOF_EW_RADIO_JAMMABLE,						///< Object that can have its radio communications jammed.
		KINDOF_LOITERING_MUNITION_LAUNCHER,				///< Loitering munition launcher system.
		KINDOF_UNMANNED_AERIAL_CARRIER,					///< Unmanned aerial vehicle carrier system.
		KINDOF_SUPPORT_UNIT,								///< Support unit providing assistance to other units.

		KINDOF_EXTRA1,
		KINDOF_EXTRA2,
		KINDOF_EXTRA3,
		KINDOF_EXTRA4,
		KINDOF_EXTRA5,
		KINDOF_EXTRA6,
		KINDOF_EXTRA7,
		KINDOF_EXTRA8,
		KINDOF_EXTRA9,
		KINDOF_EXTRA10,
		KINDOF_EXTRA11,
		KINDOF_EXTRA12,
		KINDOF_EXTRA13,
		KINDOF_EXTRA14,
		KINDOF_EXTRA15,
		KINDOF_EXTRA16,


		KINDOF_COUNT,									// total number of kindofs
		KINDOF_FIRST = 0,
};

typedef BitFlags<KINDOF_COUNT>	KindOfMaskType;

#define MAKE_KINDOF_MASK(k) KindOfMaskType(KindOfMaskType::kInit, (k))
#define MAKE_KINDOF_MASK2(k,a) KindOfMaskType(KindOfMaskType::kInit, (k), (a))
#define MAKE_KINDOF_MASK3(k,a,b) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b))
#define MAKE_KINDOF_MASK4(k,a,b,c) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c))
#define MAKE_KINDOF_MASK5(k,a,b,c,d) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d))
#define MAKE_KINDOF_MASK6(k,a,b,c,d,e) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e))
#define MAKE_KINDOF_MASK7(k,a,b,c,d,e,f) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e), (f))
#define MAKE_KINDOF_MASK8(k,a,b,c,d,e,f,g) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e), (f), (g))
#define MAKE_KINDOF_MASK9(k,a,b,c,d,e,f,g,h) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e), (f), (g), (h))
#define MAKE_KINDOF_MASK10(k,a,b,c,d,e,f,g,h,i) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e), (f), (g), (h), (i))
#define MAKE_KINDOF_MASK11(k,a,b,c,d,e,f,g,h,i,j) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e), (f), (g), (h), (i), (j))
#define MAKE_KINDOF_MASK12(k,a,b,c,d,e,f,g,h,i,j,l) KindOfMaskType(KindOfMaskType::kInit, (k), (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (l))

inline Bool TEST_KINDOFMASK(const KindOfMaskType& m, KindOfType t)
{
	return m.test(t);
}

inline Bool TEST_KINDOFMASK_ANY(const KindOfMaskType& m, const KindOfMaskType& mask)
{
	return m.anyIntersectionWith(mask);
}

inline Bool TEST_KINDOFMASK_MULTI(const KindOfMaskType& m, const KindOfMaskType& mustBeSet, const KindOfMaskType& mustBeClear)
{
	return m.testSetAndClear(mustBeSet, mustBeClear);
}

inline Bool KINDOFMASK_ANY_SET(const KindOfMaskType& m)
{
	return m.any();
}

inline void CLEAR_KINDOFMASK(KindOfMaskType& m)
{
	m.clear();
}

inline void SET_ALL_KINDOFMASK_BITS(KindOfMaskType& m)
{
	m.clear();
	m.flip();
}

inline void FLIP_KINDOFMASK(KindOfMaskType& m)
{
	m.flip();
}

// defined in Common/System/Kindof.cpp
extern KindOfMaskType KINDOFMASK_NONE;	// inits to all zeroes
extern KindOfMaskType KINDOFMASK_FS;		// Initializes all FS types for faction structures.
void initKindOfMasks();

#endif	// __KINDOF_H_
