# BridgeTowerBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BridgeTowerBehavior manages individual bridge tower structures and their connections to bridge segments.

**Base Class:** [`BehaviorModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h), [`BridgeTowerBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeTowerBehavior.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by bridge tower objects to coordinate with bridge segments, manage tower-specific functionality, and handle tower destruction.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Civilian Building Bridge Tower
```ini
Behavior = BridgeTowerBehavior ModuleTag_03
  ;No Data
End
```

### Example 2: Bridge Tower Connection
```ini
Behavior = BridgeTowerBehavior ModuleTag_03
  ConnectionRange = 100.0
  TowerHeight = 30.0
End
```

### Example 3: Bridge Tower Destruction
```ini
Behavior = BridgeTowerBehavior ModuleTag_03
  DestructionDelay = 1500
  CollapseEffect = FX_BridgeTowerCollapse
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeTowerBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeTowerBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeTowerBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeTowerBehavior.cpp)
