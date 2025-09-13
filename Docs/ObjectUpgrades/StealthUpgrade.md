# StealthUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

StealthUpgrade provides stealth enhancement functionality for objects that can upgrade their stealth capabilities.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can upgrade their stealth capabilities, enhance stealth detection, or improve stealth systems.

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
Behavior = StealthUpgrade Upgrade_02
  TriggeredBy = Upgrade_GenericObject300
End
```

### Example 2
```ini
Behavior = StealthUpgrade ModuleStealth_02
  TriggeredBy = Upgrade_China_StealthTechnologies
End
```

### Example 3
```ini
Behavior = StealthUpgrade Upgrade_03
  TriggeredBy = Upgrade_GenericObject900
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/StealthUpgrade.cpp`](../../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/StealthUpgrade.cpp)
