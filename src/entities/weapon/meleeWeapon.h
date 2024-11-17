#pragma once

#include "weapon.h"

class MeleeWeapon : public Weapon {
public:
    MeleeWeapon();
    virtual ~MeleeWeapon() = default;

    void Use() override;              // Perform melee attack (swing, thrust, etc.)
    void SetDurability(int durability); // Set the durability of the weapon
    int GetDurability() const;        // Get the current durability of the weapon

protected:
    int durability;                   // Durability of the melee weapon (how many hits before breaking)
};
