# StealthUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

StealthUpdate provides stealth functionality for objects that can become stealthy or invisible.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can enter stealth mode, become invisible, or have stealth-related abilities.

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
Behavior = StealthUpdate ModuleTag_GPSStealth01
  StealthDelay                = 2000 ; msec
  StealthForbiddenConditions  = FIRING_PRIMARY FIRING_SECONDARY FIRING_TERTIARY RIDERS_ATTACKING
  InnateStealth               = Yes
End
```

### Example 2
```ini
Behavior = StealthUpdate ModuleStealth_01
  StealthDelay                = 500 ; msec
  StealthForbiddenConditions  = MOVING
  InnateStealth               = No ;Requires upgrade first
End
```

### Example 3
```ini
Behavior = StealthUpdate ModuleStealth_GPSScramblerGenericStealthModule
  StealthDelay                = 2000 ; msec
  InnateStealth               = Yes
  StealthForbiddenConditions  = ATTACKING USING_ABILITY
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/StealthUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/StealthUpdate.cpp)
