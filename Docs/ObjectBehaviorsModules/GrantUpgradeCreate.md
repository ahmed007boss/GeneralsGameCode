# GrantUpgradeCreate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

GrantUpgradeCreate provides functionality for granting upgrades when objects are created or spawned.

**Base Class:** [`CreateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)

## Usage

Used by objects that can grant upgrades to other objects upon creation or when specific conditions are met.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Special Object Grant Upgrade Create
```ini
Behavior = GrantUpgradeCreate ModuleTag_04
  UpgradeToGrant = Upgrade_AmericaRangerFlashBangGrenade
End
```

### Example 2: GLA Special Object Grant Upgrade Create Alternative
```ini
Behavior = GrantUpgradeCreate ModuleTag_04
  UpgradeToGrant = Upgrade_AmericaRangerFlashBangGrenade
End
```

### Example 3: GLA Special Object Grant Upgrade Create Third
```ini
Behavior = GrantUpgradeCreate ModuleTag_04
  UpgradeToGrant = Upgrade_AmericaRangerFlashBangGrenade
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/GrantUpgradeCreate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/GrantUpgradeCreate.cpp)
