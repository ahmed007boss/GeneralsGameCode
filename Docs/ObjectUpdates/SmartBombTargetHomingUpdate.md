# SmartBombTargetHomingUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SmartBombTargetHomingUpdate provides smart bomb target homing functionality for objects that can create smart bomb effects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can create smart bombs with target homing capabilities and guidance systems.

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
Behavior = SmartBombTargetHomingUpdate ModuleTag_11
  CourseCorrectionScalar = 0.99 ; 1=no homing, 0=snapto; 0.99=smooth, 0.95=too-fast
End
```

### Example 2
```ini
Behavior = SmartBombTargetHomingUpdate ModuleTag_11
  CourseCorrectionScalar = 0.99 ; 1=no homing, 0=snapto; 0.99=smooth, 0.95=too-fast
End
```

*Only 2 examples of SmartBombTargetHomingUpdate were found in the INI files, both identical.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SmartBombTargetHomingUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SmartBombTargetHomingUpdate.cpp)
