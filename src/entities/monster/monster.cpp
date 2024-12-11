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
    AddTag(Tag::MONSTER);
}

void Monster::Attack() {

}

void Monster::Update(float deltaTime) {
   

    if (!IsActive()) return;
    
    AutoMationMove();
    std::cout << "Monster is updating..." << std::endl;
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

void Monster::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER_ATTACK)) {
        Injuried(dynamic_cast<Projectile*>(gameObject)->GetDamage());
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

void Monster::Injuried(double damage) {
    if (this->HasTag(Tag::DEAD)) {
        return;
    }
    this->hp -= damage;
    std::cout << this->hp << std::endl;
    if (this->hp < 0) {
        this->hp = 0;
    }

    

    // if (!damageText) {
    //     CreateNewDamageText();
    // }

    // if (damageText->IsAlive() == false) {
    //     CreateNewDamageText();
    // }

    // damageText->AddDamage(damage);
}