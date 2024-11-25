#pragma once
#include "projectile.h"
#include "../gameObject.h"
// #include "../utils/object/RotatableObject.h"


// class Bullet : public RotatableObject, public Projectile {
class Bullet : public Projectile {
public:
    Bullet();
    void Start();
    void Update();
    void Collision(GameObject* gameObject);
    void UpdateTag(GameObject* gameObject);
};