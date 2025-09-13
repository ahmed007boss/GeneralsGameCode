# PreorderCreate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

PreorderCreate provides functionality for preordering objects or units when creation conditions are met.

**Base Class:** [`CreateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)

## Usage

Used by objects that can preorder other objects or units for production or deployment.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Command Center Preorder Create
```ini
Behavior = PreorderCreate ModuleTag_PreorderCreate
End
```

### Example 2: GLA Chemical Lab Preorder Create
```ini
Behavior = PreorderCreate ModuleTag_PreorderCreate
End
```

### Example 3: China Propaganda Center Preorder Create
```ini
Behavior = PreorderCreate ModuleTag_PreorderCreate
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CreateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/PreorderCreate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Create/PreorderCreate.cpp)
