# Armor INI Documentation

## Overview

The `Armor` INI file contains armor configuration settings and damage resistance parameters for game objects. Armor defines how different damage types are modified when applied to objects, allowing for strategic balance between different unit types and weapons. Each armor type can have different resistance values for various damage types, creating rock-paper-scissors style gameplay mechanics.

## Usage

Armor configurations are applied to game objects through their templates to provide damage resistance and vulnerability patterns. This is a **global configuration file** that defines reusable armor templates. The armor system allows objects to have different resistances to various damage types, creating tactical depth in combat.

**Limitations**:
- Armor only affects damage modification, not other game mechanics
- Armor coefficients are limited to the predefined damage types
- Armor cannot be dynamically changed during gameplay (only through upgrades)
- Armor effectiveness depends on proper damage type configuration

**Conditions**:
- Armor manages damage resistance across all game objects
- The configuration handles damage modification for different attack types
- Armor operations provide strategic combat balance
- Armor management creates tactical gameplay depth
- **Multiple instances behavior**: Each object can have only one armor type, but multiple objects can share the same armor template

**Dependencies**:
- Uses DamageType definitions for damage type identification
- Integrates with the damage system for combat calculations
- Referenced by object templates through the Armor property

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
  - [Armor Coefficients](#armor-coefficients)
- [DamageType Values](#damagetype-values)
- [Examples](#examples)
  - [Heavy Armor (Tank)](#heavy-armor-tank)
  - [Light Armor (Infantry)](#light-armor-infantry)
  - [Building Armor](#building-armor)
  - [Aircraft Armor](#aircraft-armor)
  - [Specialized Armor (Anti-Explosion)](#specialized-armor-anti-explosion)
- [Template](#template)
- [How Armor Damage Calculation Works](#how-armor-damage-calculation-works)
  - [The Math Behind Armor](#the-math-behind-armor)
  - [Step-by-Step Process](#step-by-step-process)
  - [Real Examples](#real-examples)
  - [Percentage Conversion](#percentage-conversion)
  - [Strategic Implications](#strategic-implications)
- [Notes](#notes)
- [Source Files](#source-files)
- [Changes History](#changes-history)
- [Status](#status)
  - [Reviews (0)](#modder-reviews)

## Properties

### Armor Coefficients *(v1.04)*

#### `Armor` *(v1.04)*
- **Type**: `DamageType` and `Percentage` pair
- **Description**: Defines damage resistance for a specific damage type. The first parameter is the damage type name, the second is the resistance percentage (100% = no resistance, 0% = complete immunity).
- **Default**: `100%` (no resistance)
- **Example**: `Armor = EXPLOSION 50%` // 50% resistance to explosion damage

**Special Values**:
- **`Default`** - Sets the same resistance value for all damage types
- **Damage Type Names** - Any valid damage type from the [DamageType Values](#damagetype-values) section

**Resistance Values**:
- **`0%`** - Complete immunity (0% damage taken)
- **`50%`** - 50% resistance (50% damage taken)
- **`100%`** - No resistance (100% damage taken)
- **`> 100%`** - Vulnerability (more than 100% damage taken)

## DamageType Values *(v1.04)*

The Armor property accepts the following damage types:

- **`EXPLOSION`** *(v1.04)* - Explosive damage from bombs, grenades, and artillery
- **`CRUSH`** *(v1.04)* - Crushing damage from vehicles running over infantry
- **`ARMOR_PIERCING`** *(v1.04)* - Armor-piercing ammunition designed to penetrate armor
- **`SMALL_ARMS`** *(v1.04)* - Small arms fire from rifles and pistols
- **`GATTLING`** *(v1.04)* - High-rate fire from gatling guns and machine guns
- **`RADIATION`** *(v1.04)* - Radiation damage from nuclear weapons and hazards
- **`FLAME`** *(v1.04)* - Fire damage from flamethrowers and incendiary weapons
- **`LASER`** *(v1.04)* - Energy damage from laser weapons
- **`SNIPER`** *(v1.04)* - High-precision damage from sniper rifles
- **`POISON`** *(v1.04)* - Toxic damage from chemical weapons
- **`HEALING`** *(v1.04)* - Healing damage (negative damage that restores health)
- **`UNRESISTABLE`** *(v1.04)* - Damage that cannot be resisted by any armor
- **`WATER`** *(v1.04)* - Damage from drowning or water-related hazards
- **`DEPLOY`** *(v1.04)* - Special damage for deploying units from transports
- **`SURRENDER`** *(v1.04)* - Special damage that causes units to surrender
- **`HACK`** *(v1.04)* - Electronic warfare damage for hacking systems
- **`KILLPILOT`** *(v1.04)* - Special damage that kills vehicle pilots
- **`PENALTY`** *(v1.04)* - Game penalty damage
- **`FALLING`** *(v1.04)* - Damage from falling or impact
- **`MELEE`** *(v1.04)* - Close combat damage from blades and clubs
- **`DISARM`** *(v1.04)* - Special damage for disarming explosives
- **`HAZARD_CLEANUP`** *(v1.04)* - Damage for cleaning up environmental hazards
- **`PARTICLE_BEAM`** *(v1.04)* - Extreme energy damage from orbital weapons
- **`TOPPLING`** *(v1.04)* - Damage from being knocked over
- **`INFANTRY_MISSILE`** *(v1.04)* - Anti-infantry missile damage
- **`AURORA_BOMB`** *(v1.04)* - Special damage from Aurora bombs
- **`LAND_MINE`** *(v1.04)* - Damage from land mines
- **`JET_MISSILES`** *(v1.04)* - Damage from jet-launched missiles
- **`STEALTHJET_MISSILES`** *(v1.04)* - Damage from stealth jet missiles
- **`MOLOTOV_COCKTAIL`** *(v1.04)* - Incendiary damage from Molotov cocktails
- **`COMANCHE_VULCAN`** *(v1.04)* - Damage from Comanche helicopter Vulcan cannon
- **`SUBDUAL_MISSILE`** *(v1.04)* - Non-lethal damage that incapacitates without killing
- **`SUBDUAL_VEHICLE`** *(v1.04)* - Non-lethal vehicle damage
- **`SUBDUAL_BUILDING`** *(v1.04)* - Non-lethal building damage
- **`SUBDUAL_UNRESISTABLE`** *(v1.04)* - Non-lethal damage that cannot be resisted
- **`MICROWAVE`** *(v1.04)* - Microwave radiation that affects infantry only
- **`KILL_GARRISONED`** *(v1.04)* - Damage that kills garrisoned units
- **`STATUS`** *(v1.04)* - Damage that applies status effects rather than health damage
- **`EW_MISSILE`** *(v1.04)* - Electronic warfare missile damage
- **`EW_VEHICLE`** *(v1.04)* - Electronic warfare vehicle damage
- **`EW_BUILDING`** *(v1.04)* - Electronic warfare building damage
- **`EW_UNRESISTABLE`** *(v1.04)* - Electronic warfare damage that cannot be resisted

## Examples

### Heavy Armor (Tank)
```ini
Armor HeavyArmor
    Armor = Default 80%
    Armor = EXPLOSION 60%
    Armor = ARMOR_PIERCING 40%
    Armor = SMALL_ARMS 90%
    Armor = FLAME 70%
End
```

### Light Armor (Infantry)
```ini
Armor LightArmor
    Armor = Default 100%
    Armor = EXPLOSION 150%
    Armor = CRUSH 200%
    Armor = SMALL_ARMS 80%
    Armor = ARMOR_PIERCING 120%
End
```

### Building Armor
```ini
Armor BuildingArmor
    Armor = Default 90%
    Armor = EXPLOSION 50%
    Armor = ARMOR_PIERCING 30%
    Armor = FLAME 60%
    Armor = RADIATION 80%
End
```

### Aircraft Armor
```ini
Armor AircraftArmor
    Armor = Default 100%
    Armor = EXPLOSION 180%
    Armor = SMALL_ARMS 90%
    Armor = SNIPER 70%
    Armor = JET_MISSILES 60%
End
```

### Specialized Armor (Anti-Explosion)
```ini
Armor ExplosionResistant
    Armor = Default 100%
    Armor = EXPLOSION 20%
    Armor = LAND_MINE 10%
    Armor = AURORA_BOMB 30%
End
```

## Template

```ini
Armor ArmorName
    Armor = Default 100%               ; // Default resistance for all damage types *(v1.04)*
    Armor = EXPLOSION 100%             ; // Explosive damage resistance *(v1.04)*
    Armor = CRUSH 100%                 ; // Crushing damage resistance *(v1.04)*
    Armor = ARMOR_PIERCING 100%        ; // Armor-piercing damage resistance *(v1.04)*
    Armor = SMALL_ARMS 100%            ; // Small arms fire resistance *(v1.04)*
    Armor = GATTLING 100%              ; // Gatling gun damage resistance *(v1.04)*
    Armor = RADIATION 100%             ; // Radiation damage resistance *(v1.04)*
    Armor = FLAME 100%                 ; // Fire damage resistance *(v1.04)*
    Armor = LASER 100%                 ; // Laser damage resistance *(v1.04)*
    Armor = SNIPER 100%                ; // Sniper damage resistance *(v1.04)*
    Armor = POISON 100%                ; // Poison damage resistance *(v1.04)*
    Armor = HEALING 100%               ; // Healing damage resistance *(v1.04)*
    Armor = UNRESISTABLE 100%          ; // Unresistable damage resistance *(v1.04)*
    Armor = WATER 100%                 ; // Water damage resistance *(v1.04)*
    Armor = DEPLOY 100%                ; // Deploy damage resistance *(v1.04)*
    Armor = SURRENDER 100%             ; // Surrender damage resistance *(v1.04)*
    Armor = HACK 100%                  ; // Hack damage resistance *(v1.04)*
    Armor = KILLPILOT 100%             ; // Kill pilot damage resistance *(v1.04)*
    Armor = PENALTY 100%               ; // Penalty damage resistance *(v1.04)*
    Armor = FALLING 100%               ; // Falling damage resistance *(v1.04)*
    Armor = MELEE 100%                 ; // Melee damage resistance *(v1.04)*
    Armor = DISARM 100%                ; // Disarm damage resistance *(v1.04)*
    Armor = HAZARD_CLEANUP 100%        ; // Hazard cleanup damage resistance *(v1.04)*
    Armor = PARTICLE_BEAM 100%         ; // Particle beam damage resistance *(v1.04)*
    Armor = TOPPLING 100%              ; // Toppling damage resistance *(v1.04)*
    Armor = INFANTRY_MISSILE 100%      ; // Infantry missile damage resistance *(v1.04)*
    Armor = AURORA_BOMB 100%           ; // Aurora bomb damage resistance *(v1.04)*
    Armor = LAND_MINE 100%             ; // Land mine damage resistance *(v1.04)*
    Armor = JET_MISSILES 100%          ; // Jet missiles damage resistance *(v1.04)*
    Armor = STEALTHJET_MISSILES 100%   ; // Stealth jet missiles damage resistance *(v1.04)*
    Armor = MOLOTOV_COCKTAIL 100%      ; // Molotov cocktail damage resistance *(v1.04)*
    Armor = COMANCHE_VULCAN 100%       ; // Comanche Vulcan damage resistance *(v1.04)*
    Armor = SUBDUAL_MISSILE 100%       ; // Subdual missile damage resistance *(v1.04)*
    Armor = SUBDUAL_VEHICLE 100%       ; // Subdual vehicle damage resistance *(v1.04)*
    Armor = SUBDUAL_BUILDING 100%      ; // Subdual building damage resistance *(v1.04)*
    Armor = SUBDUAL_UNRESISTABLE 100%  ; // Subdual unresistable damage resistance *(v1.04)*
    Armor = MICROWAVE 100%             ; // Microwave damage resistance *(v1.04)*
    Armor = KILL_GARRISONED 100%       ; // Kill garrisoned damage resistance *(v1.04)*
    Armor = STATUS 100%                ; // Status damage resistance *(v1.04)*
    Armor = EW_MISSILE 100%            ; // EW missile damage resistance *(v1.04)*
    Armor = EW_VEHICLE 100%            ; // EW vehicle damage resistance *(v1.04)*
    Armor = EW_BUILDING 100%           ; // EW building damage resistance *(v1.04)*
    Armor = EW_UNRESISTABLE 100%       ; // EW unresistable damage resistance *(v1.04)*
End
```

## How Armor Damage Calculation Works

Understanding how armor affects damage is crucial for creating balanced gameplay. Here's a friendly explanation of the damage calculation process:

### The Math Behind Armor

When a weapon hits a target, the game follows this simple formula:

```
Final Damage = Original Damage × (Armor Resistance ÷ 100)
```

### Step-by-Step Process

1. **Weapon Fires**: A weapon deals, for example, 100 damage of type `EXPLOSION`
2. **Armor Check**: The game looks up the target's armor resistance for `EXPLOSION` damage
3. **Calculation**: If the armor has `EXPLOSION 50%`, the calculation becomes:
   ```
   Final Damage = 100 × (50 ÷ 100) = 100 × 0.5 = 50 damage
   ```
4. **Health Reduction**: The target loses 50 health instead of 100

### Real Examples

**Tank vs. Infantry Explosion**:
- **Explosion damage**: 100 points
- **Tank armor**: `EXPLOSION 60%` (40% resistance)
- **Infantry armor**: `EXPLOSION 150%` (50% vulnerability)
- **Tank takes**: 100 × 0.6 = **60 damage**
- **Infantry takes**: 100 × 1.5 = **150 damage**

**Special Cases**:
- **`EXPLOSION 0%`**: Complete immunity (0 damage taken)
- **`EXPLOSION 100%`**: Normal damage (no armor effect)
- **`EXPLOSION 200%`**: Double damage (100% vulnerability)


### Percentage Conversion

When you write `Armor = EXPLOSION 50%` in the INI file, the game converts it internally:
- **50%** becomes **0.5** (50 ÷ 100)
- **150%** becomes **1.5** (150 ÷ 100)
- **0%** becomes **0.0** (complete immunity)

### Strategic Implications

**Creating Rock-Paper-Scissors Balance**:
- Tanks: High resistance to `SMALL_ARMS` (90%), vulnerable to `ARMOR_PIERCING` (40%)
- Infantry: Vulnerable to `EXPLOSION` (150%), resistant to `SMALL_ARMS` (80%)
- Buildings: Resistant to most damage, but vulnerable to `ARMOR_PIERCING` (30%)

**Modding Tips**:
- Use values between 0% and 200% for most scenarios
- Test combinations to ensure no unit is overpowered
- Consider the "Default" setting for quick bulk changes
- Remember that `UNRESISTABLE` damage ignores all armor

## Notes

- Armor provides damage resistance and vulnerability patterns for strategic gameplay balance
- The configuration manages damage modification for different attack types and defenses
- Armor operations create tactical depth through rock-paper-scissors mechanics
- Armor management ensures balanced and engaging combat experiences
- This configuration is essential for unit balance and tactical gameplay
- Armor coordination creates strategic variety between different unit types
- Resistance values below 100% reduce damage taken (armor protection)
- Resistance values above 100% increase damage taken (vulnerability)
- Resistance value of 100% means no modification (normal damage)
- Resistance value of 0% means complete immunity to that damage type
- Default armor setting applies the same resistance to all damage types
- Individual damage type settings override the default for specific types
- UNRESISTABLE damage type bypasses all armor resistance
- Armor templates are reusable and can be applied to multiple objects
- Armor cannot be changed dynamically during gameplay (only through upgrades)
- The armor system works in conjunction with the damage system for combat calculations

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Armor.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Armor.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Armor.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Armor.cpp)
- Damage Types: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Damage.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Damage.h)

## Changes History

- No Changes done since 1.04

## Status

- **Documentation Status**: AI Generated Pending Reviews 
- **Last Updated**: [Current Date] by @ahmed Salah using AI

### Modder Reviews 
- No Reviews done yet