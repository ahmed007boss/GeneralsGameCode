# SupplyWarehouseDockUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SupplyWarehouseDockUpdate provides docking functionality specifically for supply warehouse facilities.

**Base Class:** [`DockUpdate`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)

## Usage

Used by objects that need to dock with supply warehouses for resource storage and management operations.

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
Behavior = SupplyWarehouseDockUpdate ModuleTag_06
  AllowsPassthrough = No ;You can't drive through this guy while docking.  Use this when the dock points are all outside
  NumberApproachPositions = -1 ; This is a Boneless dock, so this means infinite can approach
  StartingBoxes     = 800 ; Even if you use a script to set the cash value, this will determine graphically what "full" is.
End
```

### Example 2
```ini
Behavior = SupplyWarehouseDockUpdate ModuleTag_04
  AllowsPassthrough = Yes ;You can't drive through this guy while docking.  Use this when the dock points are all outside
  NumberApproachPositions = -1 ; This is a Boneless dock, so this means infinite can approach
  StartingBoxes     = 50 ; Even if you use a script to set the cash value, this will determine graphically what "full" is.
End
```

### Example 3
```ini
Behavior = SupplyWarehouseDockUpdate ModuleTag_04
  NumberApproachPositions = -1 ; There are 5 approach bones in the art
  StartingBoxes     = 240 ; Even if you use a script to set the cash value, this will determine graphically what "full" is.
  DeleteWhenEmpty = Yes
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/SupplyWarehouseDockUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/SupplyWarehouseDockUpdate.cpp)
