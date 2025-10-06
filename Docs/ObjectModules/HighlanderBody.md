# HighlanderBody

Body module that prevents death from normal damage but allows death from unresistable damage.

## Overview

HighlanderBody is a specialized body module that makes objects nearly invulnerable to normal damage while still allowing them to be destroyed by unresistable damage types. Objects with this body can take damage normally according to their armor, but their health is clamped to never go below 1 point unless the damage is unresistable. This creates "immortal" objects that can only be destroyed by special weapons or abilities.

HighlanderBody must be embedded within object definitions and cannot be used as a standalone object template.

## Usage

Used by objects that should be nearly invulnerable to normal damage but can still be destroyed by unresistable damage. This is a **body module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- Cannot die from normal damage types
- Still vulnerable to unresistable damage
- Requires proper armor definitions to function correctly
- Only one body module per object

**Conditions**:
- Multiple instances behavior: Multiple HighlanderBody modules cannot exist - only one body module per object
- Always active once assigned to an object
- Health is automatically maintained at minimum 1 point
- Creates "immortal" objects that can only be destroyed by special weapons or abilities

**Dependencies**:
- Inherits all properties and functionality from ActiveBody
- Requires proper armor and damage type definitions
- Depends on the damage system for unresistable damage detection

## Properties

HighlanderBody inherits all properties from ActiveBody with no additional INI-parsable properties. See [ActiveBody documentation](ActiveBody.md) for complete property list.

## Examples

### Immortal Hero Unit
```ini
Body = HighlanderBody ModuleTag_01
  MaxHealth = 1000.0
  InitialHealth = 1000.0
  SubdualDamageCap = 0.0
  SubdualDamageHealRate = 0
  SubdualDamageHealAmount = 0.0
  EWDamageCap = 0.0
  EWDamageHealRate = 0
  EWDamageHealAmount = 0.0
End
```

### Invulnerable Structure
```ini
Body = HighlanderBody ModuleTag_02
  MaxHealth = 5000.0
  InitialHealth = 5000.0
  SubdualDamageCap = 0.0
  SubdualDamageHealRate = 0
  SubdualDamageHealAmount = 0.0
  EWDamageCap = 0.0
  EWDamageHealRate = 0
  EWDamageHealAmount = 0.0
End
```

## Template

```ini
Body = HighlanderBody ModuleTag_XX
  ; Inherits all ActiveBody properties
  MaxHealth = 100.0                  ; // maximum health points *(v1.04)*
  InitialHealth = 100.0              ; // starting health points *(v1.04)*

  ; Subdual Damage Settings (Generals Zero Hour only)
  SubdualDamageCap = 0.0             ; // maximum subdual damage *(v1.04, Generals Zero Hour only)*
  SubdualDamageHealRate = 0          ; // subdual damage heal rate *(v1.04, Generals Zero Hour only)*
  SubdualDamageHealAmount = 0.0      ; // subdual damage heal amount *(v1.04, Generals Zero Hour only)*

  ; Electronic Warfare Settings (Generals Zero Hour only)
  EWDamageCap = 0.0                  ; // maximum electronic warfare damage *(v1.04, Generals Zero Hour only)*
  EWDamageHealRate = 0               ; // electronic warfare damage heal rate *(v1.04, Generals Zero Hour only)*
  EWDamageHealAmount = 0.0           ; // electronic warfare damage heal amount *(v1.04, Generals Zero Hour only)*
End
```

## Notes

- HighlanderBody objects can take damage normally but cannot die from it
- Health is automatically clamped to minimum 1 point for normal damage
- Only unresistable damage can reduce health below 1 point and cause death
- All damage calculations, armor, and status effects work normally
- Useful for creating hero units, special objectives, or indestructible objects
- The name references the "Highlander" concept of near-immortality

## Source Files

**Base Class:** [`ActiveBody`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ActiveBody.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/HighlanderBody.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/HighlanderBody.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/HighlanderBody.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Body/HighlanderBody.cpp)