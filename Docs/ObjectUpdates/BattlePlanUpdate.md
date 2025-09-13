# BattlePlanUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BattlePlanUpdate provides battle plan functionality for objects that can execute complex battle strategies.

**Base Class:** [`SpecialPowerUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerUpdateModule.h)

## Usage

Used by objects that need to execute battle plans, coordinate attacks, and manage complex combat strategies.

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
Behavior = BattlePlanUpdate ModuleTag_14
  SpecialPowerTemplate              = SpecialAbilityChangeBattlePlans

  ;Transition Timings
  BombardmentPlanAnimationTime      = 7000
  HoldTheLinePlanAnimationTime      = 7000
  SearchAndDestroyPlanAnimationTime = 7000
  TransitionIdleTime                = 0

  ;Messages
  BombardmentMessageLabel      = MESSAGE:BattlePlanBombardmentInitiated
End
```

*Only one example of BattlePlanUpdate was found in the INI files.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/BattlePlanUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/BattlePlanUpdate.cpp)
