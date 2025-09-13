# FXListDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FXListDie provides death mechanics with visual effects lists when objects die.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that need complex visual effects when they die or are destroyed.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Scout Van FX List Die
```ini
; A crushing defeat
Behavior = FXListDie DeathTag_03
  DeathTypes = NONE +CRUSHED +SPLATTED
  DeathFX = FX_CarCrush
End
```

### Example 2: GLA Airfield FX List Die
```ini
Behavior             = FXListDie ModuleTag_19
  DeathFX       = FX_StructureMediumDeath
End
```

### Example 3: GLA Artillery Bunker FX List Die
```ini
Behavior = FXListDie ModuleTag_324
  DeathFX = FX_StructureSmallDeath
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/FXListDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/FXListDie.cpp)
