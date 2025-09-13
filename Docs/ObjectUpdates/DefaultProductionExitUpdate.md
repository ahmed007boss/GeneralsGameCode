# DefaultProductionExitUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DefaultProductionExitUpdate provides default production exit functionality for objects that produce other objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`ExitInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DefaultProductionExitUpdate.h)

## Usage

Used by production buildings and facilities that need standard exit mechanics for produced units.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Radar Station DefaultProductionExitUpdate
```ini
Behavior = DefaultProductionExitUpdate ModuleTag_Production02
  UnitCreatePoint = X:10 Y:23 Z:0
  NaturalRallyPoint = X:25 Y:23 Z:0
End
```

### Example 2: GLA Secret Lab DefaultProductionExitUpdate
```ini
Behavior = DefaultProductionExitUpdate ModuleTag_06
  UnitCreatePoint   = X: 5.0   Y:  0.0   Z:0.0
  NaturalRallyPoint = X: 65.0  Y:  0.0   Z:0.0
End
```

### Example 3: USA War Factory DefaultProductionExitUpdate
```ini
Behavior = DefaultProductionExitUpdate ModuleTag_11
  UnitCreatePoint   = X: -10.0  Y:-30.0   Z:0.0
  NaturalRallyPoint = X: 53.0  Y:-30.0   Z:0.0;NaturalRallyPointX must always match GeometryMajorRadius! -ML
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/DefaultProductionExitUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/DefaultProductionExitUpdate.cpp)
