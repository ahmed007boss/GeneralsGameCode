# PoisonedBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

PoisonedBehavior provides poison effect functionality for objects that can apply or suffer from poison damage over time.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by objects that can poison enemies or are affected by poison effects, such as chemical weapons or poisoned units.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA AT Site Poisoned Behavior
```ini
Behavior = PoisonedBehavior ModuleTag_12
  PoisonDamageInterval = 100  ; Every this many msec I will retake the poison damage dealt me...
  PoisonDuration = 3000       ; ... for this long after last hit by poison damage
End
```

### Example 2: GLA Stinger Site Poisoned Behavior
```ini
Behavior = PoisonedBehavior ModuleTag_09
  PoisonDamageInterval = 100  ; Every this many msec I will retake the poison damage dealt me...
  PoisonDuration = 3000       ; ... for this long after last hit by poison damage
End
```

### Example 3: GLA Fortress Turret Poisoned Behavior (Commented)
```ini
; Behavior = PoisonedBehavior ModuleTag_09
;   PoisonDamageInterval = 100  ; Every this many msec I will retake the poison damage dealt me...
;   PoisonDuration = 3000       ; ... for this long after last hit by poison damage
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/PoisonedBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/PoisonedBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/PoisonedBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/PoisonedBehavior.cpp)
