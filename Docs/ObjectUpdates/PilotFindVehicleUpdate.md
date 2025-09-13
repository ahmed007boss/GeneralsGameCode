# PilotFindVehicleUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

PilotFindVehicleUpdate provides pilot vehicle finding functionality for pilot units that need to find vehicles.

## Usage

Used by pilot units that need to find and enter vehicles, such as ejected pilots or pilot units.

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
Behavior = PilotFindVehicleUpdate   ModuleTag_07 ; This update will have the unit go to a vehicle. jba 
  ScanRate = 1000 ; once a second.
  ScanRange = 300 ;
  MinHealth = 0.5 ;  don't enter a vehicl less than 50% healthy.
End
```

### Example 2
```ini
Behavior = PilotFindVehicleUpdate   ModuleTag_07 ; This update will have the unit go to a vehicle. jba 
  ScanRate = 1000 ; once a second.
  ScanRange = 300 ;
  MinHealth = 0.5 ;  don't enter a vehicle less than 50% healthy.
End
```

*Only 2 examples of PilotFindVehicleUpdate were found in the INI files, both identical.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/PilotFindVehicleUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/PilotFindVehicleUpdate.cpp)
