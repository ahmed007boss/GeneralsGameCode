# BaikonurLaunchPower

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

BaikonurLaunchPower provides special power functionality for Baikonur launch systems.

**Base Class:** [`SpecialPowerModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)

## Usage

Used by objects that can trigger Baikonur launch special powers, such as missile launch systems.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America CINE Unit Launch
```ini
Behavior               = BaikonurLaunchPower ModuleTag_06
  SpecialPowerTemplate = SuperweaponLaunchBaikonurRocket
  DetonationObject     = BaikonurRocketDetonation
End
```

### Example 2: GLA CINE Unit Launch
```ini
Behavior               = BaikonurLaunchPower ModuleTag_06
  SpecialPowerTemplate = SuperweaponLaunchBaikonurRocket
  DetonationObject     = BaikonurRocketDetonation
End
```

### Example 3: Civilian Unit Launch
```ini
Behavior               = BaikonurLaunchPower ModuleTag_06
  SpecialPowerTemplate = SuperweaponLaunchBaikonurRocket
  DetonationObject     = BaikonurRocketDetonation
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/BaikonurLaunchPower.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/BaikonurLaunchPower.cpp)
