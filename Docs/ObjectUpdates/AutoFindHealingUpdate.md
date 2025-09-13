# AutoFindHealingUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

AutoFindHealingUpdate provides automatic healing search functionality for objects that can find and move to healing facilities.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to automatically find and move to healing facilities when damaged.

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
Behavior = AutoFindHealingUpdate   ModuleTag_05 ; This update will have the unit go to a healing station if injured. jba 
  ScanRate = 1000 ; once a second.
  ScanRange = 300 ;
  NeverHeal = 0.85 ;  don't heal if we are > 85% healthy.
  AlwaysHeal = 0.25 ; if we get below 25%, find healing right away.
End
```

### Example 2
```ini
Behavior = AutoFindHealingUpdate   ModuleTag_04 ; This update will have the unit go to a healing station if injured. jba 
  ScanRate = 1000 ; once a second.
  ScanRange = 300 ;
  NeverHeal = 0.85 ;  don't heal if we are > 85% healthy.
  AlwaysHeal = 0.25 ; if we get below 25%, find healing right away.
End
```

### Example 3
```ini
Behavior = AutoFindHealingUpdate   ModuleTag_06 ; This update will have the unit go to a healing station if injured. jba 
  ScanRate = 1000 ; once a second.
  ScanRange = 300 ;
  NeverHeal = 0.85 ;  don't heal if we are > 85% healthy.
  AlwaysHeal = 0.25 ; if we get below 25%, find healing right away.
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../../GeneralsMD
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AutoFindHealingUpdate.cpp`](../../../GeneralsMD
