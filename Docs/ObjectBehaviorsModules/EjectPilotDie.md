# EjectPilotDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

EjectPilotDie provides death mechanics for aircraft that can eject their pilot before destruction.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by aircraft that can eject their pilot when destroyed, creating a pilot unit.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Jammer Van Eject Pilot
```ini
Behavior = EjectPilotDie ModuleTag_07
  GroundCreationList = OCL_EjectPilotOnGround
  AirCreationList = OCL_EjectPilotViaParachute
  ExemptStatus = HIJACKED
  VeterancyLevels =  ALL -REGULAR ;only vet+ gives pilot
End
```

### Example 2: America CINE Unit Eject Pilot
```ini
Behavior = EjectPilotDie ModuleTag_16
  GroundCreationList = OCL_EjectPilotOnGround
  AirCreationList = OCL_EjectPilotViaParachute
  ExemptStatus = HIJACKED
  VeterancyLevels =  ALL -REGULAR ;only vet+ gives pilot
End
```

### Example 3: America CINE Unit Eject Pilot Alternative
```ini
Behavior = EjectPilotDie ModuleTag_06
  GroundCreationList = OCL_EjectPilotOnGround
  AirCreationList = OCL_EjectPilotViaParachute
  ExemptStatus = HIJACKED
  VeterancyLevels =  ALL -REGULAR ;only vet+ gives pilot
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/EjectPilotDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/EjectPilotDie.cpp)
