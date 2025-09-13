# UndeadBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

UndeadBody provides specialized body mechanics for undead units with unique health and resurrection systems.

**Base Class:** [`ActiveBody`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)

## Usage

Used by undead units that have special health mechanics, such as resurrection abilities or damage resistance.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Battle Fortress Undead
```ini
Body = UndeadBody ModuleTag_02
  MaxHealth = 730.0
  InitialHealth = 730.0
  SecondLifeMaxHealth = 950.0
End
```

### Example 2: Battle Bus Undead
```ini
Body = UndeadBody ModuleTag_02
  MaxHealth = 650.0
  InitialHealth = 650.0
  SecondLifeMaxHealth = 800.0
End
```

### Example 3: CINE Unit Undead
```ini
Body = UndeadBody ModuleTag_02
  MaxHealth = 500.0
  InitialHealth = 500.0
  SecondLifeMaxHealth = 750.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/UndeadBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/UndeadBody.cpp)
