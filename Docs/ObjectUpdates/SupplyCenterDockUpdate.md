# SupplyCenterDockUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SupplyCenterDockUpdate provides docking functionality specifically for supply center facilities.

**Base Class:** [`DockUpdate`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)

## Usage

Used by objects that need to dock with supply centers for resource management and supply operations.

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
Behavior = SupplyCenterDockUpdate ModuleTag_13
  AllowsPassthrough = No ;You can't drive through this guy while docking.  Use this when the dock points are all outside
  NumberApproachPositions = -1 ; This is a Boneless dock, so this means infinite can approach
  GrantTemporaryStealth = 20000
End
```

### Example 2
```ini
Behavior = SupplyCenterDockUpdate ModuleTag_13
  AllowsPassthrough = No ;You can't drive through this guy while docking.  Use this when the dock points are all outside
  NumberApproachPositions = -1 ; This is a Boneless dock, so this means infinite can approach
End
```

### Example 3
```ini
Behavior = SupplyCenterDockUpdate ModuleTag_13
  AllowsPassthrough = No ;You can't drive through this guy while docking.  Use this when the dock points are all outside
  NumberApproachPositions = 9 ; There are 9 approach bones in the art
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/SupplyCenterDockUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/SupplyCenterDockUpdate.cpp)
