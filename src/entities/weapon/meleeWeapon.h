#pragma once

#include "weapon.h"

class MeleeWeapon : public Weapon {
public:
    MeleeWeapon();
    virtual ~MeleeWeapon() = default;
    void Attack() override;     
    void Update(float deltaTime) override;      
    double GetRange();  
    void SetDurability(int durability); 
    int GetDurability() const;        
    bool IsInRange();
protected:
    int durability;                   
};
