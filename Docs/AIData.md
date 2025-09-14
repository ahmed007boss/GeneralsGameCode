# AIData INI Documentation

## Overview

**⚠️ Work In Progress (WIP) ⚠️**

This documentation page is currently under development. The AIData INI file contains AI configuration settings and parameters for game artificial intelligence systems.

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

- [Object](Object.md) - Objects can have AI behaviors
- [CommandButton](CommandButton.md) - AI can interact with command buttons
- [SpecialPower](SpecialPower.md) - AI can use special powers

---

**Note**: This page will be completed as part of the GMX documentation effort. For now, refer to the existing game files and source code for AIData template information.

## Example Structure

```ini
AIData
    StructureSeconds                    = 5.0     ;  Ai tries to build a new structure every N seconds.
    TeamSeconds                         = 15       ;Ai tries to build a new team every N seconds.
    Wealthy                             = 7000    ;   Number of resources for the AI to consider itself wealthy
    Poor                                = 2000    ;   Number of resources for the AI to consider itself poor
    StructuresWealthyRate               = 2.0     ;  (2=twice as fast) Rate modifier for structure building when wealthy.
    StructuresPoorRate                  = 0.6     ;  (0.5=half as fast) Rate modifier for structures when poor.
    TeamsWealthyRate                    = 2.0     ;   (2=twice as fast) Rate modifier for teams building when wealthy.
    TeamsPoorRate                       = 0.6     ;  (0.5=half as fast) Rate modifier for teams when poor.
    TeamResourcesToStart                = 0.2    ; (1.0=100%) Amount of resources required to start building a team. 
    GuardInnerModifierAI                = 1.4     ;The radius modifier to vision which a guarding (AI Controlled) unit will agressively attack
    GuardOuterModifierAI                = 1.6   ;The radius modifier to vision which a guarding (AI Controlled) unit will chase after
    GuardInnerModifierHuman             = 1.8 ;1.1     ;The radius modifier to vision which a guarding (Human Controlled) unit will agressively attack
    GuardOuterModifierHuman             = 2.2 ;1.333   ;The radius modifier to vision which a guarding (Human Controlled) unit will chase after
    GuardChaseUnitsDuration             = 10000   ;The number of msec for which a guarding unit will chase attackers before giving up
    GuardEnemyScanRate                  = 500     ; when actively guarding, how often to scan for enemies (msec)
    GuardEnemyReturnScanRate            = 1000    ; when returning to "active" guarding (from pursuing someone), how often to scan for enemies (msec)
    AlertRangeModifier                  = 1.1     ;The adjustment applied when a unit is alert and doing various scans for enemies (AI units only)
    AggressiveRangeModifier             = 1.5     ;The adjustment applied when a unit is aggressive and doing various scans for enemies (AI units only)
    AttackPriorityDistanceModifier      = 100.0   ;The distance required to reduce attack priority by 1.
    MaxRecruitRadius                    = 500.0   ;The maximum distance a unit will be from a unit that recruits it.
    SkirmishBaseDefenseExtraDistance    = 150.0   ; Instead of placing base defenses on the template edge, bump it this much farther out
    ForceIdleMSEC                       = 67      ;The number of milisec a unit must be idle before looking for an enemy, 2 frames.
    ForceSkirmishAI                     = No      ; Use skirmish instead of solo ai.  For development till the skirmish ui is finished.  jba.
    RotateSkirmishBases                 = Yes    ;  If yes, rotate base layout so same side of base faces center of map.  
    AttackUsesLineOfSight               = Yes     ;  If yes, attack for ALL UNITS (player and ai) uses line of sight.  

    EnableRepulsors                     = Yes     ; If yes, KINDOF_CAN_BE_REPULSED will run from enemies & repulsors.
    RepulsedDistance                    = 150.0   ; How far beyond vision range a repulsed civilian will run before stopping.
    ; so if vision range is 120.0, he will move to a point at least 270.0 away from the enemy, and then stop running.

    WallHeight                          = 43      ; Height of the "Wall", made of KIND WALK_ON_TOP pieces. 
    
    AttackIgnoreInsignificantBuildings  = Yes     ; If yes, units will ignore enemy-owned buildings that are not faction buildings

    ; SkirmishGroupFudgeDistance is the distance that is multiplied by the number of units in a group to 
    ; determine if they are close enough to the waypoint to consider themselves AT the waypoint. This is 
    ; only used for "Follow Waypoint Path as a Team."
    SkirmishGroupFudgeDistance          = 10.0

    ; Group pathfinding parameters.
    ;  MinInfantryForGroup                 = 3     ; Have to have 3 infantry to do group movement.
    ;  MinVehiclesForGroup                 = 3       ; Have to have 3 vehicles to do group movement.
    ;  MinDistanceForGroup                 = 100.0    ; Have to be moving at least this far for group movement.
    ;  DistanceRequiresGroup               = 500.0    ; Force group movement if moving at least this far.

    ; Note that these group pathfind parameters are inter-related, and modifying them may produce really
    ; ugly results & require code changes.  jba.
    InfantryPathfindDiameter            = 6       ; Number of pathfind cells wide group path is for infantry.
    VehiclePathfindDiameter             = 7       ; Number of pathfind cells wide group path is for vehicles.

    SupplyCenterSafeRadius              = 300.0    ; Radius to scan for enemies to determine if a supply center is safe.
    RebuildDelayTimeSeconds             = 30       ; Delay this many seconds when a base building is destroyed or captured before attempting rebuild.

    AIDozerBoredRadiusModifier          = 2.0      ; Multiplier to dozer scan radius for repair & mine clearing.  2.0 means ai uses twice the radius as human dozers.
    AICrushesInfantry                   = No      ; If yes, ai will attempt to crush infantry with vehicles.

    ; Retaliation parameters.
    MaxRetaliationDistance              = 200.0    ; If the attacker is more than this far away, won't chase.  Keeps from chasing artillery.
    RetaliationFriendsRadius            = 120.0    ; Retaliator gathers allies within this distance & attacks.

    SideInfo America
        ResourceGatherersEasy     = 1
        ResourceGatherersNormal   = 1
        ResourceGatherersHard     = 1 
        BaseDefenseStructure1     = AmericaPatriotBattery  

        SkillSet1
        End

    End

    SideInfo China
        ResourceGatherersEasy     = 1
        ResourceGatherersNormal   = 1
        ResourceGatherersHard     = 1     
        BaseDefenseStructure1     = ChinaGattlingCannon  

        SkillSet1
        End
    End

    SideInfo GLA
        ResourceGatherersEasy     = 5
        ResourceGatherersNormal   = 5
        ResourceGatherersHard     = 6     
        BaseDefenseStructure1     = GLAStingerSite  

        SkillSet1
        End
    End


    SideInfo ChinaNukeGeneral
        ResourceGatherersEasy     = 1
        ResourceGatherersNormal   = 1
        ResourceGatherersHard     = 1     
        BaseDefenseStructure1     = Russia_Kashtan

        SkillSet1
        End
    End
    
    
    ;Skirmish AI Build List
    SkirmishBuildList America
    Structure AmericaCommandCenter
        Location = X:1797.84 Y:1734.92
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaCommandCenter
    Structure AmericaPowerPlant_AI
        Location = X:1721.07 Y:1644.86
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPowerPlant_AI
    Structure AmericaWarFactory
        Location = X:1698.15 Y:1828.44
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaWarFactory
    Structure AmericaPowerPlant_AI
        Location = X:1565.97 Y:1873.79
        Rebuilds = 0
        Angle = 45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPowerPlant_AI
    Structure AmericaAirfield
        Location = X:1863.75 Y:1886.41
        Rebuilds = 0
        Angle = 135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaAirfield
    Structure AmericaPatriotBattery
        Location = X:1711.52 Y:1716.64
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPatriotBattery
    Structure AmericaPatriotBattery
        Location = X:1905.67 Y:1708.89
        Rebuilds = 0
        Angle = 45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPatriotBattery
    Structure AmericaWarFactory
        Location = X:2009.43 Y:1727.80
        Rebuilds = 0
        Angle = 45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaWarFactory
    Structure AmericaPowerPlant_AI
        Location = X:2088.60 Y:1657.89
        Rebuilds = 0
        Angle = 135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPowerPlant_AI
    Structure AmericaDetentionCamp
        Location = X:2029.77 Y:1561.06
        Rebuilds = 0
        Angle = -45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaDetentionCamp
    Structure AmericaAirfield
        Location = X:1834.36 Y:1551.97
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaAirfield
    Structure AmericaPowerPlant_AI
        Location = X:1883.66 Y:1399.81
        Rebuilds = 0
        Angle = 45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPowerPlant_AI
    Structure TacticalStrategyCenter
        Location = X:1560.78 Y:1736.14
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure TacticalStrategyCenter
    Structure AmericaPowerPlant_AI
        Location = X:2079.86 Y:1845.33
        Rebuilds = 0
        Angle = 45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaPowerPlant_AI
    Structure AmericaSupplyDropZone
        Location = X:1941.03 Y:1482.67
        Rebuilds = 0
        Angle = -45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaSupplyDropZone
    Structure AmericaSupplyDropZone
        Location = X:1931.32 Y:2046.39
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaSupplyDropZone
    Structure AmericaWarFactory
        Location = X:1645.60 Y:1966.25
        Rebuilds = 0
        Angle = 135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaWarFactory
    Structure AmericaAirfield
        Location = X:1678.90 Y:2021.27
        Rebuilds = 0
        Angle = -135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaAirfield
    Structure AmericaSupplyDropZone
        Location = X:1640.57 Y:1673.14
        Rebuilds = 0
        Angle = 135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AmericaSupplyDropZone
    Structure AIAmericaNukeSilo
        Location = X:2037.80 Y:1959.58
        Rebuilds = 0
        Angle = -45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AIAmericaNukeSilo
    Structure AIAmericaNukeSilo
        Location = X:1658.07 Y:1566.53
        Rebuilds = 0
        Angle = 135.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AIAmericaNukeSilo
    Structure AIAmericaNukeSilo
        Location = X:1740.48 Y:2058.59
        Rebuilds = 0
        Angle = 45.00
        InitiallyBuilt = No
        AutomaticallyBuild = No
    END ;Structure AIAmericaNukeSilo
    END ;SkirmishBuildList FactionAmerica





    
    ;Skirmish AI Build List
    SkirmishBuildList China
        Structure ChinaCommandCenter
            Location = X:1724.70 Y:1650.91
            Rebuilds = 0
            Angle = -135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaCommandCenter
        Structure ChinaPowerPlant_AI
            Location = X:1606.76 Y:1588.63
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaPowerPlant_AI
        Structure ChinaWarFactory
            Location = X:1805.69 Y:1443.01
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaWarFactory
        Structure ChinaWarFactory
            Location = X:1797.40 Y:1831.60
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaWarFactory
        Structure ChinaGattlingCannon
            Location = X:1657.14 Y:1738.54
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaGattlingCannon
        Structure ChinaGattlingCannon
            Location = X:1801.11 Y:1599.33
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaGattlingCannon
        Structure ChinaAirfield
            Location = X:1561.96 Y:1470.39
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaAirfield
        Structure ChinaPowerPlant
            Location = X:1928.68 Y:1824.28
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaPowerPlant
        Structure ChinaInternetCenter
            Location = X:1563.23 Y:1735.47
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaInternetCenter
        Structure ChinaPropagandaCenter
            Location = X:1942.61 Y:1672.55
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaPropagandaCenter
        Structure ChinaWarFactory
            Location = X:1426.97 Y:1686.52
            Rebuilds = 0
            Angle = -135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaWarFactory
        Structure ChinaPowerPlant
            Location = X:1701.01 Y:1335.39
            Rebuilds = 0
            Angle = -135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaPowerPlant
        Structure ChinaAirfield
            Location = X:1643.41 Y:1937.40
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaAirfield
        Structure ChinaPowerPlant_AI
            Location = X:1874.76 Y:1580.05
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaPowerPlant_AI
        Structure ChinaSpeakerTower
            Location = X:1543.50 Y:1845.88
            Rebuilds = 0
            Angle = 0.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaSpeakerTower
        Structure ChinaSpeakerTower
            Location = X:1965.30 Y:1466.99
            Rebuilds = 0
            Angle = 0.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure ChinaSpeakerTower
    END ;SkirmishBuildList FactionChina






    
    
    ;Skirmish AI Build List
    SkirmishBuildList GLA
        Structure GLACommandCenter
            Location = X:1436.74 Y:1526.25
            Rebuilds = 0
            Angle = 225.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLACommandCenter
        Structure GLABarracks
            Location = X:1287.69 Y:1335.54
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLABarracks
        Structure GLABarracks
            Location = X:1591.78 Y:1718.79
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLABarracks
        Structure GLAArmsDealer
            Location = X:1213.95 Y:1733.77
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAArmsDealer
        Structure GLAArmsDealer
            Location = X:1377.72 Y:1790.43
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAArmsDealer
        Structure GLAArmsDealer
            Location = X:1715.67 Y:1433.14
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAArmsDealer
        Structure GLAArmsDealer
            Location = X:1406.98 Y:1234.25
            Rebuilds = 0
            Angle = 225.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAArmsDealer
        Structure GLAChemLab
            Location = X:1512.13 Y:1785.55
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAChemLab
        Structure GLAPalace
            Location = X:1606.47 Y:1343.88
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAPalace
        Structure GLAAirfield
            Location = X:1131.36 Y:1496.45
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAAirfield
        Structure GLABlackMarket
            Location = X:1253.40 Y:1544.79
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLABlackMarket
        Structure GLABlackMarket
            Location = X:1750.91 Y:1596.13
            Rebuilds = 0
            Angle = 225.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLABlackMarket
        Structure GLABlackMarket
            Location = X:1394.60 Y:1393.29
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLABlackMarket
        Structure GLAStingerSite
            Location = X:1509.33 Y:1452.66
            Rebuilds = 0
            Angle = 0.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAStingerSite
        Structure GLAStingerSite
            Location = X:1344.19 Y:1614.98
            Rebuilds = 0
            Angle = 225.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAStingerSite
        Structure GLATunnelNetwork
            Location = X:1485.14 Y:1343.58
            Rebuilds = 0
            Angle = 315.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLATunnelNetwork
        Structure GLATunnelNetwork
            Location = X:1486.50 Y:1636.62
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLATunnelNetwork
        Structure GLAAirfield
            Location = X:1635.81 Y:1608.27
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure GLAAirfield
    END ;SkirmishBuildList FactionGLA




        
        ;Skirmish AI Build List RUSSIA
    SkirmishBuildList ChinaNukeGeneral
        Structure Russia_CommandC
            Location = X:1767.27 Y:1846.44
            Rebuilds = 0
            Angle = -135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_CommandC
        Structure Russia_GasR_AI
            Location = X:1813.90 Y:1939.40
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_GasR_AI
        Structure Russia_WarF
            Location = X:1894.06 Y:1999.95
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_WarF
        Structure Russia_WarF
            Location = X:1587.84 Y:1799.89
            Rebuilds = 0
            Angle = -135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_WarF
        Structure Russia_AirF
            Location = X:1679.52 Y:1984.86
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_AirF
        Structure Russia_GasR_AI
            Location = X:1477.52 Y:1788.75
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_GasR_AI
        Structure Russia_Kashtan
            Location = X:1868.22 Y:1867.89
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_Kashtan
        Structure Russia_Kashtan
            Location = X:1660.22 Y:1816.53
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_Kashtan
        Structure Russia_RadSt
            Location = X:1681.38 Y:1706.09
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_RadSt
        Structure Russia_AirF
            Location = X:1831.44 Y:1696.03
            Rebuilds = 0
            Angle = -135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_AirF
        Structure Russia_ProsperityCenter
            Location = X:1653.49 Y:2164.60
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_ProsperityCenter
        Structure Russia_WarF
            Location = X:1979.20 Y:1870.71
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_WarF
        Structure Russia_GasR_AI
            Location = X:1799.15 Y:2122.72
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_GasR_AI
        Structure Russia_SupplyPost
            Location = X:1622.30 Y:1607.90
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_SupplyPost
        Structure Russia_SupplyPost
            Location = X:1948.87 Y:1630.30
            Rebuilds = 0
            Angle = 45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_SupplyPost
        Structure Russia_SupplyPost
            Location = X:1453.69 Y:1895.81
            Rebuilds = 0
            Angle = -45.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_SupplyPost
        Structure Russia_BlackoutRadar
            Location = X:2013.13 Y:1750.21
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_BlackoutRadar
        Structure Russia_BlackoutRadar
            Location = X:1524.43 Y:2052.54
            Rebuilds = 0
            Angle = 135.00
            InitiallyBuilt = No
            AutomaticallyBuild = No
        END ;Structure Russia_BlackoutRadar
    END ;SkirmishBuildList FactionChinaNukeGeneral
End
```

## Source Files


- Source: [`GeneralsMD/Code\GameEngine/Source/Common/INI/INIAiData.cpp`](../GeneralsMD/Code\GameEngine/Source/Common/INI/INIAiData.cpp)
