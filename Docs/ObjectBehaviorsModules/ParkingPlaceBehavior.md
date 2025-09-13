# ParkingPlaceBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ParkingPlaceBehavior manages parking spaces for vehicles and aircraft, including space reservation and management.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h), [`ParkingPlaceBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ParkingPlaceBehavior.h)

## Usage

Used by structures that provide parking spaces for vehicles or aircraft, such as garages, hangars, or parking areas.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Airfield Parking Place Behavior
```ini
Behavior = ParkingPlaceBehavior ModuleTag_11
  HealAmountPerSecond     = 25
  NumRows                 = 2
  NumCols                 = 1
  HasRunways              = Yes
  ApproachHeight          = 50
End
```

### Example 2: GLA Airbase Parking Place Behavior
```ini
Behavior = ParkingPlaceBehavior ModuleTag_906
  HealAmountPerSecond     = 25
  NumRows                 = 2
  NumCols                 = 1
  HasRunways              = Yes
  ApproachHeight          = 50
End
```

### Example 3: USA Helipad Parking Place Behavior
```ini
Behavior = ParkingPlaceBehavior ModuleTag_09
  HealAmountPerSecond     = 25
  NumRows                 = 2
  NumCols                 = 1
  HasRunways              = Yes
  ApproachHeight          = 50
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ParkingPlaceBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ParkingPlaceBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/ParkingPlaceBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/ParkingPlaceBehavior.cpp)
