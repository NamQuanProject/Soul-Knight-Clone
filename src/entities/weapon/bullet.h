#pragma once

#include "../gameObject.h"
#include "../../utils/vec.h"

class Bullet : public GameObject {
public:
    Bullet(double damage, double speed, Vec direction, GameObject* owner);
    virtual ~Bullet() = default;
    
    void Update() override;            // Update the bullet's state
    void Collision(GameObject* gameObject) override; // Handle collision
          // Start method to be implemented by derived classes
    
protected:
    double damage;
    double speed;
    Vec direction;
    GameObject* owner;
};
