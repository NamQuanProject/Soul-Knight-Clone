#include "meleeWeapon.h"
#include <iostream>

MeleeWeapon::MeleeWeapon()
    : durability(100) {}

int MeleeWeapon::GetDurability() const {
    return durability;
}

void MeleeWeapon::SetDurability(int durabilityCount) {
    durability = durabilityCount;
}

// double MeleeWeapon::GetDamage() const {
//     return damage;
// }

// void MeleeWeapon::SetDamage(double damageValue) {
//     damage = damageValue;
// }

// void MeleeWeapon::SetRange(double rangeValue) {
//     range = rangeValue;
// }

// double MeleeWeapon::GetRange() const {
//     return range;
// }

void MeleeWeapon::Update(float deltaTime) {
    std::cout << "Updating melee weapon..." << std::endl;
}

bool MeleeWeapon::IsInRange() {
    return true;
}

void MeleeWeapon::Attack() {
    
}
