#pragma once
#include "projectile.h"
#include "../gameObject.h"
// #include "../utils/object/RotatableObject.h"


// class Bullet : public RotatableObject, public Projectile {
class Bullet : public GameObject, public Projectile {
public:
    Bullet();
    void Update(float deltaTime) override;
    void Collision(GameObject* gameObject) override;
    virtual void UpdateTag(GameObject* gameObject);
    virtual void LoadResources() = 0;
    virtual void SetSpeed(Vec newSpeed) = 0; // Add this method

    
    virtual sf::Vector2f GetPosition() = 0;




};