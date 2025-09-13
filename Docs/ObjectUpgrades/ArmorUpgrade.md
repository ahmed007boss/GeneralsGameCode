# ArmorUpgrade

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

ArmorUpgrade provides armor enhancement functionality for objects that can upgrade their armor or defense capabilities.

**Base Class:** [`UpgradeModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can upgrade their armor, enhance defense capabilities, or improve protection systems.

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
Behavior = ArmorUpgrade ModuleTag_Upgrade04
  TriggeredBy = Upgrade_GLAFortifiedStructure
End
```

### Example 2
```ini
Behavior                = ArmorUpgrade Upgrade_05
  TriggeredBy           = Upgrade_LightVehicleArmor
End
```

### Example 3
```ini
Behavior        = ArmorUpgrade ModuleTag_Armor01
  TriggeredBy   = Upgrade_GLAFortifiedStructure
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h`](../../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ArmorUpgrade.cpp`](../../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Upgrade/ArmorUpgrade.cpp)
