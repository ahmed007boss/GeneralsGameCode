# SpectreGunshipUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpectreGunshipUpdate provides update functionality specifically for Spectre gunship units.

**Base Class:** [`SpecialPowerUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerUpdateModule.h)

## Usage

Used by Spectre gunship units that need specialized update mechanics and operations.

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
Behavior = SpectreGunshipUpdate ModuleTag_06
  GattlingStrafeFXParticleSystem  = SpectreGattlingArmsSmoke
  SpecialPowerTemplate            = SuperweaponSpectreGunship
  HowitzerWeaponTemplate          = SpectreHowitzerGun
End
```

### Example 2
```ini
Behavior = SpectreGunshipUpdate ModuleTag_06
  SpecialPowerTemplate            = SuperweaponAWACS
  OrbitInsertionSlope     = 0.7   ; steepness of orbit entry
  GunshipOrbitRadius      = 300
End
```

### Example 3
```ini
Behavior = SpectreGunshipUpdate ModuleTag_06
  SpecialPowerTemplate            = SuperweaponAWACS
  OrbitInsertionSlope     = 0.7   ; steepness of orbit entry
  GunshipOrbitRadius      = 350
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpectreGunshipUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpectreGunshipUpdate.cpp)
