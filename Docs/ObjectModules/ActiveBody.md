# ActiveBody

ActiveBody provides comprehensive health and damage management for objects that can take damage, be healed, and be destroyed through combat.

## Overview

The `ActiveBody` class manages active health systems for objects that can take damage and be destroyed. It handles health tracking, damage states, healing, subdual damage, electronic warfare damage, and visual damage effects. Objects with ActiveBody can be damaged by weapons, healed by repair systems, and transition through different damage states that affect their appearance and functionality.

## Usage

Used by objects that have active health systems, can take damage, and can be destroyed through combat. This is a **body module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- ActiveBody automatically manages damage states (PRISTINE, DAMAGED, REALLYDAMAGED, RUBBLE) based on health percentage
- Damage states affect visual appearance and particle systems
- Subdual damage can disable objects without destroying them
- Electronic warfare damage can jam electronic systems
- Objects automatically heal subdual and EW damage over time if healing rates are set
- Damage states are calculated based on global thresholds defined in game data
- Subdual and EW damage properties are exclusive to Generals Zero Hour (v1.04)

**Conditions**:
- Objects with ActiveBody can be targeted by weapons (see [Weapon documentation](../Weapon.md)) and affected by damage types
- Veterancy levels can modify maximum health and healing rates
- ActiveBody integrates with armor systems (see [Armor documentation](../Armor.md)) and damage effects
- **Multiple instances behavior**: Only one ActiveBody instance should exist per object; multiple instances may cause conflicts in health management

**Dependencies**:
- Requires proper armor and damage type definitions to function correctly

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
  - [Health Settings](#health-settings)
  - [Subdual Damage Settings](#subdual-damage-settings)
  - [Electronic Warfare Settings](#electronic-warfare-settings)
  - [Component Settings](#component-settings)
- [Enum Value Lists](#enum-value-lists)
- [Examples](#examples)
- [Template](#template)
- [Notes](#notes)

## Properties

### Health Settings

#### `MaxHealth` *(v1.04)*
- **Type**: `Real`
- **Description**: Maximum health points the object can have. Higher values make objects more durable and resistant to damage. This determines the total damage capacity before destruction
- **Default**: `100.0`
- **Example**: `MaxHealth = 500.0`

#### `InitialHealth` *(v1.04)*
- **Type**: `Real`
- **Description**: Starting health points when the object is created. Higher values allow objects to spawn with more health than their maximum, providing temporary damage buffer. Lower values spawn objects at reduced health
- **Default**: `100.0`
- **Example**: `InitialHealth = 500.0`

### Subdual Damage Settings

#### `SubdualDamageCap` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Maximum subdual damage that can accumulate before the object is subdued. Higher values allow objects to absorb more subdual damage before becoming incapacitated. At 0 (default), objects cannot be subdued
- **Default**: `0.0`
- **Example**: `SubdualDamageCap = 350.0`

#### `SubdualDamageHealRate` *(v1.04, Generals Zero Hour only)*
- **Type**: `UnsignedInt` (milliseconds)
- **Description**: Time interval between subdual damage healing attempts. Lower values heal subdual damage more frequently, while higher values heal less often. At 0 (default), no automatic subdual healing occurs
- **Default**: `0`
- **Example**: `SubdualDamageHealRate = 500`

#### `SubdualDamageHealAmount` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Amount of subdual damage healed per healing interval. Higher values heal more subdual damage per tick, while lower values heal less. At 0 (default), no subdual healing occurs
- **Default**: `0.0`
- **Example**: `SubdualDamageHealAmount = 50.0`

### Electronic Warfare Settings

#### `EWDamageCap` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Maximum electronic warfare damage that can accumulate before the object is jammed. Higher values allow objects to absorb more EW damage before becoming electronically disabled. At 0 (default), objects cannot be jammed
- **Default**: `0.0`
- **Example**: `EWDamageCap = 200.0`

#### `EWDamageHealRate` *(v1.04, Generals Zero Hour only)*
- **Type**: `UnsignedInt` (milliseconds)
- **Description**: Time interval between electronic warfare damage healing attempts. Lower values heal EW damage more frequently, while higher values heal less often. At 0 (default), no automatic EW healing occurs
- **Default**: `0`
- **Example**: `EWDamageHealRate = 1000`

#### `EWDamageHealAmount` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Amount of electronic warfare damage healed per healing interval. Higher values heal more EW damage per tick, while lower values heal less. At 0 (default), no EW healing occurs
- **Default**: `0.0`
- **Example**: `EWDamageHealAmount = 25.0`

### Component Settings

#### `Component` *(v1.04, Generals Zero Hour only)*
- **Type**: `Component` block
- **Description**: Defines individual component health systems for detailed damage modeling. Each component can have its own health, healing behavior, and hit side restrictions. Components allow for realistic damage simulation where different parts of an object can be damaged independently
- **Default**: No components defined
- **Example**: 
```ini
Component PRIMARY_WEAPON
  MaxHealth = 100.0
  InitialHealth = 100.0
  HealingType = NORMAL
  DamageOnSides = HIT_SIDE_FRONT HIT_SIDE_TOP
End
```

#### Component Properties

##### `MaxHealth` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Maximum health points for this specific component. Higher values make the component more durable and resistant to damage. This determines the total damage capacity before the component is destroyed
- **Default**: `0.0`
- **Example**: `MaxHealth = 100.0`

##### `InitialHealth` *(v1.04, Generals Zero Hour only)*
- **Type**: `Real`
- **Description**: Starting health points for this component when the object is created. Higher values allow components to spawn with more health than their maximum, providing temporary damage buffer
- **Default**: `0.0`
- **Example**: `InitialHealth = 100.0`

##### `HealingType` *(v1.04, Generals Zero Hour only)*
- **Type**: `ComponentHealingType` (see [ComponentHealingType Values](#componenthealingtype-values) section)
- **Description**: Defines how this component can be healed. Different healing types control whether components can be fully repaired, partially repaired, or require replacement
- **Default**: `NORMAL`
- **Example**: `HealingType = NORMAL`

##### `DamageOnSides` *(v1.04, Generals Zero Hour only)*
- **Type**: `HitSideFlags` (see [HitSide Values](#hitside-values) section)
- **Description**: Specifies which hit sides can damage this component. If not set (empty), the component can be damaged from any hit side. This allows for realistic damage modeling where certain components are only vulnerable from specific angles
- **Default**: Empty (damageable from all sides)
- **Example**: `DamageOnSides = HIT_SIDE_FRONT HIT_SIDE_TOP`

##### `ReplacementCost` *(v1.04, Generals Zero Hour only)*
- **Type**: `UnsignedInt`
- **Description**: Cost in money to fully replace this component when it's damaged. Higher values make component replacement more expensive. At 0 (default), the component cannot be replaced via the GUI command system
- **Default**: `0`
- **Example**: `ReplacementCost = 500`

## Enum Value Lists

#### `BodyDamageType` Values *(v1.04)*
**Source:** [BodyModule.h](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h#53) - `BodyDamageType` enum definition

- **`BODY_PRISTINE`** *(v1.04)* - Unit should appear in pristine condition
- **`BODY_DAMAGED`** *(v1.04)* - Unit has been damaged
- **`BODY_REALLYDAMAGED`** *(v1.04)* - Unit is extremely damaged / nearly destroyed
- **`BODY_RUBBLE`** *(v1.04)* - Unit has been reduced to rubble/corpse/exploded-hulk, etc

#### `ComponentHealingType` Values *(v1.04, Generals Zero Hour only)*
**Source:** [Component.h](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Component.h#40) - `ComponentHealingType` enum definition

- **`NORMAL`** *(v1.04)* - Can be healed from destroyed to max normally
- **`PARTIAL_ONLY`** *(v1.04)* - Can be healed if not destroyed to max normally
- **`PARTIAL_DESTROYED`** *(v1.04)* - Can be healed from destroyed to partially working normally, but to max needs replacement
- **`PARTIAL_LIMITED`** *(v1.04)* - Can be healed if not destroyed to partially working normally, but to max needs replacement
- **`REPLACEMENT_ONLY`** *(v1.04)* - Cannot be healed normally, needs replacement

#### `HitSide` Values *(v1.04)*
**Source:** [Damage.h](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Damage.h#188) - `HitSide` enum definition

- **`HIT_SIDE_FRONT`** *(v1.04)* - Front side of the object
- **`HIT_SIDE_BACK`** *(v1.04)* - Back side of the object
- **`HIT_SIDE_LEFT`** *(v1.04)* - Left side of the object
- **`HIT_SIDE_RIGHT`** *(v1.04)* - Right side of the object
- **`HIT_SIDE_TOP`** *(v1.04)* - Top side of the object
- **`HIT_SIDE_BOTTOM`** *(v1.04)* - Bottom side of the object
- **`HIT_SIDE_UNKNOWN`** *(v1.04)* - Used when hit side cannot be determined

## Examples

### Scout Van with Subdual Resistance
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 200.0
  InitialHealth = 200.0
  SubdualDamageCap = 350.0
  SubdualDamageHealRate = 500
  SubdualDamageHealAmount = 50.0
End
```

### Anti-Tank Site
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 75.0
  InitialHealth = 75.0
End
```

### Stinger Site with EW Protection
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 500.0
  InitialHealth = 500.0
  EWDamageCap = 300.0
  EWDamageHealRate = 2000
  EWDamageHealAmount = 30.0
End
```

### Command Center with Full Protection
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 1000.0
  InitialHealth = 1000.0
  SubdualDamageCap = 800.0
  SubdualDamageHealRate = 1000
  SubdualDamageHealAmount = 100.0
  EWDamageCap = 500.0
  EWDamageHealRate = 1500
  EWDamageHealAmount = 75.0
End
```

### Tank with Component Damage System
```ini
Body = ActiveBody ModuleTag_02
  MaxHealth = 500.0
  InitialHealth = 500.0
  
  Component PRIMARY_WEAPON
    MaxHealth = 100.0
    InitialHealth = 100.0
    HealingType = NORMAL
    DamageOnSides = HIT_SIDE_FRONT HIT_SIDE_TOP
    ReplacementCost = 300
  End
  
  Component ENGINE
    MaxHealth = 150.0
    InitialHealth = 150.0
    HealingType = PARTIAL_DESTROYED
    DamageOnSides = HIT_SIDE_BACK HIT_SIDE_LEFT HIT_SIDE_RIGHT
    ReplacementCost = 500
  End
  
  Component TURRET
    MaxHealth = 80.0
    InitialHealth = 80.0
    HealingType = NORMAL
    DamageOnSides = HIT_SIDE_TOP
    ReplacementCost = 200
  End
End
```

## Template

```ini
Body = ActiveBody ModuleTag_XX
  ; Health Settings
  MaxHealth = 500.0               ; // maximum health points *(v1.04)*
  InitialHealth = 500.0           ; // starting health points *(v1.04)*

  ; Subdual Damage Settings (Generals Zero Hour only)
  SubdualDamageCap = 0.0          ; // maximum subdual damage before subdual *(v1.04, Generals Zero Hour only)*
  SubdualDamageHealRate = 0       ; // milliseconds between subdual damage healing *(v1.04, Generals Zero Hour only)*
  SubdualDamageHealAmount = 0.0   ; // amount of subdual damage healed per interval *(v1.04, Generals Zero Hour only)*

  ; Electronic Warfare Settings (Generals Zero Hour only)
  EWDamageCap = 0.0               ; // maximum EW damage before jamming *(v1.04, Generals Zero Hour only)*
  EWDamageHealRate = 0            ; // milliseconds between EW damage healing *(v1.04, Generals Zero Hour only)*
  EWDamageHealAmount = 0.0        ; // amount of EW damage healed per interval *(v1.04, Generals Zero Hour only)*

  ; Component Settings (Generals Zero Hour only)
  ; Component COMPONENT_NAME
  ;   MaxHealth = 100.0            ; // maximum health for this component *(v1.04, Generals Zero Hour only)*
  ;   InitialHealth = 100.0        ; // starting health for this component *(v1.04, Generals Zero Hour only)*
  ;   HealingType = NORMAL         ; // how this component can be healed *(v1.04, Generals Zero Hour only)*
  ;   DamageOnSides = HIT_SIDE_FRONT HIT_SIDE_TOP ; // which hit sides can damage this component *(v1.04, Generals Zero Hour only)*
  ;   ReplacementCost = 0          ; // cost to replace this component when damaged *(v1.04, Generals Zero Hour only)*
  ; End
End
```

## Notes

- ActiveBody automatically manages damage states (PRISTINE, DAMAGED, REALLYDAMAGED, RUBBLE) based on health percentage
- Damage states affect visual appearance and particle systems
- Subdual damage can disable objects without destroying them
- Electronic warfare damage can jam electronic systems
- Objects automatically heal subdual and EW damage over time if healing rates are set
- Damage states are calculated based on global thresholds defined in game data
- Objects with ActiveBody can be targeted by weapons (see [Weapon documentation](../Weapon.md)) and affected by damage types
- Veterancy levels can modify maximum health and healing rates
- ActiveBody integrates with armor systems (see [Armor documentation](../Armor.md)) and damage effects
- **Component System**: Individual components can be damaged independently, affecting object functionality (weapons, movement, etc.)
- **Component Replacement**: Damaged components can be replaced via GUI commands if `ReplacementCost` is set
- **Hit Side Restrictions**: Components can be configured to only take damage from specific hit sides for realistic damage modeling
- **Component Healing Types**: Different components can have different healing behaviors (normal, partial only, replacement only, etc.)
- **Model State Updates**: Component replacement automatically updates visual model states to reflect component status

## Component Replacement System

The component damage system includes a GUI-based replacement system that allows players to repair damaged components:

### **GUI Command Integration**
- **Command Type**: `GUI_COMMAND_REPLACE_COMPONENT` - Available in command button definitions
- **Component Targeting**: Can target specific components or all damaged components
- **Cost Calculation**: Automatically calculates replacement costs based on component `ReplacementCost` values
- **Multi-Object Support**: Works with multiple selected objects simultaneously

### **Command Button Properties**
- **`ComponentName`**: Specifies which component to replace (empty = all damaged components)
- **Cost Display**: Shows replacement cost in tooltips with "not enough money" warnings
- **Availability**: Button is disabled when no damaged components exist or player lacks sufficient funds

### **Replacement Process**
1. **Cost Check**: Verifies player has sufficient money for replacement
2. **Component Healing**: Sets component health to maximum value
3. **Model Update**: Updates visual model state to reflect component repair
4. **Money Deduction**: Deducts replacement cost from player's money

### **Usage in Command Buttons**
```ini
CommandButton = Command_ReplaceEngine
  Command = REPLACE_COMPONENT
  ComponentName = ENGINE
  TextLabel = "Replace Engine"
  ButtonImage = "ReplaceEngineButton"
End
```

## Source Files

**Base Class:** [`BodyModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BodyModule.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp)
