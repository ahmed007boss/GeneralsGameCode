# BridgeBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BridgeBehavior manages bridge structures, including tower connections, destruction sequences, and bridge functionality.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`BridgeBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeBehavior.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by bridge objects to coordinate between bridge towers, manage bridge integrity, and handle bridge-specific behaviors.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Bridge Behavior
```ini
Behavior = BridgeBehavior ModuleTag_03
  LateralScaffoldSpeed = 100.0
  VerticalScaffoldSpeed = 70.0
End
```

### Example 2: Civilian Building Bridge
```ini
Behavior = BridgeBehavior ModuleTag_03
  LateralScaffoldSpeed = 80.0
  VerticalScaffoldSpeed = 60.0
End
```

### Example 3: System Bridge Alternative
```ini
Behavior = BridgeBehavior ModuleTag_05
  LateralScaffoldSpeed = 120.0
  VerticalScaffoldSpeed = 90.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeBehavior.cpp)
