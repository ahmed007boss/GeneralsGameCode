# SupplyTruckAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SupplyTruckAIUpdate provides AI update functionality for supply truck units.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h), [`SupplyTruckAIInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SupplyTruckAIUpdate.h)

## Usage

Used by supply truck units to handle AI-driven supply operations, resource transport, and logistics.

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
Behavior = SupplyTruckAIUpdate ModuleTag_AI01
  MaxBoxes = 4
  SupplyCenterActionDelay = 25
  SupplyWarehouseActionDelay = 25
End
```

### Example 2
```ini
Behavior = SupplyTruckAIUpdate ModuleTag_03
 MaxBoxes                = 8
  SupplyCenterActionDelay = 3500
  SupplyWarehouseActionDelay = 1500 ; ms per box (many small transactions)
End
```

### Example 3
```ini
Behavior = SupplyTruckAIUpdate ModuleTag_03
  MaxBoxes = 4
  SupplyCenterActionDelay = 400     ; ms for whole thing (one transaction)
  SupplyWarehouseActionDelay = 1000 ; ms per box (many small transactions)
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/SupplyTruckAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/SupplyTruckAIUpdate.cpp)
