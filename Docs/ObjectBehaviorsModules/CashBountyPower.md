# CashBountyPower

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CashBountyPower provides special power functionality for cash bounty systems.

**Base Class:** [`SpecialPowerModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)

## Usage

Used by objects that can provide cash bounties as special powers or rewards.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Cash Bounty Power
```ini
Behavior = CashBountyPower ModuleTag_05
  SpecialPowerTemplate    = SpecialAbilityCashBounty1
  Bounty                  = 7%
End
```

### Example 2: System Cash Bounty Power Alternative
```ini
Behavior = CashBountyPower ModuleTag_05
  SpecialPowerTemplate    = SpecialAbilityCashBounty1
  Bounty                  = 7%
End
```

### Example 3: System Cash Bounty Power Third
```ini
Behavior = CashBountyPower ModuleTag_05
  SpecialPowerTemplate    = SpecialAbilityCashBounty1
  Bounty                  = 7%
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/CashBountyPower.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/CashBountyPower.cpp)
