# PointDefenseLaserUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

PointDefenseLaserUpdate provides point defense laser functionality for objects that can create point defense laser effects.

## Usage

Used by objects that can create point defense laser systems for protecting against incoming threats.

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
Behavior = PointDefenseLaserUpdate ModuleTag_99
  WeaponTemplate        = SAMAntiBallisticPointDefenseLaser
  PrimaryTargetTypes    = BALLISTIC_MISSILE
  ScanRate              = 1
End
```

### Example 2
```ini
Behavior = PointDefenseLaserUpdate ModuleTag_99
  WeaponTemplate        = SAMAntiAircraftPointDefenseLaser
  PrimaryTargetTypes    = AIRCRAFT VEHICLE
  ScanRate              = 1
End
```

### Example 3
```ini
Behavior = PointDefenseLaserUpdate ModuleTag_08
  WeaponTemplate        = GuardianShieldWeapon2
  PrimaryTargetTypes    = BALLISTIC_MISSILE
  ScanRate              = 50
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/PointDefenseLaserUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/PointDefenseLaserUpdate.cpp)
