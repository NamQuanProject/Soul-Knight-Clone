#include "weapon.h"

Weapon::Weapon() : damage(0.0), range(0.0), owner(nullptr) {}

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
    return Vec(0.0, 0.0);
}


void Weapon::Initialize() {
    return ;
}


