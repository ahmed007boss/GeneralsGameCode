# ParticleUplinkCannonUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ParticleUplinkCannonUpdate provides particle uplink cannon functionality for objects that can create particle uplink effects.

**Base Class:** [`SpecialPowerUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerUpdateModule.h)

## Usage

Used by objects that can create particle uplink cannon effects, such as orbital weapons or special particle systems.

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
Behavior = ParticleUplinkCannonUpdate ModuleTag_12
  SpecialPowerTemplate            = SuperweaponParticleUplinkCannon

  ;The values trigger the various pre-stages before being ready to actually fire.
End
```

### Example 2
```ini
Behavior = ParticleUplinkCannonUpdate ModuleTag_12
  SpecialPowerTemplate            = SuperweaponParticleUplinkCannon

  ;The values trigger the various pre-stages before being ready to actually fire.
End
```

*Only 2 examples of ParticleUplinkCannonUpdate were found in the INI files, both identical.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ParticleUplinkCannonUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/ParticleUplinkCannonUpdate.cpp)
