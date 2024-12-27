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
    
    virtual void Attack();
    void Poisoned(double poisonDamage);
    void Collision(GameObject* gameObject) override;
    void setSpeed(Vec newSpeed);
    void setSpeedX(double x);
    void setSpeedY(double y);
    bool GetInteract();
    void SetInteractive(bool new_isInteract);
    virtual void SwitchWeapon();
    virtual void UseSkill();


    // STATE RELATED
    int GetHP() const;
    int GetMaxHP() const;

    int GetMana() const;
    int GetMaxMana() const;
    
    int GetShield() const;
    int GetMaxShield() const;

    void Healing(int health);
    void ManaRegen(int add_mana);
    void ShieldRegen(int add_shield);


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
