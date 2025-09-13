# TechBuildingBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

TechBuildingBehavior provides technology building functionality for structures that provide research or technology benefits.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by technology buildings to provide research capabilities, technology unlocks, or special technology-based abilities.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Tech Building Behavior Module 09
```ini
Behavior = TechBuildingBehavior ModuleTag_09
  ;nothing
End
```

### Example 2: Tech Building Behavior Module 10
```ini
Behavior = TechBuildingBehavior ModuleTag_10
  ;nothing
End
```

### Example 3: Tech Building Behavior Module 12
```ini
Behavior = TechBuildingBehavior ModuleTag_12
  ;nothing
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/TechBuildingBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/TechBuildingBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/TechBuildingBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/TechBuildingBehavior.cpp)
