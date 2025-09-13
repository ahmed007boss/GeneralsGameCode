# SupplyWarehouseCreate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SupplyWarehouseCreate provides functionality for creating supply warehouse effects when objects are created or spawned.

**Base Class:** [`CreateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)

## Usage

Used by objects that can create supply warehouse effects upon creation or when specific conditions are met.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Supplies Supply Warehouse Create
```ini
Behavior = SupplyWarehouseCreate ModuleTag_05
  ;nothing
End
```

### Example 2: Supplies Supply Warehouse Create Alternative
```ini
Behavior = SupplyWarehouseCreate ModuleTag_03
  ;nothing
End
```

### Example 3: Supplies Supply Warehouse Create Third
```ini
Behavior = SupplyWarehouseCreate ModuleTag_04
  ;nothing
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/SupplyWarehouseCreate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/SupplyWarehouseCreate.cpp)
