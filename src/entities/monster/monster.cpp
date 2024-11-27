#include "monster.h"
#include <iostream>

Monster::Monster(double level, bool isMeleeAttackMonster)
    : level(level),
      isMeleeAttackMonster(isMeleeAttackMonster),
      maxSpeed(100.0), // Example default value
      isInitializeWeapon(false),
      isOnDeadTrigger(false),
      player(nullptr),
      collideOnObstacle(false)
    {
    SetMonsterType(isMeleeAttackMonster ? MonsterType::Melee : MonsterType::Ranged);
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
    sf::CircleShape monsterShape(20);
    monsterShape.setFillColor(isMeleeAttackMonster ? sf::Color::Red : sf::Color::Blue);
    monsterShape.setPosition(static_cast<float>(GetPosition().x), static_cast<float>(GetPosition().y));
    window.draw(monsterShape);
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


