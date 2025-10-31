// VisionComponent.cpp ///////////////////////////////////////////////////////////////////
// Vision-specific component with additional sight and detection properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/VisionComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

Real VisionComponent::getShroudClearingRange() const
{
	const ComponentStatus status = getStatus();
	if (status == COMPONENT_STATUS_DOWNED || status == COMPONENT_STATUS_USER_DISABLED)
	{
		return m_shroudClearingRangeDisabled;
	}
	if (status == COMPONENT_STATUS_PARTIALLY_FUNCTIONAL)
	{
		return (m_shroudClearingRangePartial >= 0.0f) ? m_shroudClearingRangePartial : m_shroudClearingRange;
	}
	return m_shroudClearingRange;
}
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for VisionComponent inheritance support
//-------------------------------------------------------------------------------------------------
void VisionComponent::parseVisionComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "MainSensors", "ThermalVision", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	VisionComponent* component = new VisionComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	VisionComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_components.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for VisionComponent inheritance support
//-------------------------------------------------------------------------------------------------
void VisionComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Add base Component properties
	Component::buildFieldParse(p);

	// Add VisionComponent-specific properties (empty for now, will be added later)
	static const FieldParse visionComponentFieldParse[] = {
		{ "ShroudClearingRange", INI::parseReal, NULL, offsetof(VisionComponent, m_shroudClearingRange) },
		{ "PartiallyFunctionalShroudClearingRange", INI::parseReal, NULL, offsetof(VisionComponent, m_shroudClearingRangePartial) },
		{ "DisabledShroudClearingRange", INI::parseReal, NULL, offsetof(VisionComponent, m_shroudClearingRangeDisabled) },
		{ 0, 0, 0, 0 }
	};

	p.add(visionComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
void VisionComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void VisionComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void VisionComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
