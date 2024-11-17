#pragma once

#include "../gameObject.h"
#include "../../utils/vec.h"
// #include "Weapon.h"
// #include "PoisonedIcon.h"

class Player : public GameObject {
public:
    Player();
    virtual ~Player() = default;

    void Start() override;
    void Update() override;
    void Collision(GameObject* gameObject) override;

    double GetHP() const;
    double GetMaxHP() const;
    virtual void Attack();
    virtual void Injured(double damage) = 0;
    void Poisoned(double poisonDamage);

protected:

    // Weapon* weapon1;
    double weaponOffsetX;
    double weaponOffsetY;

    enum Face { RIGHT, LEFT } face;
    enum State { IDLE, RUN, DEAD, READY } state;

private:
    struct Poison {
        double damage;
        int counter;
        int damageRemainingTimes;
        const int damageInterval = 50;
    } poison;

    // PoisonedIcon* poisonedIcon;

    virtual void CheckState();
    void CheckFace();
};
