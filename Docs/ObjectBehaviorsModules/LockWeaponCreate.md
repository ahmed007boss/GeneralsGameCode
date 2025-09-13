# LockWeaponCreate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

LockWeaponCreate provides functionality for locking weapons when objects are created or under specific conditions.

**Base Class:** [`CreateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)

## Usage

Used by objects that need to lock weapons upon creation or when certain conditions are met.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA AT Site Lock Weapon Create
```ini
Behavior = LockWeaponCreate ModuleTag_13
  SlotToLock = PRIMARY
End
```

### Example 2: America CINE Unit Lock Weapon Create
```ini
Behavior = LockWeaponCreate ModuleTag_21
  SlotToLock = PRIMARY
End
```

### Example 3: GLA Stinger Soldier Lock Weapon Create
```ini
Behavior = LockWeaponCreate ModuleTag_Lock
  SlotToLock = PRIMARY
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/LockWeaponCreate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/LockWeaponCreate.cpp)
