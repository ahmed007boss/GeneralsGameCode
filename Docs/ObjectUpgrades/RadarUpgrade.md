# RadarUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

RadarUpgrade provides radar enhancement functionality for objects that can upgrade their radar capabilities.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can upgrade their radar capabilities, enhance detection range, or improve radar systems.

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
Behavior         = RadarUpgrade ModuleTag_Radar2
  TriggeredBy   = Upgrade_GLA ;Upgrade_ChinaRadar
  DisableProof  = Yes ; Won't be disabled by power low
End
```

### Example 2
```ini
Behavior        = RadarUpgrade Upgrade_04
  TriggeredBy   = Upgrade_GroundRadarDrone
  DisableProof  = Yes ; Won't be disabled by power low
End
```

### Example 3
```ini
Behavior         = RadarUpgrade ModuleTag_Radar2
  TriggeredBy   = Upgrade_CHINA ;Upgrade_ChinaRadar
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/RadarUpgrade.cpp`](../../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/RadarUpgrade.cpp)
