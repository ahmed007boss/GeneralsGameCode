// ElectronicsComponent.cpp ///////////////////////////////////////////////////////////////////
// Electronics-specific component with additional electronic systems properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/ElectronicsComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for ElectronicsComponent inheritance support
//-------------------------------------------------------------------------------------------------
void ElectronicsComponent::parseElectronicsComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "MainComputer", "RadarSystem", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	ElectronicsComponent* component = new ElectronicsComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	ElectronicsComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_componentsData.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for ElectronicsComponent inheritance support
//-------------------------------------------------------------------------------------------------
void ElectronicsComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Add base Component properties
	Component::buildFieldParse(p);

	// Add ElectronicsComponent-specific properties (EW moved here)
	static const FieldParse electronicsComponentFieldParse[] = {
		{ "JammingDamageCap", INI::parseReal, NULL, offsetof(ElectronicsComponent, m_jammingDamageCap) },
		{ "JammingDamageHealRate", INI::parseDurationUnsignedInt, NULL, offsetof(ElectronicsComponent, m_jammingDamageHealRate) },
		{ "JammingDamageHealAmount", INI::parseReal, NULL, offsetof(ElectronicsComponent, m_jammingDamageHealAmount) },
		{ "CanBeJammedByDirectJammers", INI::parseBool, NULL, offsetof(ElectronicsComponent, m_canBeJammedByDirectJammers) },
		{ "CanBeJammedByAreaJammers", INI::parseBool, NULL, offsetof(ElectronicsComponent, m_canBeJammedByAreaJammers) },
		{ 0, 0, 0, 0 }
	};

	p.add(electronicsComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 15/01/2025 Override getStatus to include jamming damage
//-------------------------------------------------------------------------------------------------
ComponentStatus ElectronicsComponent::getStatus() const
{
	// Get base status first
	ComponentStatus baseStatus = Component::getStatus();
	
	// If user disabled or already downed, jamming doesn't change that
	if (baseStatus == COMPONENT_STATUS_USER_DISABLED || baseStatus == COMPONENT_STATUS_DOWNED)
		return baseStatus;
	
	// Check jamming damage against max health
	Real maxHealth = getCurrentMaxHealth();
	if (maxHealth > 0.0f && m_currentJammingDamage > 0.0f)
	{
		// Component is fully jammed if jamming damage >= max health
		if (m_currentJammingDamage >= maxHealth)
			return COMPONENT_STATUS_DOWNED;
		
		// Component is partially jammed if jamming damage >= 50% of max health
		if (m_currentJammingDamage >= (maxHealth * 0.5f))
		{
			// Downgrade to partially functional if base status was fully functional
			if (baseStatus == COMPONENT_STATUS_FULLY_FUNCTIONAL)
				return COMPONENT_STATUS_PARTIALLY_FUNCTIONAL;
		}
	}
	
	// Return base status (jamming didn't affect it)
	return baseStatus;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Virtual clone method for polymorphic copying
//-------------------------------------------------------------------------------------------------
Component* ElectronicsComponent::clone() const
{
	// Create a new ElectronicsComponent
	ElectronicsComponent* copy = new ElectronicsComponent();
	
	// Copy base Component members using helper method
	copyBaseComponentMembers(copy);
	
	// Copy ElectronicsComponent-specific members
	copy->m_jammingDamageCap = m_jammingDamageCap;
	copy->m_jammingDamageHealRate = m_jammingDamageHealRate;
	copy->m_jammingDamageHealAmount = m_jammingDamageHealAmount;
	copy->m_currentJammingDamage = m_currentJammingDamage;
	copy->m_jammingHealCountdown = m_jammingHealCountdown;
	copy->m_canBeJammedByDirectJammers = m_canBeJammedByDirectJammers;
	copy->m_canBeJammedByAreaJammers = m_canBeJammedByAreaJammers;
	
	return copy;
}

//-------------------------------------------------------------------------------------------------
void ElectronicsComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);

	// Include current EW runtime state in CRC
	xfer->xferReal(&m_currentJammingDamage);
	xfer->xferUnsignedInt(&m_jammingHealCountdown);
	xfer->xferBool(&m_canBeJammedByDirectJammers);
	xfer->xferBool(&m_canBeJammedByAreaJammers);
}

//-------------------------------------------------------------------------------------------------
void ElectronicsComponent::xfer( Xfer *xfer )
{
	// version for ElectronicsComponent-specific runtime fields
	XferVersion currentVersion = 1;
	XferVersion version = currentVersion;
	xfer->xferVersion(&version, currentVersion);

	Component::xfer(xfer);

	// Persist current EW runtime state
	xfer->xferReal(&m_currentJammingDamage);
	xfer->xferUnsignedInt(&m_jammingHealCountdown);
	xfer->xferBool(&m_canBeJammedByDirectJammers);
	xfer->xferBool(&m_canBeJammedByAreaJammers);
}

//-------------------------------------------------------------------------------------------------
void ElectronicsComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
