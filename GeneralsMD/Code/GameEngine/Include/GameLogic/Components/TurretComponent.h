// TurretComponent.h ///////////////////////////////////////////////////////////////
// Turret-specific component with turret-related properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TURRET_COMPONENT_H
#define TURRET_COMPONENT_H

#include "Common/GameType.h"
#include "Common/AsciiString.h"
#include "Common/INI.h"
#include "GameLogic/Damage.h"
#include "Component.h"

// Forward declarations
class MultiIniFieldParse;

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Turret component for weapon mounting systems
//-------------------------------------------------------------------------------------------------
class TurretComponent : public Component
{
public:
	TurretComponent() {}

	static void parseTurretComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/);
	static void buildFieldParse(MultiIniFieldParse& p);

	// TheSuperHackers @feature author 15/01/2025 Virtual clone method for polymorphic copying
	virtual Component* clone() const;

	// Save/Load/CRC hooks
	virtual void crc( Xfer *xfer );
	virtual void xfer( Xfer *xfer );
	virtual void loadPostProcess( void );
};

#endif // TURRET_COMPONENT_H
