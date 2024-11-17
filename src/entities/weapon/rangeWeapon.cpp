#include "rangeWeapon.h"
#include "bullet.h"

RangeWeapon::RangeWeapon()
    : ammo(10), fireRate(0.5), muzzleOffset(10.0), timeSinceLastFire(0) {
    // Default constructor values
    weaponDirection = Vec(1.0, 0.0);  // Default direction to the right (or however your default direction is)
}

void RangeWeapon::Use() {
    // Check if enough time has passed to fire again (fireRate)
    if (timeSinceLastFire >= fireRate && ammo > 0) {
        // Get the bullet's initial position slightly ahead of the gun's position
        Vec bulletPosition = GetBulletPosition();

        // Create a bullet with the current weapon direction

        // Decrease ammo after firing
        ammo--;

        // Reset fire timer
        timeSinceLastFire = 0;

        // Add the bullet to the game or bullet manager for updates/rendering
    }
}

void RangeWeapon::Reload() {
    // Reload weapon (reset ammo)
    ammo = 10;  // Full ammo reload
}

void RangeWeapon::SetAmmo(int ammoCount) {
    ammo = ammoCount;
}

int RangeWeapon::GetAmmo() const {
    return ammo;
}

Vec RangeWeapon::GetBulletPosition() const {
    // Calculate a small offset in the direction the gun is pointing (muzzle offset)
    Vec bulletPosition = owner->GetPosition() + weaponDirection * muzzleOffset;
    return bulletPosition;
}

Vec RangeWeapon::GetWeaponDirection() const {
    return weaponDirection;  // Return the current direction the weapon is pointing
}

void RangeWeapon::SetWeaponDirection(const Vec& direction) {
    weaponDirection = direction;  // Set the new direction for the weapon
}

void RangeWeapon::Update(float deltaTime) {
    // Update time since last fire (for managing fire rate)
    timeSinceLastFire += deltaTime;
}

Vec RangeWeapon::PointAtEnemy(const Vec& enemyPosition) {
    // Calculate the direction vector from the weapon's position to the enemy's position
    Vec directionToEnemy = enemyPosition - owner->GetPosition();
    
    // Normalize the direction to get a unit vector (direction only, no magnitude)
    directionToEnemy.Normalize();
    
    // Set the weapon's direction to the calculated direction
    SetWeaponDirection(directionToEnemy);
    
    return directionToEnemy;
}
