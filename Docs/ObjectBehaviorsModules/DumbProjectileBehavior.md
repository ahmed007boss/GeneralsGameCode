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

The following INI properties are parsed by this module's `ModuleData`. All are optional unless noted.

- **`MaxLifespan`**
  - **Type**: `UnsignedInt` (duration)
  - **Description**: Maximum lifetime before forced detonation.
  - **Default**: 10 seconds.
  - **Example**: `MaxLifespan = 3000`

- **`TumbleRandomly`**
  - **Type**: `Bool`
  - **Description**: If `Yes`, applies random angular rates to the projectile (pitch, yaw, roll) during flight.
  - **Example**: `TumbleRandomly = Yes`

- **`DetonateCallsKill`**
  - **Type**: `Bool`
  - **Description**: If `Yes`, uses a kill/damage path with `DEATH_DETONATED` instead of immediate destroy on detonation.
  - **Example**: `DetonateCallsKill = Yes`

- **`OrientToFlightPath`**
  - **Type**: `Bool`
  - **Description**: If `Yes`, orients the projectile model to face its Bezier flight path rather than only setting position.
  - **Example**: `OrientToFlightPath = Yes`

- **`FirstHeight`**
  - **Type**: `Real`
  - **Description**: Height offset above highest intervening terrain for the first Bezier control point.
  - **Example**: `FirstHeight = 10.0`

- **`SecondHeight`**
  - **Type**: `Real`
  - **Description**: Height offset above highest intervening terrain for the second Bezier control point.
  - **Example**: `SecondHeight = 30.0`

- **`FirstPercentIndent`**
  - **Type**: `Percent -> Real`
  - **Description**: Fraction along start→target line for the first control point (0.0–1.0 after parsing).
  - **Example**: `FirstPercentIndent = 50%`

- **`SecondPercentIndent`**
  - **Type**: `Percent -> Real`
  - **Description**: Fraction along start→target line for the second control point.
  - **Example**: `SecondPercentIndent = 75%`

- **`GarrisonHitKillRequiredKindOf`**
  - **Type**: `KindOfMaskType`
  - **Description**: Restricts which garrisoned units can be killed when colliding with a garrisonable building.
  - **Example**: `GarrisonHitKillRequiredKindOf = INFANTRY`

- **`GarrisonHitKillForbiddenKindOf`**
  - **Type**: `KindOfMaskType`
  - **Description**: KindOf mask that must NOT be present on garrisoned units to be killed.
  - **Example**: `GarrisonHitKillForbiddenKindOf = HERO`

- **`GarrisonHitKillCount`**
  - **Type**: `UnsignedInt`
  - **Description**: Maximum number of garrisoned units to instantly kill upon collision when conditions are met.
  - **Example**: `GarrisonHitKillCount = 3`

- **`GarrisonHitKillFX`**
  - **Type**: `FXList`
  - **Description**: FX to play at the building center when one or more garrisoned units are killed.
  - **Example**: `GarrisonHitKillFX = FX_ClearGarrison`

- **`FlightPathAdjustDistPerSecond`**
  - **Type**: `Real` (velocity)
  - **Description**: Max distance per second the projectile's target point can adjust to track a moving victim; enables limited in-flight retargeting.
  - **Example**: `FlightPathAdjustDistPerSecond = 100.0`

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
  TumbleRandomly = Yes
  OrientToFlightPath = Yes
  FirstHeight = 20
  SecondHeight = 60
  FirstPercentIndent = 40%
  SecondPercentIndent = 80%
  GarrisonHitKillRequiredKindOf = INFANTRY
  GarrisonHitKillForbiddenKindOf = HERO
  GarrisonHitKillCount = 2
  GarrisonHitKillFX = FX_ClearGarrison
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DumbProjectileBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DumbProjectileBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/DumbProjectileBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/DumbProjectileBehavior.cpp)

## Template

Ready-to-use template with all properties:

```ini
Behavior = DumbProjectileBehavior <ModuleTag_Projectile>
  MaxLifespan                   = 3000      ; Max lifetime before forced detonation (ms)
  TumbleRandomly                = No        ; Apply random angular rotation if Yes
  DetonateCallsKill             = No        ; Use kill path with DEATH_DETONATED on explode
  OrientToFlightPath            = Yes       ; Face along Bezier flight path

  FirstHeight                   = 10.0      ; Bezier control 1 height above highest terrain
  SecondHeight                  = 30.0      ; Bezier control 2 height above highest terrain
  FirstPercentIndent            = 50%       ; Control 1 along line start→target
  SecondPercentIndent           = 75%       ; Control 2 along line start→target

  GarrisonHitKillRequiredKindOf = INFANTRY  ; KindOf required for garrison kill
  GarrisonHitKillForbiddenKindOf= HERO      ; KindOf not allowed for garrison kill
  GarrisonHitKillCount          = 0         ; Max garrisoned units to kill on hit
  GarrisonHitKillFX             = FX_None   ; FX when garrison kills occur

  FlightPathAdjustDistPerSecond = 0.0       ; Max retarget distance per second during flight
End
```
