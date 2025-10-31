#ifndef ELECTRONICS_COMPONENT_INTERFACE_H
#define ELECTRONICS_COMPONENT_INTERFACE_H

// Types used by the interface
#include "Common/GameType.h"


class IElectronicsComponent
{
public:
	virtual ~IElectronicsComponent() {}
	virtual Real getCurrentJammingDamage() const = 0;
	virtual Real getJammingDamageCap() const = 0;
	virtual UnsignedInt getJammingDamageHealRate() const = 0;
	virtual Real getJammingDamageHealAmount() const = 0;
	virtual Bool setCurrentJammingDamage(Real damage) = 0;
	virtual Bool addJammingDamage(Real damage) = 0;
	virtual Bool hasAnyJammingDamage() const = 0;
	virtual void healJammingDamage(Real healing) = 0;
  virtual void updateJammingDamageHealing() = 0;

  // Jamming capability flags
  virtual Bool isJammableByDirect() const = 0;
  virtual void setJammableByDirect(Bool v) = 0;
  virtual Bool isJammableByArea() const = 0;
  virtual void setJammableByArea(Bool v) = 0;
};

#endif // ELECTRONICS_COMPONENT_INTERFACE_H
