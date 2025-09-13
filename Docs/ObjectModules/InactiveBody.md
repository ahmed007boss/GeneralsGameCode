# InactiveBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

InactiveBody provides inactive health mechanics for objects that cannot take damage or be destroyed.

**Base Class:** [`BodyModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)

## Usage

Used by objects that need to be invulnerable to damage, such as terrain features or indestructible structures.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Object Inactive
```ini
Body = InactiveBody ModuleTag_02
  ;nothing
End
```

### Example 2: Terrain Feature Inactive
```ini
Body = InactiveBody ModuleTag_02
  MaxHealth = 0
  InitialHealth = 0
End
```

### Example 3: Invulnerable Structure
```ini
Body = InactiveBody ModuleTag_02
  ; Invulnerable to all damage types
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/InactiveBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/InactiveBody.cpp)
