# ActiveShroudUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ActiveShroudUpgrade provides active shroud functionality for objects that can create or manage active shroud effects.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can create active shroud effects, provide shroud coverage, or manage shroud-based systems.

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
Behavior = ActiveShroudUpgrade ModuleTag_ShroudModule01
  TriggeredBy = Upgrade_GroundRadarDrone
  NewShroudRange = 9999.0
End
```

### Example 2
```ini
Behavior = ActiveShroudUpgrade ModuleTag_12
  TriggeredBy = Upgrade_RUSSIA
  RequiresAllTriggers = No
  NewShroudRange = 375.0
End
```

### Example 3
```ini
Behavior = ActiveShroudUpgrade ModuleTag_03
  TriggeredBy = Upgrade_RUSSIA
  RequiresAllTriggers = No
  NewShroudRange = 375.0
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ActiveShroudUpgrade.cpp`](../../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ActiveShroudUpgrade.cpp)
