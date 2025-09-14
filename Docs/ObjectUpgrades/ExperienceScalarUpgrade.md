# ExperienceScalarUpgrade

ExperienceScalarUpgrade provides experience scaling functionality for objects that can modify experience gain rates.

## Overview

The `ExperienceScalarUpgrade` class manages experience scaling operations for objects that can modify experience gain rates, provide experience bonuses, or manage experience scaling. It handles experience multiplier enhancement, experience scaling, and experience system integration. This upgrade is commonly used by objects that provide experience bonuses, experience systems, and units with experience scaling capabilities.

## Usage

Used by objects that can modify experience gain rates, provide experience bonuses, or manage experience scaling. This is an **upgrade module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- Experience scaling operations are limited by experience scalar parameters and experience system capabilities
- Experience scaling activation depends on proper upgrade system integration
- Experience management is controlled by experience parameters and system capabilities
- Experience effectiveness varies based on experience capabilities

**Conditions**:
- ExperienceScalarUpgrade manages experience scaling operations and experience system coordination
- The upgrade handles experience multiplier enhancement, experience scaling, and experience management
- Experience scaling operations provide experience bonus and experience system capabilities
- Experience management creates realistic experience system operations
- **Multiple instances behavior**: Multiple instances can coexist; each operates independently with its own experience parameters

**Dependencies**:
- Uses upgrade system for experience upgrade activation
- Integrates with experience system for experience scaling
- Uses scaling system for experience multiplier management

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
  - [Experience Settings](#experience-settings)
- [Examples](#examples)
- [Template](#template)
- [Notes](#notes)
- [Source Files](#source-files)
- [Changes History](#changes-history)
- [Status](#status)
  - [Reviews (0)](#modder-reviews)

## Properties

### Experience Settings

#### `AddXPScalar` *(v1.04)*
- **Type**: `Real`
- **Description**: Additional experience scalar multiplier. Higher values provide greater experience gain. Lower values provide smaller experience gain. 1.0 = 100% additional experience gain
- **Default**: `0.0`
- **Example**: `AddXPScalar = 1.0`

## Examples

### Basic Experience Scalar Upgrade
```ini
Behavior = ExperienceScalarUpgrade Upgrade_02
  TriggeredBy = Upgrade_BallisticCommandset
  AddXPScalar = 1.0 ;Increases experience gained by an additional 100%
End
```

### Experience Scalar Upgrade with Multiplier
```ini
Behavior = ExperienceScalarUpgrade Upgrade_02
  TriggeredBy = Upgrade_BallisticCommandset
  AddXPScalar = 1.0 ;Increases experience gained by an additional 100%
End
```

### Advanced Experience Scalar Upgrade
```ini
Behavior = ExperienceScalarUpgrade Upgrade_03
  TriggeredBy = Upgrade_BallisticCommandset
  AddXPScalar = 1.0 ;Increases experience gained by an additional 100%
End
```

## Template

```ini
Behavior = ExperienceScalarUpgrade ModuleTag_XX
  ; Experience Settings
  AddXPScalar = 0.0                   ; // additional experience scalar multiplier *(v1.04)*
End
```

## Notes

- ExperienceScalarUpgrade provides experience scaling operations and experience system coordination capabilities
- The upgrade manages experience multiplier enhancement, experience scaling, and experience management
- Experience scaling operations provide essential experience bonus and experience system capabilities
- Experience management creates realistic experience system operations and coordination
- This upgrade is commonly used by objects that provide experience bonuses, experience systems, and experience scaling capability units
- Experience coordination ensures efficient experience scaling and system integration operations

## Source Files

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ExperienceScalarUpgrade.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ExperienceScalarUpgrade.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ExperienceScalarUpgrade.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ExperienceScalarUpgrade.cpp)

## Changes History

- No Changes done since 1.04

## Status

- **Documentation Status**: AI Generated Pending Reviews 
- **Last Updated**: [Current Date] by @ahmed Salah using AI

### Modder Reviews 
- No Reviews done yet