# CashHackSpecialPower

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CashHackSpecialPower provides special power functionality for cash hacking systems.

**Base Class:** [`SpecialPowerModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)

## Usage

Used by objects that can hack cash or financial systems as special powers.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: System Cash Hack Special Power
```ini
Behavior           = CashHackSpecialPower ModuleTag_13
  SpecialPowerTemplate = SuperweaponCashHack
  UpgradeMoneyAmount   = SCIENCE_CashHack3 6000
  UpgradeMoneyAmount   = SCIENCE_CashHack2 4000
  MoneyAmount          = 2000  ; amount of money to steal
End
```

### Example 2: China Command Center Cash Hack
```ini
Behavior           = CashHackSpecialPower ModuleTag_88
  SpecialPowerTemplate = SuperweaponCashHack
  UpgradeMoneyAmount   = SCIENCE_CashHack3 6000
  UpgradeMoneyAmount   = SCIENCE_CashHack2 4000
  MoneyAmount          = 2000  ; amount of money to steal
End
```

### Example 3: China Internet Center Cash Hack (Commented)
```ini
;  Behavior           = CashHackSpecialPower ModuleTag_42
;    SpecialPowerTemplate = SuperweaponCashHack
;    UpgradeMoneyAmount   = SCIENCE_CashHack3 6000
;    UpgradeMoneyAmount   = SCIENCE_CashHack2 4000
;    MoneyAmount          = 2000  ; amount of money to steal
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SpecialPowerModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/CashHackSpecialPower.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/SpecialPower/CashHackSpecialPower.cpp)
