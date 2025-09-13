# WorkerAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

WorkerAIUpdate provides AI update functionality for worker units and construction vehicles.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h), [`DozerAIInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DozerAIUpdate.h), [`SupplyTruckAIInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/SupplyTruckAIUpdate.h), [`WorkerAIInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/WorkerAIUpdate.h)

## Usage

Used by worker units to handle AI-driven construction, resource gathering, and building operations.

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
Behavior = WorkerAIUpdate ModuleTag_03
  RepairHealthPercentPerSecond  = 2%    ; % of max health to repair each second
  BoredTime                     = 5000  ; in milliseconds
  BoredRange                    = 150   ; when bored, we look this far away to do something
```

### Example 2
```ini
Behavior = WorkerAIUpdate ModuleTag_03
  RepairHealthPercentPerSecond  = 2%    ; % of max health to repair each second
  BoredTime                     = 5000  ; in milliseconds
  BoredRange                    = 150   ; when bored, we look this far away to do something
```

### Example 3
```ini
Behavior = WorkerAIUpdate ModuleTag_03
  RepairHealthPercentPerSecond  = 2%    ; % of max health to repair each second
  BoredTime                     = 5000  ; in milliseconds
  BoredRange                    = 150   ; when bored, we look this far away to do something
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/WorkerAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/WorkerAIUpdate.cpp)
