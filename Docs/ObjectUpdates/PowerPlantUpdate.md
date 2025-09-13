# PowerPlantUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

PowerPlantUpdate provides power plant functionality for objects that can generate power or manage power systems.

## Usage

Used by power plant buildings and structures that need to manage power generation and distribution.

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
Behavior = PowerPlantUpdate ModuleTag_ED01b
    RodsExtendTime = 1500
End
```

### Example 2
```ini
Behavior = PowerPlantUpdate ModuleTag_ED01b
    RodsExtendTime = 500
End
```

### Example 3
```ini
Behavior = PowerPlantUpdate ModuleTag_09
  RodsExtendTime = 600
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/PowerPlantUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/PowerPlantUpdate.cpp)
