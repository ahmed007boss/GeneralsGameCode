# FireWeaponCollide

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireWeaponCollide provides collision behavior for objects that can fire weapons when colliding with targets.

**Base Class:** [`CollideModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h)

## Usage

Used by objects that need to fire weapons upon collision, such as ramming units or collision-based weapons.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Dushka Nest Remove Gunner
```ini
Behavior = FireWeaponCollide ModuleTag_RemoveGunner01
  CollideWeapon = StingerSiteDeathConcussion
  RequiredStatus = SOLD
End
```

### Example 2: Command Center Kill Trade Objects
```ini
Behavior = FireWeaponCollide ModuleTag_KillTradeObjects01
  CollideWeapon = GenericBuildingCollisionWeapon
  RequiredStatus = SOLD
End
```

### Example 3: Command Truck Deploy Marker
```ini
Behavior = FireWeaponCollide ModuleTag_DeployMarkerDecal01
  CollideWeapon = DeployMarkerWeapon
  RequiredStatus = DEPLOYED
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/FireWeaponCollide.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/FireWeaponCollide.cpp)
