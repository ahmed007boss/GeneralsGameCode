# TransportAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

TransportAIUpdate provides AI update functionality for transport vehicle units.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)

## Usage

Used by transport vehicles to handle AI-driven transport operations, cargo management, and logistics.

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
Behavior = TransportAIUpdate ModuleTag_03
  Turret
    TurretTurnRate = 180
    RecenterTime = 5000   ; how long to wait during idle before recentering
End
```

### Example 2
```ini
Behavior = TransportAIUpdate ModuleTag_03
  Turret
    ControlledWeaponSlots = PRIMARY SECONDARY
    TurretTurnRate        = 280
End
```

### Example 3
```ini
Behavior = TransportAIUpdate ModuleTag_15
  AutoAcquireEnemiesWhenIdle = Yes
  Turret
    TurretTurnRate = 120
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/TransportAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/TransportAIUpdate.cpp)
