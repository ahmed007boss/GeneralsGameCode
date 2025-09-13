# FirestormDynamicGeometryInfoUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FirestormDynamicGeometryInfoUpdate provides firestorm dynamic geometry information functionality for objects with firestorm effects.

**Base Class:** [`DynamicGeometryInfoUpdate`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DynamicGeometryInfoUpdate.h)

## Usage

Used by objects that have firestorm effects with dynamic geometry that changes over time.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Object FirestormDynamicGeometryInfoUpdate
```ini
Behavior = FirestormDynamicGeometryInfoUpdate ModuleTag_03
  InitialDelay       = 800
  InitialHeight      = 8.0
  InitialMajorRadius = 5.0
End
```

### Example 2: System Object FirestormDynamicGeometryInfoUpdate with Different Height
```ini
Behavior = FirestormDynamicGeometryInfoUpdate ModuleTag_03
  InitialDelay       = 800
  InitialHeight      = 7.0
  InitialMajorRadius = 5.0
End
```

### Example 3: System Object FirestormDynamicGeometryInfoUpdate with Larger Radius
```ini
Behavior = FirestormDynamicGeometryInfoUpdate ModuleTag_03
  InitialDelay       = 800
  InitialHeight      = 8.0
  InitialMajorRadius = 15.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FirestormDynamicGeometryInfoUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FirestormDynamicGeometryInfoUpdate.cpp)
