# HeightDieUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

HeightDieUpdate provides height-based death functionality for objects that can die based on height conditions.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to die when they fall below a certain height or meet height-based death conditions.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object HeightDieUpdate
```ini
Behavior = HeightDieUpdate ModuleTag_06
  TargetHeight = 1.0
  TargetHeightIncludesStructures = Yes
  OnlyWhenMovingDown  = Yes
End
```

### Example 2: Weapon Object HeightDieUpdate with Initial Delay
```ini
Behavior = HeightDieUpdate ModuleTag_03
  TargetHeight = 3.0                          ;;; changed from previous, 50
  TargetHeightIncludesStructures = Yes
End
```

### Example 3: Weapon Object HeightDieUpdate with High Target
```ini
Behavior = HeightDieUpdate ModuleTag_08
  TargetHeight        = 900.0
  TargetHeightIncludesStructures = Yes
  OnlyWhenMovingDown  = Yes
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/HeightDieUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/HeightDieUpdate.cpp)
