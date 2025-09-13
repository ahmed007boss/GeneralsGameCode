# FireWeaponWhenDamagedBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireWeaponWhenDamagedBehavior allows objects to automatically fire weapons when they receive damage.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by objects that need reactive combat capabilities, such as defensive structures or units that retaliate when attacked.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Jammer Van Fire Weapon When Damaged
```ini
Behavior = FireWeaponWhenDamagedBehavior ModuleTag_IronCrutain
  StartsActive = Yes
  ReactionWeaponPristine = IronCrutainDroneWeapon
  ReactionWeaponDamaged = IronCrutainDroneWeapon
  ReactionWeaponReallyDamaged = IronCrutainDroneWeapon
  ReactionWeaponRubble = IronCrutainDroneWeapon
  ReactionWeaponDamaged = IronCrutainDroneWeapon
End
```

### Example 2: GLA SURN Scrambler Fire Weapon When Damaged
```ini
Behavior = FireWeaponWhenDamagedBehavior ModuleTag_IronCrutain
  StartsActive = Yes
  ReactionWeaponPristine = IronCrutainDroneWeapon
  ReactionWeaponDamaged = IronCrutainDroneWeapon
  ReactionWeaponReallyDamaged = IronCrutainDroneWeapon
  ReactionWeaponRubble = IronCrutainDroneWeapon
  ReactionWeaponDamaged = IronCrutainDroneWeapon
End
```

### Example 3: GLA SURN Fire Weapon When Damaged
```ini
Behavior = FireWeaponWhenDamagedBehavior ModuleTag_IronCrutain
  StartsActive = Yes
  ReactionWeaponPristine = IronCrutainDroneWeapon
  ReactionWeaponDamaged = IronCrutainDroneWeapon
  ReactionWeaponReallyDamaged = IronCrutainDroneWeapon
  ReactionWeaponRubble = IronCrutainDroneWeapon
  ReactionWeaponDamaged = IronCrutainDroneWeapon
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/FireWeaponWhenDamagedBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/FireWeaponWhenDamagedBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDamagedBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDamagedBehavior.cpp)
