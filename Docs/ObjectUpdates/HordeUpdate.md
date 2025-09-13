# HordeUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

HordeUpdate provides horde functionality for objects that can form or join hordes.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`HordeUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/HordeUpdate.h)

## Usage

Used by objects that can form hordes, join existing hordes, or coordinate with other units in horde formations.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: China CINE Unit HordeUpdate
```ini
Behavior = HordeUpdate ModuleTag_06
  RubOffRadius = 60    ; if I am this close to a real hordesman, I will get to be an honorary hordesman
  UpdateRate = 1000    ; how often to recheck horde status (msec)
  Radius = 30          ; how close other units must be to us to count towards our horde-ness (~30 feet or so)
End
```

### Example 2: China ZBL09 HordeUpdate
```ini
Behavior = HordeUpdate ModuleTag_04A
  RubOffRadius = 150    ; if I am this close to a real hordesman, I will get to be an honorary hordesman
  UpdateRate = 1000     ; how often to recheck horde status (msec)
  Radius = 75           ; how close other units must be to us to count towards our horde-ness (~30 feet or so)
End
```

### Example 3: China Tank Hunter HordeUpdate
```ini
Behavior = HordeUpdate ModuleTag_04
  RubOffRadius = 60    ; if I am this close to a real hordesman, I will get to be an honorary hordesman
  UpdateRate = 1000    ; how often to recheck horde status (msec)
  Radius = 50          ; how close other units must be to us to count towards our horde-ness (~30 feet or so)
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/HordeUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/HordeUpdate.cpp)
