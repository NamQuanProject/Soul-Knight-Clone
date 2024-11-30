#include "rangeWeapon.h"


RangeWeapon::RangeWeapon()
    : ammo(10), fireRate(0.5), muzzleOffset(10.0), timeSinceLastFire(0) {
    weaponDirection = Vec(1.0, 0.0);  
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


int RangeWeapon::GetAmmo() {
    return ammo;
}

Vec RangeWeapon::GetBulletPosition() {
    double x = owner->GetPosition().GetX();
    double y = owner->GetPosition().GetY();

    Vec bulletPosition(x + weaponDirection.GetX() * muzzleOffset, 
                       y + weaponDirection.GetY() * muzzleOffset);

    return bulletPosition;
}

Vec RangeWeapon::GetWeaponDirection() {
    return weaponDirection; 
}


void RangeWeapon::Reload() {
    ammo = 10;
}

void RangeWeapon::SetAmmo(int ammoCount) {
    ammo = ammoCount;
}


void RangeWeapon::SetWeaponDirection(Vec& direction) {
    weaponDirection = direction;  // Set the new direction for the weapon
}

void RangeWeapon::Update(float deltaTime) {
    // Update time since last fire (for managing fire rate)
    timeSinceLastFire += deltaTime;
}

Vec RangeWeapon::PointAtEnemy(Vec& enemyPosition) {
    // Vec directionToEnemy = enemyPosition - owner->GetPosition();   
    // SetWeaponDirection(directionToEnemy);
    // return directionToEnemy;
    return Vec(0.0, 0.0);
}

double GetDamage() {
    return 0;
}


