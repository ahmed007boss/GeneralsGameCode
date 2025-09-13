# LifetimeUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

LifetimeUpdate provides lifetime management functionality for objects with limited lifespans.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that have limited lifespans and need to be managed or destroyed after a certain time.

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
Behavior = LifetimeUpdate ModuleTag_04
  MinLifetime = 3800
  MaxLifetime = 3800
End
```

### Example 2
```ini
Behavior = LifetimeUpdate ModuleTag_10
  MinLifetime = 9000   ; min lifetime in msec
  MaxLifetime = 9000 ; max lifetime in msec
End
```

### Example 3
```ini
Behavior = LifetimeUpdate ModuleTag_09
    MinLifetime = 1000
    MaxLifetime = 1000
End
```

*Examples will be added when this page is completed.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/LifetimeUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/LifetimeUpdate.cpp)
