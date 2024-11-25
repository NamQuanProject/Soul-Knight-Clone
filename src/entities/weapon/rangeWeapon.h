#pragma once

#include "weapon.h"
#include "../../utils/vec.h"

class RangeWeapon : public Weapon {
public:
    RangeWeapon();
    virtual ~RangeWeapon() = default;

    // Abstract methods that derived classes must implement
    virtual void Fire() = 0;                    // Abstract method to fire a bullet
    virtual void Reload() = 0;                  // Abstract method for reloading

    // Common methods for all ranged weapons
    void SetAmmo(int ammoCount);                // Set the ammo count
    int GetAmmo() const;                        // Get the ammo count
    void SetWeaponDirection(const Vec& direction); // Set the direction of the weapon
    Vec GetWeaponDirection() const;             // Get the current direction of the weapon
    Vec PointAtEnemy(const Vec& enemyPosition); // Helper function to point the weapon at an enemy
    Vec GetBulletPosition() const;              // Get the bullet spawn position

    // Override from Weapon
    void Use() override;                        // Default implementation to fire
    void Update(float deltaTime) override;      // Update weapon state (e.g., timing)
    
protected:
    int ammo;                                   // Ammo count
    double fireRate;                            // Fire rate (shots per second)
    double muzzleOffset;                        // Offset to spawn bullets slightly ahead
    double timeSinceLastFire;                   // Time elapsed since the last shot
    Vec weaponDirection;                        // Current direction of the weapon
};
