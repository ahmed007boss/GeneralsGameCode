# StealthDetectorUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

StealthDetectorUpdate provides stealth detection functionality for objects that can detect stealth units.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can detect stealth units, provide stealth detection coverage, or manage stealth detection systems.

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
Behavior = StealthDetectorUpdate ModuleTag_AirDetection1
  DetectionRate   = 500   ; how often to rescan for stealthed things in my sight (msec)
  DetectionRange = 285 ;Dustin, enable this for independant balancing!
  ExtraForbiddenKindOf     = AIRCRAFT DRONE
End
```

### Example 2
```ini
Behavior = StealthDetectorUpdate ModuleTag_12
  DetectionRate   = 2000
  DetectionRange = 0
  ExtraRequiredKindOf      = AIRCRAFT
End
```

### Example 3
```ini
Behavior = StealthDetectorUpdate ModuleTag_10
  DetectionRate   = 1500   ; how often to rescan for stealthed things in my sight (msec)
  DetectionRange = 230 ;Dustin, enable this for independant balancing!
  ExtraRequiredKindOf      = AIRCRAFT 
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/StealthDetectorUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/StealthDetectorUpdate.cpp)
