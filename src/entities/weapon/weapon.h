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
    virtual void setPlayerPosition(sf::Vector2f position) = 0;
    virtual void setOffset(double x , double y) = 0 ;

protected:
    double damage;              
    double range;               
    GameObject* owner;           
};
