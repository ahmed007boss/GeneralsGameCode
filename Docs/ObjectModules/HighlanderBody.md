# HighlanderBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

HighlanderBody provides special body mechanics for units that can only be destroyed by specific means or have unique death conditions.

**Base Class:** [`ActiveBody`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)

## Usage

Used by units that have special destruction requirements or unique health mechanics, such as "there can be only one" style units.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Highlander
```ini
Body = HighlanderBody ModuleTag_NewBody
  MaxHealth = 1.0
  InitialHealth = 1.0
End
```

### Example 2: Faction Building Highlander
```ini
Body = HighlanderBody ModuleTag_03
  MaxHealth = 100.0
  InitialHealth = 100.0
End
```

### Example 3: Special Weapon Highlander
```ini
Body = HighlanderBody ModuleTag_01
  MaxHealth = 50.0
  InitialHealth = 50.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/HighlanderBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/HighlanderBody.cpp)
