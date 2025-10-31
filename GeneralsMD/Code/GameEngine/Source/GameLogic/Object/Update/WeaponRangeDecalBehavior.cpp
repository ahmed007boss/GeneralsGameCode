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

// FILE: WeaponRangeDecalBehavior.cpp ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#define DEFINE_WEAPONSLOTTYPE_NAMES

#include "Common/RandomValue.h"
#include "Common/Xfer.h"
#include "GameLogic/Damage.h"
#include "GameLogic/GameLogic.h"
#include "GameLogic/Module/WeaponRangeDecalBehavior.h"
#include "GameLogic/Object.h"
#include "GameLogic/Weapon.h"
#include "GameLogic/WeaponSet.h"
#include "GameLogic/Module/ContainModule.h"


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

// Helper function to compute weapon bonus (replicates Weapon::computeBonus logic)
static void computeWeaponBonus(const Object* source, const WeaponTemplate* weaponTemplate, WeaponBonusConditionFlags extraBonusFlags, WeaponBonus& bonus)
{
	bonus.clear();
	WeaponBonusConditionFlags flags = source->getWeaponBonusCondition();
	flags |= extraBonusFlags;

	if (source->getContainedBy())
	{
		// We may be able to add in our container's flags
		const ContainModuleInterface* theirContain = source->getContainedBy()->getContain();
		if (theirContain && theirContain->isWeaponBonusPassedToPassengers())
			flags |= theirContain->getWeaponBonusPassedToPassengers();
	}

	if (TheGlobalData->m_weaponBonusSet)
		TheGlobalData->m_weaponBonusSet->appendBonuses(flags, bonus);
	const WeaponBonusSet* extra = weaponTemplate->getExtraBonus();
	if (extra)
		extra->appendBonuses(flags, bonus);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

WeaponRangeDecalBehaviorModuleData::WeaponRangeDecalBehaviorModuleData()
{
	m_weaponSlot = NONE_WEAPON;		// Default to primary weapon slot
	m_useSlavedObjectWeapon = FALSE;	// Default to using own weapon
	m_specificWeaponName.clear();		// Default to no specific weapon
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
 void WeaponRangeDecalBehaviorModuleData::buildFieldParse(MultiIniFieldParse& p)
{
	UpdateModuleData::buildFieldParse(p);
	static const FieldParse dataFieldParse[] =
	{
		{ "WeaponSlot",		INI::parseLookupList, TheWeaponSlotTypeNamesLookupList, offsetof(WeaponRangeDecalBehaviorModuleData, m_weaponSlot) },
		{ "UseSlavedObjectWeapon", INI::parseBool, NULL, offsetof(WeaponRangeDecalBehaviorModuleData, m_useSlavedObjectWeapon) },
		{ "SpecificWeaponName", INI::parseAsciiString, NULL, offsetof(WeaponRangeDecalBehaviorModuleData, m_specificWeaponName) },
		{ "MinRangeDecal",	RadiusDecalTemplate::parseRadiusDecalTemplate,	NULL, offsetof(WeaponRangeDecalBehaviorModuleData, m_minRangeDecalTemplate) },
		{ "MaxRangeDecal",	RadiusDecalTemplate::parseRadiusDecalTemplate,	NULL, offsetof(WeaponRangeDecalBehaviorModuleData, m_maxRangeDecalTemplate) },
		{ 0, 0, 0, 0 }
	};

	BehaviorModuleData::buildFieldParse(p);
	p.add(dataFieldParse);
	p.add(UpgradeMuxData::getFieldParse(), offsetof(WeaponRangeDecalBehaviorModuleData, m_upgradeMuxData));
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
WeaponRangeDecalBehavior::WeaponRangeDecalBehavior(Thing* thing, const ModuleData* moduleData) : UpdateModule(thing, moduleData)
{
	// Check if the object wants to show range decals for this weapon slot
	WeaponSlotType objectDecalSlot = getObject()->getRangeDecalShownForSlot();
	WeaponSlotType moduleWeaponSlot = getWeaponRangeDecalBehaviorModuleData()->m_weaponSlot;

	if (objectDecalSlot == moduleWeaponSlot || (moduleWeaponSlot == NONE_WEAPON && objectDecalSlot != -2))
	{
		// Object wants to show decals for this slot - activate via upgrade system
		giveSelfUpgrade();
	}
	else {
		clearDecals();
		setWakeFrame(getObject(), UPDATE_SLEEP_FOREVER);
	}
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
WeaponRangeDecalBehavior::~WeaponRangeDecalBehavior(void)
{
	clearDecals();
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::createWeaponRangeDecals(void)
{
	const WeaponRangeDecalBehaviorModuleData* data = getWeaponRangeDecalBehaviorModuleData();

	// Clear existing decals
	clearDecals();

	// Get the weapon from the specified slot
	Weapon* weapon = NULL;
	Object* weaponOwner = getObject();

	// Check if a specific weapon is specified (highest priority)
	if (!data->m_specificWeaponName.isEmpty())
	{
		// Use the specific weapon template by name
		const WeaponTemplate* weaponTemplate = TheWeaponStore->findWeaponTemplate(data->m_specificWeaponName);
		if (weaponTemplate)
		{
			// Create a temporary weapon instance for range calculation
			// We'll use the weapon template directly for range values
			weapon = NULL; // We'll handle this case specially below
		}
		else
		{
			setWakeFrame(getObject(), UPDATE_SLEEP_FOREVER);
			return;
		}
	}
	else if (data->m_useSlavedObjectWeapon)
	{
		// Use first slaved object's weapon instead of own weapon
		std::vector<Object*> slavedObjects = getObject()->getSlavedObjects();
		if (!slavedObjects.empty())
		{
			weaponOwner = slavedObjects[0]; // Use first slaved object
		}
		if (data->m_weaponSlot == NONE_WEAPON)
		{
			weapon = weaponOwner->getCurrentWeapon();
		}
		else
		{
			weapon = weaponOwner->getWeaponInWeaponSlot(data->m_weaponSlot);
		}

	}
	else
	{
		// Use own weapon from specified slot
		if (data->m_weaponSlot == NONE_WEAPON)
		{
			weapon = weaponOwner->getCurrentWeapon();
		}
		else
		{
			weapon = weaponOwner->getWeaponInWeaponSlot(data->m_weaponSlot);
		}
	}

	if (!weapon && data->m_specificWeaponName.isEmpty())
	{
		setWakeFrame(getObject(), UPDATE_SLEEP_FOREVER);
		return;
	}

	// Get weapon range values
	Real minRange = 0.0f;
	Real maxRange = 0.0f;
	const WeaponTemplate* weaponTemplate = NULL;

	if (!data->m_specificWeaponName.isEmpty())
	{
		// Use specific weapon template
		weaponTemplate = TheWeaponStore->findWeaponTemplate(data->m_specificWeaponName);
		if (weaponTemplate)
		{
			minRange = weaponTemplate->getMinimumAttackRange();

			// Compute weapon bonus manually
			WeaponBonus bonus;
			computeWeaponBonus(weaponOwner, weaponTemplate, 0, bonus);

			Real baseRange = weaponTemplate->getAttackRange(bonus);

			// If attack range is 1 (contact weapon), use primary damage radius instead
			if (baseRange <= 1.0f)
			{
				maxRange = weaponTemplate->getPrimaryDamageRadius(bonus);
			}
			else
			{
				maxRange = baseRange;
			}
		}
	}
	else if (weapon)
	{
		// Use actual weapon instance
		weaponTemplate = weapon->getTemplate();
		minRange = weaponTemplate->getMinimumAttackRange();
		Real actualRange = weapon->getAttackRange(weaponOwner);

		// Get weapon bonus for damage radius calculation
		WeaponBonus bonus;
		computeWeaponBonus(weaponOwner, weaponTemplate, 0, bonus);

		// If attack range is 1 (contact weapon), use primary damage radius instead
		if (actualRange <= 1.0f)
		{
			maxRange = weaponTemplate->getPrimaryDamageRadius(bonus);
		}
		else
		{
			maxRange = actualRange;
		}
	}

	// Determine automatic colors based on weapon capabilities
	Int minRangeColor = 0xFF0000; // Red for minimum range (default)
	Int maxRangeColor = 0x808080; // Grey (default for ground-only)

	// Check if colors are set in INI (non-zero means custom color)
	if (data->m_minRangeDecalTemplate.getColor() == 0) {
		// Use automatic red for minimum range
		minRangeColor = 0xFF0000;
	}
	else {
		// Use INI-specified color
		minRangeColor = data->m_minRangeDecalTemplate.getColor();
	}

	if (data->m_maxRangeDecalTemplate.getColor() == 0 && weaponTemplate) {
		// Determine automatic color based on weapon capabilities
		Int antiMask = weaponTemplate->getAntiMask();
		DamageType damageType = weaponTemplate->getDamageType();

		// Check if weapon can attack air units (airborne vehicles or infantry)
		Bool canAttackAir = (antiMask & WEAPON_ANTI_AIRBORNE_VEHICLE) != 0 ||
			(antiMask & WEAPON_ANTI_AIRBORNE_INFANTRY) != 0;

		// Check if weapon can attack ground units
		Bool canAttackGround = (antiMask & WEAPON_ANTI_GROUND) != 0;

		// Check if weapon does health damage
		Bool doesHealthDamage = IsHealthDamagingDamage(damageType);

		// Determine color based on capabilities
		if (!doesHealthDamage) {
			maxRangeColor = 0x800080; // Purple for non-health damage
		}
		else if (canAttackAir && canAttackGround) {
			maxRangeColor = 0x00FF00; // Green for both air and ground
		}
		else if (canAttackAir) {
			maxRangeColor = 0x00FFFF; // Cyan for air only
		}
		else if (canAttackGround) {
			maxRangeColor = 0x808080; // Grey for ground only
		}
		else {
			maxRangeColor = 0x808080; // Default grey
		}
	}
	else {
		// Use INI-specified color
		maxRangeColor = data->m_maxRangeDecalTemplate.getColor();
	}

	// Create minimum range decal only if minRange > 0
	if (minRange > 0.0f && data->m_minRangeDecalTemplate.valid())
	{
		// Use the original template to create the decal
		data->m_minRangeDecalTemplate.createRadiusDecal(
			*(getObject()->getPosition()),
			minRange,
			getObject()->getControllingPlayer(),
			m_minRangeDecal
		);

		// Set the color after creation if we have a custom color
		if (minRangeColor != 0 && !m_minRangeDecal.isEmpty()) {
			m_minRangeDecal.setColor(minRangeColor);
		}
	}

	// Create maximum range decal
	if (maxRange > 0.0f && data->m_maxRangeDecalTemplate.valid())
	{
		// Use the original template to create the decal
		data->m_maxRangeDecalTemplate.createRadiusDecal(
			*(getObject()->getPosition()),
			maxRange,
			getObject()->getControllingPlayer(),
			m_maxRangeDecal
		);

		// Set the color after creation if we have a custom color
		if (maxRangeColor != 0 && !m_maxRangeDecal.isEmpty()) {
			m_maxRangeDecal.setColor(maxRangeColor);
		}
	}

	// Set wake frame based on whether we have any active decals
	Bool hasActiveDecals = (!m_minRangeDecal.isEmpty()) || (!m_maxRangeDecal.isEmpty());
	setWakeFrame(getObject(), hasActiveDecals ? UPDATE_SLEEP_NONE : UPDATE_SLEEP_FOREVER);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::killWeaponRangeDecals()
{
	clearDecals();
	setWakeFrame(getObject(), UPDATE_SLEEP_FOREVER);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::refreshDecalState()
{
	// Check if the object wants to show range decals for this weapon slot
	WeaponSlotType objectDecalSlot = getObject()->getRangeDecalShownForSlot();
	WeaponSlotType moduleWeaponSlot = getWeaponRangeDecalBehaviorModuleData()->m_weaponSlot;

	if (objectDecalSlot == moduleWeaponSlot || (moduleWeaponSlot == NONE_WEAPON && objectDecalSlot != -2))
	{
		// Object wants to show decals for this slot - activate via upgrade system
		if (!isUpgradeActive()) {
			giveSelfUpgrade();
		}
		setWakeFrame(getObject(), UPDATE_SLEEP_NONE);
	}
	else {
		// Object doesn't want to show decals for this slot - deactivate via upgrade system
	/*	if (isUpgradeActive()) {
			removeSelfUpgrade();
		}*/
		clearDecals();
		setWakeFrame(getObject(), UPDATE_SLEEP_FOREVER);
	}
}

// -----------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::clearDecals()
{
	m_minRangeDecal.clear();
	m_maxRangeDecal.clear();
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
UpdateSleepTime WeaponRangeDecalBehavior::update(void)
{
	if (getObject()->isDisabledByType(DISABLED_HELD)) {
		if (!m_minRangeDecal.isEmpty() || !m_maxRangeDecal.isEmpty())
			clearDecals();
		return UPDATE_SLEEP_NONE;  // We wait to be re-enabled
	}

	// Check if the object still wants to show range decals for this weapon slot
	WeaponSlotType objectDecalSlot = getObject()->getRangeDecalShownForSlot();
	WeaponSlotType moduleWeaponSlot = getWeaponRangeDecalBehaviorModuleData()->m_weaponSlot;

	if (objectDecalSlot != moduleWeaponSlot && !(moduleWeaponSlot == NONE_WEAPON && objectDecalSlot != -2)) {
		clearDecals();
		return UPDATE_SLEEP_FOREVER;
	}

	// Upgrade has not been triggered, or it might have been removed.
	if (!isUpgradeActive()) {
		clearDecals();
		return UPDATE_SLEEP_FOREVER;
	}

	// The object is dead
	if (getObject()->isEffectivelyDead()) {
		clearDecals();
		return UPDATE_SLEEP_FOREVER;
	}

	// Update existing decals
	Bool hasActiveDecals = false;

	if (!m_minRangeDecal.isEmpty()) {
		m_minRangeDecal.update();
		m_minRangeDecal.setPosition(*(getObject()->getPosition()));
		hasActiveDecals = true;
	}

	if (!m_maxRangeDecal.isEmpty()) {
		m_maxRangeDecal.update();
		m_maxRangeDecal.setPosition(*(getObject()->getPosition()));
		hasActiveDecals = true;
	}

	if (hasActiveDecals) {
		return UPDATE_SLEEP_NONE;
	}

	// We get here if we were disabled or decals were cleared
	createWeaponRangeDecals();
	return UPDATE_SLEEP_NONE;
}

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::crc(Xfer* xfer)
{

	// extend base class
	UpdateModule::crc(xfer);

}  // end crc

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version */
	// ------------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::xfer(Xfer* xfer)
{

	// version
	XferVersion currentVersion = 1;
	XferVersion version = currentVersion;
	xfer->xferVersion(&version, currentVersion);

	// extend base class
	UpdateModule::xfer(xfer);

	// decals, if any
	m_minRangeDecal.xferRadiusDecal(xfer);
	m_maxRangeDecal.xferRadiusDecal(xfer);


}  // end xfer

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
void WeaponRangeDecalBehavior::loadPostProcess(void)
{

	// extend base class
	UpdateModule::loadPostProcess();

}  // end loadPostProcess
