# OverchargeBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

OverchargeBehavior provides overcharge functionality for objects that can temporarily boost their capabilities beyond normal limits.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h), [`OverchargeBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/OverchargeBehavior.h)

## Usage

Used by objects that can enter an overcharged state for enhanced performance, such as power plants or energy weapons.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: China Power Plant Overcharge Behavior
```ini
Behavior            = OverchargeBehavior ModuleTag_06
  HealthPercentToDrainPerSecond    = 3% ;% of max health to drain per second
  NotAllowedWhenHealthBelowPercent = 20% ;When currHealth below this, it turns off automatically
End
```

### Example 2: China Power Plant Overcharge Behavior Alternative
```ini
Behavior            = OverchargeBehavior ModuleTag_06
  HealthPercentToDrainPerSecond    = 3% ;% of max health to drain per second
  NotAllowedWhenHealthBelowPercent = 20% ;When currHealth below this, it turns off automatically
End
```

### Example 3: China Power Plant Overcharge Behavior Third
```ini
Behavior            = OverchargeBehavior ModuleTag_06
  HealthPercentToDrainPerSecond    = 3% ;% of max health to drain per second
  NotAllowedWhenHealthBelowPercent = 20% ;When currHealth below this, it turns off automatically
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/OverchargeBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/OverchargeBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/OverchargeBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/OverchargeBehavior.cpp)
