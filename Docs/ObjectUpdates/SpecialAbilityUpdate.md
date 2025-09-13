# SpecialAbilityUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpecialAbilityUpdate provides special ability functionality for objects that have special abilities.

**Base Class:** [`SpecialPowerUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerUpdateModule.h)

## Usage

Used by objects that have special abilities that can be activated, managed, or controlled.

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
Behavior = SpecialAbilityUpdate ModuleTag_19
  SpecialPowerTemplate  = SpecialAbilityRangerCaptureBuilding
  StartAbilityRange  = 5.0
  UnpackTime            = 3000  ; (changing this will scale anim speed)
End
```

### Example 2
```ini
Behavior = SpecialAbilityUpdate ModuleTag_09
  SpecialPowerTemplate = SpecialAbilityColonelBurtonRemoteCharges
  StartAbilityRange = 0.0
  PreparationTime = 0
End
```

### Example 3
```ini
Behavior = SpecialAbilityUpdate ModuleTag_Disguise02
  SpecialPowerTemplate = SpecialAbilityDisguiseAsVehicle
  StartAbilityRange = 1000000.0
  ApproachRequiresLOS = No
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpecialAbilityUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpecialAbilityUpdate.cpp)
