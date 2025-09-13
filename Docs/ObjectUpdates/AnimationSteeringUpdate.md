# AnimationSteeringUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

AnimationSteeringUpdate provides animation steering functionality for objects with animated movement.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need animation-based steering and movement control.

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
Behavior = AnimationSteeringUpdate ModuleTag_SteerUpdate
  MinTransitionTime = 300
End
```

### Example 2
```ini
Behavior = AnimationSteeringUpdate ModuleTag_17
  MinTransitionTime = 300
End
```

### Example 3
```ini
Behavior = AnimationSteeringUpdate ModuleTag_09
  MinTransitionTime = 300
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AnimationSteeringUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AnimationSteeringUpdate.cpp)
