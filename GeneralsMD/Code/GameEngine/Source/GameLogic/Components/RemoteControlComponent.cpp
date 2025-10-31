// RemoteControlComponent.cpp ///////////////////////////////////////////////////////////////
// Remote control-specific component inheriting communication behavior
// Author: TheSuperHackers
/////////////////////////////////////////////////////////////////////////////////////

#include "GameLogic/Components/RemoteControlComponent.h"
#include "Common/INI.h"
#include "GameLogic/Module/ActiveBody.h"

void RemoteControlComponent::parseRemoteControlComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
    ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
    AsciiString componentName = ini->getNextToken();
    if (componentName.isEmpty()) return;

    RemoteControlComponent* component = new RemoteControlComponent();
    component->setName(componentName);

    MultiIniFieldParse p;
    RemoteControlComponent::buildFieldParse(p);
    ini->initFromINIMulti(component, p);
    moduleData->m_components.push_back(component);
}

void RemoteControlComponent::buildFieldParse(MultiIniFieldParse& p)
{
    // Include CommunicationComponent (and base Component) fields
    CommunicationComponent::buildFieldParse(p);

    // Remote-control-specific fields can be appended here later
    static const FieldParse rcFields[] = {
        { 0, 0, 0, 0 }
    };
    p.add(rcFields);
}

//-------------------------------------------------------------------------------------------------
void RemoteControlComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void RemoteControlComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void RemoteControlComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}


