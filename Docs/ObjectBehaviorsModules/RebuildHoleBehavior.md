# RebuildHoleBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

RebuildHoleBehavior provides functionality for rebuilding destroyed structures or filling holes left by destroyed objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h), [`RebuildHoleBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/RebuildHoleBehavior.h)

## Usage

Used by objects that can rebuild destroyed structures or fill holes in the terrain left by destroyed buildings.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Holes Rebuild Hole Behavior
```ini
Behavior                    = RebuildHoleBehavior ModuleTag_04
  WorkerObjectName          = GLAInfantryWorker
  WorkerRespawnDelay        = 20000 ;in milliseconds
  HoleHealthRegen%PerSecond = 0.5%    ;regen this % of HoleMaxHealth per second
End
```

### Example 2: GLA Holes Rebuild Hole Behavior Alternative
```ini
Behavior                    = RebuildHoleBehavior ModuleTag_04
  WorkerObjectName          = GLAInfantryWorker
  WorkerRespawnDelay        = 20000 ;in milliseconds
  HoleHealthRegen%PerSecond = 0.5%    ;regen this % of HoleMaxHealth per second
End
```

### Example 3: GLA Palace Rebuild Hole Behavior
```ini
Behavior = RebuildHoleBehavior ModuleTag_04
  WorkerObjectName          = GLAInfantryWorker
  WorkerRespawnDelay        = 20000 ;in milliseconds
  HoleHealthRegen%PerSecond = 0.5%    ;regen this % of HoleMaxHealth per second
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/RebuildHoleBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/RebuildHoleBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/RebuildHoleBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/RebuildHoleBehavior.cpp)
