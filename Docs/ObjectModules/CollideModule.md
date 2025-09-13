# CollideModule

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CollideModule is the base class for collision modules that handle object collision detection and response.

**Base Class:** [`BehaviorModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h), [`CollideModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h)

## Usage

Serves as the foundation for specialized collision modules that implement different collision behaviors.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: AT Site SquishCollide
```ini
Behavior = SquishCollide ModuleTag_06
  ;nothing
End
```

### Example 2: Stinger Site SquishCollide
```ini
Behavior = SquishCollide ModuleTag_08
  ;nothing
End
```

### Example 3: Fortress Turret SquishCollide
```ini
Behavior = SquishCollide ModuleTag_08
  ;nothing
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/CollideModule.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/CollideModule.cpp)
