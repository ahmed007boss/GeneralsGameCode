# SpawnBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

SpawnBehavior provides spawning functionality for objects that can create or spawn other objects.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`SpawnBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpawnBehavior.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by objects that can spawn other units or objects, such as spawn points, production buildings, or special spawn generators.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Dushka Nest Spawn Behavior
```ini
Behavior                = SpawnBehavior ModuleTag_06
  SpawnNumber           = 1
  SpawnReplaceDelay     = 40000 ; 19500 ;msec
  SpawnTemplateName     = GLAInfantryDushkaGunner
  CanReclaimOrphans     = No
End
```

### Example 2: GLA AT Site Spawn Behavior
```ini
Behavior = SpawnBehavior ModuleTag_Defender01
  SpawnNumber = 3
  SpawnReplaceDelay = 30000
  SpawnTemplateName = GLAInfantryATSiteDefender
  SpawnTemplateName = GLAInfantryATSiteDefender
  SpawnTemplateName = GLAInfantryATSiteDefender
  CanReclaimOrphans = No
  SpawnedRequireSpawner = Yes
  SlavesHaveFreeWill = No
End
```

### Example 3: GLA Dushka Nest Spawn Behavior Alternative
```ini
Behavior                = SpawnBehavior ModuleTag_06
  SpawnNumber           = 1
  SpawnReplaceDelay     = 40000 ; 19500 ;msec
  SpawnTemplateName     = GLAInfantryDushkaGunner
  CanReclaimOrphans     = No
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpawnBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpawnBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/SpawnBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/SpawnBehavior.cpp)
