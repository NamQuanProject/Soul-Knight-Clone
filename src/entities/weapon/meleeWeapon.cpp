#include "meleeWeapon.h"
#include <iostream>

MeleeWeapon::MeleeWeapon() : durability(100) {
    damage = 25;  
    range = 1.5;
}

void MeleeWeapon::Use() {
    // if (durability > 0) {
    //     std::cout << "Swinging melee weapon for " << damage << " damage!" << std::endl;
    //     durability--;
    // } else {
    //     std::cout << "Weapon is broken! Durability is zero." << std::endl;
    // }
}

void MeleeWeapon::SetDurability(int durability) {
    this->durability = durability;
}

int MeleeWeapon::GetDurability() const {
    return durability;
}
