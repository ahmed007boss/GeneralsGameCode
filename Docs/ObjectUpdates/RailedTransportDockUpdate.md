# RailedTransportDockUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

RailedTransportDockUpdate provides docking functionality specifically for railed transport systems.

## Usage

Used by railed transport units that need to dock with rail stations or other rail facilities.

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
Behavior = RailedTransportDockUpdate ModuleTag_06
  NumberApproachPositions = 9
  PullInsideDuration      = 4500  ; in milliseconds
  PushOutsideDuration     = 4500  ; in milliseconds
End
```

*Only 1 example of RailedTransportDockUpdate was found in the INI files.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DockUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/RailedTransportDockUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/RailedTransportDockUpdate.cpp)
