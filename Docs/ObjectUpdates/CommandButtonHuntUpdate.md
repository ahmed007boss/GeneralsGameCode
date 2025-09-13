# CommandButtonHuntUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CommandButtonHuntUpdate provides command button hunt functionality for objects that can hunt targets based on command button actions.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to hunt targets when specific command buttons are activated or pressed.

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
Behavior = CommandButtonHuntUpdate  ModuleTag_11 ; allows use of command button hunt script with this unit. 
End
```

### Example 2
```ini
Behavior = CommandButtonHuntUpdate ModuleTag_02
End
```

### Example 3
```ini
Behavior = CommandButtonHuntUpdate  ModuleTag_12 ; allows use of command button hunt script with this unit.
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/CommandButtonHuntUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/CommandButtonHuntUpdate.cpp)
