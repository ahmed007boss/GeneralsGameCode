# GrantStealthBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

GrantStealthBehavior provides functionality for granting stealth capabilities to nearby friendly units.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that can provide stealth benefits to allies, such as stealth generators or stealth support units.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Grant Stealth Behavior
```ini
Behavior = GrantStealthBehavior ModuleTag_02
  StartRadius               = 20.0
  FinalRadius               = 100.0 ;this needs to sync with the radiuscursorradius in SpecialPower SuperweaponGPSScrambler 
  RadiusGrowRate            = 10.0
  RadiusParticleSystemName  = ParticleUplinkCannon_LaserBaseReadyToFire
  KindOf                    = VEHICLE INFANTRY
End
```

### Example 2: GPS Scrambler Grant Stealth
```ini
Behavior = GrantStealthBehavior ModuleTag_02
  StartRadius               = 20.0
  FinalRadius               = 100.0 ;this needs to sync with the radiuscursorradius in SpecialPower SuperweaponGPSScrambler 
  RadiusGrowRate            = 10.0
  RadiusParticleSystemName  = ParticleUplinkCannon_LaserBaseReadyToFire
  KindOf                    = VEHICLE INFANTRY
End
```

### Example 3: Stealth Generator Grant Stealth
```ini
Behavior = GrantStealthBehavior ModuleTag_02
  StartRadius               = 20.0
  FinalRadius               = 100.0 ;this needs to sync with the radiuscursorradius in SpecialPower SuperweaponGPSScrambler 
  RadiusGrowRate            = 10.0
  RadiusParticleSystemName  = ParticleUplinkCannon_LaserBaseReadyToFire
  KindOf                    = VEHICLE INFANTRY
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/GrantStealthBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/GrantStealthBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/GrantStealthBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/GrantStealthBehavior.cpp)
