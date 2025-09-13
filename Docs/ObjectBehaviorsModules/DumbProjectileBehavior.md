# DumbProjectileBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DumbProjectileBehavior provides behavior for unguided projectiles that follow ballistic trajectories without active guidance systems.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`ProjectileUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DumbProjectileBehavior.h)

## Usage

Used by projectile objects that need to follow simple ballistic physics without homing or guidance capabilities.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Dumb Projectile Module 06
```ini
Behavior = DumbProjectileBehavior ModuleTag_06
  DetonateCallsKill = Yes
  FirstHeight = 10 ; Height of Bezier control points above highest intervening terrain
  SecondHeight = 33
  FirstPercentIndent = 50% ; Percentage of shot distance control points are placed
  SecondPercentIndent = 75%
  FlightPathAdjustDistPerSecond   = 99 ; Can allow a max speed this can attempt to follow a target. Units are their velocity we can tag.
End
```

### Example 2: Weapon Object Dumb Projectile Module 04
```ini
Behavior = DumbProjectileBehavior ModuleTag_04
  DetonateCallsKill = Yes
  FirstHeight = 33 ; Height of Bezier control points above highest intervening terrain
  SecondHeight = 133
  FirstPercentIndent = 50% ; Percentage of shot distance control points are placed
  SecondPercentIndent = 75%
  FlightPathAdjustDistPerSecond   = 99 ; Can allow a max speed this can attempt to follow a target. Units are their velocity we can tag.
End
```

### Example 3: Weapon Object Dumb Projectile Module 03
```ini
Behavior = DumbProjectileBehavior ModuleTag_03
  DetonateCallsKill = Yes
  FirstHeight = 33 ; Height of Bezier control points above highest intervening terrain
  SecondHeight = 133
  FirstPercentIndent = 50% ; Percentage of shot distance control points are placed
  SecondPercentIndent = 75%
  FlightPathAdjustDistPerSecond   = 99 ; Can allow a max speed this can attempt to follow a target. Units are their velocity we can tag.
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DumbProjectileBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DumbProjectileBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/DumbProjectileBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/DumbProjectileBehavior.cpp)
