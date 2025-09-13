# FloatUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FloatUpdate provides floating functionality for objects that can float on water or other surfaces.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to float on water, maintain buoyancy, or have floating mechanics.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Civilian Unit FloatUpdate
```ini
Behavior = FloatUpdate UpdateTag_01
  Enabled = No ; 'no' because we dont want to be lifted by this update, just swayed around like a buoy
End
```

*All examples of FloatUpdate found in the INI files are identical with Enabled = No.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FloatUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FloatUpdate.cpp)
