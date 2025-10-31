// PowerComponent.cpp ///////////////////////////////////////////////////////////////////
// Power-specific component with additional electrical power generation properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/PowerComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for PowerComponent inheritance support
//-------------------------------------------------------------------------------------------------
void PowerComponent::parsePowerComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "MainGenerator", "BackupBattery", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	PowerComponent* component = new PowerComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	PowerComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_components.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for PowerComponent inheritance support
//-------------------------------------------------------------------------------------------------
void PowerComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Add base ElectronicsComponent (and Component) properties
	ElectronicsComponent::buildFieldParse(p);

	// Add PowerComponent-specific properties (empty for now, will be added later)
	static const FieldParse powerComponentFieldParse[] = {
		{ 0, 0, 0, 0 }
	};

	p.add(powerComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
void PowerComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void PowerComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void PowerComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
