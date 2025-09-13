# WeaponBonusUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

WeaponBonusUpdate provides weapon bonus functionality for objects that can provide weapon bonuses or enhancements.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can provide weapon bonuses, enhance weapon capabilities, or manage weapon enhancement systems.

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
Behavior = WeaponBonusUpdate ModuleTag_02
  RequiredAffectKindOf = CAN_ATTACK ; Must be set
  ForbiddenAffectKindOf = STRUCTURE ; Must be clear
  BonusDuration = 15000             ; How long effect lasts
```

### Example 2
```ini
Behavior = WeaponBonusUpdate ModuleTag_04
  RequiredAffectKindOf = INFANTRY
  ForbiddenAffectKindOf = AIRCRAFT VEHICLE
  BonusDuration = 5000
```

### Example 3
```ini
Behavior = WeaponBonusUpdate ModuleTag_03
  BonusDuration = 15000
  ;BonusDelay = 1000
  BonusRange = 20
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/WeaponBonusUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/WeaponBonusUpdate.cpp)
