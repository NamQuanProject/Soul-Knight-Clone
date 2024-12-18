#pragma once

#include "../gameObject.h"
#include "../../utils/vec.h"
#include "../weapon/weapon.h"
#include "../../utils/vec.h"
#include "../../manager/animationManager.h"
// #include "PoisonedIcon.h"

class Player : public GameObject {
public:
    Player();
    virtual ~Player() = default;
    virtual void Render(sf::RenderWindow& window) override;
    void Update(float deltaTime) override;
    double GetHP() const;
    double GetMaxHP() const;
    virtual void Attack();
    void Poisoned(double poisonDamage);
    void Collision(GameObject* gameObject) override;
    void setSpeed(Vec newSpeed);
    void setSpeedX(double x);
    void setSpeedY(double y);
    bool GetInteract();
    void SetInteractive(bool new_isInteract);
    Vec getSpeed();


    virtual void runLeft() = 0;
    virtual void runRight() = 0;
    virtual void standLeft() = 0;
    virtual void standRight() = 0;



    enum Face { RIGHT, LEFT } face;
    enum State { IDLE, RUN, DEAD, READY } state;
    State CheckState();
    Face CheckFace();
protected:
    int hp;
    int maxHp;
    int mana;
    int maxMana;
    int shield;
    int maxShield;
    bool isInteract = false;
    Vec speed;
    AnimationManager animationManager;
    double weaponOffsetX;
    double weaponOffsetY;

};
