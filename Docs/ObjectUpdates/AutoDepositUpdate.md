# AutoDepositUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

AutoDepositUpdate provides automatic deposit functionality for objects that can automatically deposit resources.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)

## Usage

Used by objects that need to automatically deposit resources or items when certain conditions are met.

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
Behavior = AutoDepositUpdate ModuleTag_05
  DepositTiming       = 60000   ; in milliseconds
  DepositAmount       = 800   ; cash amount to deposit every DepositTiming
  InitialCaptureBonus = 0  ; no initial bonus
End
```

### Example 2
```ini
Behavior = AutoDepositUpdate ModuleTag_05
  DepositTiming       = 20000   ; in milliseconds
  DepositAmount       = 200   ; cash amount to deposit every DepositTiming
End
```

### Example 3
```ini
Behavior              = AutoDepositUpdate ModuleTag_Money
  DepositTiming       = 15000  ; in milliseconds
  DepositAmount       = 100    ; cash amount to deposit every Deposit Timings
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AutoDepositUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AutoDepositUpdate.cpp)
