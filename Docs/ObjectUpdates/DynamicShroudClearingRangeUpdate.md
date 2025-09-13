# DynamicShroudClearingRangeUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DynamicShroudClearingRangeUpdate provides dynamic shroud clearing range functionality for objects that can clear fog of war.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can clear shroud or fog of war with dynamic range that changes over time.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Object DynamicShroudClearingRangeUpdate
```ini
Behavior = DynamicShroudClearingRangeUpdate ModuleTag_02
  FinalVision = 0.0 
  ShrinkDelay = 5000
  ShrinkTime = 2500
End
```

### Example 2: USA Drone DynamicShroudClearingRangeUpdate
```ini
Behavior = DynamicShroudClearingRangeUpdate ModuleTag_04
  FinalVision = 300.0 
  ChangeInterval = 50
  ShrinkDelay = 2000
End
```

### Example 3: System Object DynamicShroudClearingRangeUpdate with Longer Delay
```ini
Behavior = DynamicShroudClearingRangeUpdate ModuleTag_02
  FinalVision = 0.0 
  ShrinkDelay = 10000
  ShrinkTime = 5000
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DynamicShroudClearingRangeUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DynamicShroudClearingRangeUpdate.cpp)
