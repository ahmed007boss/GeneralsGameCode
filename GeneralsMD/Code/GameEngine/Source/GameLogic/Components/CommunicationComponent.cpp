// CommunicationComponent.cpp ///////////////////////////////////////////////////////////////////
// Communication-specific component with additional radio and communication properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/CommunicationComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for CommunicationComponent inheritance support
//-------------------------------------------------------------------------------------------------
void CommunicationComponent::parseCommunicationComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "MainRadio", "SatelliteComm", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	CommunicationComponent* component = new CommunicationComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	CommunicationComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_components.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for CommunicationComponent inheritance support
//-------------------------------------------------------------------------------------------------
void CommunicationComponent::buildFieldParse(MultiIniFieldParse& p)
{
    // Add base Electronics (and Component) properties
    ElectronicsComponent::buildFieldParse(p);

	// Add CommunicationComponent-specific properties (empty for now, will be added later)
	static const FieldParse communicationComponentFieldParse[] = {
		{ 0, 0, 0, 0 }
	};

	p.add(communicationComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
void CommunicationComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void CommunicationComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void CommunicationComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
