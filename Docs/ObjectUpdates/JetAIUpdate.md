# JetAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

JetAIUpdate provides AI update functionality for jet aircraft units.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)

## Usage

Used by jet aircraft to handle AI-driven flight operations, combat, and airfield management.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America CINE Unit JetAIUpdate
```ini
Behavior = JetAIUpdate ModuleTag_06
  OutOfAmmoDamagePerSecond = 10%  ; amount of damage to take per SEC (not per frame) when out of ammo
                                  ; note that it's expressed as a percent of max health, not an absolute
  TakeoffDistForMaxLift     = 0%   ; larger numbers give more lift sooner when taking off
End
```

### Example 2: America CINE Unit JetAIUpdate with MinHeight
```ini
Behavior = JetAIUpdate ModuleTag_06
  MinHeight                     = 5
  NeedsRunway                   = No
  KeepsParkingSpaceWhenAirborne = No
End
```

### Example 3: China H20 JetAIUpdate
```ini
Behavior = JetAIUpdate ModuleTag_05
  OutOfAmmoDamagePerSecond  = 10%  ; amount of damage to take per SEC (not per frame) when out of ammo
                                  ; note that it's expressed as a percent of max health, not an absolute
  TakeoffDistForMaxLift     = 0%   ; larger numbers give more lift sooner when taking off
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/JetAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/JetAIUpdate.cpp)
