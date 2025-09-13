# OCLUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

OCLUpdate provides Object Creation List (OCL) functionality for objects that can create other objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can create other objects using OCL systems for spawning, production, or special effects.

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
Behavior       = OCLUpdate ModuleTag_12
  OCL          = OCL_KurierRevealObject
  MinDelay     = 12000
  MaxDelay     = 12000
End
```

### Example 2
```ini
Behavior       = OCLUpdate ModuleTag_12 ; Context window is a reaction to this, no CommandSet 
  OCL          = OCL_RussiaSpyPlaneDetonationObject
  MinDelay     = 1000
  MaxDelay     = 1000
End
```

### Example 3
```ini
Behavior       = OCLUpdate ModuleTag_05 ; Context window is a reaction to this, no CommandSet 
  OCL          = OCL_SmokeFireWeapon
  MinDelay     = 100
  MaxDelay     = 100
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/OCLUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/OCLUpdate.cpp)
