# Campaign INI Documentation

## Overview

**⚠️ Work In Progress (WIP) ⚠️**

This documentation page is currently under development. The Campaign INI file contains campaign configuration settings and parameters for single-player campaign modes.

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

## Related Documentation

- [Object](Object.md) - Campaign objects and units
- [SpecialPower](SpecialPower.md) - Campaign special powers
- [Science](Science.md) - Campaign technology trees

---

**Note**: This page will be completed as part of the GMX documentation effort. For now, refer to the existing game files and source code for Campaign template information.

## Example Structure

```ini
Campaign CHALLENGE_2
  CampaignNameLabel CAMPAIGN:CHALLENGE_2
  PlayerFaction FactionChina
  FirstMission Mission01
  IsChallengeCampaign yes  
  Mission Mission01
    Map Maps\GC_AirGeneral\GC_AirGeneral3.map
    GeneralName GUI:BioNameEntry_Pos0
    IntroMovie GeneralsChallengeBackground
    NextMission Mission02
  END
  Mission Mission02
    Map Maps\GC_SuperWeaponsGeneral\GC_SuperWeaponsGeneral3.map
    GeneralName GUI:BioNameEntry_Pos3
    IntroMovie GeneralsChallengeBackground
    NextMission Mission03
  END
  Mission Mission03
    Map Maps\GC_LaserGeneral\GC_LaserGeneral3.map
    GeneralName GUI:BioNameEntry_Pos5
    IntroMovie GeneralsChallengeBackground
    NextMission Mission04
  END
  Mission Mission04
    Map Maps\GC_Stealth\GC_Stealth3.map
    GeneralName GUI:BioNameEntry_Pos6
    IntroMovie GeneralsChallengeBackground
    NextMission Mission05
  END
  Mission Mission05
    Map Maps\GC_DemolitionGeneral\GC_DemolitionGeneral3.map
    GeneralName GUI:BioNameEntry_Pos8
    IntroMovie GeneralsChallengeBackground
    NextMission Mission06
  END
  Mission Mission06
    Map Maps\GC_ChemGeneral\GC_ChemGeneral3.map
    GeneralName GUI:BioNameEntry_Pos1
    IntroMovie GeneralsChallengeBackground
    NextMission Mission07
  END
  Mission Mission07
    Map Maps\GC_TankGeneral\GC_TankGeneral3.map
    GeneralName GUI:BioNameEntry_Pos4
    IntroMovie GeneralsChallengeBackground
    NextMission Mission08
  END
  Mission Mission08
    Map Maps\GC_InfantryGeneral\GC_InfantryGeneral3.map
    GeneralName GUI:BioNameEntry_Pos7
    IntroMovie GeneralsChallengeBackground
  END
END
```

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Campaign.h`](../GeneralsMD/Code/GameEngine/Include/GameLogic/Campaign.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Campaign/Campaign.cpp`](../GeneralsMD/Code/GameEngine/Source/GameLogic/Campaign/Campaign.cpp)
