# BunkerBusterBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BunkerBusterBehavior provides specialized behavior for bunker buster weapons and projectiles that can penetrate structures.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by bunker buster projectiles and weapons to handle penetration mechanics, delayed detonation, and structure-specific damage.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Bunker Buster
```ini
Behavior        = BunkerBusterBehavior ModuleTag_04
  UpgradeRequired               = Upgrade_AmericaLaserMissiles                
  DetonationFX                  = FX_BunkerBusterExplosion            ; the big detonation kaboom at the bottom
  CrashThroughBunkerFX          = WeaponFX_BunkerBusterIntialImpact   ; the crash bang crunch FX on the way through the bunker ceiling
  CrashThroughBunkerFXFrequency = 571                                 ; msec... how often to play the crash bang crunch FX on the way through the bunker ceiling

  SeismicEffectRadius         = 200
  SeismicEffectMagnitude      = 5

 ShockwaveWeaponTemplate     =  BunkerBusterShockwaveWeaponSmall
End
```

### Example 2: Weapon Object Bunker Buster Alternative
```ini
Behavior        = BunkerBusterBehavior ModuleTag_04
  UpgradeRequired               = Upgrade_AmericaLaserMissiles                
  DetonationFX                  = FX_BunkerBusterExplosion
  CrashThroughBunkerFX          = WeaponFX_BunkerBusterIntialImpact
  CrashThroughBunkerFXFrequency = 571

  SeismicEffectRadius         = 200
  SeismicEffectMagnitude      = 5

 ShockwaveWeaponTemplate     =  BunkerBusterShockwaveWeaponSmall
End
```

### Example 3: Weapon Object Bunker Buster Module 13
```ini
Behavior        = BunkerBusterBehavior ModuleTag_13
  UpgradeRequired               = Upgrade_AmericaLaserMissiles                
  DetonationFX                  = FX_BunkerBusterExplosion
  CrashThroughBunkerFX          = WeaponFX_BunkerBusterIntialImpact
  CrashThroughBunkerFXFrequency = 571

  SeismicEffectRadius         = 200
  SeismicEffectMagnitude      = 5

 ShockwaveWeaponTemplate     =  BunkerBusterShockwaveWeaponSmall
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BunkerBusterBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BunkerBusterBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BunkerBusterBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/BunkerBusterBehavior.cpp)
