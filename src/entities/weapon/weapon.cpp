#include "weapon.h"

Weapon::Weapon() : damage(0), range(0), owner(nullptr) {
}

void Weapon::Use() {
    // Default weapon action (e.g., no action for base class)
}

double Weapon::GetDamage() const {
    return damage;
}

void Weapon::SetOwner(GameObject* owner) {
    this->owner = owner;
}
