# SquishCollide

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SquishCollide provides collision behavior for objects that can crush or squish other objects upon collision.

**Base Class:** [`CollideModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h)

## Usage

Used by objects that can crush smaller units or structures when they collide, such as large vehicles or buildings.

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
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/SquishCollide.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/SquishCollide.cpp)
