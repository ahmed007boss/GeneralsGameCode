# NeutronMissileUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

NeutronMissileUpdate provides neutron missile functionality for objects that can create or use neutron missile effects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h), [`ProjectileUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/NeutronMissileUpdate.h)

## Usage

Used by objects that can create neutron missiles, neutron weapons, or neutron-based special effects.

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
Behavior = NeutronMissileUpdate ModuleTag_03
  DistanceToTravelBeforeTurning = 600       ; goes straight up a long ways first
  MaxTurnRate = 7200                        ; huge, since it turns off-camera
  ForwardDamping = 0.1
End
```

### Example 2
```ini
Behavior = NeutronMissileUpdate ModuleTag_07
  DistanceToTravelBeforeTurning = 600       ; goes straight up a long ways first
  MaxTurnRate = 7200                        ; huge, since it turns off-camera
  ForwardDamping = 0.1
End
```

*Only 2 examples of NeutronMissileUpdate were found in the INI files, both identical.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/NeutronMissileUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/NeutronMissileUpdate.cpp)
