# FireOCLAfterWeaponCooldownUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FireOCLAfterWeaponCooldownUpdate provides functionality for firing Object Creation List (OCL) effects after weapon cooldown periods.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h)

## Usage

Used by objects that need to fire OCL effects after weapon cooldown periods have elapsed.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA Toxin Truck FireOCLAfterWeaponCooldownUpdate
```ini
Behavior = FireOCLAfterWeaponCooldownUpdate Upgrade_04
  WeaponSlot            = SECONDARY
  TriggeredBy           = Upgrade_GLAAnthraxBeta Upgrade_Veterancy_HEROIC
  OCL                   = OCL_PoisonFieldUpgradedMedium
End
```

### Example 2: GLA Toxin Truck FireOCLAfterWeaponCooldownUpdate with Conflicts
```ini
Behavior = FireOCLAfterWeaponCooldownUpdate ModuleTag_08
  WeaponSlot            = SECONDARY
  ConflictsWith         = Upgrade_GLAAnthraxBeta Upgrade_Veterancy_HEROIC
  OCL                   = OCL_PoisonFieldMedium
End
```

### Example 3: GLA CINE Unit FireOCLAfterWeaponCooldownUpdate
```ini
Behavior = FireOCLAfterWeaponCooldownUpdate ModuleTag_13
  WeaponSlot            = SECONDARY
  ConflictsWith         = Upgrade_GLAAnthraxBeta Upgrade_Veterancy_HEROIC
  OCL                   = OCL_PoisonFieldMedium
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FireOCLAfterWeaponCooldownUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/FireOCLAfterWeaponCooldownUpdate.cpp)
