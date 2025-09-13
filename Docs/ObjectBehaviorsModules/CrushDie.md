# CrushDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CrushDie provides death mechanics for objects that can be crushed or destroyed by crushing forces.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that can be crushed by larger units, vehicles, or structures.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Civilian Unit Crush Die
```ini
Behavior = CrushDie ModuleTag_04
  DeathTypes = NONE +CRUSHED +SPLATTED
  TotalCrushSound     = CarAlarm
  BackEndCrushSound   = CarAlarm
  FrontEndCrushSound  = CarAlarm
  TotalCrushSoundPercent    = 50   
  BackEndCrushSoundPercent  = 50
  FrontEndCrushSoundPercent = 50
End
```

### Example 2: Civilian Unit Crush Die Alternative
```ini
Behavior = CrushDie ModuleTag_04
  DeathTypes = NONE +CRUSHED +SPLATTED
  TotalCrushSound     = CarAlarm
  BackEndCrushSound   = CarAlarm
  FrontEndCrushSound  = CarAlarm
  TotalCrushSoundPercent    = 50   
  BackEndCrushSoundPercent  = 50
  FrontEndCrushSoundPercent = 50
End
```

### Example 3: Civilian Unit Crush Die Module 05
```ini
Behavior = CrushDie ModuleTag_05
  DeathTypes = NONE +CRUSHED +SPLATTED
  TotalCrushSound     = CarAlarm
  BackEndCrushSound   = CarAlarm
  FrontEndCrushSound  = CarAlarm
  TotalCrushSoundPercent    = 50   
  BackEndCrushSoundPercent  = 50
  FrontEndCrushSoundPercent = 50
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/CrushDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/CrushDie.cpp)
