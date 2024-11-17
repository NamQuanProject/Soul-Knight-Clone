#pragma once

#include "weapon.h"

class rangeWeapon : public Weapon {
public:
    RangeWeapon();
    virtual ~RangeWeapon() = default;

    void Use() override;              // Shoot projectile or perform ranged attack
    void Reload();                    // Reload the weapon
    void SetAmmo(int ammoCount);      // Set the amount of ammo
    int GetAmmo() const;              // Get current ammo count

protected:
    int ammo;                         // Ammo count for the ranged weapon
    double fireRate;                  // Time between shots (rate of fire)
};
