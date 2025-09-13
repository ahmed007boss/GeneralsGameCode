# WeaponBonusUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

WeaponBonusUpgrade provides weapon bonus functionality for objects that can provide weapon bonuses or enhancements.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can provide weapon bonuses, enhance weapon capabilities, or manage weapon enhancement systems.

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
Behavior = WeaponBonusUpgrade Upgrade_05
  TriggeredBy = Upgrade_GLAAPRockets
End
```

### Example 2
```ini
Behavior = WeaponBonusUpgrade Upgrade_03
  TriggeredBy = Upgrade_GLAAPBullets
End
```

### Example 3
```ini
Behavior = WeaponBonusUpgrade ModuleTag_99
  TriggeredBy = Upgrade_AmericaLaserMissiles
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/WeaponBonusUpgrade.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/WeaponBonusUpgrade.cpp)
