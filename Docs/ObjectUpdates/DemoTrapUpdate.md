# DemoTrapUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DemoTrapUpdate provides demolition trap functionality for objects that can create explosive traps.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can create demolition traps, such as explosive devices or booby traps.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: China ECM Tank DemoTrapUpdate
```ini
Behavior = DemoTrapUpdate ModuleTag_04
  DefaultProximityMode      = Yes       ;If yes, defaults to proximity mode, otherwise defaults to manual.
  DetonationWeaponSlot      = PRIMARY   ;The slot the weapon is in when it detonates.
  ProximityModeWeaponSlot   = SECONDARY ;The slot proximity mode is determined by (bogus weapon)
End
```

### Example 2: Faction Building DemoTrapUpdate
```ini
Behavior = DemoTrapUpdate ModuleTag_04
  DefaultProximityMode      = Yes       ;If yes, defaults to proximity mode, otherwise defaults to manual.
  DetonationWeaponSlot      = PRIMARY   ;The slot the weapon is in when it detonates.
  ProximityModeWeaponSlot   = SECONDARY ;The slot proximity mode is determined by (bogus weapon)
End
```

*Only two examples of DemoTrapUpdate were found in the INI files.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DemoTrapUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DemoTrapUpdate.cpp)
