# EMPUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

EMPUpdate provides electromagnetic pulse (EMP) functionality for objects that can create or be affected by EMP effects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can create EMP effects or are affected by electromagnetic pulse attacks.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Object EMPUpdate
```ini
Behavior = EMPUpdate ModuleTag_03
  DisabledDuration    = 0
  Lifetime            = 1500
  EffectRadius        = 0.01
End
```

### Example 2: System Object EMPUpdate with Disable Duration
```ini
Behavior = EMPUpdate ModuleTag_02
  DisabledDuration    = 7000
  Lifetime            = 750
  StartFadeTime       = 400
End
```

### Example 3: System Object EMPUpdate with Medium Duration
```ini
Behavior = EMPUpdate ModuleTag_01
  DisabledDuration    = 3000
  Lifetime            = 3000
  StartFadeTime       = 300
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/EMPUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/EMPUpdate.cpp)
