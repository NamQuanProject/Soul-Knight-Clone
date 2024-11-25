#pragma once

#include "weapon.h"

class MeleeWeapon : public Weapon {
public:
    MeleeWeapon();
    virtual ~MeleeWeapon() = default;

    void Use();             
    void SetDurability(int durability); 
    int GetDurability() const;        

protected:
    int durability;                   
};
