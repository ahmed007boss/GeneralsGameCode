# PropagandaTowerBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

PropagandaTowerBehavior provides propaganda tower functionality for structures that can broadcast propaganda effects over a radius.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by propaganda tower structures to provide area-of-effect propaganda benefits or special propaganda abilities.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: China Overlord Propaganda Tower Behavior
```ini
Behavior        = PropagandaTowerBehavior ModuleTag_04
  Radius                = 150.0
  DelayBetweenUpdates   = 2000 ; in milliseconds
  HealPercentEachSecond = 1%   ; get this % of max health every second 
  PulseFX               = FX_PropagandaTowerPropagandaPulse ;plays as often as DelayBetweenUpdates
  UpgradeRequired       = Upgrade_ChinaSubliminalMessaging
End
```

### Example 2: China Helix Propaganda Tower Behavior
```ini
Behavior        = PropagandaTowerBehavior ModuleTag_04
  Radius                = 150.0
  DelayBetweenUpdates   = 2000 ; in milliseconds
  HealPercentEachSecond = 1%   ; get this % of max health every second 
  PulseFX               = FX_HelixPropagandaTowerPropagandaPulse ;plays as often as DelayBetweenUpdates
End
```

### Example 3: China Troop Crawler Propaganda Tower Behavior
```ini
Behavior        = PropagandaTowerBehavior ModuleTag_10
  Radius                = 150.0
  DelayBetweenUpdates   = 2000 ; in milliseconds
  HealPercentEachSecond = 1%   ; get this % of max health every second 
  PulseFX               = FX_PropagandaTowerPropagandaPulse ;plays as often as DelayBetweenUpdates
  UpgradeRequired       = Upgrade_ChinaSubliminalMessaging
  UpgradedHealPercentEachSecond = 2%   ; get this % of max health every second 
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/PropagandaTowerBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/PropagandaTowerBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/PropagandaTowerBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/PropagandaTowerBehavior.cpp)
