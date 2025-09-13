# ChinookAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ChinookAIUpdate provides AI update functionality for Chinook helicopter units.

**Base Class:** [`SupplyTruckAIUpdate`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SupplyTruckAIUpdate.h)

## Usage

Used by Chinook helicopters to handle AI-driven flight operations, transport, and combat missions.

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
Behavior = ChinookAIUpdate ModuleTag_07
  MaxBoxes                = 8
  SupplyCenterActionDelay = 3000     ; ms for whole thing (one transaction)
  SupplyWarehouseActionDelay = 1250  ; 875 ; ms per box (many small transactions)
  SupplyWarehouseScanDistance = 700 ;350 ; Max distance to look for a warehouse, or we go home.  (Direct dock command on warehouse overrides, and no max on Center Scan)
  SuppliesDepletedVoice = ChinookVoiceSuppliesDepleted
End
```

### Example 2
```ini
Behavior = ChinookAIUpdate ModuleTag_04
   AutoAcquireEnemiesWhenIdle = Yes 
  MoodAttackCheckRate = 333
   RotorWashParticleSystem = HelixRotorWashRing
End
```

### Example 3
```ini
Behavior = ChinookAIUpdate ModuleTag_05
  MaxBoxes                = 8
  SupplyCenterActionDelay = 3500
  SupplyWarehouseActionDelay = 1250 ;1250  ; 875 ; ms per box (many small transactions)
  SupplyWarehouseScanDistance = 700 ;350 ; Max distance to look for a warehouse, or we go home.  (Direct dock command on warehouse overrides, and no max on Center Scan)
  SuppliesDepletedVoice = ChinookVoiceSuppliesDepleted
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/ChinookAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/ChinookAIUpdate.cpp)
