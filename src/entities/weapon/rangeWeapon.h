#pragma once

#include "weapon.h"
#include "bullet.h"

class RangeWeapon : public Weapon {
public:
    RangeWeapon();
    virtual ~RangeWeapon() = default;

    void Use() override;              // Use the weapon (fire)
    void Reload();                    // Reload the weapon
    void SetAmmo(int ammoCount);      // Set ammo count
    int GetAmmo() const;              // Get ammo count

    Vec GetBulletPosition() const;    // Get the position where the bullet is spawned
    void SetWeaponDirection(const Vec& direction);  // Set the direction the weapon is pointing to
    Vec PointAtEnemy(const Vec& enemyPosition);
    void Update(float deltaTime);     // Update method to manage fire rate and timing

protected:
    int ammo;                        // Ammo count
    double fireRate;                  // Fire rate (shots per second)
    double muzzleOffset;              // Muzzle offset to spawn the bullet slightly ahead
    double timeSinceLastFire;         // Time since last shot

    Vec weaponDirection;              // Direction the weapon is pointing to (independent of owner)

    Vec GetWeaponDirection() const;   // Get the current direction the weapon is pointing to
};
