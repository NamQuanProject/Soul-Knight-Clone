#pragma once

#include "../gameObject.h"
#include "../weapon/weapon.h"

enum class MonsterType {
    Melee,
    Ranged,
    Boss
};

class Monster : public GameObject {
public:
    Monster(double level, bool isMeleeAttackMonster = false);

    // Core lifecycle methods
    void Update(float deltaTime) override;
    void Collision(GameObject* gameObject) override;
    void Render(sf::RenderWindow& window) override;

    // Monster-specific functionality
    virtual void OnDead();
    virtual void AutoMationMove();
    virtual void AutoMation() = 0;
    virtual void InitializeWeapon() = 0;

    // Setter and getter methods
    void SetWeapon(Weapon* weapon);
    void SetLevel(double level);
    MonsterType GetMonsterType() const;

    void Injuried(double damage);
    void Reset();

protected:
    // Monster attributes
    double maxSpeed;
    double level;
    MonsterType monsterType;
    bool isMeleeAttackMonster;
    bool collideOnObstacle;

    void SetMonsterType(MonsterType type);
    void SetOnDeadTrigger(bool isOnDeadTrigger);

private:
    // Internal states
    bool isInitializeWeapon;
    bool isOnDeadTrigger;

    // Player reference
    GameObject* player;
};
