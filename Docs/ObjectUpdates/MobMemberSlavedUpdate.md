# MobMemberSlavedUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

MobMemberSlavedUpdate provides mob member slaved functionality for objects that are part of mob formations.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`SlavedUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/MobMemberSlavedUpdate.h)

## Usage

Used by objects that are part of mob formations and need to coordinate with other mob members.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1
```ini
Behavior = MobMemberSlavedUpdate ModuleTag_04
  MustCatchUpRadius   = 40
  NoNeedToCatchUpRadius = 15
  Squirrelliness = 0.05
End
```

### Example 2
```ini
Behavior = MobMemberSlavedUpdate ModuleTag_04
  MustCatchUpRadius   = 70   ; bigger; bigger; bigger; bigger; bigger; bigger
  NoNeedToCatchUpRadius = 25 ; bigger; bigger; bigger; bigger; bigger; bigger
  Squirrelliness = 0.00      ; zero; zero; zero; zero; zero; zero
End
```

### Example 3
```ini
Behavior = MobMemberSlavedUpdate ModuleTag_04
  MustCatchUpRadius   = 40
  NoNeedToCatchUpRadius = 15
  Squirrelliness = 0.05
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/MobMemberSlavedUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/MobMemberSlavedUpdate.cpp)
