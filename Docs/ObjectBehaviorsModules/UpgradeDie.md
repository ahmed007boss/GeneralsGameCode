# UpgradeDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

UpgradeDie provides death mechanics that trigger upgrades when objects die.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that need to trigger upgrades or special effects when they die.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Special Object Upgrade Die
```ini
Behavior = UpgradeDie ModuleTag_RemUP
  ; This frees the object based upgrade for the producer object.
  DeathTypes = ALL
  UpgradeToRemove = Upgrade_GenericObject300 ModuleTag_Tower04
End
```

### Example 2: GLA Special Object Upgrade Die Alternative
```ini
Behavior = UpgradeDie ModuleTag_RemUP
  ; This frees the object based upgrade for the producer object.
  DeathTypes = ALL
  UpgradeToRemove = Upgrade_GenericObject300 ModuleTag_Tower04
End
```

### Example 3: GLA Towers Upgrade Die
```ini
Behavior = UpgradeDie ModuleTag_RemUP
  ; This frees the object based upgrade for the producer object.
  DeathTypes = ALL
  UpgradeToRemove = Upgrade_GenericObject300 ModuleTag_Tower04
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/UpgradeDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/UpgradeDie.cpp)
