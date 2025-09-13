# GenerateMinefieldBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

GenerateMinefieldBehavior provides functionality for generating minefields around objects or at specific locations.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can create minefields, such as mine-laying vehicles or special minefield generators.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Generate Minefield
```ini
Behavior = GenerateMinefieldBehavior ModuleTag_05
  MineName                = ChinaClusterMine
  DistanceAroundObject    = 80
  GenerateOnlyOnDeath     = Yes
  SmartBorder             = Yes
  SmartBorderSkipInterior = No
  AlwaysCircular          = Yes
End
```

### Example 2: China War Factory Generate Minefield
```ini
Behavior = GenerateMinefieldBehavior     ModuleTag_16
  MineName                = ChinaClusterMine
  DistanceAroundObject    = 80
  GenerateOnlyOnDeath     = Yes
  SmartBorder             = Yes
  SmartBorderSkipInterior = No
  AlwaysCircular          = Yes
End
```

### Example 3: China Barracks Generate Minefield
```ini
Behavior = GenerateMinefieldBehavior     ModuleTag_12
  MineName                = ChinaClusterMine
  DistanceAroundObject    = 80
  GenerateOnlyOnDeath     = Yes
  SmartBorder             = Yes
  SmartBorderSkipInterior = No
  AlwaysCircular          = Yes
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/GenerateMinefieldBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/GenerateMinefieldBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/GenerateMinefieldBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/GenerateMinefieldBehavior.cpp)
