### DumbProjectileBehavior — Bezier-curve projectile motion and detonation logic

Class: `DumbProjectileBehavior` — Update module that controls a projectile following a Bezier-curve path with optional tumbling/orientation and special garrison hit-kill behavior.

## Table of Contents
- Overview
- Usage
- Properties
  - General Settings
  - Flight Path Settings
  - Garrison Hit/Kill Settings
- Enums
- Examples
- Template
- Cross-References & Source Links

## Overview

`DumbProjectileBehavior` drives projectile objects along a precomputed Bezier flight path between launch and target, with configurable curve control points, optional random tumbling, runtime re-aiming, and detonation handling. It can optionally kill a limited number of garrisoned occupants in a target structure with an FX upon impact.

- Used as: object behavior module (inside an `Object`)
- Base classes: `UpdateModule`
- GMX vs vanilla: Matches Zero Hour behavior; no GMX-specific changes identified.

## Usage

Add inside an object’s `Behavior` list:

```
Behavior = DumbProjectileBehavior ModuleTag_Projectile
  MaxLifespan                      = 5000
  TumbleRandomly                   = No
  DetonateCallsKill               = Yes
  OrientToFlightPath              = Yes

  FirstHeight                     = 25.0
  SecondHeight                    = 10.0
  FirstPercentIndent              = 0.25%
  SecondPercentIndent             = 0.75%

  GarrisonHitKillRequiredKindOf   = INFANTRY
  GarrisonHitKillForbiddenKindOf  = HERO
  GarrisonHitKillCount            = 2
  GarrisonHitKillFX               = FX_GarrisonHit

  FlightPathAdjustDistPerSecond   = 30.0
End
```

The module becomes active when the object is created and a projectile is launched via a weapon. Detonation is handled automatically on collision or lifespan expiry.

## Properties

All properties below are parsed in `buildFieldParse` for `DumbProjectileBehaviorModuleData` and inherited base parsers.

### General Settings

#### `MaxLifespan` (v1.04)
- Type: UnsignedInt (milliseconds)
- Default: `10 * LOGICFRAMES_PER_SECOND` (internal default; roughly 10 seconds at 30 FPS)
- Description: Maximum simulated lifetime. Projectile detonates when exceeded.

#### `TumbleRandomly` (v1.04)
- Type: Bool
- Default: No
- Description: Applies random pitch/yaw/roll rates to the projectile’s `PhysicsBehavior` while in flight.

#### `DetonateCallsKill` (v1.04)
- Type: Bool
- Default: No
- Description: On detonation, apply unresistable damage equal to max health with `DEATH_DETONATED` instead of standard destroy.

#### `OrientToFlightPath` (v1.04)
- Type: Bool
- Default: Yes
- Description: Orients object’s transform to current segment direction while following the Bezier path. Ignored if tumbling.

### Flight Path Settings

#### `FirstHeight` (v1.04)
- Type: Real
- Default: 0.0
- Description: Offset above highest intervening terrain for first Bezier control point’s Z.

#### `SecondHeight` (v1.04)
- Type: Real
- Default: 0.0
- Description: Offset above highest intervening terrain for second Bezier control point’s Z.

#### `FirstPercentIndent` (v1.04)
- Type: Real (parsed from percent, e.g., `0.25%` -> `0.0025`)
- Default: 0.0
- Description: Fraction of distance from start to target for first control point along XY line.

#### `SecondPercentIndent` (v1.04)
- Type: Real (parsed from percent)
- Default: 0.0
- Description: Fraction of distance from start to target for second control point along XY line.

#### `FlightPathAdjustDistPerSecond` (v1.04)
- Type: Real (velocity)
- Default: 0.0
- Description: Per-second limit on how much the end point can adjust toward a moving target each frame. Enables limited in-flight retargeting.

### Garrison Hit/Kill Settings

#### `GarrisonHitKillRequiredKindOf` (v1.04)
- Type: KindOfMaskType (see Object KindOf docs)
- Default: None (mask clear)
- Description: KindOf bits occupants must have to be eligible for garrison kill.

#### `GarrisonHitKillForbiddenKindOf` (v1.04)
- Type: KindOfMaskType
- Default: None
- Description: KindOf bits that exclude occupants from garrison kill.

#### `GarrisonHitKillCount` (v1.04)
- Type: UnsignedInt
- Default: 0
- Description: Max number of garrisoned occupants to kill on impact. 0 disables behavior.

#### `GarrisonHitKillFX` (v1.04)
- Type: FXList
- Default: None
- Description: FX to play at the building center if at least one occupant is killed.

## Enums

- KindOfMaskType: See `KindOfMaskType Values` in `Object.md` / engine KindOf documentation.

## Examples

### Simple arc with orientation
```
Behavior = DumbProjectileBehavior ModuleTag_Arc
  MaxLifespan                    = 4000
  TumbleRandomly                 = No
  DetonateCallsKill             = No
  OrientToFlightPath            = Yes
  FirstHeight                   = 20.0
  SecondHeight                  = 20.0
  FirstPercentIndent            = 0.20%
  SecondPercentIndent           = 0.80%
  FlightPathAdjustDistPerSecond = 0.0
End
```

### Flash-bang vs garrison
```
Behavior = DumbProjectileBehavior ModuleTag_Flashbang
  MaxLifespan                     = 2500
  TumbleRandomly                  = No
  DetonateCallsKill              = No
  OrientToFlightPath             = Yes
  FirstHeight                    = 10.0
  SecondHeight                   = 10.0
  FirstPercentIndent             = 0.15%
  SecondPercentIndent            = 0.85%
  GarrisonHitKillRequiredKindOf  = INFANTRY
  GarrisonHitKillForbiddenKindOf = HERO
  GarrisonHitKillCount           = 1
  GarrisonHitKillFX              = FX_GarrisonStun
  FlightPathAdjustDistPerSecond  = 10.0
End
```

## Template

```
; Template for DumbProjectileBehavior
; -----------------------------------
; General Settings
MaxLifespan = 5000                ; // max life before forced detonation (ms) *(v1.04)*
TumbleRandomly = No                ; // random spin using physics *(v1.04)*
DetonateCallsKill = No             ; // use DEATH_DETONATED kill vs destroy *(v1.04)*
OrientToFlightPath = Yes           ; // face along Bezier direction *(v1.04)*

; Flight Path Settings
FirstHeight = 25.0                 ; // control point 1 Z offset above terrain *(v1.04)*
SecondHeight = 10.0                ; // control point 2 Z offset above terrain *(v1.04)*
FirstPercentIndent = 0.25%         ; // control point 1 XY fraction toward target *(v1.04)*
SecondPercentIndent = 0.75%        ; // control point 2 XY fraction toward target *(v1.04)*
FlightPathAdjustDistPerSecond = 0  ; // max target-follow distance per second *(v1.04)*

; Garrison Hit/Kill Settings
GarrisonHitKillRequiredKindOf =    ; // KindOf required for occupants *(v1.04)*
GarrisonHitKillForbiddenKindOf =   ; // KindOf forbidden for occupants *(v1.04)*
GarrisonHitKillCount = 0           ; // occupants to kill on impact *(v1.04)*
GarrisonHitKillFX =                ; // FXList played if any killed *(v1.04)*
```

## Cross-References & Source Links

- Headers: `GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DumbProjectileBehavior.h`
- Source: `Generals/Code/GameEngine/Source/GameLogic/Object/Behavior/DumbProjectileBehavior.cpp`
- Base: `UpdateModule` (see `GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`)
- Related: `Weapon` (for speed, min speed, range scaling), `KindOf` documentation.

