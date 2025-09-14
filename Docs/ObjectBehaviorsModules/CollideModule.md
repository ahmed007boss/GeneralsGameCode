# CollideModule

Base class for collision modules that handle object collision detection and response in the game engine.

## Overview

CollideModule is the abstract base class for all collision modules that handle object collision detection and response. It provides the fundamental interface for collision processing, collision detection, and collision response behaviors. This module serves as the foundation for specialized collision implementations like FireWeaponCollide, SquishCollide, and other collision types that implement specific collision behaviors.

CollideModule must be embedded within object definitions and cannot be used as a standalone object template.

## Usage

Used as the base class for specialized collision modules that implement different collision behaviors. This is a **base collision module** that must be embedded within object definitions. Use the [Template](#template) below by copying it into your object definition. Then, customize it as needed, making sure to review any limitations, conditions, or dependencies related to its usage.

**Limitations**:
- Abstract base class - cannot be used directly
- Requires concrete implementation for actual functionality
- Only one collision module per object
- Must be implemented by derived classes for specific behavior

**Conditions**:
- Multiple instances behavior: Multiple CollideModule instances cannot exist - only one collision module per object
- Always active once assigned to an object
- Provides interface for collision detection and response
- Creates foundation for specialized collision implementations

**Dependencies**:
- Inherits all properties and functionality from BehaviorModule
- Requires concrete implementation by derived classes
- Depends on collision detection systems for proper functionality

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Template](#template)
- [Notes](#notes)

## Properties

CollideModule is an abstract base class and does not expose any additional INI-parsable properties beyond those inherited from BehaviorModule. All functionality is implemented by derived classes such as:

- **FireWeaponCollide**: For objects that fire weapons on collision
- **SquishCollide**: For objects that can be crushed by larger vehicles
- **Other collision modules**: For specific collision behaviors

## Examples

*CollideModule is a base class and is not directly used in INI files. See derived classes like FireWeaponCollide, SquishCollide, and other collision modules for actual usage examples.*

## Template

*CollideModule is an abstract base class and cannot be instantiated directly. Use derived classes like FireWeaponCollide or SquishCollide for actual implementations.*

## Notes

- CollideModule provides the fundamental interface for collision detection and response
- All collision modules inherit from this base class and implement its virtual methods
- The module handles collision processing, collision detection, and collision response behaviors
- Specialized collision types implement specific behaviors while maintaining the common interface
- This creates a consistent collision system across all object types

## Source Files

**Base Class:** [`BehaviorModule`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h)

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/CollideModule.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/CollideModule.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Collide/CollideModule.cpp)
