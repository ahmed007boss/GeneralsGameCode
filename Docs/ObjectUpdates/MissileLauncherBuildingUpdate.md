# MissileLauncherBuildingUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

MissileLauncherBuildingUpdate provides missile launcher building functionality for structures that can launch missiles.

**Base Class:** [`SpecialPowerUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerUpdateModule.h)

## Usage

Used by missile launcher buildings to handle missile launch operations, targeting, and building-specific mechanics.

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
Behavior = MissileLauncherBuildingUpdate ModuleTag_11
  SpecialPowerTemplate = SuperweaponShtora
  DoorOpenTime         = 1000
  DoorWaitOpenTime     = 1000
End
```

### Example 2
```ini
Behavior = MissileLauncherBuildingUpdate ModuleTag_09
  SpecialPowerTemplate = SuperweaponNeutronMissile
  DoorOpenTime         = 8000
  DoorWaitOpenTime     = 2000
End
```

### Example 3
```ini
Behavior = MissileLauncherBuildingUpdate ModuleTag_18
  SpecialPowerTemplate = SpecialAbilityGuardianShield
  DoorOpenTime         = 1
  DoorWaitOpenTime     = 1
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/MissileLauncherBuildingUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/MissileLauncherBuildingUpdate.cpp)
