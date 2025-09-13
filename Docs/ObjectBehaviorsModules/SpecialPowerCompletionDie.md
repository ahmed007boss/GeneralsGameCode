# SpecialPowerCompletionDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpecialPowerCompletionDie provides death mechanics that trigger when special powers are completed.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that need to die or be destroyed when special powers are completed.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Weapon Object Special Power Completion Die
```ini
Behavior = SpecialPowerCompletionDie ModuleTag_06
  SpecialPowerTemplate = SU30GroundAttack
End
```

### Example 2: Weapon Object Special Power Completion Die Alternative
```ini
Behavior = SpecialPowerCompletionDie ModuleTag_09
  SpecialPowerTemplate = SU30GroundAttack
End
```

### Example 3: Weapon Object Special Power Completion Die Third
```ini
Behavior = SpecialPowerCompletionDie ModuleTag_11
  SpecialPowerTemplate = SU30GroundAttack
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/SpecialPowerCompletionDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/SpecialPowerCompletionDie.cpp)
