#pragma once

#include "../gameObject.h"
#include "../../utils/vec.h"

class Weapon : public GameObject {
public:
    Weapon();
    virtual ~Weapon() = default;

    virtual void Use() = 0;  
    virtual double GetDamage() = 0; 
    void SetOwner(GameObject* owner); 
    virtual Vec GetPosition();

protected:
    double damage;              
    double range;               
    GameObject* owner;           
};
