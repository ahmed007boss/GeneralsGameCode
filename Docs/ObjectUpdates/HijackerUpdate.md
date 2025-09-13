# HijackerUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

HijackerUpdate provides hijacking functionality for objects that can hijack other objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can hijack other vehicles, buildings, or systems.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA CINE Unit HijackerUpdate
```ini
Behavior = HijackerUpdate ModuleTag_04
  ParachuteName = AmericaParachute
End
```

### Example 2: GLA Hijacker HijackerUpdate
```ini
Behavior = HijackerUpdate ModuleTag_03
  ParachuteName = AmericaParachute
End
```

*Only two examples of HijackerUpdate were found in the INI files.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/HijackerUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/HijackerUpdate.cpp)
