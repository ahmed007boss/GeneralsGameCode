# JetSlowDeathBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

JetSlowDeathBehavior provides specialized death behavior for jet aircraft, including crash sequences and debris effects.

**Base Class:** [`SlowDeathBehavior`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SlowDeathBehavior.h)

## Usage

Used by jet aircraft to create realistic crash animations and death effects when destroyed.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Jet Slow Death
```ini
;--spinning and burning
Behavior                            = JetSlowDeathBehavior ModuleTag_999
 DeathTypes = ALL -BURNED
   FXOnGroundDeath = FX_JetGroundDeathSmall
   OCLOnGroundDeath = OCL_VampireDeathFinalBlowUp
   FXInitialDeath                     = FX_VampireDeathInitial
   OCLInitialDeath                    = OCL_VampireSlowBD
End
```

### Example 2: America CINE Unit Jet Slow Death
```ini
Behavior                          = JetSlowDeathBehavior ModuleTag_10
 DeathTypes = ALL -BURNED
   FXOnGroundDeath = FX_JetGroundDeathSmall
   OCLOnGroundDeath = OCL_VampireDeathFinalBlowUp
   FXInitialDeath                     = FX_VampireDeathInitial
   OCLInitialDeath                    = OCL_VampireSlowBD
End
```

### Example 3: America CINE Unit Jet Slow Death Alternative
```ini
Behavior                          = JetSlowDeathBehavior ModuleTag_05
 DeathTypes = ALL -BURNED
   FXOnGroundDeath = FX_JetGroundDeathSmall
   OCLOnGroundDeath = OCL_VampireDeathFinalBlowUp
   FXInitialDeath                     = FX_VampireDeathInitial
   OCLInitialDeath                    = OCL_VampireSlowBD
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/JetSlowDeathBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/JetSlowDeathBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/JetSlowDeathBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/JetSlowDeathBehavior.cpp)
