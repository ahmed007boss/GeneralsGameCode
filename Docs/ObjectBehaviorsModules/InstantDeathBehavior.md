# InstantDeathBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

InstantDeathBehavior provides immediate death functionality for objects without complex death sequences.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that need to die instantly without special effects or death animations.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Radar Station Instant Death
```ini
Behavior = InstantDeathBehavior ModuleTag_Death03
  OCL = OCL_SmallStructureDebris
  FX = FX_StructureSmallDeath
End
```

### Example 2: GLA Special Object Instant Death
```ini
Behavior = InstantDeathBehavior DeathTag_01
  OCL = OCL_SmallStructureDebris
  FX = FX_StructureSmallDeath
End
```

### Example 3: GLA AT Site Instant Death
```ini
Behavior = InstantDeathBehavior ModuleTag_Death01
  OCL = OCL_SmallStructureDebris
  FX = FX_StructureSmallDeath
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/InstantDeathBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/InstantDeathBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/InstantDeathBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/InstantDeathBehavior.cpp)
