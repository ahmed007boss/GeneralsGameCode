# FlightDeckBehavior

*This documentation is a work in progress (WIP) and will be completed as part of the GMX project.*

## Overview

FlightDeckBehavior manages aircraft parking, runway operations, and flight deck functionality for airfields and aircraft carriers.

**Base Class:** [`AIUpdateInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/AIUpdate.h), [`ParkingPlaceBehaviorInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/ParkingPlaceBehavior.h), [`DieModuleInterface`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/DieModule.h)

## Usage

Used by airfield structures and aircraft carriers to manage aircraft parking spaces, runway reservations, and flight operations.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Properties](#properties)
- [Examples](#examples)
- [Notes](#notes)

## Properties

*Properties documentation will be added when this page is completed.*

## Examples

### Example 1: Faction Building Flight Deck
```ini
Behavior = FlightDeckBehavior ModuleTag_11
  NumRunways              = 2
  NumSpacesPerRunway      = 10

  Runway1Spaces           = RunwayStart1 Runway1Prep1 Runway1Prep2 Runway1Prep3 Runway1Prep4 Runway1Prep5 Runway1Prep6 Runway1Prep7 Runway1Prep8 Runway1Prep9
  Runway1Takeoff          = RunwayStart1 RunwayEnd1
  Runway1Landing          = RunwayLDStart1 RunwayLDEnd1
  Runway1Taxi             = Taxi2 Taxi3 Taxi4 Taxi6
End
```

### Example 2: Airfield Flight Deck
```ini
Behavior = FlightDeckBehavior ModuleTag_11
  NumRunways              = 2
  NumSpacesPerRunway      = 10

  Runway1Spaces           = RunwayStart1 Runway1Prep1 Runway1Prep2 Runway1Prep3 Runway1Prep4 Runway1Prep5 Runway1Prep6 Runway1Prep7 Runway1Prep8 Runway1Prep9
  Runway1Takeoff          = RunwayStart1 RunwayEnd1
  Runway1Landing          = RunwayLDStart1 RunwayLDEnd1
  Runway1Taxi             = Taxi2 Taxi3 Taxi4 Taxi6
End
```

### Example 3: Aircraft Carrier Flight Deck
```ini
Behavior = FlightDeckBehavior ModuleTag_11
  NumRunways              = 2
  NumSpacesPerRunway      = 10

  Runway1Spaces           = RunwayStart1 Runway1Prep1 Runway1Prep2 Runway1Prep3 Runway1Prep4 Runway1Prep5 Runway1Prep6 Runway1Prep7 Runway1Prep8 Runway1Prep9
  Runway1Takeoff          = RunwayStart1 RunwayEnd1
  Runway1Landing          = RunwayLDStart1 RunwayLDEnd1
  Runway1Taxi             = Taxi2 Taxi3 Taxi4 Taxi6
End
```

## Notes

- This is a GMX (Generals Modding eXtended) documentation page
- Properties and examples will be documented from the corresponding C++ source files
- Version compatibility information will be included for all properties

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Module/FlightDeckBehavior.h`](../../GeneralsMD/Code/GameEngine/Include/GameLogic/Module/FlightDeckBehavior.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/FlightDeckBehavior.cpp`](../../GeneralsMD/Code/GameEngine/Source/GameLogic/Object/Behavior/FlightDeckBehavior.cpp)
