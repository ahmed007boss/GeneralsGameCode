# LaserUpdate

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

LaserUpdate provides laser functionality for objects that can create or use laser effects.

**Base Class:** [`ClientUpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ClientUpdateModule.h)

## Usage

Used by objects that can create laser beams, laser weapons, or laser-based special effects.

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
ClientUpdate = LaserUpdate ModuleTag_02
  MuzzleParticleSystem = RedFlare
  TargetParticleSystem = GenericRedLaserFlare
End
```

### Example 2
```ini
ClientUpdate = LaserUpdate ModuleTag_02
  MuzzleParticleSystem = GenericGreenLaserFlare
  TargetParticleSystem = GenericGreenLaserFlare
End
```

### Example 3
```ini
ClientUpdate = LaserUpdate ModuleTag_07
  MuzzleParticleSystem = GreenPointDefenseLaserFlare
  TargetParticleSystem = GenericGreenLaserFlare
  PunchThroughScalar = 1.5 ; If our target dies, we get this much bigger so it looks like we punched through
End
```

*Examples will be added when this page is completed.*

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/LaserUpdate.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Update/LaserUpdate.cpp)
