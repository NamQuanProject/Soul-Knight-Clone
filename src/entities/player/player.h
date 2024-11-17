#pragma once

#include "../gameObject.h"
#include "../../utils/vec.h"
#include "../weapon/weapon.h"
#include "../../utils/vec.h"
// #include "PoisonedIcon.h"

class Player : public GameObject {
public:
    Player();
    virtual ~Player() = default;

    void Update() override;
    void Collision(GameObject* gameObject) override;

    double GetHP() const;
    double GetMaxHP() const;
    virtual void Attack();
    virtual void Injured(double damage) = 0;
    void Poisoned(double poisonDamage);

protected:
    Vec vision;
    double hp;          // Current health points
    double maxHp;       // Maximum health points

    Weapon* weapon1;
    double weaponOffsetX;
    double weaponOffsetY;

    enum Face { RIGHT, LEFT } face;
    enum State { IDLE, RUN, DEAD, READY } state;

private:
    // PoisonedIcon* poisonedIcon;

    virtual void CheckState();
    void CheckFace();
};
