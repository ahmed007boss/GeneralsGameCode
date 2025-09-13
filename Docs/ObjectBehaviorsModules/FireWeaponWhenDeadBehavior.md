# FireWeaponWhenDeadBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireWeaponWhenDeadBehavior allows objects to fire weapons when they are destroyed or about to be destroyed.

**Base Class:** [`BehaviorModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that need to retaliate or cause damage even after death, such as explosive units or defensive structures.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Dushka Nest Fire Weapon When Dead
```ini
Behavior   = FireWeaponWhenDeadBehavior ModuleTag_RemoveGunner02
  DeathWeapon   = StingerSiteDeathConcussion
  StartsActive  = Yes
End
```

### Example 2: GLA AT Site Fire Weapon When Dead
```ini
Behavior = FireWeaponWhenDeadBehavior ModuleTag_Death03
  DeathWeapon   = StingerSiteDeathConcussion
  StartsActive  = Yes
End
```

### Example 3: GLA Stinger Site Fire Weapon When Dead
```ini
Behavior        = FireWeaponWhenDeadBehavior ModuleTag_12
  DeathWeapon   = StingerSiteDeathConcussion
  StartsActive  = Yes
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/FireWeaponWhenDeadBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/FireWeaponWhenDeadBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDeadBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDeadBehavior.cpp)
