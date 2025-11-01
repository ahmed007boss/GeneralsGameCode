// InventoryStorageComponent.cpp ///////////////////////////////////////////////////////////////////
// Inventory storage-specific component with additional storage and cargo properties
// Author: TheSuperHackers
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_HIT_SIDE_NAMES

#include "GameLogic/Components/InventoryStorageComponent.h"
#include "Common/INI.h"
#include "GameLogic/Components/Component.h"
#include "GameLogic/Damage.h"
#include "Common/GameType.h"
#include "GameLogic/Module/ActiveBody.h"

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Static parse method for InventoryStorageComponent inheritance support
//-------------------------------------------------------------------------------------------------
void InventoryStorageComponent::parseInventoryStorageComponent(INI* ini, void* instance, void* /*store*/, const void* /*userData*/)
{
	// instance is actually ActiveBodyModuleData*
	ActiveBodyModuleData* moduleData = (ActiveBodyModuleData*)instance;
	
	// Get component name from the first token (e.g., "CargoBay", "AmmoStorage", etc.)
	AsciiString componentName = ini->getNextToken();
	if (componentName.isEmpty()) return;
	
	InventoryStorageComponent* component = new InventoryStorageComponent();
	// Set component name using direct assignment
	component->setName(componentName);
	
	MultiIniFieldParse p;
	InventoryStorageComponent::buildFieldParse(p);

	// Parse the component block using the field parse table
	ini->initFromINIMulti(component, p);
	
	// Add the parsed component to the module data
	moduleData->m_componentsData.push_back(component);
}

//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Build field parse method for InventoryStorageComponent inheritance support
//-------------------------------------------------------------------------------------------------
void InventoryStorageComponent::buildFieldParse(MultiIniFieldParse& p)
{
	// Add base Component properties
	Component::buildFieldParse(p);

	// Add InventoryStorageComponent-specific properties (empty for now, will be added later)
	static const FieldParse inventoryStorageComponentFieldParse[] = {
		{ 0, 0, 0, 0 }
	};

	p.add(inventoryStorageComponentFieldParse);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @feature author 15/01/2025 Virtual clone method for polymorphic copying
//-------------------------------------------------------------------------------------------------
Component* InventoryStorageComponent::clone() const
{
	// Create a new InventoryStorageComponent
	InventoryStorageComponent* copy = new InventoryStorageComponent();
	
	// Copy base Component members using helper method (InventoryStorageComponent has no additional members)
	copyBaseComponentMembers(copy);
	
	return copy;
}

//-------------------------------------------------------------------------------------------------
void InventoryStorageComponent::crc( Xfer *xfer )
{
	Component::crc(xfer);
}

//-------------------------------------------------------------------------------------------------
void InventoryStorageComponent::xfer( Xfer *xfer )
{
	Component::xfer(xfer);
}

//-------------------------------------------------------------------------------------------------
void InventoryStorageComponent::loadPostProcess( void )
{
	Component::loadPostProcess();
}
