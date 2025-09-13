# RebuildHoleExposeDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

RebuildHoleExposeDie provides death mechanics that expose rebuild holes when structures are destroyed.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by structures that create rebuild holes when destroyed, allowing them to be rebuilt.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Radar Station Rebuild Hole Expose Die
```ini
Behavior = RebuildHoleExposeDie ModuleTag_Death04
  HoleName = GLAHoleRadarStation
  HoleMaxHealth = 500
End
```

### Example 2: GLA Airfield Rebuild Hole Expose Die
```ini
Behavior             = RebuildHoleExposeDie ModuleTag_08
  HoleName = GLAHoleAirfield
  HoleMaxHealth = 500
End
```

### Example 3: GLA Artillery Bunker Rebuild Hole Expose Die
```ini
Behavior = RebuildHoleExposeDie ModuleTag_321
  HoleName = GLAHoleArtilleryBunker
  HoleMaxHealth = 500
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/RebuildHoleExposeDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/RebuildHoleExposeDie.cpp)
