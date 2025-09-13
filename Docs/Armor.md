# Armor INI Documentation

## Overview

Armor defines per-damage-type multipliers that scale incoming damage. Each `armor` entry provides coefficients for all `DamageType` values. Armor entries are referenced by objects via their templates to adjust received damage. The default for all types is 100% unless explicitly overridden.

## Source Files

- Header: `GeneralsMD/Code/GameEngine/Include/GameLogic/Armor.h` – `ArmorTemplate`, `ArmorStore`
- Source: `GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Armor.cpp` – parsing and application

## Usage

- INI section root: `Armor` definitions are top-level.
- Referenced by object templates to set their armor profile.
- Coefficients are specified as percentages (e.g., `50%`).

## Properties

### General Settings

#### Armor (v1.04)
- Type: block lines within an armor definition
- Description: Maps `DamageType` name to a percentage multiplier. Special key `Default` sets all types.
- Example lines:
  - `Armor = Default 100%`
  - `Armor = EXPLOSION 50%`

## Enum Value Lists

#### DamageType Values (v1.04, Generals Zero Hour)
- Source: `GeneralsMD/Code/GameEngine/Include/GameLogic/Damage.h`
- Values:
  - DAMAGE_EXPLOSION (0)
  - DAMAGE_CRUSH (1)
  - DAMAGE_ARMOR_PIERCING (2)
  - DAMAGE_SMALL_ARMS (3)
  - DAMAGE_GATTLING (4)
  - DAMAGE_RADIATION (5)
  - DAMAGE_FLAME (6)
  - DAMAGE_LASER (7)
  - DAMAGE_SNIPER (8)
  - DAMAGE_POISON (9)
  - DAMAGE_HEALING (10)
  - DAMAGE_UNRESISTABLE (11)
  - DAMAGE_WATER (12)
  - DAMAGE_DEPLOY (13)
  - DAMAGE_SURRENDER (14)
  - DAMAGE_HACK (15)
  - DAMAGE_KILLPILOT (16)
  - DAMAGE_PENALTY (17)
  - DAMAGE_FALLING (18)
  - DAMAGE_MELEE (19)
  - DAMAGE_DISARM (20)
  - DAMAGE_HAZARD_CLEANUP (21)
  - DAMAGE_PARTICLE_BEAM (22)
  - DAMAGE_TOPPLING (23)
  - DAMAGE_INFANTRY_MISSILE (24)
  - DAMAGE_AURORA_BOMB (25)
  - DAMAGE_LAND_MINE (26)
  - DAMAGE_JET_MISSILES (27)
  - DAMAGE_STEALTHJET_MISSILES (28)
  - DAMAGE_MOLOTOV_COCKTAIL (29)
  - DAMAGE_COMANCHE_VULCAN (30)
  - DAMAGE_SUBDUAL_MISSILE (31)
  - DAMAGE_SUBDUAL_VEHICLE (32)
  - DAMAGE_SUBDUAL_BUILDING (33)
  - DAMAGE_SUBDUAL_UNRESISTABLE (34)
  - DAMAGE_MICROWAVE (35)
  - DAMAGE_KILL_GARRISONED (36)
  - DAMAGE_STATUS (37)

#### DeathType Values (v1.04)
- Source: `GeneralsMD/Code/GameEngine/Include/GameLogic/Damage.h`
- Values include: DEATH_NORMAL, DEATH_NONE, DEATH_CRUSHED, DEATH_BURNED, DEATH_EXPLODED, DEATH_POISONED, DEATH_TOPPLED, DEATH_FLOODED, DEATH_SUICIDED, DEATH_LASERED, DEATH_DETONATED, DEATH_SPLATTED, DEATH_POISONED_BETA, DEATH_EXTRA_2..DEATH_EXTRA_8, DEATH_POISONED_GAMMA

## Examples

### Basic Armor
```
Armor HumveeArmor
  Armor = Default 100%
  Armor = EXPLOSION 75%
  Armor = SMALL_ARMS 50%
End
```

### Subdual-focused Armor
```
Armor DroneArmor
  Armor = Default 100%
  Armor = SUBDUAL_VEHICLE 25%
  Armor = MICROWAVE 0%
End
```

## Notes

- Parsing table key: `Armor` lines set coefficients. `Default` applies to all types.
- In Zero Hour, `DAMAGE_SUBDUAL_UNRESISTABLE` is treated like unresistable subdual (no reduction).
- Negative post-scale values are clamped to 0 internally.

## Template

```
; Define an armor profile
Armor <ArmorName>
  Armor = Default 100%          ; base multiplier for all damage types
  Armor = EXPLOSION 75%         ; reduce explosion damage to 75%
  Armor = SMALL_ARMS 50%        ; reduce small arms damage to 50%
  Armor = LASER 80%             ; laser damage scaled to 80%
  Armor = STATUS 100%           ; status effects unaffected (often ignored by health)
  Armor = SUBDUAL_VEHICLE 25%   ; subdual vs vehicles scaled down
End
```

