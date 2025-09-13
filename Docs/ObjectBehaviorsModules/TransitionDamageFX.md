# TransitionDamageFX

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

TransitionDamageFX provides visual effects for damage transitions and damage state changes.

**Base Class:** [`DamageModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by objects that need visual effects when transitioning between different damage states.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Scout Van Transition Damage FX
```ini
Behavior                 = TransitionDamageFX ModuleTag_08
  ReallyDamagedParticleSystem1 = Bone:Smoke RandomBone:Yes PSys:SmallLightSmokeColumn
  ReallyDamagedFXList1 = Loc: X:0 Y:0 Z:0 FXList:FX_CrusaderDamageTransition
End
```

### Example 2: GLA Airfield Transition Damage FX
```ini
Behavior = TransitionDamageFX ModuleTag_16
  ReallyDamagedParticleSystem1 = Bone:Smoke RandomBone:Yes PSys:SmallLightSmokeColumn
  ReallyDamagedFXList1 = Loc: X:0 Y:0 Z:0 FXList:FX_CrusaderDamageTransition
End
```

### Example 3: GLA Radar Station Transition Damage FX (Commented)
```ini
; Behavior = TransitionDamageFX ModuleTag_Death02
;   ReallyDamagedParticleSystem1 = Bone:Smoke RandomBone:Yes PSys:SmallLightSmokeColumn
;   ReallyDamagedFXList1 = Loc: X:0 Y:0 Z:0 FXList:FX_CrusaderDamageTransition
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Damage/TransitionDamageFX.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Damage/TransitionDamageFX.cpp)
