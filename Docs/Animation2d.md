# Animation2d INI Documentation

## Overview

**⚠️ Work In Progress (WIP) ⚠️**

This documentation page is currently under development. The Animation2d INI file contains 2D animation definitions for user interface elements, status indicators, and visual effects.

## Status

- **Documentation Status**: In Progress
- **Completion**: ~10%
- **Last Updated**: [Current Date]

## Planned Sections

- [ ] Overview and Usage
- [ ] Properties
- [ ] Enum Value Lists
- [ ] Examples
- [ ] Best Practices
- [ ] Notes


---

**Note**: This page will be completed as part of the GMX documentation effort. For now, refer to the existing game files and source code for Animation2d template information.

## Example Structure

```ini
Animation DefaultHeal
  AnimationMode          = LOOP
  AnimationDelay         = 30  ; in milliseconds
  RandomizeStartFrame    = Yes
  NumberImages           = 16
  Image                  = SCPCross000
  Image                  = SCPCross001
  ; ... more images
End

Animation StructureHeal
  AnimationMode          = PING_PONG
  AnimationDelay         = 60  ; in milliseconds
  RandomizeStartFrame    = Yes
  NumberImages           = 10
  Image                  = SCPWrench000
  ; ... more images
End
```

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Animation2d.h`](../GeneralsMD/Code/GameEngine/Include/GameLogic/Animation2d.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Animation2d/Animation2d.cpp`](../GeneralsMD/Code/GameEngine/Source/GameLogic/Animation2d/Animation2d.cpp)
