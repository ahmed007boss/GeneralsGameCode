# SpecialPower INI Documentation

## Overview

Special powers are player-activated abilities and superweapons. A `specialpower` template defines reload time, science requirements, sounds, UI behavior, cursor radius, viewing helpers, and classification. Objects execute powers via `SpecialPowerModule` and related modules.

## Source Files

- Header: `GeneralsMD/Code/GameEngine/Include/Common/SpecialPower.h` – `SpecialPowerTemplate`, store
- Source: `GeneralsMD/Code/GameEngine/Source/Common/RTS/SpecialPower.cpp` – parse table and type names
- Object modules: `Generals/Code/GameEngine/Source/GameLogic/Object/SpecialPower/*`

## Usage

- INI root: `SpecialPower` blocks define templates, e.g., `SpecialPower DefaultSpecialPower ... End`.
- Objects attach modules (e.g., `SpecialPowerModule`) that reference a `SpecialPowerTemplate`.
- Powers may require `Science` and can share timers across command centers.

## Properties

### General Settings

#### ReloadTime (v1.04)
- Type: UnsignedInt (frames)
- Description: Cooldown before power can be used again

#### RequiredScience (v1.04)
- Type: ScienceType
- Description: Science that must be owned by the player

#### PublicTimer (v1.04)
- Type: Bool
- Description: Shows global countdown timer in UI

#### SharedSyncedTimer (v1.04)
- Type: Bool
- Description: Share cooldown between all of a player's command centers

#### Enum (v1.04)
- Type: SpecialPowerMaskType (bitset)
- Description: Power classification flags used by systems

#### ShortcutPower (v1.04)
- Type: Bool
- Description: Allow firing from side panel shortcut

### Visual and Audio

#### InitiateSound (v1.04)
- Type: AudioEventRTS
- Description: Sound played when power is initiated by a unit

#### InitiateAtLocationSound (v1.04)
- Type: AudioEventRTS
- Description: Sound played at target location

### Targeting Helpers

#### DetectionTime (v1.04)
- Type: UnsignedInt (frames)
- Description: Time before former allies detect defection/infiltration

#### ViewObjectDuration (v1.04)
- Type: UnsignedInt (frames)
- Description: Lifetime of temporary viewing object used to follow effects

#### ViewObjectRange (v1.04)
- Type: Real
- Description: Vision range of viewing object

#### RadiusCursorRadius (v1.04)
- Type: Real
- Description: Radius of the targeting cursor, for area powers

### Classification

#### AcademyClassify (v1.04, Generals Zero Hour only)
- Type: AcademyClassificationType
- Description: Classification used by the academy system for advice/analytics

## Enum Value Lists

#### SpecialPowerType / SpecialPowerMaskType (v1.04)
- Source: `SpecialPowerType.h`, names in `SpecialPower.cpp`
- Includes: `SPECIAL_DAISY_CUTTER`, `SPECIAL_PARADROP_AMERICA`, `SPECIAL_CARPET_BOMB`, `SPECIAL_CLUSTER_MINES`, `SPECIAL_EMP_PULSE`, `SPECIAL_NAPALM_STRIKE`, `SPECIAL_CASH_HACK`, `SPECIAL_NEUTRON_MISSILE`, `SPECIAL_SPY_SATELLITE`, `SPECIAL_DEFECTOR`, `SPECIAL_TERROR_CELL`, `SPECIAL_AMBUSH`, `SPECIAL_BLACK_MARKET_NUKE`, `SPECIAL_ANTHRAX_BOMB`, `SPECIAL_SCUD_STORM`, `SPECIAL_DEMORALIZE` (or `_OBSOLETE`), `SPECIAL_CRATE_DROP`, `SPECIAL_A10_THUNDERBOLT_STRIKE`, `SPECIAL_DETONATE_DIRTY_NUKE`, `SPECIAL_ARTILLERY_BARRAGE`, and Zero Hour additions like `SPECIAL_HELIX_NAPALM_BOMB`, `SPECIAL_BOOBY_TRAP`, `SPECIAL_PARTICLE_UPLINK_CANNON`, `SPECIAL_SPECTRE_GUNSHIP`, `SPECIAL_GPS_SCRAMBLER`, `SPECIAL_FRENZY`, `SPECIAL_SNEAK_ATTACK`, faction-specific variants, and `SPECIAL_BATTLESHIP_BOMBARDMENT`.

## Examples

### Basic Power
```
SpecialPower SpySatellite
  Enum                   = SPECIAL_SPY_SATELLITE
  RequiredScience        = SCIENCE_SpySatellite
  ReloadTime             = 4500
  PublicTimer            = Yes
  SharedSyncedTimer      = Yes
  InitiateSound          = SpySatActivate
  InitiateAtLocationSound= SpySatTarget
  ViewObjectDuration     = 600
  ViewObjectRange        = 300.0
  RadiusCursorRadius     = 200.0
  ShortcutPower          = Yes
End
```

## Notes

- `DefaultSpecialPower` can act as a base; overrides inherit via store logic.
- Module-specific data is defined in each module (e.g., `OCLSpecialPower` has its own parse table: `OCL`, `CreateLocation`, etc.). Document those in their respective module pages.

## Template

```
SpecialPower <Name>
  Enum                    = SPECIAL_...
  RequiredScience         = SCIENCE_...
  ReloadTime              = 0                 ; frames
  PublicTimer             = No                ; show global timer
  SharedSyncedTimer       = No                ; share CC timers
  InitiateSound           = None              ; fire sound
  InitiateAtLocationSound = None              ; target sound
  DetectionTime           = 600               ; defection/infiltration grace
  ViewObjectDuration      = 0                 ; follow cam helper lifetime
  ViewObjectRange         = 0.0               ; helper vision radius
  RadiusCursorRadius      = 0.0               ; cursor radius for area powers
  ShortcutPower           = No                ; allow shortcut firing
  AcademyClassify         = NONE              ; ZH only
End
```

