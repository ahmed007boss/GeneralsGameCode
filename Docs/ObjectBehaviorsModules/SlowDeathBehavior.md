# SlowDeathBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SlowDeathBehavior provides extended death sequences for objects, allowing for complex death animations and effects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h), [`SlowDeathBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlowDeathBehavior.h)

## Usage

Used by objects that need elaborate death sequences with multiple phases, animations, and special effects.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Scout Van Slow Death Behavior
```ini
;Deaths-------------------------------------------------------------
Behavior = SlowDeathBehavior  DeathTag_01
  DeathTypes = ALL -CRUSHED -SPLATTED -POISONED -POISONED_BETA -EXTRA_8
  FX = INITIAL FX_BigTruckDeathFX
  FX = FINAL FX_BuggyNewDeathExplosion
  OCL = FINAL OCL_RadarVanDeathEffect
End
```

### Example 2: GLA AT Site Slow Death Behavior
```ini
Behavior = SlowDeathBehavior DeathTag_01
  DeathTypes = ALL -CRUSHED -SPLATTED -POISONED -POISONED_BETA -EXTRA_8
  FX = INITIAL FX_BigTruckDeathFX
  FX = FINAL FX_BuggyNewDeathExplosion
  OCL = FINAL OCL_RadarVanDeathEffect
End
```

### Example 3: GLA Scout Van Slow Death Behavior Alternative
```ini
Behavior = SlowDeathBehavior DeathTag_05
  DeathTypes = ALL -CRUSHED -SPLATTED -POISONED -POISONED_BETA -EXTRA_8
  FX = INITIAL FX_BigTruckDeathFX
  FX = FINAL FX_BuggyNewDeathExplosion
  OCL = FINAL OCL_RadarVanDeathEffect
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlowDeathBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlowDeathBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/SlowDeathBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/SlowDeathBehavior.cpp)
