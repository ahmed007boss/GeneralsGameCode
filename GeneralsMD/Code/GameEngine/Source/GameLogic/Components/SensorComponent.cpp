// SensorComponent.cpp ///////////////////////////////////////////////////////////////////
// Sensor component combining vision and electronics
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "GameLogic/Components/SensorComponent.h"
#include "Common/INI.h"
#include "GameLogic/Module/ActiveBody.h"
#include "GameLogic/Components/VisionComponent.h"
#include "GameLogic/Components/ElectronicsComponent.h"

Real SensorComponent::getShroudClearingRange() const
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

Bool SensorComponent::setCurrentJammingDamage(Real damage)
{
	if (damage < 0.0f) damage = 0.0f;
	if (damage > m_jammingDamageCap) damage = m_jammingDamageCap;
	m_currentJammingDamage = damage;
	return TRUE;
}

Bool SensorComponent::addJammingDamage(Real damage)
{
	if (damage <= 0.0f) return FALSE;
	return setCurrentJammingDamage(m_currentJammingDamage + damage);
}

void SensorComponent::healJammingDamage(Real healing)
{
	if (healing <= 0.0f) return;
	Real newDamage = m_currentJammingDamage - healing;
	if (newDamage < 0.0f) newDamage = 0.0f;
	m_currentJammingDamage = newDamage;
}

void SensorComponent::updateJammingDamageHealing()
{
	if (m_jammingDamageHealRate <= 0 || m_jammingDamageHealAmount <= 0.0f)
		return;
	if (m_jammingHealCountdown > 0)
	{
		m_jammingHealCountdown--;
		return;
	}
	m_jammingHealCountdown = m_jammingDamageHealRate;
	healJammingDamage(m_jammingDamageHealAmount);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 30/10/2025 Static parse method for SensorComponent
//-------------------------------------------------------------------------------------------------
void SensorComponent::parseSensorComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "SensorSuite", "ReconPackage", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	SensorComponent* sensor = new SensorComponent();
	sensor->setName(componentName);
	
	MultiIniFieldParse p;
	SensorComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(sensor, p);
	
	// Add the parsed component to the module data
	moduleData->m_components.push_back(sensor);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature Ahmed Salah 30/10/2025 Build field parse for SensorComponent
//-------------------------------------------------------------------------------------------------
void SensorComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Base Component properties
	Component::buildFieldParse(p);
	
	// Vision-equivalent fields
	static const FieldParse sensorVisionFieldParse[] = {
		{ "ShroudClearingRange", INI::parseReal, NULL, offsetof(SensorComponent, m_shroudClearingRange) },
		{ "PartiallyFunctionalShroudClearingRange", INI::parseReal, NULL, offsetof(SensorComponent, m_shroudClearingRangePartial) },
		{ "DisabledShroudClearingRange", INI::parseReal, NULL, offsetof(SensorComponent, m_shroudClearingRangeDisabled) },
		{ 0, 0, 0, 0 }
	};
	p.add(sensorVisionFieldParse);

	// Electronics-equivalent fields
	static const FieldParse sensorElectronicsFieldParse[] = {
		{ "JammingDamageCap", INI::parseReal, NULL, offsetof(SensorComponent, m_jammingDamageCap) },
		{ "JammingDamageHealRate", INI::parseUnsignedInt, NULL, offsetof(SensorComponent, m_jammingDamageHealRate) },
		{ "JammingDamageHealAmount", INI::parseReal, NULL, offsetof(SensorComponent, m_jammingDamageHealAmount) },
		{ "CanBeJammedByDirectJammers", INI::parseBool, NULL, offsetof(SensorComponent, m_canBeJammedByDirectJammers) },
		{ "CanBeJammedByAreaJammers", INI::parseBool, NULL, offsetof(SensorComponent, m_canBeJammedByAreaJammers) },
		{ 0, 0, 0, 0 }
	};
	p.add(sensorElectronicsFieldParse);
}

//-------------------------------------------------------------------------------------------------
void SensorComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void SensorComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void SensorComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
