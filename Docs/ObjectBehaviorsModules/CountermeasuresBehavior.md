# CountermeasuresBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

CountermeasuresBehavior provides countermeasure functionality for objects, allowing them to deploy defensive measures against incoming threats.

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h), [`CountermeasuresBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CountermeasuresBehavior.h)

## Usage

Used by units that can deploy countermeasures such as flares, chaff, or other defensive systems to evade or counter incoming weapons.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: China H20 Countermeasures
```ini
Behavior                = CountermeasuresBehavior Upgrade_05
  TriggeredBy           = Upgrade_AmericaCountermeasures
  FlareTemplateName     = CountermeasureFlare
  FlareBoneBaseName     = Flare ; Name of the base flare bone (Flare01, Flare02, Flare03)
  VolleySize            = 2     ; Number of flares launched per volley (requires bones)
  VolleyArcAngle        = 60.0  ; Max angle of flare relative to forward direction (with VolleySize of 1, flare will always goes straight back).
  VolleyVelocityFactor  = 2.0   ; Shoots out flares at a stronger velocity with a higher value.
  DelayBetweenVolleys   = 650  ; Time between flare volleys
End
```

### Example 2: Russia Tu22M3 Countermeasures
```ini
Behavior                = CountermeasuresBehavior Upgrade_02
  TriggeredBy           = Upgrade_AmericaCountermeasures
  FlareTemplateName     = RuCountermeasureECMJet
  FlareBoneBaseName     = Flare ; Name of the base flare bone (Flare01, Flare02, Flare03)
  VolleySize            = 1   ; Number of flares launched per volley (requires bones)
  VolleyArcAngle        = 0  ; Max angle of flare relative to forward direction (with VolleySize of 1, flare will always goes straight back).
  VolleyVelocityFactor  = 0   ; Shoots out flares at a stronger velocity with a higher value.
  DelayBetweenVolleys   = 100  ; Time between flare volleys
  NumberOfVolleys       = 4    ; Number of times the volleys will fire before reloading
End
```

### Example 3: America CINE Unit Countermeasures (Commented)
```ini
;  Behavior                = CountermeasuresBehavior ModuleTag_13
;    TriggeredBy           = Upgrade_AmericaCountermeasures
;    FlareTemplateName     = CountermeasureFlare
;    FlareBoneBaseName     = Flare
;    VolleySize            = 2
;    VolleyArcAngle        = 60.0
;    VolleyVelocityFactor  = 2.0
;    DelayBetweenVolleys   = 650
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CountermeasuresBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CountermeasuresBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/CountermeasuresBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/CountermeasuresBehavior.cpp)
