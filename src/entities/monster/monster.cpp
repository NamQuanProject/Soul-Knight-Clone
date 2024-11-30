#include "monster.h"
#include <iostream>

Monster::Monster(double level, bool isMeleeAttackMonster)
    : level(level),
      isMeleeAttackMonster(isMeleeAttackMonster),
      maxSpeed(100.0), // Example default value
      isInitializeWeapon(false),
      isOnDeadTrigger(false),
      player(nullptr),
      collideOnObstacle(false),
       face(RIGHT), state(IDLE)
    {
    
}

void Monster::Update(float deltaTime) {
    if (!IsActive()) return;
    AutoMationMove();
    std::cout << "Monster is updating..." << std::endl;
}

void Monster::Collision(GameObject* gameObject) {
    std::cout << "Monster collided with another object!" << std::endl;
    SetActive(false);
}

void Monster::Render(sf::RenderWindow& window) {
    return ;
}

void Monster::OnDead() {
    std::cout << "Monster is dead!" << std::endl;
    SetActive(false);
}

void Monster::AutoMationMove() {
    Translate(Vec(maxSpeed * 0.1, 0)); 
}

void Monster::SetWeapon(Weapon* weapon) {
    isInitializeWeapon = true;
}

void Monster::SetLevel(double level) {
    this->level = level;
}

MonsterType Monster::GetMonsterType() const {
    return monsterType;
}

void Monster::SetMonsterType(MonsterType type) {
    monsterType = type;
}

void Monster::SetOnDeadTrigger(bool isOnDeadTrigger) {
    this->isOnDeadTrigger = isOnDeadTrigger;
}

void Monster::Injuried(double damage) {
    std::cout << "Monster took " << damage << " damage!" << std::endl;
    if (damage >= level * 10) {
        OnDead();
    }
}

void Monster::Reset() {
    SetActive(true);
    level = 1;
    isOnDeadTrigger = false;
}


Monster::State Monster::CheckState() {
    if (hp <= 0) {
        state = DEAD;
    } else if (state == DEAD && hp > 0) {
        state = IDLE;
    }
    return state;
}

Monster::Face Monster::CheckFace() {
    return face;
}



