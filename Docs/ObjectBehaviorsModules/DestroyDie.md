# DestroyDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DestroyDie provides standard destruction death mechanics for objects.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that need standard destruction death effects and mechanics.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Scout Van Destroy Die
```ini
Behavior = DestroyDie DeathTag_02
  DeathTypes = NONE +CRUSHED +SPLATTED
End
```

### Example 2: GLA Airfield Destroy Die
```ini
Behavior             = DestroyDie ModuleTag_15
  ;nothing
End
```

### Example 3: GLA Artillery Bunker Destroy Die
```ini
Behavior = DestroyDie ModuleTag_322
  ; nothing
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/DestroyDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/DestroyDie.cpp)
