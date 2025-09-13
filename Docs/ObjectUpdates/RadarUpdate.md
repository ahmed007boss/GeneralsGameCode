# RadarUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

RadarUpdate provides radar functionality for objects that can detect or provide radar coverage.

## Usage

Used by objects that can provide radar coverage, detect other objects, or manage radar systems.

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
Behavior = RadarUpdate ModuleTag_Upgrade01
  RadarExtendTime = 4000
End
```

### Example 2
```ini
Behavior = RadarUpdate ModuleTag_Radar3
  RadarExtendTime   = 4000     ;in mSeconds
End
```

### Example 3
```ini
Behavior = RadarUpdate ModuleTag_11
  RadarExtendTime   = 4000     ;in mSeconds
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/RadarUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/RadarUpdate.cpp)
