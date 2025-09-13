# CommandSet INI Documentation

## Overview
The `CommandSet` class represents a collection of CommandButtons that are displayed together in the game's control bar. CommandSets provide context-sensitive command interfaces that change based on the selected object, building, or game state.

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameClient/ControlBar.h`](../GeneralsMD/Code/GameEngine/Include/GameClient/ControlBar.h) - `CommandSet` class definition
- Source: [`GeneralsMD/Code/GameEngine/Source/GameClient/GUI/ControlBar/ControlBar.cpp`](../GeneralsMD/Code/GameEngine/Source/GameClient/GUI/ControlBar/ControlBar.cpp) - `CommandSet` parsing logic

## Usage
CommandSets are defined in `.ini` files within the game's data directories in a root folder called "CommandSet". They are typically associated with specific objects, buildings, or game contexts and determine which [CommandButtons](CommandButton.md) are available to the player at any given time.

## Table of Contents
- [Properties](#properties)
  - [Basic Properties](#basic-properties)
- [Command Set Assignment](#command-set-assignment)
- [Command Set Limits](#command-set-limits)
- [Examples](#examples)
- [Best Practices](#best-practices)
- [Notes](#notes)

## Properties

### Basic Properties

#### Command Button Slots *(v1.04)*
- **Type**: [`commandButton`](CommandButton.md) (up to 18 slots) *(Generals Zero Hour only)*
- **Description**: Individual command buttons in this set
- **Index**: 1 to 18 (only slots 1-14 are visible in UI) *(slots 13-18 are Generals Zero Hour only)*
- **Example**: 
```
CommandSet BZK600CommandSet
  1  = Command_SU34Bomb
  2  = Command_UpgradeChinaBZKReloadDrone
  11 = Command_AttackMove
  13 = Command_Guard    ; *(Generals Zero Hour only)*
  14 = Command_Stop     ; *(Generals Zero Hour only)*
End
```


## Command Set Assignment

### Object-Based Assignment
Command sets are typically assigned to objects through their template definitions:

```
Object USAInfantry
; ... other properties ...
CommandSet = "USAInfantryCommandSet"
END
```

### Building-Based Assignment
Buildings use command sets to define their production capabilities:

```
Object USABarracks
; ... other properties ...
CommandSet = "USABarracksCommandSet"
END
```

### Command Set Switching
There are two types of command set switching:

#### User-Initiated Switching
- **Switch Command Set Buttons**: Up to 5 command sets can be switched by clicking buttons with type `SWITCH_COMMAND_SET`
- **Player Selection**: User manually clicks buttons to switch between different command sets
- **Examples**: `COMMAND_SWITCH_COMMAND_SET`, `COMMAND_SWITCH_COMMAND_SET2`, etc.

#### Automatic Switching (CommandSetupgradeModule)
- **CommandSetupgradeModule**: Automatically changes command sets based on upgrades
- **Upgrade-Based**: Command sets change when specific upgrades are researched
- **Automatic**: No user interaction required - happens automatically when conditions are met

## Examples

### Basic Dozer Command Set
```
CommandSet ChinaDozerCommandSet
  1  = Command_ConstructChinaBarracks
  2  = Command_ConstructChinaPowerPlant
  3  = Command_ConstructChinaGattlingCannon
  4  = Command_ConstructChinaSupplyCenter
  5  = Command_ConstructChinaBunker
  6  = Command_ConstructChinaInternetCenter
  7  = Command_ConstructChinaPropagandaCenter
  8  = Command_ConstructChinaWarFactory
  9  = Command_ConstructChinaSpeakerTower
  10 = Command_ConstructChinaAirfield
  13 = Command_DisarmMinesAtPosition
  14 = Command_ConstructChinaCommandCenter
  18 = Command_ConstructChinaPowerPlant_AI
End
```

### Faction-Specific Dozer Command Set
```
CommandSet ChinaDozerCommandSetEWF
  1  = Command_ConstructChinaBarracks
  2  = Command_ConstructChinaPowerPlant
  3  = Command_ConstructChinaGattlingCannon
  4  = Command_ConstructChinaSupplyCenter
  5  = Command_ConstructChinaBunkerEWF
  6  = Command_ConstructChinaInternetCenter
  7  = Command_ConstructChinaPropagandaCenter
  8  = Command_ConstructChinaWarFactory
  9  = Command_ConstructChinaSpeakerTower
  10 = Command_ConstructChinaAirfield
  13 = Command_DisarmMinesAtPosition
  14 = Command_ConstructChinaCommandCenter
  17 = Command_ConstructChinaBunker
  18 = Command_ConstructChinaPowerPlant_AI
End
```

### Unit Command Set
```
CommandSet BZK600CommandSet
  1  = Command_SU34Bomb
  2  = Command_UpgradeChinaBZKReloadDrone
  11 = Command_AttackMove
  13 = Command_Guard
  14 = Command_Stop
End
```

### Destroyed Building Command Set
```
CommandSet DestroyedOilDerrickCommandSet
  1  = Command_UpgradeOilDerrickRebuild
End
```

## Command Set Limits

### Maximum Commands *(v1.04)*
- **Total Slots**: 18 command button slots (numbered 1-18) *(Generals Zero Hour only)*
- **Visible Slots**: Only slots 1-14 are visible in the UI
- **Hidden Slots**: Slots 15-18 are available but not displayed *(Generals Zero Hour only)*
- **Unused Slots**: Empty slots are automatically hidden in the UI

### UI Layout
Command buttons appear in the UI in a 2x7 grid layout:
```
+--+--+--+--+--+--+--+
|01|03|05|07|09|11|13|
+--+--+--+--+--+--+--+
|02|04|06|08|10|12|14|
+--+--+--+--+--+--+--+
```

### Command Set Switching
Command sets can be dynamically switched in two ways:
- **User-Initiated**: Manual switching via `SWITCH_COMMAND_SET` buttons
- **Automatic**: Via CommandSetupgradeModule based on upgrades

## Best Practices

### Command Organization
1. **Group related commands together**
2. **Place most common commands first**
3. **Use consistent button ordering across similar units**
4. **Leave unused slots empty (they will be hidden)**

### Command Set Naming
1. **Use descriptive names that indicate the context**
2. **Include faction prefix (USA, China, GLA)**
3. **Use consistent naming conventions**
4. **Avoid special characters in names**

### Performance Considerations
1. **Keep command sets reasonably sized**
2. **Avoid unnecessary command set switching**
3. **Use prerequisites to control button availability**
4. **Consider UI layout when designing command sets**

## Notes
- CommandSets are defined in `.ini` files within the game's data directories in a root folder called "CommandSet" and in root file with name `CommandSet.ini` 
- Each CommandSet must have a unique name - no two CommandSets can share the same name even across multiple files 
- Command sets support dynamic switching based on upgrades
- All command buttons within a set must be valid CommandButton definitions
- Maximum of 18 command button slots per set (only 14 visible in UI)
- Up to 3 alternative command sets (CommandSet2-CommandSet4) can be defined


