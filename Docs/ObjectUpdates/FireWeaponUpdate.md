# FireWeaponUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireWeaponUpdate provides weapon firing functionality for objects that can fire weapons.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to fire weapons, manage weapon cooldowns, and handle weapon firing mechanics.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Special Objects FireWeaponUpdate
```ini
Behavior = FireWeaponUpdate ModuleTag_StealthField02
  Weapon = GPSScramblerSelfWeapon
End
```

### Example 2: GLA Command Center FireWeaponUpdate
```ini
Behavior = FireWeaponUpdate ModuleTag_20
  Weapon = GLASpawnSpecialPowerObject
End
```

### Example 3: GLA Scrambler Station FireWeaponUpdate
```ini
Behavior = FireWeaponUpdate ModuleTag_StealthField01
  Weapon = GPSScramblerStationWeapon
  ExclusiveWeaponDelay = 1000
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FireWeaponUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FireWeaponUpdate.cpp)
