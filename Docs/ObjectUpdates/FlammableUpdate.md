# FlammableUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FlammableUpdate provides flammability functionality for objects that can catch fire or be affected by fire.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

## Usage

Used by objects that can catch fire, spread fire, or are affected by fire damage and effects.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Radar Station FlammableUpdate
```ini
Behavior = FlammableUpdate ModuleTag_Death01
  AflameDuration = 5000
  AflameDamageAmount = 5
  AflameDamageDelay = 500
End
```

### Example 2: GLA Scout Van FlammableUpdate
```ini
Behavior = FlammableUpdate ModuleTag_06
  AflameDuration = 5000         ; If I catch fire, I'll burn for this long...
  AflameDamageAmount = 3       ; taking this much damage...
  AflameDamageDelay = 500       ; this often.
End
```

### Example 3: GLA Airfield FlammableUpdate
```ini
Behavior = FlammableUpdate ModuleTag_17
  AflameDuration = 5000         ; If I catch fire, I'll burn for this long...
  AflameDamageAmount = 5       ; taking this much damage...
  AflameDamageDelay = 500       ; this often.
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FlammableUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FlammableUpdate.cpp)
