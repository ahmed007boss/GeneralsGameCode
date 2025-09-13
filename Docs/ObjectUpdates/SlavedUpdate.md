# SlavedUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SlavedUpdate provides slaved functionality for objects that are controlled by or slaved to other objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`SlavedUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlavedUpdate.h)

## Usage

Used by objects that are slaved to other objects, such as turrets, weapons, or controlled units.

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
Behavior = SlavedUpdate ModuleTag_064
End
```

### Example 2
```ini
Behavior = SlavedUpdate ModuleTag_07
  GuardMaxRange = 1 ;How far away from master I'm allowed when master is idle (doesn't wander)
  GuardWanderRange = 1 ;How far away I'm allowed to wander from master while guarding.
  AttackRange = 1 ;How far away from master I'm allowed when master is attacking a target.
End
```

### Example 3
```ini
Behavior = SlavedUpdate ModuleTag_05
  StayOnSameLayerAsMaster = Yes
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlavedUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SlavedUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SlavedUpdate.cpp)
