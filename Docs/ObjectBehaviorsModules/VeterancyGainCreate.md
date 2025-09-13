# VeterancyGainCreate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

VeterancyGainCreate provides functionality for granting veterancy experience when objects are created or spawned.

## Usage

Used by objects that can grant veterancy experience to other objects upon creation or when specific conditions are met.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA AT Site Veterancy Gain Create
```ini
Behavior = VeterancyGainCreate Upgrade_09
  ;nothing
End
```

### Example 2: America CINE Unit Veterancy Gain Create
```ini
Behavior = VeterancyGainCreate ModuleTag_02
  ;nothing
End
```

### Example 3: System Veterancy Gain Create
```ini
Behavior = VeterancyGainCreate ModuleTag_05
  ;nothing
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/VeterancyGainCreate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/VeterancyGainCreate.cpp)
