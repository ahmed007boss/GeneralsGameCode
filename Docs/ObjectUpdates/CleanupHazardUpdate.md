# CleanupHazardUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CleanupHazardUpdate provides hazard cleanup functionality for objects that can clean up environmental hazards.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to clean up hazards, such as chemical spills, radiation, or other environmental dangers.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

The following INI properties are parsed by this module. All are optional unless noted.

- **`WeaponSlot`**
  - **Type**: `WeaponSlotType`
  - **Description**: Which weapon slot this module uses to fire at cleanup hazards.
  - **Notes**: Must reference a valid weapon on the object. Common values: `PRIMARY`, `SECONDARY`, `TERTIARY`.
  - **Example**: `WeaponSlot = PRIMARY`

- **`ScanRate`**
  - **Type**: `UnsignedInt` (duration)
  - **Description**: Time between expensive hazard scans. Converted from time to internal frames.
  - **Example**: `ScanRate = 1000`

- **`ScanRange`**
  - **Type**: `Real`
  - **Description**: Radius to search for objects with `KINDOF_CLEANUP_HAZARD`.
  - **Important**: Must be strictly greater than the weapon's `AttackRange` or a debug crash will be triggered at runtime.
  - **Example**: `ScanRange = 175.0`

## Examples

### Example 1
```ini
Behavior = CleanupHazardUpdate ModuleTag_03
  WeaponSlot            = PRIMARY
  ScanRate              = 1000
  ScanRange             = 100.0
End
```

### Example 2
```ini
Behavior = CleanupHazardUpdate ModuleTag_03
  WeaponSlot            = PRIMARY
  ScanRate              = 500
  ScanRange             = 175.0 ;If this range exceeds the AmbulanceCleanHazardWeapon AttackRange, it'll move!
End
```

### Example 3
```ini
Behavior = CleanupHazardUpdate ModuleTag_AreaClean
  WeaponSlot            = SECONDARY
  ScanRate              = 250
  ScanRange             = 300.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/CleanupHazardUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/CleanupHazardUpdate.cpp)

## Template

Ready-to-use template with all properties:

```ini
Behavior = CleanupHazardUpdate <ModuleTag_Cleanup>
  WeaponSlot  = PRIMARY  ; Weapon slot used to fire the cleanup weapon
  ScanRate    = 500      ; Milliseconds between hazard scans (converted to frames)
  ScanRange   = 200.0    ; Radius to search for KINDOF_CLEANUP_HAZARD (must exceed weapon range)
End
```
