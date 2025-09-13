# DozerAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DozerAIUpdate provides AI update functionality for dozer units and construction vehicles.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h), [`DozerAIInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DozerAIUpdate.h)

## Usage

Used by dozer units to handle AI-driven construction, repair, and building operations.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: USA Dozer DozerAIUpdate
```ini
Behavior = DozerAIUpdate ModuleTag_03
  RepairHealthPercentPerSecond = 2%    ; % of max health to repair each second
  BoredTime                    = 5000  ; in milliseconds
  BoredRange                   = 150   ; when bored, we look this far away to do something
End
```

### Example 2: China Dozer DozerAIUpdate
```ini
Behavior = DozerAIUpdate ModuleTag_03
  RepairHealthPercentPerSecond = 2%    ; % of max health to repair each second
  BoredTime                    = 5000  ; in milliseconds
  BoredRange                   = 150   ; when bored, we look this far away to do something
End
```

### Example 3: America Misc Unit DozerAIUpdate
```ini
Behavior = DozerAIUpdate ModuleTag_03
  RepairHealthPercentPerSecond = 3%    ; % of max health to repair each second
  BoredTime                    = 5000  ; in milliseconds
  BoredRange                   = 200   ; when bored, we look this far away to do something
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/DozerAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/DozerAIUpdate.cpp)
