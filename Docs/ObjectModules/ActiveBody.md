# ActiveBody

ActiveBody provides comprehensive health and damage management for objects that can take damage, be healed, and be destroyed through combat.

## Overview

The `ActiveBody` class manages active health systems for objects that can take damage and be destroyed. It handles health tracking, damage states, healing, subdual damage, electronic warfare damage, and visual damage effects. Objects with ActiveBody can be damaged by weapons, healed by repair systems, and transition through different damage states that affect their appearance and functionality.

## Usage

Used by objects that have active health systems, can take damage, and can be destroyed through combat. This is a **body module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- ActiveBody automatically manages damage states (PRISTINE, DAMAGED, REALLYDAMAGED, RUBBLE) based on health percentage
- Damage states affect visual appearance and particle systems
- Subdual damage can disable objects without destroying them
- Electronic warfare damage can jam electronic systems
- Objects automatically heal subdual and EW damage over time if healing rates are set
- Damage states are calculated based on global thresholds defined in game data
- Subdual and EW damage properties are exclusive to Generals Zero Hour (v1.04)

**Conditions**:
- Objects with ActiveBody can be targeted by weapons (see [Weapon documentation](../Weapon.md)) and affected by damage types
- Veterancy levels can modify maximum health and healing rates
- ActiveBody integrates with armor systems (see [Armor documentation](../Armor.md)) and damage effects
- **Multiple instances behavior**: Only one ActiveBody instance should exist per object; multiple instances may cause conflicts in health management

**Dependencies**:
- Requires proper armor and damage type definitions to function correctly

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
  - [Health Settings](#health-settings)
  - [Subdual Damage Settings](#subdual-damage-settings)
  - [Electronic Warfare Settings](#electronic-warfare-settings)
- [Enum Value Lists](#enum-value-lists)
- [Examples](#examples)
- [Template](#template)
- [Notes](#notes)

## Properties

### Health Settings

#### `MaxHealth` *(v1.04)*
- **Type**: `Real`
- **Description**: Maximum health points the object can have. Higher values make objects more durable and resistant to damage. This determines the total damage capacity before destruction
- **Default**: `100.0`
- **Example**: `MaxHealth = 500.0`

#### `InitialHealth` *(v1.04)*
- **Type**: `Real`
- **Description**: Starting health points when the object is created. Higher values allow objects to spawn with more health than their maximum, providing temporary damage buffer. Lower values spawn objects at reduced health
- **Default**: `100.0`
- **Example**: `InitialHealth = 500.0`

### Subdual Damage Settings

#### `SubdualDamageCap` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Maximum subdual damage that can accumulate before the object is subdued. Higher values allow objects to absorb more subdual damage before becoming incapacitated. At 0 (default), objects cannot be subdued
- **Default**: `0.0`
- **Example**: `SubdualDamageCap = 350.0`

#### `SubdualDamageHealRate` *(v1.04, Generals Zero Hour only)*
- **Type**: `UnsignedInt` (milliseconds)
- **Description**: Time interval between subdual damage healing attempts. Lower values heal subdual damage more frequently, while higher values heal less often. At 0 (default), no automatic subdual healing occurs
- **Default**: `0`
- **Example**: `SubdualDamageHealRate = 500`

#### `SubdualDamageHealAmount` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Amount of subdual damage healed per healing interval. Higher values heal more subdual damage per tick, while lower values heal less. At 0 (default), no subdual healing occurs
- **Default**: `0.0`
- **Example**: `SubdualDamageHealAmount = 50.0`

### Electronic Warfare Settings

#### `EWDamageCap` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Maximum electronic warfare damage that can accumulate before the object is jammed. Higher values allow objects to absorb more EW damage before becoming electronically disabled. At 0 (default), objects cannot be jammed
- **Default**: `0.0`
- **Example**: `EWDamageCap = 200.0`

#### `EWDamageHealRate` *(v1.04, Generals Zero Hour only)*
- **Type**: `UnsignedInt` (milliseconds)
- **Description**: Time interval between electronic warfare damage healing attempts. Lower values heal EW damage more frequently, while higher values heal less often. At 0 (default), no automatic EW healing occurs
- **Default**: `0`
- **Example**: `EWDamageHealRate = 1000`

#### `EWDamageHealAmount` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Amount of electronic warfare damage healed per healing interval. Higher values heal more EW damage per tick, while lower values heal less. At 0 (default), no EW healing occurs
- **Default**: `0.0`
- **Example**: `EWDamageHealAmount = 25.0`

## Enum Value Lists

#### `BodyDamageType` Values *(v1.04)*
**Source:** [BodyModule.h](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h#53) - `BodyDamageType` enum definition

- **`BODY_PRISTINE`** *(v1.04)* - Unit should appear in pristine condition
- **`BODY_DAMAGED`** *(v1.04)* - Unit has been damaged
- **`BODY_REALLYDAMAGED`** *(v1.04)* - Unit is extremely damaged / nearly destroyed
- **`BODY_RUBBLE`** *(v1.04)* - Unit has been reduced to rubble/corpse/exploded-hulk, etc

## Examples

### Scout Van with Subdual Resistance
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 200.0
  InitialHealth = 200.0
  SubdualDamageCap = 350.0
  SubdualDamageHealRate = 500
  SubdualDamageHealAmount = 50.0
End
```

### Anti-Tank Site
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 75.0
  InitialHealth = 75.0
End
```

### Stinger Site with EW Protection
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 500.0
  InitialHealth = 500.0
  EWDamageCap = 300.0
  EWDamageHealRate = 2000
  EWDamageHealAmount = 30.0
End
```

### Command Center with Full Protection
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 1000.0
  InitialHealth = 1000.0
  SubdualDamageCap = 800.0
  SubdualDamageHealRate = 1000
  SubdualDamageHealAmount = 100.0
  EWDamageCap = 500.0
  EWDamageHealRate = 1500
  EWDamageHealAmount = 75.0
End
```

## Template

```ini
Body = ActiveBody ModuleTag_XX
  ; Health Settings
  MaxHealth = 500.0               ; // maximum health points *(v1.04)*
  InitialHealth = 500.0           ; // starting health points *(v1.04)*

  ; Subdual Damage Settings (Generals Zero Hour only)
  SubdualDamageCap = 0.0          ; // maximum subdual damage before subdual *(v1.04, Generals Zero Hour only)*
  SubdualDamageHealRate = 0       ; // milliseconds between subdual damage healing *(v1.04, Generals Zero Hour only)*
  SubdualDamageHealAmount = 0.0   ; // amount of subdual damage healed per interval *(v1.04, Generals Zero Hour only)*

  ; Electronic Warfare Settings (Generals Zero Hour only)
  EWDamageCap = 0.0               ; // maximum EW damage before jamming *(v1.04, Generals Zero Hour only)*
  EWDamageHealRate = 0            ; // milliseconds between EW damage healing *(v1.04, Generals Zero Hour only)*
  EWDamageHealAmount = 0.0        ; // amount of EW damage healed per interval *(v1.04, Generals Zero Hour only)*
End
```

## Notes

- ActiveBody automatically manages damage states (PRISTINE, DAMAGED, REALLYDAMAGED, RUBBLE) based on health percentage
- Damage states affect visual appearance and particle systems
- Subdual damage can disable objects without destroying them
- Electronic warfare damage can jam electronic systems
- Objects automatically heal subdual and EW damage over time if healing rates are set
- Damage states are calculated based on global thresholds defined in game data
- Objects with ActiveBody can be targeted by weapons (see [Weapon documentation](../Weapon.md)) and affected by damage types
- Veterancy levels can modify maximum health and healing rates
- ActiveBody integrates with armor systems (see [Armor documentation](../Armor.md)) and damage effects

## Source Files

**Base Class:** [`BodyModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp)
