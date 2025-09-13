# ActiveShroudUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ActiveShroudUpgrade provides active shroud functionality for objects that can create or manage active shroud effects.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can create active shroud effects, provide shroud coverage, or manage shroud-based systems.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

The following INI properties are parsed by this module and its base upgrade mux. All are optional unless noted.

- **`TriggeredBy`**
  - **Type**: `AsciiStringVector`
  - **Description**: One or more upgrade names that activate this upgrade when acquired by the object/player.
  - **Notes**: Provided by `UpgradeMuxData` in the base class.
  - **Example**: `TriggeredBy = Upgrade_GroundRadarDrone`

- **`RequiredAnyUpgradeOf`**
  - **Type**: `AsciiStringVector`
  - **Description**: Requires at least one of the listed upgrades to be present to allow activation.
  - **Example**: `RequiredAnyUpgradeOf = Upgrade_A Upgrade_B`

- **`RequiredAllUpgradesOf`**
  - **Type**: `AsciiStringVector`
  - **Description**: Requires all of the listed upgrades to be present to allow activation.
  - **Example**: `RequiredAllUpgradesOf = Upgrade_Core Upgrade_Tech`

- **`ConflictsWith`**
  - **Type**: `AsciiStringVector`
  - **Description**: If any of these upgrades are present, this upgrade will not activate.
  - **Example**: `ConflictsWith = Upgrade_StealthField`

- **`RemovesUpgrades`**
  - **Type**: `AsciiStringVector`
  - **Description**: Upgrades to remove when this upgrade activates.
  - **Example**: `RemovesUpgrades = Upgrade_OldShroud`

- **`FXListUpgrade`**
  - **Type**: `FXList`
  - **Description**: FX played upon successful activation of the upgrade.
  - **Example**: `FXListUpgrade = FX_ShroudActivate`

- **`RequiresAllTriggers`**
  - **Type**: `Bool`
  - **Description**: If `Yes`, requires all entries in `TriggeredBy` to be present to activate; if `No`, any one trigger is sufficient.
  - **Example**: `RequiresAllTriggers = No`

- **`NewShroudRange`**
  - **Type**: `Real`
  - **Description**: New shroud range to set on the object when the upgrade executes.
  - **Behavior**: On activation, the object’s shroud range is set and partition maintenance is forced for immediate effect.
  - **Example**: `NewShroudRange = 375.0`

## Examples

### Example 1
```ini
Behavior = ActiveShroudUpgrade ModuleTag_ShroudModule01
  TriggeredBy = Upgrade_GroundRadarDrone
  NewShroudRange = 9999.0
End
```

### Example 2
```ini
Behavior = ActiveShroudUpgrade ModuleTag_12
  TriggeredBy = Upgrade_RUSSIA
  RequiresAllTriggers = No
  NewShroudRange = 375.0
End
```

### Example 3
```ini
Behavior = ActiveShroudUpgrade ModuleTag_ShroudMixed
  TriggeredBy = Upgrade_RadarDrone Upgrade_FieldOps
  RequiresAllTriggers = Yes
  RequiredAnyUpgradeOf = Upgrade_Tech1 Upgrade_Tech2
  RequiredAllUpgradesOf = Upgrade_Core
  ConflictsWith = Upgrade_StealthField
  FXListUpgrade = FX_ShroudActivate
  NewShroudRange = 450.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ActiveShroudUpgrade.cpp`](../../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ActiveShroudUpgrade.cpp)

## Template

Ready-to-use template with all properties:

```ini
Behavior = ActiveShroudUpgrade <ModuleTag_Shroud>
  TriggeredBy            = Upgrade_GroundRadarDrone     ; Upgrades that activate this
  RequiredAnyUpgradeOf   =                              ; Any of these also required (optional)
  RequiredAllUpgradesOf  =                              ; All of these required (optional)
  ConflictsWith          =                              ; Blocks activation if present (optional)
  RemovesUpgrades        =                              ; Remove these on activation (optional)
  FXListUpgrade          =                              ; FX to play on activation (optional)
  RequiresAllTriggers    = No                           ; All TriggeredBy required? (Yes/No)

  NewShroudRange         = 375.0                        ; New active shroud range to apply
End
```
