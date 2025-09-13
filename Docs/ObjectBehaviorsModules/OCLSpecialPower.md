# OCLSpecialPower

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

OCLSpecialPower provides special power functionality for Object Creation List (OCL) systems.

**Base Class:** [`SpecialPowerModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)

## Usage

Used by objects that can create other objects through special powers using OCL systems.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Radar Station OCL Special Power
```ini
Behavior = OCLSpecialPower ModuleTag_RadarUp03
  SpecialPowerTemplate = SpecialPowerRadarVanScan
  OCL = SUPERWEAPON_RadarVanScan
  CreateLocation = CREATE_AT_LOCATION
End
```

### Example 2: GLA Supply Stash OCL Special Power
```ini
Behavior           = OCLSpecialPower ModuleTag_Money01
  SpecialPowerTemplate = SpecialPowerSupplyStash
  OCL = SUPERWEAPON_SupplyStash
  CreateLocation = CREATE_AT_LOCATION
End
```

### Example 3: GLA Secret Lab OCL Special Power
```ini
Behavior           = OCLSpecialPower ModuleTag_GenPower07
  SpecialPowerTemplate = SpecialPowerSecretLab
  OCL = SUPERWEAPON_SecretLab
  CreateLocation = CREATE_AT_LOCATION
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/OCLSpecialPower.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/OCLSpecialPower.cpp)
