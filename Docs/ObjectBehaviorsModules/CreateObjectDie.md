# CreateObjectDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CreateObjectDie provides functionality for creating other objects when objects die or are destroyed.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that can create other objects upon death, such as spawning units or special object generators.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Scout Van Create Object
```ini
Behavior = CreateObjectDie DeathTag_04
  DeathTypes = NONE +CRUSHED +SPLATTED
  CreationList = OCL_RadarVanDeathEffect
End
```

### Example 2: GLA Airfield Create Object
```ini
Behavior             = CreateObjectDie ModuleTag_18
  CreationList  = OCL_ABPowerPlantExplode
End
```

### Example 3: GLA Artillery Bunker Create Object
```ini
Behavior = CreateObjectDie ModuleTag_323
  CreationList = OCL_ArtilleryBunkerExplode
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/CreateObjectDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/CreateObjectDie.cpp)
