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


    


    enum Face { RIGHT, LEFT } face;
    enum State { IDLE, RUN, DEAD, READY } state;
    State CheckState();
    Face CheckFace();
protected:
    int hp;
    int maxHp;
    int shield;
    int maxShield;
    int mana;
    Vec speed;
    AnimationManager animationManager;
    double weaponOffsetX;
    double weaponOffsetY;


    

    


};
