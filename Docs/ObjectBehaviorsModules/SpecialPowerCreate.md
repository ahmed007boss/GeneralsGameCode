# SpecialPowerCreate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpecialPowerCreate provides functionality for creating special power effects when objects are created or spawned.

**Base Class:** [`CreateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)

## Usage

Used by objects that can trigger special powers upon creation or when specific conditions are met.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America CINE Unit Special Power Create
```ini
Behavior = SpecialPowerCreate ModuleTag_16
  ;nothing
End
```

### Example 2: Faction Building Special Power Create
```ini
Behavior = SpecialPowerCreate ModuleTag_16
  ;nothing
End
```

### Example 3: GLA Mig21 Special Power Create
```ini
Behavior = SpecialPowerCreate ModuleTag_05
  ;nothing
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/SpecialPowerCreate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/SpecialPowerCreate.cpp)
