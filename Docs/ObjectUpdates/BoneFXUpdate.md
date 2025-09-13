# BoneFXUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BoneFXUpdate provides bone-based visual effects functionality for objects with skeletal animations.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need bone-based visual effects, such as animated models with skeletal systems.

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
Behavior = BoneFXUpdate ModuleTag_09c
  PristineParticleSystem1  = bone:ENGINE01 OnlyOnce:Yes  1600  1800 PSys:UnderWaterShipSplash;
  PristineParticleSystem2  = bone:ENGINE01 OnlyOnce:No  1800  1800 PSys:BigTorpedoExhaust;
End
```

### Example 2
```ini
Behavior = BoneFXUpdate ModuleTag_09b
  PristineParticleSystem1  = bone:ENGINE01 OnlyOnce:Yes  0  0 PSys:BastionEngineFlameLeftCase;
  PristineParticleSystem2  = bone:ENGINE01 OnlyOnce:Yes  0  0 PSys:BastionEngineFlameRightCase;
End
```

### Example 3
```ini
Behavior = BoneFXUpdate ModuleTag_05
  DamageFXTypes       = ALL -WATER
  RubbleFXList1        = bone:Smoke02 OnlyOnce:Yes 3000 3000 FXList:FX_DefaultStructureSecondary
  DamageParticleTypes = ALL -WATER    
  RubbleParticleSystem1  = bone:Fire02 OnlyOnce:Yes 3000 3000 PSys:StructureToppleSmokeTrail
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/BoneFXUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/BoneFXUpdate.cpp)
