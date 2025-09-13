# DeliverPayloadAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DeliverPayloadAIUpdate provides AI update functionality for payload delivery systems.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)

## Usage

Used by objects that need to deliver payloads to specific locations with AI-driven navigation.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America CINE Unit DeliverPayloadAIUpdate
```ini
Behavior = DeliverPayloadAIUpdate ModuleTag_08
  DoorDelay         = 500
  MaxAttempts       = 4
  DropOffset        = X:0 Y:0 Z:-10
End
```

### Example 2: China Special Power Airplane DeliverPayloadAIUpdate
```ini
Behavior = DeliverPayloadAIUpdate ModuleTag_05
  DoorDelay = 500
  MaxAttempts = 4
  DropOffset = X:0 Y:0 Z:-10
End
```

### Example 3: USA Cargo Plane DeliverPayloadAIUpdate
```ini
Behavior = DeliverPayloadAIUpdate ModuleTag_05
  DoorDelay         = 500
  MaxAttempts       = 4
  DropOffset        = X:0 Y:0 Z:-10
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/DeliverPayloadAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/DeliverPayloadAIUpdate.cpp)
