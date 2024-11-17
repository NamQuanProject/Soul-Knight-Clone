#include "RangeWeapon.h"
#include <iostream>

RangeWeapon::RangeWeapon() : ammo(10), fireRate(0.5) {
    damage = 15;  
    range = 10.0;  
}

void RangeWeapon::Use() {
    if (ammo > 0) {
        std::cout << "Firing projectile for " << damage << " damage!" << std::endl;
        ammo--;
    } else {
        std::cout << "Out of ammo! Reloading..." << std::endl;
    }
}

void RangeWeapon::Reload() {
    std::cout << "Reloading weapon..." << std::endl;
    ammo = 10;  
}

void RangeWeapon::SetAmmo(int ammoCount) {
    ammo = ammoCount;
}

int RangeWeapon::GetAmmo() const {
    return ammo;
}
