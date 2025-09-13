# CleanupAreaPower

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CleanupAreaPower provides special power functionality for area cleanup systems.

**Base Class:** [`SpecialPowerModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)

## Usage

Used by objects that can clean up areas or remove hazards as special powers.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America CINE Unit Cleanup Area
```ini
;Can be ordered to clean up a larger area with the ability to move around at an extended range.
Behavior = CleanupAreaPower ModuleTag_04
  SpecialPowerTemplate          = SpecialAbilityAmbulanceCleanupArea
  MaxMoveDistanceFromLocation   = 300.0 ;allows the unit to move around while cleaning up
End
```

### Example 2: Russia Vodnik Cleanup Area
```ini
Behavior = CleanupAreaPower ModuleTag_04
  SpecialPowerTemplate          = SpecialAbilityAmbulanceCleanupArea
  MaxMoveDistanceFromLocation   = 300.0 ;allows the unit to move around while cleaning up
End
```

### Example 3: USA Medic Vehicle Cleanup Area
```ini
Behavior = CleanupAreaPower ModuleTag_04
  SpecialPowerTemplate          = SpecialAbilityAmbulanceCleanupArea
  MaxMoveDistanceFromLocation   = 300.0 ;allows the unit to move around while cleaning up
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/CleanupAreaPower.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/CleanupAreaPower.cpp)
