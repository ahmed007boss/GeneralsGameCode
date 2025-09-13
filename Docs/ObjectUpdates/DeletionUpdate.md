# DeletionUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DeletionUpdate provides deletion functionality for objects that need to be deleted after a certain time or condition.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to be automatically deleted after a specific duration or when certain conditions are met.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Special Objects DeletionUpdate
```ini
Behavior = DeletionUpdate ModuleTag_03
  MinLifetime = 1000
  MaxLifetime = 1000
End
```

### Example 2: Weapon Object DeletionUpdate
```ini
Behavior = DeletionUpdate ModuleTag_09d
    MinLifetime = 300
    MaxLifetime = 300
End
```

### Example 3: System Object DeletionUpdate
```ini
Behavior = DeletionUpdate ModuleTag_04
  MinLifetime = 2000
  MaxLifetime = 2000
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DeletionUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DeletionUpdate.cpp)
