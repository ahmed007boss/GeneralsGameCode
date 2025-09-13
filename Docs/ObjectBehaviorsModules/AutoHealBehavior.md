### AutoHealBehavior — Passive/self or area heal over time with upgrade gating

Class: `AutoHealBehavior` — Update module that periodically heals itself and/or nearby allies, optionally gated by upgrades.

## Table of Contents
- Overview
- Usage
- Properties
  - General Settings
  - Area/Target Filters
  - Visuals
  - Upgrade Gating
- Enums
- Examples
- Template
- Cross-References & Source Links

## Overview

`AutoHealBehavior` periodically restores health either to the host object (self-heal) or to nearby eligible units within a radius. Behavior can be gated by upgrades and can play FX on the radius and on each healed unit per pulse.

- Used as: object behavior module (inside an `Object`)
- Base classes: `UpdateModule`, `UpgradeMux`, `DamageModuleInterface`
- GMX vs vanilla: Matches Zero Hour behavior; no GMX-specific changes identified.

## Usage

Add inside an object’s `Behavior` list. If you want it to start only after an upgrade, use upgrade fields under Upgrade Gating.

```
Behavior = AutoHealBehavior ModuleTag_AutoHeal
  StartsActive                      = Yes
  SingleBurst                       = No
  HealingAmount                     = 10
  HealingDelay                      = 1000
  StartHealingDelay                 = 3000
  Radius                            = 100.0
  AffectsWholePlayer                = No
  SkipSelfForHealing                = No
  KindOf                            = INFANTRY VEHICLE
  ForbiddenKindOf                   = STRUCTURE
  RadiusParticleSystemName          = PS_HealAura
  UnitHealPulseParticleSystemName   = PS_HealTick
End
```

## Properties

All properties below are parsed in `buildFieldParse` for `AutoHealBehaviorModuleData`, plus upgrade mux parsing.

### General Settings

#### `StartsActive` (v1.04)
- Type: Bool
- Default: No
- Description: If Yes, healing logic activates immediately without upgrades.

#### `SingleBurst` (v1.04)
- Type: Bool
- Default: No
- Description: If Yes, perform a single heal pulse then stop.

#### `HealingAmount` (v1.04)
- Type: Int
- Default: 0
- Description: Hit points restored per heal pulse to each affected object.

#### `HealingDelay` (v1.04)
- Type: UnsignedInt (milliseconds)
- Default: UINT_MAX
- Description: Interval between heal pulses. Also used to stagger initial wakes.

#### `StartHealingDelay` (v1.04)
- Type: UnsignedInt (milliseconds)
- Default: 0
- Description: Delay after taking damage before auto-heal can resume.

### Area/Target Filters

#### `Radius` (v1.04)
- Type: Real
- Default: 0.0
- Description: Heal area radius. 0 means self-only.

#### `AffectsWholePlayer` (v1.04)
- Type: Bool
- Default: No
- Description: If Yes, attempts to affect all units owned by the player instead of radius scan.

#### `SkipSelfForHealing` (v1.04)
- Type: Bool
- Default: No
- Description: If Yes, do not heal the host object.

#### `KindOf` (v1.04)
- Type: KindOfMaskType
- Default: All bits set
- Description: Only objects with any of these KindOf bits are eligible targets.

#### `ForbiddenKindOf` (v1.04)
- Type: KindOfMaskType
- Default: None
- Description: Objects with any of these KindOf bits are excluded.

### Visuals

#### `RadiusParticleSystemName` (v1.04)
- Type: ParticleSystemTemplate
- Default: None
- Description: Continuous particle system for the overall heal aura while active.

#### `UnitHealPulseParticleSystemName` (v1.04)
- Type: ParticleSystemTemplate
- Default: None
- Description: Particle system played on each healed unit per pulse.

### Upgrade Gating

The following are parsed via `UpgradeMuxData` and apply to this behavior’s activation. See Upgrade docs for details.

#### `TriggeredBy` (v1.04)
- Type: List of AsciiString
- Description: Upgrades that activate this behavior.

#### `ConflictsWith` (v1.04)
- Type: List of AsciiString
- Description: Upgrades that block this behavior when present.

#### `RemovesUpgrades` (v1.04)
- Type: List of AsciiString
- Description: Upgrades to remove when this behavior activates.

#### `FXListUpgrade` (v1.04)
- Type: FXList
- Description: FX played upon activation via upgrade.

#### `RequiresAllTriggers` (v1.04)
- Type: Bool
- Description: If Yes, requires all `TriggeredBy` upgrades; otherwise any one is sufficient.

## Enums

- KindOfMaskType: See `KindOfMaskType Values` in Object documentation.

## Examples

### Self-heal only after damage delay
```
Behavior = AutoHealBehavior ModuleTag_SelfHeal
  StartsActive          = Yes
  SingleBurst           = No
  HealingAmount         = 5
  HealingDelay          = 2000
  StartHealingDelay     = 5000
  Radius                = 0.0
  SkipSelfForHealing    = No
End
```

### Aura heal gated by upgrade
```
Behavior = AutoHealBehavior ModuleTag_AuraHeal
  StartsActive                      = No
  SingleBurst                       = No
  HealingAmount                     = 8
  HealingDelay                      = 1000
  Radius                            = 120.0
  KindOf                            = INFANTRY VEHICLE
  ForbiddenKindOf                   = STRUCTURE
  RadiusParticleSystemName          = PS_HealAura
  UnitHealPulseParticleSystemName   = PS_HealTick
  TriggeredBy                       = Upgrade_GenericHealing
  RequiresAllTriggers               = No
End
```

## Template

```
; Template for AutoHealBehavior
; -----------------------------
; General Settings
StartsActive = No                       ; // activate without upgrades *(v1.04)*
SingleBurst = No                        ; // one pulse then stop *(v1.04)*
HealingAmount = 10                      ; // HP restored per pulse *(v1.04)*
HealingDelay = 1000                     ; // interval between pulses (ms) *(v1.04)*
StartHealingDelay = 3000                ; // delay after damage before healing *(v1.04)*

; Area/Target Filters
Radius = 100.0                          ; // 0=self-only; >0 = aura radius *(v1.04)*
AffectsWholePlayer = No                  ; // heal all owned units *(v1.04)*
SkipSelfForHealing = No                  ; // do not heal the host *(v1.04)*
KindOf = INFANTRY VEHICLE                ; // eligible targets by KindOf *(v1.04)*
ForbiddenKindOf = STRUCTURE              ; // excluded targets by KindOf *(v1.04)*

; Visuals
RadiusParticleSystemName = PS_HealAura   ; // aura particle system *(v1.04)*
UnitHealPulseParticleSystemName = PS_HealTick ; // unit pulse particle *(v1.04)*

; Upgrade Gating
TriggeredBy = Upgrade_GenericHealing     ; // upgrades that activate *(v1.04)*
ConflictsWith =                          ; // upgrades that block *(v1.04)*
RemovesUpgrades =                        ; // upgrades to remove *(v1.04)*
FXListUpgrade =                          ; // FX on upgrade activation *(v1.04)*
RequiresAllTriggers = No                 ; // require all triggers vs any *(v1.04)*
```

## Cross-References & Source Links

- Headers: `GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AutoHealBehavior.h`
- Source: `Generals/Code/GameEngine/Source/GameLogic/Object/Behavior/AutoHealBehavior.cpp`
- Base: `UpdateModule`, `UpgradeMux`, `DamageModuleInterface`
- Related: `KindOf` documentation; Upgrade system (UpgradeMuxData).

