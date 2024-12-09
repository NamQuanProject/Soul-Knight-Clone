#pragma once

#include "../gameObject.h"
#include "monsterType.h"
#include "../weapon/weapon.h"
#include "../projectile/projectile.h"

class Monster : public GameObject {
public:
    Monster(double level, bool isMeleeAttackMonster = false);
    void Update(float deltaTime) override;
    void Collision(GameObject* gameObject) override;
    void Render(sf::RenderWindow& window) override;
    
    virtual void OnDead();
    virtual void AutoMationMove();
    virtual void AutoMation() = 0;
    virtual void InitializeWeapon() = 0;

    // Setter and getter methods
    void SetWeapon(Weapon* weapon);
    void SetLevel(double level);
    

    void Injuried(double damage);
    void Reset();


    enum Face { RIGHT, LEFT } face;
    enum State { IDLE, RUN, DEAD, READY } state;
    MonsterType GetMonsterType() const;
    State CheckState();
    Face CheckFace();

protected:
    double maxSpeed;
    double level;
    MonsterType monsterType;
    bool isMeleeAttackMonster;
    bool collideOnObstacle;
    double hp;
    double maxHp;

    void SetMonsterType(MonsterType type);
    void SetOnDeadTrigger(bool isOnDeadTrigger);

private:
    bool isInitializeWeapon;
    bool isOnDeadTrigger;
    

    GameObject* player;
};
