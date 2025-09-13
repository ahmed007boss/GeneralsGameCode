# CreateCrateDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CreateCrateDie provides functionality for creating crates when objects die or are destroyed.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that can create crates upon death, such as supply units or special crate-generating objects.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Jammer Van Create Crate
```ini
Behavior = CreateCrateDie ModuleTag_06
  CrateData = SalvageCrateData
  ;CrateData = EliteTankCrateData
  ;CrateData = HeroicTankCrateData
End
```

### Example 2: GLA SURN Scrambler Create Crate
```ini
Behavior = CreateCrateDie ModuleTag_08
  CrateData = SalvageCrateData
  ;CrateData = EliteTankCrateData
  ;CrateData = HeroicTankCrateData
End
```

### Example 3: GLA SURN Create Crate
```ini
Behavior = CreateCrateDie ModuleTag_09
  CrateData = SalvageCrateData
  ;CrateData = EliteTankCrateData
  ;CrateData = HeroicTankCrateData
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/CreateCrateDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/CreateCrateDie.cpp)
