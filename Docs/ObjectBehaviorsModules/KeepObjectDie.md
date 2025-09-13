# KeepObjectDie

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

KeepObjectDie provides death mechanics that keep the object alive in a special state rather than destroying it.

**Base Class:** [`DieModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that need to enter a special state upon "death" rather than being completely destroyed.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: America CINE Unit Keep Object Die
```ini
; never truly destroyed, even when reduced to zero health. Also note that garrisonable
; buildings automatically stick around because GarrisonContain has it's own DieModule
Behavior = KeepObjectDie ModuleTag_IWantRubble
End
```

### Example 2: America CINE Unit Keep Object Die Alternative
```ini
Behavior = KeepObjectDie ModuleTag_IWantRubble
End
```

### Example 3: GLA CINE Unit Keep Object Die
```ini
Behavior = KeepObjectDie ModuleTag_IWantRubble
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/KeepObjectDie.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Die/KeepObjectDie.cpp)
