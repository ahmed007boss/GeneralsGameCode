# SpectreGunshipDeploymentUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpectreGunshipDeploymentUpdate provides deployment functionality specifically for Spectre gunship units.

**Base Class:** [`SpecialPowerUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerUpdateModule.h)

## Usage

Used by Spectre gunship units that need specialized deployment mechanics and operations.

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
Behavior           = SpectreGunshipDeploymentUpdate ModuleTag_08
  SpecialPowerTemplate = SuperweaponSpectreGunship
  GunshipTemplateName  = AmericaJetSpectreGunship
  AttackAreaRadius     = 200
End
```

### Example 2
```ini
Behavior           = SpectreGunshipDeploymentUpdate ModuleSpectre_25
  SpecialPowerTemplate = SuperweaponAWACS
  RequiredScience      = SCIENCE_AWACS_L3
  GunshipTemplateName  = AmericaJetAWACS_L3
End
```

### Example 3
```ini
Behavior           = SpectreGunshipDeploymentUpdate ModuleTag_83
  SpecialPowerTemplate = SuperweaponSpectreGunship
  GunshipTemplateName  = AmericaJetSpectreGunship
  AttackAreaRadius     = 200
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpectreGunshipDeploymentUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpectreGunshipDeploymentUpdate.cpp)
