# ProductionUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ProductionUpdate provides production functionality for objects that can produce other objects or units.

## Usage

Used by production buildings and facilities that need to manage unit production, queues, and production mechanics.

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
Behavior = ProductionUpdate ModuleTag_Production01
  NumDoorAnimations = 1
  DoorOpeningTime = 1500
  DoorWaitOpenTime = 3000
End
```

### Example 2
```ini
Behavior = ProductionUpdate ModuleTag_12
  NumDoorAnimations            = 2
  DoorOpeningTime              = 2000  ;in mSeconds
  DoorWaitOpenTime             = 3000  ;in mSeconds
End
```

### Example 3
```ini
Behavior = ProductionUpdate ModuleTag_09
  MaxQueueEntries = 1; So you can't build multiple upgrades in the same frame
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ProductionUpdate.cpp)
