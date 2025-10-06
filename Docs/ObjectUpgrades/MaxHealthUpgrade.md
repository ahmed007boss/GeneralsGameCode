# MaxHealthUpgrade

MaxHealthUpgrade provides the ability to increase an object's maximum health when an upgrade is applied, allowing for enhanced durability and survivability.

## Overview

The `MaxHealthUpgrade` class manages maximum health increases for objects when specific upgrades are applied. This upgrade module allows objects to have their maximum health increased by a specified amount, providing enhanced durability and survivability. The behavior supports different health change types to control how the current health is affected when the maximum health is increased.

## Usage

Used by objects that need to increase their maximum health when upgrades are applied. This is an **upgrade module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- Only affects maximum health, not current health (unless specified by ChangeType)
- The health increase is permanent until the upgrade is removed
- Objects must have a BodyModule to function properly
- Health increases are additive, not multiplicative

**Conditions**:
- MaxHealthUpgrade increases the object's maximum health when the specified upgrade is applied
- The upgrade integrates with the upgrade system for conditional activation
- Different health change types control how current health is affected
- The upgrade works with objects that have BodyModule (ActiveBody)
- **Multiple instances behavior**: Multiple instances can coexist; each operates independently with its own health increases

**Dependencies**:
- Requires an object with upgrade system integration
- Objects must have BodyModule (ActiveBody) to function properly
- The upgrade system must be properly configured for the object

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Enum Value Lists](#enum-value-lists)
- [Examples](#examples)
- [Template](#template)
- [Notes](#notes)
- [Source Files](#source-files)
- [Changes History](#changes-history)
- [Status](#status)

## Properties

### Health Modification Settings

#### `AddMaxHealth` *(v1.04)*
- **Type**: `Real`
- **Description**: The amount of maximum health to add to the object. Positive values increase maximum health, providing enhanced durability. The value is added to the current maximum health
- **Default**: `0.0`
- **Example**: `AddMaxHealth = 100.0`

#### `ChangeType` *(v1.04)*
- **Type**: `MaxHealthChangeType` (see [MaxHealthChangeType Values](#maxhealthchangetype-values) section)
- **Description**: Controls how the current health is affected when maximum health is increased. Different types provide different behaviors for health management
- **Default**: `SAME_CURRENTHEALTH`
- **Example**: `ChangeType = PRESERVE_RATIO`

## Enum Value Lists

#### `MaxHealthChangeType` Values *(v1.04)*
**Source:** [BodyModule.h](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h#84) - `TheMaxHealthChangeTypeNames[]` array definition

- **`SAME_CURRENTHEALTH`** *(v1.04)* - Keeps current health the same when maximum health is increased
- **`PRESERVE_RATIO`** *(v1.04)* - Maintains the same health percentage when maximum health is increased
- **`ADD_CURRENT_HEALTH_TOO`** *(v1.04)* - Adds the same amount to current health as maximum health
- **`FULLY_HEAL`** *(v1.04)* - Fully heals the object when maximum health is increased

## Examples

### Basic Health Increase
```ini
Upgrade = MaxHealthUpgrade ModuleTag_HealthBoost
  AddMaxHealth = 100.0
  ChangeType = SAME_CURRENTHEALTH
  TriggeredBy = Upgrade_HealthTraining
End
```

### Health Increase with Ratio Preservation
```ini
Upgrade = MaxHealthUpgrade ModuleTag_HealthUpgrade
  AddMaxHealth = 50.0
  ChangeType = PRESERVE_RATIO
  TriggeredBy = Upgrade_AdvancedTraining
End
```

### Health Increase with Current Health Boost
```ini
Upgrade = MaxHealthUpgrade ModuleTag_HealthBoost
  AddMaxHealth = 75.0
  ChangeType = ADD_CURRENT_HEALTH_TOO
  TriggeredBy = Upgrade_MedicalTraining
End
```

### Full Heal with Health Increase
```ini
Upgrade = MaxHealthUpgrade ModuleTag_HealthRestore
  AddMaxHealth = 200.0
  ChangeType = FULLY_HEAL
  TriggeredBy = Upgrade_EmergencyHealing
End
```

## Template

```ini
Upgrade = MaxHealthUpgrade ModuleTag_XX
  ; Health Modification Settings
  AddMaxHealth = 0.0               ; // amount of maximum health to add *(v1.04)*
  ChangeType = SAME_CURRENTHEALTH  ; // how current health is affected *(v1.04)*
  
  ; Upgrade Integration (inherited from UpgradeModule)
  TriggeredBy =                    ; // required upgrade flags *(v1.04)*
  ConflictsWith =                  ; // conflicting upgrade flags *(v1.04)*
  RequiresAll = No                 ; // require all TriggeredBy upgrades *(v1.04)*
End
```

## Notes

- MaxHealthUpgrade increases the object's maximum health when the specified upgrade is applied
- The upgrade integrates with the upgrade system for conditional activation
- Different health change types control how current health is affected
- The upgrade works with objects that have BodyModule (ActiveBody)
- Only affects maximum health, not current health (unless specified by ChangeType)
- The health increase is permanent until the upgrade is removed
- Health increases are additive, not multiplicative
- Objects must have a BodyModule to function properly

## Source Files

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/MaxHealthUpgrade.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/MaxHealthUpgrade.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/MaxHealthUpgrade.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/MaxHealthUpgrade.cpp)

## Changes History

- No Changes done since 1.04

## Status

- **Documentation Status**: AI Generated Pending Reviews 
- **Last Updated**: [Current Date] by @ahmed Salah using AI

### Modder Reviews 
- No Reviews done yet
