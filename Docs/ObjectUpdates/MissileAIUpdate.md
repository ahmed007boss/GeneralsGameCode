# MissileAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

MissileAIUpdate provides AI update functionality for missile and projectile systems.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h), [`ProjectileUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/MissileAIUpdate.h)

## Usage

Used by missiles and projectiles to handle AI-driven flight paths, targeting, and guidance systems.

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
Behavior = MissileAIUpdate ModuleTag_05
  TryToFollowTarget       = Yes 
  FuelLifetime            = 99999
  UseWeaponSpeed          = Yes
End
```

### Example 2
```ini
Behavior = MissileAIUpdate ModuleTag_07
  DetonateCallsKill = Yes
  TryToFollowTarget = Yes
  FuelLifetime = 2333
End
```

### Example 3
```ini
Behavior = MissileAIUpdate ModuleTag_04
  DetonateCallsKill = Yes
  TryToFollowTarget       = No
  FuelLifetime        = 9999
End
```

*Examples will be added when this page is completed.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/MissileAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/MissileAIUpdate.cpp)
