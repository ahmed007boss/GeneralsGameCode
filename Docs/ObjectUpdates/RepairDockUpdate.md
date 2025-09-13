# RepairDockUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

RepairDockUpdate provides docking functionality specifically for repair facilities and repair operations.

**Base Class:** [`DockUpdate`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)

## Usage

Used by objects that need to dock with repair facilities for maintenance and repair operations.

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
Behavior = RepairDockUpdate ModuleTag_09
  TimeForFullHeal   = 5000   ;(in milliseconds)     
  NumberApproachPositions = 5
End
```

### Example 2
```ini
Behavior = RepairDockUpdate ModuleTag_14
  TimeForFullHeal   = 5000   ;(in milliseconds)     
  NumberApproachPositions = 5
End
```

### Example 3
```ini
Behavior = RepairDockUpdate ModuleTag_05
  TimeForFullHeal   = 5000   ;(in milliseconds)   
  AllowsPassthrough = Yes 
  NumberApproachPositions = 5
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/RepairDockUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/RepairDockUpdate.cpp)
