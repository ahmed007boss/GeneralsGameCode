// TurretComponent.cpp ///////////////////////////////////////////////////////////////////
// Turret-specific component with additional turret-related properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/TurretComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for TurretComponent inheritance support
//-------------------------------------------------------------------------------------------------
void TurretComponent::parseTurretComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "MainTurret", "SecondaryTurret", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	TurretComponent* component = new TurretComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	TurretComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_components.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for TurretComponent inheritance support
//-------------------------------------------------------------------------------------------------
void TurretComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Add base Component properties
	Component::buildFieldParse(p);

	// Add TurretComponent-specific properties (empty for now, will be added later)
	static const FieldParse turretComponentFieldParse[] = {
		{ 0, 0, 0, 0 }
	};

	p.add(turretComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
void TurretComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void TurretComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void TurretComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
