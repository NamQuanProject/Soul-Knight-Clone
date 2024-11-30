#include "weapon.h"

// Default constructor: Initializes damage, range, and owner to default values
Weapon::Weapon() : damage(0.0), range(0.0), owner(nullptr) {}

// SetOwner: Assigns an owner to the weapon
void Weapon::SetOwner(GameObject* newOwner) {
    owner = newOwner;
}

Vec Weapon::GetPosition() {
    if (owner) {
        Vec pos =  owner->GetPosition();
        Vec temp = Vec(1.0, 0.0);
        pos = pos + temp;
        return pos;
    }

    return Vec(0.0, 0.0); // Default position if no owner
}

