#pragma once
#include "projectile.h"
#include "../gameObject.h"
// #include "../utils/object/RotatableObject.h"


// class Bullet : public RotatableObject, public Projectile {
class Bullet : public Projectile, public GameObject {
public:
    Bullet();

    void Update(float deltaTime) override;
    void Collision(GameObject* gameObject) override;
    virtual void UpdateTag(GameObject* gameObject);
    virtual void LoadResources() = 0;
    virtual void SetSpeed(const sf::Vector2f& newSpeed) = 0; // Add this method
    virtual sf::Vector2f GetPosition() = 0;
};