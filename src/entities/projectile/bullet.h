#pragma once
#include "projectile.h"
#include "../gameObject.h"
// #include "../utils/object/RotatableObject.h"


// class Bullet : public RotatableObject, public Projectile {
class Bullet : public Projectile {
public:
    Bullet();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Collision(GameObject* gameObject);
    virtual void UpdateTag(GameObject* gameObject);
    virtual void LoadResources() = 0;
};