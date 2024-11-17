#include "badPistol.h"
#include <iostream>

BadPistol::BadPistol() {
    damage = 5;         // Low damage, reflecting a "bad" weapon
    ammo = 6;           // Low ammo capacity
    fireRate = 1.0;     // Slow rate of fire (higher value for slower fire rate)
    range = 7.0;        // Decent range, but not great
}

void BadPistol::Use() {
    if (ammo > 0) {
        std::cout << "Firing Bad Pistol for " << damage << " damage!" << std::endl;
        ammo--;
    } else {
        std::cout << "Out of ammo! Reloading..." << std::endl;
    }
}
