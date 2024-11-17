#pragma once

#include "../gameObject.h"
#include "../../utils/vec.h"

class Weapon : public GameObject {
public:
    Weapon();
    virtual ~Weapon() = default;

    virtual void Use();          // Perform the weapon's primary action
    virtual double GetDamage() const; // Get the damage dealt by the weapon
    void SetOwner(GameObject* owner); // Set the weapon's owner

protected:
    double damage;               // Damage dealt by the weapon
    double range;                // Weapon's effective range
    GameObject* owner;           // Owner of the weapon
};
