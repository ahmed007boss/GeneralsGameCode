# ExperienceScalarUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ExperienceScalarUpgrade provides experience scaling functionality for objects that can modify experience gain rates.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can modify experience gain rates, provide experience bonuses, or manage experience scaling.

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
Behavior = ExperienceScalarUpgrade Upgrade_02
  TriggeredBy = Upgrade_BallisticCommandset
  AddXPScalar = 1.0 ;Increases experience gained by an additional 100%
End
```

### Example 2
```ini
Behavior = ExperienceScalarUpgrade Upgrade_02
  TriggeredBy = Upgrade_BallisticCommandset
  AddXPScalar = 1.0 ;Increases experience gained by an additional 100%
End
```

### Example 3
```ini
Behavior = ExperienceScalarUpgrade Upgrade_03
  TriggeredBy = Upgrade_BallisticCommandset
  AddXPScalar = 1.0 ;Increases experience gained by an additional 100%
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ExperienceScalarUpgrade.cpp`](../../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ExperienceScalarUpgrade.cpp)
