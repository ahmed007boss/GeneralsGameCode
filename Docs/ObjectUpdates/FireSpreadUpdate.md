# FireSpreadUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireSpreadUpdate provides fire spread functionality for objects that can spread fire or be affected by fire.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can spread fire to nearby objects or are affected by fire spread mechanics.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Nature Prop FireSpreadUpdate
```ini
Behavior = FireSpreadUpdate ModuleTag_06
  OCLEmbers        = OCL_BurningEmbers
  MinSpreadDelay   = 1000
  MaxSpreadDelay   = 2000
End
```

*All examples of FireSpreadUpdate found in the INI files are identical.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FireSpreadUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FireSpreadUpdate.cpp)
