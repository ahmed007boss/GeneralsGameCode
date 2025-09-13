# QueueProductionExitUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

QueueProductionExitUpdate provides queue-based production exit functionality for objects that produce multiple units.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`ExitInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/QueueProductionExitUpdate.h)

## Usage

Used by production buildings that need queue management for multiple unit production and exit coordination.

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
Behavior = QueueProductionExitUpdate ModuleTag_06
  UnitCreatePoint   = X:  0.0  Y:  0.0   Z:0.0
  NaturalRallyPoint = X: 0.0  Y:  0.0   Z:0.0
  ExitDelay     = 7000 ; 7 sec
End
```

### Example 2
```ini
Behavior = QueueProductionExitUpdate ModuleTag_11
  UnitCreatePoint   = X:  0.0  Y:  -25.0   Z:0.0
  NaturalRallyPoint = X: 36.0  Y:  -25.0   Z:0.0;NaturalRallyPointX must always match GeometryMajorRadius! -ML
  ExitDelay = 300 ; Mainly for the multiple produced Red Guard.  Make them come out one at a time.
End
```

### Example 3
```ini
Behavior = QueueProductionExitUpdate ModuleTag_09
  UnitCreatePoint   = X:  0.0  Y:  29.0   Z:0.0
  NaturalRallyPoint = X: 80.0  Y:  29.0   Z:0.0;NaturalRallyPointX must always match GeometryMajorRadius! -ML
  ExitDelay = 300 ; Mainly for the multiple produced Red Guard.  Make them come out one at a time.
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/QueueProductionExitUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/QueueProductionExitUpdate.cpp)
