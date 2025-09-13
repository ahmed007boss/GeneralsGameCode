# StructureBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

StructureBody provides specialized body mechanics for structures with unique health and damage characteristics.

**Base Class:** [`ActiveBody`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)

## Usage

Used by building structures that need special health mechanics different from regular units.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Radar Station Structure
```ini
Body = StructureBody ModuleTag_05
  MaxHealth = 2500
  InitialHealth = 2500
  SubdualDamageCap = 5000
  SubdualDamageHealRate = 500
  SubdualDamageHealAmount = 100
  EWDamageCap = 5000
End
```

### Example 2: Airfield Structure
```ini
Body = StructureBody ModuleTag_06
  MaxHealth = 3000
  InitialHealth = 3000
  SubdualDamageCap = 6000
  SubdualDamageHealRate = 800
  SubdualDamageHealAmount = 150
End
```

### Example 3: Artillery Bunker Structure
```ini
Body = StructureBody ModuleTag_315
  MaxHealth = 2000
  InitialHealth = 2000
  SubdualDamageCap = 4000
  SubdualDamageHealRate = 600
  SubdualDamageHealAmount = 120
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/StructureBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/StructureBody.cpp)
