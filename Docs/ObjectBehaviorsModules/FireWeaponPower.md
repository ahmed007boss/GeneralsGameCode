# FireWeaponPower

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireWeaponPower provides special power functionality for firing weapons as special abilities.

**Base Class:** [`SpecialPowerModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)

## Usage

Used by objects that can fire weapons as special powers or special attacks.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America Misc Unit Fire Weapon Power
```ini
Behavior = FireWeaponPower ModuleTag_FireWeapon01
  SpecialPowerTemplate = SpecialPowerBattleshipBombardment
  ;Automatically reloads weapons immediately upon trigger, then fires multiple weapon slots.
  MaxShotsToFire    = 3
End
```

### Example 2: America Misc Unit Fire Weapon Power Alternative
```ini
Behavior = FireWeaponPower ModuleTag_FireWeapon01
  SpecialPowerTemplate = SpecialPowerBattleshipBombardment
  ;Automatically reloads weapons immediately upon trigger, then fires multiple weapon slots.
  MaxShotsToFire    = 3
End
```

### Example 3: America Misc Unit Fire Weapon Power Third
```ini
Behavior = FireWeaponPower ModuleTag_FireWeapon01
  SpecialPowerTemplate = SpecialPowerBattleshipBombardment
  ;Automatically reloads weapons immediately upon trigger, then fires multiple weapon slots.
  MaxShotsToFire    = 3
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/FireWeaponPower.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/FireWeaponPower.cpp)
