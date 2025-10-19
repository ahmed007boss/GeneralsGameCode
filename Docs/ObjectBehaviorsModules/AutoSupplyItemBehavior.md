# AutoSupplyItemBehavior

## Overview

The `AutoSupplyItemBehavior` is a behavior module that automatically supplies items from an object's inventory to nearby units within a configurable radius and time interval. This behavior works in conjunction with the `InventoryBehavior` to create automated supply chains and resource distribution systems.

## Usage

The `AutoSupplyItemBehavior` is designed to be embedded within objects that have inventory capabilities. It continuously monitors nearby units and automatically transfers specified items from the object's inventory to units that meet the supply criteria.

### Limitations

- Requires the object to have an `InventoryBehavior` module
- Target units must also have an `InventoryBehavior` module
- Supply operations are limited by the source object's inventory capacity
- Target units must have available storage space for the supplied items

### Conditions

- The behavior only activates when the source object has the required item in sufficient quantity
- Target units must be within the specified supply radius
- Target units must meet the alliance and health criteria (if configured)
- Target units must have available storage capacity for the item

### Dependencies

- **InventoryBehavior**: Both source and target objects must have inventory capabilities
- **UpdateModule**: Inherits update functionality for continuous monitoring
- **GameLogic**: Requires access to the game's object management system

## Table of Contents

- [Properties](#properties)
- [Examples](#examples)
- [Best Practices](#best-practices)
- [Notes](#notes)
- [Template](#template)

## Properties

### `SupplyItemKey` *(v1.04)*

- **Type**: `AsciiString`
- **Description**: The key identifier for the item to be supplied (e.g., "Ammo", "Fuel", "MedicalSupplies"). This must match an item key defined in the source object's `InventoryBehavior`.
- **Default**: `""` (empty string)
- **Example**: `SupplyItemKey = Ammo`
- **Available Values**: Any valid item key from the source object's inventory configuration

### `SupplyAmount` *(v1.04)*

- **Type**: `Real`
- **Description**: The amount of the item to supply per supply cycle. Higher values provide more items per supply operation but consume more inventory.
- **Default**: `1.0`
- **Example**: `SupplyAmount = 5.0`
- **Available Values**: Any positive real number

### `SupplyRadius` *(v1.04)*

- **Type**: `Real`
- **Description**: The maximum distance (in game units) to search for units to supply. Larger radius allows supplying units that are farther away but may impact performance.
- **Default**: `100.0`
- **Example**: `SupplyRadius = 150.0`
- **Available Values**: Any positive real number

### `SupplyDelay` *(v1.04)*

- **Type**: `UnsignedInt`
- **Description**: The delay between supply attempts in milliseconds. Lower values make supply more frequent but may impact performance. 1000ms = 1 second.
- **Default**: `1000`
- **Example**: `SupplyDelay = 2000`
- **Available Values**: Any positive integer (milliseconds)

### `SupplyAllUnits` *(v1.04)*

- **Type**: `Bool`
- **Description**: If true, supplies all units in range that meet the target prerequisites. If false, supplies only the unit with the lowest amount of the target item.
- **Default**: `false` (supply only best match)
- **Example**: `SupplyAllUnits = true`
- **Available Values**: `true` or `false`

### `TargetPrerequisite` *(v1.04)*

- **Type**: `ObjectPrerequisite` (see [ObjectPrerequisite documentation](../ObjectPrerequisite.md))
- **Description**: Prerequisites that target units must meet to be eligible for supply. This allows for complex filtering based on object type, upgrades, health, alliance, inventory status, and more.
- **Default**: No prerequisites (all units are eligible)
- **Example**: 
  ```ini
  TargetPrerequisite = ObjectIsKindOf INFANTRY
  TargetPrerequisite = ObjectHasAtLeastItem Ammo 0
  TargetPrerequisite = ObjectItemStorageNotFull Ammo
  ```
- **Available Values**: Any valid ObjectPrerequisite conditions

## Examples

### Basic Ammo Supply Station

```ini
Behavior = AutoSupplyItemBehavior ModuleTag_SupplyStation
    SupplyItemKey = Ammo
    SupplyAmount = 10.0
    SupplyRadius = 75.0
    SupplyDelay = 1500
    TargetPrerequisite = ObjectIsKindOf INFANTRY
    TargetPrerequisite = ObjectItemStorageNotFull Ammo
End
```

### Medical Supply for Damaged Units

```ini
Behavior = AutoSupplyItemBehavior ModuleTag_MedicalStation
    SupplyItemKey = MedicalSupplies
    SupplyAmount = 5.0
    SupplyRadius = 100.0
    SupplyDelay = 1000
    TargetPrerequisite = ObjectIsKindOf INFANTRY
    TargetPrerequisite = ObjectHasAtMostItem MedicalSupplies 0
    TargetPrerequisite = ObjectItemStorageNotFull MedicalSupplies
End
```

### Fuel Depot for Vehicles

```ini
Behavior = AutoSupplyItemBehavior ModuleTag_FuelDepot
    SupplyItemKey = Fuel
    SupplyAmount = 25.0
    SupplyRadius = 120.0
    SupplyDelay = 2000
    TargetPrerequisite = ObjectIsKindOf VEHICLE
    TargetPrerequisite = ObjectItemStorageNotFull Fuel
End
```

## Best Practices

1. **Performance Considerations**: Use appropriate `SupplyDelay` values to balance responsiveness with performance. Avoid very low values (less than 500ms) unless necessary.

2. **Radius Optimization**: Set `SupplyRadius` based on the expected gameplay. Larger radii are useful for mobile supply units, while smaller radii work well for fixed supply depots.

3. **Target Filtering**: Use `TargetPrerequisite` to filter which units can receive supplies. Common patterns include:
   - `ObjectIsKindOf INFANTRY` for infantry-only supplies
   - `ObjectIsKindOf VEHICLE` for vehicle-only supplies
   - `ObjectItemStorageNotFull ItemName` to avoid over-supplying
   - `ObjectHasAtMostItem ItemName 0` to only supply units that don't have the item

4. **Inventory Management**: Ensure the source object has sufficient inventory capacity and the target units have available storage space.

## Notes

- The behavior automatically finds the best eligible unit within the supply radius using the partition manager for efficient spatial queries. When `SupplyAllUnits = false`, it selects the unit with the lowest amount of the target item.
- Supply operations are atomic - either the full amount is transferred or nothing is transferred
- The behavior respects inventory capacity limits on both source and target objects
- Multiple `AutoSupplyItemBehavior` instances can be used on the same object to supply different items
- The behavior works with any item type defined in the source object's `InventoryBehavior`

## Template

```ini
Behavior = AutoSupplyItemBehavior ModuleTag_XX
    SupplyItemKey = ItemKey              ; // Item to supply *(v1.04)*
    SupplyAmount = 1.0                   ; // Amount per supply cycle *(v1.04)*
    SupplyRadius = 100.0                 ; // Search radius in game units *(v1.04)*
    SupplyDelay = 1000                   ; // Delay between supply attempts in milliseconds *(v1.04)*
    SupplyAllUnits = false               ; // Supply all units or just best match *(v1.04)*
    TargetPrerequisite = ObjectIsKindOf INFANTRY ; // Target filtering *(v1.04)*
    TargetPrerequisite = ObjectItemStorageNotFull ItemKey ; // Avoid over-supplying *(v1.04)*
End
```

## Source Files

**Base Class:** [UpdateModule](../../Core/GameEngine/Include/GameLogic/Module/UpdateModule.h)

- **Header**: [AutoSupplyItemBehavior.h](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AutoSupplyItemBehavior.h)
- **Source**: [AutoSupplyItemBehavior.cpp](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Module/AutoSupplyItemBehavior.cpp)
