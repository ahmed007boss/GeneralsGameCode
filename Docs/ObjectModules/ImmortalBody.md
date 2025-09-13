# ImmortalBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ImmortalBody provides immortal health mechanics for objects that cannot be destroyed through normal means.

**Base Class:** [`ActiveBody`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)

## Usage

Used by objects that need to be indestructible or have special immortality mechanics.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Special Power Object
```ini
Body = ImmortalBody ModuleTag_02
  MaxHealth = 1
  InitialHealth = 1
End
```

### Example 2: Weapon Object Immortal
```ini
Body = ImmortalBody ModuleTag_02
  MaxHealth = 100
  InitialHealth = 100
End
```

### Example 3: Special Effect Immortal
```ini
Body = ImmortalBody ModuleTag_02
  MaxHealth = 50
  InitialHealth = 50
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ImmortalBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ImmortalBody.cpp)
