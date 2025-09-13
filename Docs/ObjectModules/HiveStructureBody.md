# HiveStructureBody

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

HiveStructureBody provides specialized body mechanics for hive-like structures with unique health and damage systems.

**Base Class:** [`StructureBody`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/StructureBody.h)

## Usage

Used by hive structures that have special health mechanics, such as distributed health across multiple components.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: AT Site Hive Structure
```ini
Body = HiveStructureBody ModuleTag_Body01
  MaxHealth = 2200.0
  InitialHealth = 2200.0
  PropagateDamageTypesToSlavesWhenExisting = NONE +SMALL_ARMS +SNIPER +POISON +RADIATION +SURRENDER +MICROWAVE
  SwallowDamageTypesIfSlavesNotExisting = NONE +SNIPER +POISON +SURRENDER
  SubdualDamageCap = 1200
  SubdualDamageHealRate = 500
  SubdualDamageHealAmount = 100
End
```

### Example 2: Dushka Nest Hive Structure
```ini
Body = HiveStructureBody ModuleTag_04
  MaxHealth = 1500.0
  InitialHealth = 1500.0
  PropagateDamageTypesToSlavesWhenExisting = NONE +SMALL_ARMS +SNIPER +POISON +RADIATION +SURRENDER +MICROWAVE
  SwallowDamageTypesIfSlavesNotExisting = NONE +SNIPER +POISON +SURRENDER
End
```

### Example 3: Stinger Site Hive Structure
```ini
Body = HiveStructureBody ModuleTag_04
  MaxHealth = 1800.0
  InitialHealth = 1800.0
  PropagateDamageTypesToSlavesWhenExisting = NONE +SMALL_ARMS +SNIPER +POISON +RADIATION +SURRENDER +MICROWAVE
  SwallowDamageTypesIfSlavesNotExisting = NONE +SNIPER +POISON +SURRENDER
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/HiveStructureBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/HiveStructureBody.cpp)
