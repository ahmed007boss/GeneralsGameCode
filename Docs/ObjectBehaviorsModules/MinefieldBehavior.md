# MinefieldBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

MinefieldBehavior manages minefield objects, including mine detection, detonation, and area control functionality.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`CollideModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by minefield objects to handle mine interactions, detection by enemy units, and minefield management.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Minefield Behavior
```ini
; this is a misleading name, since it's really single-Mine Behavior...
Behavior = MinefieldBehavior     ModuleTag_04
  DetonationWeapon            = StructureMineWeapon        ; what happens when we detonate
  DetonatedBy                 = ENEMIES
  ; we no longer want the "scoot" behavior. it looks funky with current art. (srj)
  ;ScootFromStartingPointTime  = 500
  RepeatDetonateMoveThresh    = 5.0
End
```

### Example 2: Weapon Object Minefield Behavior Alternative
```ini
Behavior = MinefieldBehavior     ModuleTag_04
  DetonationWeapon            = StructureMineWeapon        ; what happens when we detonate
  DetonatedBy                 = ENEMIES
  ; we no longer want the "scoot" behavior. it looks funky with current art. (srj)
  ;ScootFromStartingPointTime  = 500
  RepeatDetonateMoveThresh    = 5.0
End
```

### Example 3: Weapon Object Minefield Behavior Third
```ini
Behavior = MinefieldBehavior     ModuleTag_04
  DetonationWeapon            = StructureMineWeapon        ; what happens when we detonate
  DetonatedBy                 = ENEMIES
  ; we no longer want the "scoot" behavior. it looks funky with current art. (srj)
  ;ScootFromStartingPointTime  = 500
  RepeatDetonateMoveThresh    = 5.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/MinefieldBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/MinefieldBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/MinefieldBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/MinefieldBehavior.cpp)
