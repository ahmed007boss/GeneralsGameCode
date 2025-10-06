# AutoHealBehavior

AutoHealBehavior provides automatic healing functionality for objects, allowing them to heal themselves or nearby friendly units over time.

## Overview

The `AutoHealBehavior` class manages automatic healing systems that can heal the object itself or nearby friendly units within a specified radius. It supports upgrade-based activation, area healing, particle effects, and selective healing based on object types. The behavior is commonly used for medical buildings, repair facilities, and units with regenerative abilities.

## Usage

Used by objects that need automatic healing capabilities, such as medical buildings, repair facilities, or units with regenerative abilities. This is a **behavior module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- Healing only works on objects within the same team/player
- Area healing is limited by the specified radius or player ownership
- The behavior can be configured for single burst healing or continuous healing over time

**Conditions**:
- AutoHealBehavior can heal individual objects or provide area healing within a specified radius
- The behavior integrates with the upgrade system for conditional activation
- Area healing can target specific object types using KindOf and ForbiddenKindOf filters
- Particle effects provide visual feedback for healing operations
- **Multiple instances behavior**: Multiple instances can coexist; each operates independently with its own healing rates and conditions

**Dependencies**:
- Requires an object with health system (ActiveBody) to function
- Objects with ActiveBody (see [ActiveBody documentation](../ObjectModules/ActiveBody.md)) can be healed
- Healing is affected by damage types and armor systems (see [Armor documentation](../../Armor.md))

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
  - [Basic Healing Settings](#basic-healing-settings)
  - [Area Healing Settings](#area-healing-settings)
  - [Upgrade Integration](#upgrade-integration)
  - [Particle Effects](#particle-effects)
  - [Target Selection](#target-selection)
- [Enum Value Lists](#enum-value-lists)
- [Examples](#examples)
- [Template](#template)
- [Notes](#notes)

- [Source Files](#source-files)
- [Changes History](#changes-history)
- [Status](#status)
  - [Reviews (0)](#modder-reviews)

## Properties

### Basic Healing Settings

#### `HealingAmount` *(v1.04)*
- **Type**: `Int`
- **Description**: Amount of health points healed per healing pulse. Higher values heal more health per tick, providing faster recovery. Lower values heal less per tick, requiring more time for full healing
- **Default**: `1`
- **Example**: `HealingAmount = 3`

#### `HealingDelay` *(v1.04)*
- **Type**: `UnsignedInt` (milliseconds)
- **Description**: Time interval between healing pulses. Lower values provide faster healing rates, while higher values slow down the healing process. This controls how frequently healing occurs
- **Default**: `1000`
- **Example**: `HealingDelay = 1000`

#### `StartsActive` *(v1.04)*
- **Type**: `Bool`
- **Description**: Whether the healing behavior is active from the start. When true, healing begins immediately upon object creation. When false (default), healing must be activated by upgrades or other conditions
- **Default**: `No`
- **Example**: `StartsActive = No`

#### `SingleBurst` *(v1.04)*
- **Type**: `Bool`
- **Description**: Whether to perform only a single healing burst instead of continuous healing. When true, healing occurs once then stops. When false (default), healing continues at regular intervals until disabled
- **Default**: `No`
- **Example**: `SingleBurst = Yes`

#### `StartHealingDelay` *(v1.04)*
- **Type**: `UnsignedInt` (milliseconds)
- **Description**: Delay after taking damage before auto-healing starts. Higher values require longer waiting periods after damage before healing begins. At 0 (default), healing starts immediately when conditions are met
- **Default**: `0`
- **Example**: `StartHealingDelay = 5000`

### Area Healing Settings

#### `Radius` *(v1.04)*
- **Type**: `Real` (distance)
- **Description**: Radius for area healing effect. Higher values extend the healing range to affect more nearby units. At 0 (default), only heals the object itself
- **Default**: `0.0`
- **Example**: `Radius = 50.0`

#### `AffectsWholePlayer` *(v1.04)*
- **Type**: `Bool`
- **Description**: Whether to affect all objects owned by the player instead of just those in radius. When true, heals all player units regardless of distance. When false (default), only affects units within the specified radius
- **Default**: `No`
- **Example**: `AffectsWholePlayer = Yes`

#### `SkipSelfForHealing` *(v1.04, Generals Zero Hour only)*
- **Type**: `Bool`
- **Description**: Whether to skip healing the object itself when doing area healing. When true, the healing object does not heal itself, only nearby units. When false (default), the object heals both itself and nearby units
- **Default**: `No`
- **Example**: `SkipSelfForHealing = Yes`

### Upgrade Integration

#### `TriggeredBy` *(v1.04)*
- **Type**: `UpgradeMaskType` (bit flags)
- **Description**: Required upgrade flags to activate the healing behavior. When set, healing only occurs when the specified upgrades are active. When 0 (default), healing can occur without upgrade requirements
- **Default**: `0` (none)
- **Example**: `TriggeredBy = Upgrade_GLAJunkRepair`

#### `ConflictsWith` *(v1.04)*
- **Type**: `UpgradeMaskType` (bit flags)
- **Description**: Upgrade flags that conflict with this healing behavior. When the specified upgrades are active, healing is disabled. When 0 (default), no upgrade conflicts prevent healing
- **Default**: `0` (none)
- **Example**: `ConflictsWith = Upgrade_GLACamoNetting`

#### `RequiresAll` *(v1.04)*
- **Type**: `Bool`
- **Description**: Whether all TriggeredBy upgrades must be active (true) or just one (false). When true, all specified upgrades must be active for healing. When false (default), only one upgrade needs to be active
- **Default**: `No`
- **Example**: `RequiresAll = Yes`

### Particle Effects

#### `RadiusParticleSystemName` *(v1.04)*
- **Type**: `ParticleSystemTemplate`
- **Description**: Particle system played for the entire area healing effect duration. When set, displays visual effects during area healing. When empty (default), no particle effects are shown
- **Default**: `""` (empty)
- **Example**: `RadiusParticleSystemName = FX_HealArea`

#### `UnitHealPulseParticleSystemName` *(v1.04)*
- **Type**: `ParticleSystemTemplate`
- **Description**: Particle system played on each unit when it receives healing. When set, displays visual effects on individual units during healing. When empty (default), no pulse effects are shown
- **Default**: `""` (empty)
- **Example**: `UnitHealPulseParticleSystemName = FX_HealPulse`

### Target Selection

#### `KindOf` *(v1.04)*
- **Type**: `KindOfMaskType` (bit flags) (see [KindOfMaskType Values](#kindofmasktype-values) section)
- **Description**: Object types that can be healed by this behavior. When set, only objects with matching types can be healed. When 0 (default), all object types can be healed
- **Default**: `0` (all types)
- **Example**: `KindOf = INFANTRY VEHICLE`

#### `ForbiddenKindOf` *(v1.04, Generals Zero Hour only)*
- **Type**: `KindOfMaskType` (bit flags) (see [KindOfMaskType Values](#kindofmasktype-values) section)
- **Description**: Object types that cannot be healed by this behavior. When set, objects with matching types are excluded from healing. When 0 (default), no object types are forbidden from healing
- **Default**: `0` (no restrictions)
- **Example**: `ForbiddenKindOf = STRUCTURE`

## Enum Value Lists

#### `KindOfMaskType` Values *(v1.04)*
**Source:** [KindOf.cpp](../../GeneralsMD/Code/GameEngine/Source/Common/System/KindOf.cpp#35) - `KindOfMaskType::s_bitNameList[]` array definition

- **`OBSTACLE`** *(v1.04)* - Obstacle objects
- **`SELECTABLE`** *(v1.04)* - Selectable objects
- **`IMMOBILE`** *(v1.04)* - Immobile objects
- **`CAN_ATTACK`** *(v1.04)* - Objects that can attack
- **`STICK_TO_TERRAIN_SLOPE`** *(v1.04)* - Objects that stick to terrain slopes
- **`CAN_CAST_REFLECTIONS`** *(v1.04)* - Objects that can cast reflections
- **`SHRUBBERY`** *(v1.04)* - Shrubbery/vegetation
- **`STRUCTURE`** *(v1.04)* - Building structures
- **`INFANTRY`** *(v1.04)* - Infantry units
- **`VEHICLE`** *(v1.04)* - Vehicle units
- **`AIRCRAFT`** *(v1.04)* - Aircraft units
- **`HUGE_VEHICLE`** *(v1.04)* - Large vehicle units
- **`DOZER`** *(v1.04)* - Dozer vehicles
- **`HARVESTER`** *(v1.04)* - Harvester vehicles
- **`COMMANDCENTER`** *(v1.04)* - Command center buildings
- **`LINEBUILD`** *(v1.04)* - Line building structures
- **`SALVAGER`** *(v1.04)* - Salvager units
- **`WEAPON_SALVAGER`** *(v1.04)* - Weapon salvager units
- **`TRANSPORT`** *(v1.04)* - Transport units
- **`BRIDGE`** *(v1.04)* - Bridge structures
- **`LANDMARK_BRIDGE`** *(v1.04)* - Landmark bridge structures
- **`BRIDGE_TOWER`** *(v1.04)* - Bridge tower structures
- **`PROJECTILE`** *(v1.04)* - Projectile objects
- **`PRELOAD`** *(v1.04)* - Preloaded objects
- **`NO_GARRISON`** *(v1.04)* - Objects that cannot be garrisoned
- **`WAVEGUIDE`** *(v1.04)* - Wave guide objects
- **`WAVE_EFFECT`** *(v1.04)* - Wave effect objects
- **`NO_COLLIDE`** *(v1.04)* - Objects that don't collide
- **`REPAIR_PAD`** *(v1.04)* - Repair pad structures
- **`HEAL_PAD`** *(v1.04)* - Heal pad structures
- **`STEALTH_GARRISON`** *(v1.04)* - Stealth garrison structures
- **`CASH_GENERATOR`** *(v1.04)* - Cash generator structures
- **`DRAWABLE_ONLY`** *(v1.04)* - Drawable only objects
- **`MP_COUNT_FOR_VICTORY`** *(v1.04)* - Multiplayer victory count objects
- **`REBUILD_HOLE`** *(v1.04)* - Rebuild hole structures
- **`SCORE`** *(v1.04)* - Score objects
- **`SCORE_CREATE`** *(v1.04)* - Score creation objects
- **`SCORE_DESTROY`** *(v1.04)* - Score destruction objects
- **`NO_HEAL_ICON`** *(v1.04)* - Objects without heal icon
- **`CAN_RAPPEL`** *(v1.04)* - Objects that can rappel
- **`PARACHUTABLE`** *(v1.04)* - Parachutable objects
- **`CAN_BE_REPULSED`** *(v1.04)* - Objects that can be repulsed
- **`MOB_NEXUS`** *(v1.04)* - Mob nexus objects
- **`IGNORED_IN_GUI`** *(v1.04)* - Objects ignored in GUI
- **`CRATE`** *(v1.04)* - Crate objects
- **`CAPTURABLE`** *(v1.04)* - Capturable objects
- **`CLEARED_BY_BUILD`** *(v1.04)* - Objects cleared by building
- **`SMALL_MISSILE`** *(v1.04)* - Small missile projectiles
- **`ALWAYS_VISIBLE`** *(v1.04)* - Always visible objects
- **`UNATTACKABLE`** *(v1.04)* - Unattackable objects
- **`MINE`** *(v1.04)* - Mine objects
- **`CLEANUP_HAZARD`** *(v1.04)* - Cleanup hazard objects
- **`PORTABLE_STRUCTURE`** *(v1.04)* - Portable structure objects
- **`ALWAYS_SELECTABLE`** *(v1.04)* - Always selectable objects
- **`ATTACK_NEEDS_LINE_OF_SIGHT`** *(v1.04)* - Objects requiring line of sight to attack
- **`WALK_ON_TOP_OF_WALL`** *(v1.04)* - Objects that walk on top of walls
- **`DEFENSIVE_WALL`** *(v1.04)* - Defensive wall structures
- **`FS_POWER`** *(v1.04)* - Firestorm power structures
- **`FS_FACTORY`** *(v1.04)* - Firestorm factory structures
- **`FS_BASE_DEFENSE`** *(v1.04)* - Firestorm base defense structures
- **`FS_TECHNOLOGY`** *(v1.04)* - Firestorm technology structures
- **`AIRCRAFT_PATH_AROUND`** *(v1.04)* - Objects aircraft path around
- **`LOW_OVERLAPPABLE`** *(v1.04)* - Low overlappable objects
- **`FORCEATTACKABLE`** *(v1.04)* - Force attackable objects
- **`AUTO_RALLYPOINT`** *(v1.04)* - Auto rally point objects
- **`TECH_BUILDING`** *(v1.04)* - Technology buildings
- **`POWERED`** *(v1.04)* - Powered structures
- **`PRODUCED_AT_HELIPAD`** *(v1.04)* - Objects produced at helipad
- **`DRONE`** *(v1.04)* - Drone objects
- **`CAN_SEE_THROUGH_STRUCTURE`** *(v1.04)* - Objects that can see through structures
- **`BALLISTIC_MISSILE`** *(v1.04)* - Ballistic missile projectiles
- **`CLICK_THROUGH`** *(v1.04)* - Click through objects
- **`SUPPLY_SOURCE_ON_PREVIEW`** *(v1.04)* - Supply source on preview objects
- **`PARACHUTE`** *(v1.04)* - Parachute objects
- **`GARRISONABLE_UNTIL_DESTROYED`** *(v1.04)* - Garrisonable until destroyed objects
- **`BOAT`** *(v1.04)* - Boat objects
- **`IMMUNE_TO_CAPTURE`** *(v1.04)* - Immune to capture objects
- **`HULK`** *(v1.04)* - Hulk objects
- **`SHOW_PORTRAIT_WHEN_CONTROLLED`** *(v1.04)* - Show portrait when controlled objects
- **`SPAWNS_ARE_THE_WEAPONS`** *(v1.04)* - Spawns are the weapons objects
- **`CANNOT_BUILD_NEAR_SUPPLIES`** *(v1.04)* - Cannot build near supplies objects
- **`SUPPLY_SOURCE`** *(v1.04)* - Supply source objects
- **`REVEAL_TO_ALL`** *(v1.04)* - Reveal to all objects
- **`DISGUISER`** *(v1.04)* - Disguiser objects
- **`INERT`** *(v1.04)* - Inert objects
- **`HERO`** *(v1.04)* - Hero objects
- **`IGNORES_SELECT_ALL`** *(v1.04)* - Ignores select all objects
- **`DONT_AUTO_CRUSH_INFANTRY`** *(v1.04)* - Don't auto crush infantry objects
- **`CLIFF_JUMPER`** *(v1.04)* - Cliff jumper objects
- **`FS_SUPPLY_DROPZONE`** *(v1.04)* - Firestorm supply dropzone structures
- **`FS_SUPERWEAPON`** *(v1.04)* - Firestorm superweapon structures
- **`FS_BLACK_MARKET`** *(v1.04)* - Firestorm black market structures
- **`FS_SUPPLY_CENTER`** *(v1.04)* - Firestorm supply center structures
- **`FS_STRATEGY_CENTER`** *(v1.04)* - Firestorm strategy center structures
- **`MONEY_HACKER`** *(v1.04)* - Money hacker objects
- **`ARMOR_SALVAGER`** *(v1.04)* - Armor salvager objects
- **`REVEALS_ENEMY_PATHS`** *(v1.04)* - Reveals enemy paths objects
- **`BOOBY_TRAP`** *(v1.04)* - Booby trap objects
- **`FS_FAKE`** *(v1.04)* - Firestorm fake structures
- **`FS_INTERNET_CENTER`** *(v1.04)* - Firestorm internet center structures
- **`BLAST_CRATER`** *(v1.04)* - Blast crater objects
- **`PROP`** *(v1.04)* - Prop objects
- **`OPTIMIZED_TREE`** *(v1.04)* - Optimized tree objects
- **`FS_ADVANCED_TECH`** *(v1.04)* - Firestorm advanced tech structures
- **`FS_BARRACKS`** *(v1.04)* - Firestorm barracks structures
- **`FS_WARFACTORY`** *(v1.04)* - Firestorm war factory structures
- **`FS_AIRFIELD`** *(v1.04)* - Firestorm airfield structures
- **`AIRCRAFT_CARRIER`** *(v1.04)* - Aircraft carrier objects
- **`NO_SELECT`** *(v1.04)* - No select objects
- **`REJECT_UNMANNED`** *(v1.04)* - Reject unmanned objects
- **`CANNOT_RETALIATE`** *(v1.04)* - Cannot retaliate objects
- **`TECH_BASE_DEFENSE`** *(v1.04)* - Tech base defense objects
- **`EMP_HARDENED`** *(v1.04)* - EMP hardened objects
- **`DEMOTRAP`** *(v1.04)* - Demo trap objects
- **`CONSERVATIVE_BUILDING`** *(v1.04)* - Conservative building objects
- **`IGNORE_DOCKING_BONES`** *(v1.04)* - Ignore docking bones objects
- **`TANK`** *(v1.04)* - Tank vehicles
- **`APC`** *(v1.04)* - Armored Personnel Carrier vehicles
- **`IFV`** *(v1.04)* - Infantry Fighting Vehicle vehicles
- **`TRUCK`** *(v1.04)* - Truck vehicles
- **`VTOL`** *(v1.04)* - Vertical Take-Off and Landing aircraft
- **`JET`** *(v1.04)* - Jet aircraft
- **`HELICOPTER`** *(v1.04)* - Helicopter aircraft
- **`HOT_AIR_BALLOON`** *(v1.04)* - Hot air balloon aircraft
- **`BLIMP`** *(v1.04)* - Blimp aircraft
- **`LARGE_AIRCRAFT`** *(v1.04)* - Large aircraft
- **`MEDIUM_AIRCRAFT`** *(v1.04)* - Medium aircraft
- **`SMALL_AIRCRAFT`** *(v1.04)* - Small aircraft
- **`ARTILLERY`** *(v1.04)* - Artillery units
- **`HEAVY_ARTILLERY`** *(v1.04)* - Heavy artillery units
- **`ANTI_AIR`** *(v1.04)* - Anti-air units
- **`SAM`** *(v1.04)* - Surface-to-Air Missile units
- **`SCOUT`** *(v1.04)* - Scout units
- **`COMMANDO`** *(v1.04)* - Commando units
- **`HEAVY_INFANTRY`** *(v1.04)* - Heavy infantry units
- **`SUPERHEAVY_VEHICLE`** *(v1.04)* - Super heavy vehicle units
- **`EW_RADAR`** *(v1.04)* - Electronic Warfare radar units
- **`EW_RADAR_JAMMER`** *(v1.04)* - Electronic Warfare radar jammer units
- **`EW_RADIO_JAMMER`** *(v1.04)* - Electronic Warfare radio jammer units
- **`EW_JAMMABLE`** *(v1.04)* - Electronic Warfare jammable units
- **`EW_DIRECT_JAMMABLE`** *(v1.04)* - Electronic Warfare directly jammable units
- **`EW_AREA_JAMMABLE`** *(v1.04)* - Electronic Warfare area jammable units
- **`EW_RADIO_JAMMABLE`** *(v1.04)* - Electronic Warfare radio jammable units
- **`EXTRA1`** through **`EXTRA16`** *(v1.04)* - Custom KindOf types

## Examples

### Scout Van Auto Heal
```ini
Behavior = AutoHealBehavior Upgrade_01
  HealingAmount = 3
  HealingDelay = 1000
  TriggeredBy = Upgrade_GLAJunkRepair
End
```

### Scrap Yard Auto Heal
```ini
Behavior = AutoHealBehavior ModuleTag_JunkInTheTrunk01
  HealingAmount = 2
  HealingDelay = 1000
  StartsActive = No
  TriggeredBy = Upgrade_GLAJunkRepair
End
```

### Medical Building Area Heal
```ini
Behavior = AutoHealBehavior ModuleTag_Medical01
  HealingAmount = 5
  HealingDelay = 2000
  Radius = 100.0
  KindOf = INFANTRY VEHICLE
  ForbiddenKindOf = STRUCTURE
  RadiusParticleSystemName = FX_HealArea
  UnitHealPulseParticleSystemName = FX_HealPulse
  StartsActive = Yes
End
```

### Single Burst Heal
```ini
Behavior = AutoHealBehavior ModuleTag_EmergencyHeal
  HealingAmount = 50
  SingleBurst = Yes
  KindOf = INFANTRY
  AffectsWholePlayer = Yes
  SkipSelfForHealing = Yes
End
```

## Template

```ini
Behavior = AutoHealBehavior ModuleTag_XX
  ; Basic Healing Settings
  HealingAmount = 3                 ; // health points healed per pulse *(v1.04)*
  HealingDelay = 1000               ; // milliseconds between healing pulses *(v1.04)*
  StartsActive = No                 ; // whether healing starts active *(v1.04)*
  SingleBurst = No                  ; // whether to perform single burst only *(v1.04)*
  StartHealingDelay = 0             ; // delay after damage before healing starts *(v1.04)*

  ; Area Healing Settings
  Radius = 0.0                      ; // healing radius (0 = self only) *(v1.04)*
  AffectsWholePlayer = No           ; // affect all player objects *(v1.04)*
  SkipSelfForHealing = No           ; // skip self when area healing *(v1.04, Generals Zero Hour only)*

  ; Upgrade Integration
  TriggeredBy =                     ; // required upgrade flags *(v1.04)*
  ConflictsWith =                   ; // conflicting upgrade flags *(v1.04)*
  RequiresAll = No                  ; // require all TriggeredBy upgrades *(v1.04)*

  ; Particle Effects
  RadiusParticleSystemName =        ; // area healing particle system *(v1.04)*
  UnitHealPulseParticleSystemName = ; // unit healing particle system *(v1.04)*

  ; Target Selection
  KindOf =                          ; // allowed object types *(v1.04)*
  ForbiddenKindOf =                 ; // forbidden object types *(v1.04, Generals Zero Hour only)*
End
```

## Notes

- AutoHealBehavior can heal individual objects or provide area healing within a specified radius
- The behavior integrates with the upgrade system for conditional activation
- Area healing can target specific object types using KindOf and ForbiddenKindOf filters
- Particle effects provide visual feedback for healing operations
- The behavior can be configured for single burst healing or continuous healing over time
- Objects with ActiveBody (see [ActiveBody documentation](../ObjectModules/ActiveBody.md)) can be healed
- Healing is affected by damage types and armor systems (see [Armor documentation](../../Armor.md))

## Source Files

**Base Class:** [`UpdateModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h), [`UpgradeMux`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h), [`DamageModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DamageModule.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AutoHealBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AutoHealBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/AutoHealBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/AutoHealBehavior.cpp)

## Changes History

- No Changes done since 1.04

## Status

- **Documentation Status**: AI Generated Pending Reviews 
- **Last Updated**: 14th of September 2025 by @ahmed Salah using AI

### Modder Reviews 
- No Reviews done yet