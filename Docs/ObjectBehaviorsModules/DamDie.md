# DamDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DamDie provides death mechanics for dam structures and their destruction effects.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by dam structures that have special death mechanics and destruction effects.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Civilian Building Dam Die
```ini
Behavior                 = CreateObjectDie ModuleTag_04
  CreationList      = OCL_DamDie
End
Behavior = DamDie ModuleTag_05
  ;nothing
End     ;Note, must be after create object die
```

### Example 2: Dam Structure Die
```ini
Behavior = DamDie ModuleTag_05
  ;nothing
End     ;Note, must be after create object die
```

### Example 3: Dam Die with Creation List
```ini
Behavior                 = CreateObjectDie ModuleTag_04
  CreationList      = OCL_DamDie
End
Behavior = DamDie ModuleTag_05
  ;nothing
End     ;Note, must be after create object die
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/DamDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/DamDie.cpp)
