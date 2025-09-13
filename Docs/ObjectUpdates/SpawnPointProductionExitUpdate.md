# SpawnPointProductionExitUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpawnPointProductionExitUpdate provides spawn point-based production exit functionality for objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`ExitInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpawnPointProductionExitUpdate.h)

## Usage

Used by production buildings that use specific spawn points for unit exit and deployment.

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
Behavior = SpawnPointProductionExitUpdate ModuleTag_05
  SpawnPointBoneName = Tripod
End
```

### Example 2
```ini
Behavior = SpawnPointProductionExitUpdate ModuleTag_Defender02
  SpawnPointBoneName = SpawnPoint
End
```

### Example 3
```ini
Behavior = SpawnPointProductionExitUpdate ModuleTag_06
  SpawnPointBoneName = SpawnPoint
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ProductionExitUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/SpawnPointProductionExitUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionExitUpdate/SpawnPointProductionExitUpdate.cpp)
