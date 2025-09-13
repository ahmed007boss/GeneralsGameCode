# AutoHealBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

AutoHealBehavior provides automatic healing functionality for objects, allowing them to heal themselves or nearby friendly units over time.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by objects that need automatic healing capabilities, such as medical buildings or units with regenerative abilities.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Scout Van Auto Heal
```ini
Behavior = AutoHealBehavior Upgrade_01
  HealingAmount = 3
  HealingDelay = 1000 ; msec
  TriggeredBy = Upgrade_GLAJunkRepair
End
```

### Example 2: Scrap Yard Auto Heal
```ini
Behavior = AutoHealBehavior ModuleTag_JunkInTheTrunk01
  HealingAmount = 2
  HealingDelay = 1000 ; msec
  StartsActive = No
  TriggeredBy = Upgrade_GLAJunkRepair
End
```

### Example 3: Dushka Nest Auto Heal (Commented)
```ini
; Behavior = AutoHealBehavior ModuleTag_Fortified04
;   TriggeredBy = Upgrade_GLAFortifiedStructure
;   ConflictsWith = Upgrade_GLACamoNetting
;   HealingAmount = 10.0
;   HealingDelay = 1.0
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AutoHealBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AutoHealBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/AutoHealBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/AutoHealBehavior.cpp)
