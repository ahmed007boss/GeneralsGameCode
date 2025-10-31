// JetEngineComponent.cpp ///////////////////////////////////////////////////////////////
// Jet-engine specific component inheriting engine behavior
// Author: TheSuperHackers
/////////////////////////////////////////////////////////////////////////////////////

#include "GameLogic/Components/JetEngineComponent.h"
#include "Common/INI.h"
#include "GameLogic/Module/ActiveBody.h"

void JetEngineComponent::parseJetEngineComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;

	JetEngineComponent* component = new JetEngineComponent();
	component->setName(componentName);

	MultiIniFieldParse p;
	JetEngineComponent::buildFieldParse(p);
	ini->initFromINIMulti(component, p);
	moduleData->m_components.push_back(component);
}

void JetEngineComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Include EngineComponent fields by default
	EngineComponent::buildFieldParse(p);

	// JetEngine-specific fields can be appended here later
	static const FieldParse jetEngineFields[] = {
		{ 0, 0, 0, 0 }
	};
	p.add(jetEngineFields);
}

//-------------------------------------------------------------------------------------------------
void JetEngineComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void JetEngineComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void JetEngineComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
