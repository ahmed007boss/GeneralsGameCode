# BridgeScaffoldBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BridgeScaffoldBehavior manages bridge scaffold structures during construction and destruction phases.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`BridgeScaffoldBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeScaffoldBehavior.h)

## Usage

Used by bridge scaffold objects to control construction progress, movement animations, and destruction sequences.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Bridge Scaffold
```ini
Behavior = BridgeScaffoldBehavior ModuleTag_02
  ;<NO DATA>
End
```

### Example 2: Bridge Scaffold Construction
```ini
Behavior = BridgeScaffoldBehavior ModuleTag_02
  ConstructionSpeed = 50.0
  MovementSpeed = 30.0
End
```

### Example 3: Bridge Scaffold Destruction
```ini
Behavior = BridgeScaffoldBehavior ModuleTag_02
  DestructionSpeed = 75.0
  CollapseDelay = 2000
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeScaffoldBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BridgeScaffoldBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeScaffoldBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeScaffoldBehavior.cpp)
