# ActiveBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ActiveBody provides active health and damage management for objects that can take damage and be destroyed.

**Base Class:** [`BodyModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)

## Usage

Used by objects that have active health systems, can take damage, and can be destroyed through combat.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Scout Van Configuration
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth       = 200
  InitialHealth   = 200
  SubdualDamageCap = 350
  SubdualDamageHealRate = 500
  SubdualDamageHealAmount = 50
End
```

### Example 2: AT Site Configuration
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth       = 75
  InitialHealth   = 75
End
```

### Example 3: Stinger Site Configuration
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth       = 500
  InitialHealth   = 500
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp)
