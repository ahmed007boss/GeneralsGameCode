# BattleBusSlowDeathBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BattleBusSlowDeathBehavior provides specialized death behavior for Battle Bus units, allowing them to perform a dramatic "fake death" before the actual destruction.

**Base Class:** [`SlowDeathBehavior`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlowDeathBehavior.h)

## Usage

Used specifically by Battle Bus units to create cinematic death sequences where the bus is thrown into the air before landing and becoming disabled.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Battle Fortress Slow Death
```ini
Behavior = BattleBusSlowDeathBehavior  DeathTag_01
  DeathTypes = ALL -CRUSHED -SPLATTED -EXTRA_4 -POISONED -POISONED_BETA -EXTRA_8
  ModifierBonusPerOverkillPercent = 20%  ; negative means less likely to pick this in the face of much damage, positive means more likely
  ; Part the first, uses when killed the first time from non-system (unresistable) damage
  FXStartUndeath = FX_BigTruckDeathFX
  OCLStartUndeath = OCL_BattleBusStartUndeath
  FXHitGround = FX_ArmoredVehicleHitGround
  OCLHitGround = OCL_BattleBusHitGround
  PercentDamageToPassengers = 50%
  EmptyHulkDestructionDelay = 1000 ; If non-zero, msec of emptiness before we kill ourselves with Penalty damage
  ; Part the second, normal fields of a SlowDeathBehavior
  DestructionDelay = 0
End
```

### Example 2: Battle Bus Slow Death
```ini
Behavior = BattleBusSlowDeathBehavior  DeathTag_01
  DeathTypes = ALL -CRUSHED -SPLATTED -EXTRA_4 -POISONED -POISONED_BETA -EXTRA_8
  ModifierBonusPerOverkillPercent = 20%  ; negative means less likely to pick this in the face of much damage, positive means more likely
  ; Part the first, uses when killed the first time from non-system (unresistable) damage
  FXStartUndeath = FX_BigTruckDeathFX
  OCLStartUndeath = OCL_BattleBusStartUndeath
  FXHitGround = FX_ArmoredVehicleHitGround
  OCLHitGround = OCL_BattleBusHitGround
  PercentDamageToPassengers = 50%
  EmptyHulkDestructionDelay = 1000 ; If non-zero, msec of emptiness before we kill ourselves with Penalty damage
  ; Part the second, normal fields of a SlowDeathBehavior
  DestructionDelay = 0
End
```

### Example 3: CINE Unit Slow Death
```ini
Behavior = BattleBusSlowDeathBehavior  ModuleTag_08
  DeathTypes = ALL -CRUSHED -SPLATTED -EXTRA_4 -POISONED -POISONED_BETA -EXTRA_8
  ModifierBonusPerOverkillPercent = 20%  ; negative means less likely to pick this in the face of much damage, positive means more likely
  ; Part the first, uses when killed the first time from non-system (unresistable) damage
  FXStartUndeath = FX_BigTruckDeathFX
  OCLStartUndeath = OCL_BattleBusStartUndeath
  FXHitGround = FX_ArmoredVehicleHitGround
  OCLHitGround = OCL_BattleBusHitGround
  PercentDamageToPassengers = 50%
  EmptyHulkDestructionDelay = 1000 ; If non-zero, msec of emptiness before we kill ourselves with Penalty damage
  ; Part the second, normal fields of a SlowDeathBehavior
  DestructionDelay = 0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BattleBusSlowDeathBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BattleBusSlowDeathBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BattleBusSlowDeathBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BattleBusSlowDeathBehavior.cpp)
