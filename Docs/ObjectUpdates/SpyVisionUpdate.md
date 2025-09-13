# SpyVisionUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpyVisionUpdate provides spy vision functionality for objects that can provide spy vision or enhanced visibility.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that can provide spy vision, enhanced visibility, or stealth detection capabilities.

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
Behavior         = SpyVisionUpdate ModuleTag_08
  NeedsUpgrade  = Yes
  SelfPowered   = Yes         ; No SpecialPower module, turns self on and off on timers
  SelfPoweredDuration = 30000
End
```

### Example 2
```ini
Behavior         = SpyVisionUpdate ModuleTag_15
  NeedsUpgrade  = Yes
  SelfPowered   = Yes        ; No SpecialPower module, turns self on and off on timers (No timers means always on)
  SelfPoweredDuration = 3000
End
```

*Only 2 examples of SpyVisionUpdate were found in the INI files.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpyVisionUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/SpyVisionUpdate.cpp)
