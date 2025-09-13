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

*Properties documentation will be added when this page is completed.*

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
Behavior = CleanupHazardUpdate ModuleTag_03
  WeaponSlot            = PRIMARY
  ScanRate              = 500
  ScanRange             = 175.0 ;If this range exceeds the AmbulanceCleanHazardWeapon AttackRange, it'll move!
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/CleanupHazardUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/CleanupHazardUpdate.cpp)
