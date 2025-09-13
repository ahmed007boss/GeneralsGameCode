# SupplyCenterProductionExitUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SupplyCenterProductionExitUpdate provides production exit functionality specifically for supply center facilities.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`ExitInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SupplyCenterProductionExitUpdate.h)

## Usage

Used by supply center buildings that need specialized exit mechanics for supply-related units.

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
Behavior = SupplyCenterProductionExitUpdate ModuleTag_11
  UnitCreatePoint   = X:  0.0  Y:  0.0   Z:0.0
  NaturalRallyPoint = X: 36.0  Y:  0.0   Z:0.0;NaturalRallyPointX must always match GeometryMajorRadius! -ML
  ;GrantTemporaryStealth = 20000
End
```

### Example 2
```ini
Behavior = SupplyCenterProductionExitUpdate ModuleTag_11
  UnitCreatePoint   = X:  0.0  Y:  0.0   Z:0.0
  NaturalRallyPoint = X: 52.0  Y:  0.0   Z:0.0;NaturalRallyPointX must always match GeometryMajorRadius! -ML
End
```

### Example 3
```ini
Behavior = SupplyCenterProductionExitUpdate ModuleTag_11
  UnitCreatePoint   = X:  0.0  Y:  25.0   Z:0.0
  NaturalRallyPoint = X: 60.0  Y:  25.0   Z:0.0;NaturalRallyPointX must always match GeometryMajorRadius! -ML
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/SupplyCenterProductionExitUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/SupplyCenterProductionExitUpdate.cpp)
