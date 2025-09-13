# DeployStyleAIUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

DeployStyleAIUpdate provides AI update functionality for deployable units and structures.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)

## Usage

Used by units that can deploy into different modes or structures with AI-driven deployment logic.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: GLA SURN DeployStyleAIUpdate
```ini
Behavior = DeployStyleAIUpdate ModuleTag_04
  PackTime = 1667
  UnpackTime = 1667
  TurretsFunctionOnlyWhenDeployed = Yes
End
```

### Example 2: GLA Command Truck DeployStyleAIUpdate
```ini
Behavior = DeployStyleAIUpdate ModuleTag_03
  PackTime = 1667
  UnpackTime = 1667
  TurretsFunctionOnlyWhenDeployed = Yes
End
```

### Example 3: China Mortar Soldier DeployStyleAIUpdate
```ini
Behavior = DeployStyleAIUpdate ModuleTag_03
  PackTime = 500
  UnpackTime = 600
  ManualDeployAnimations = No
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/DeployStyleAIUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/DeployStyleAIUpdate.cpp)
