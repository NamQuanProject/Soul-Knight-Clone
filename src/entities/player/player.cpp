#include "player.h"

Player::Player()
    : hp(100), maxHp(100), weapon1(nullptr), weaponOffsetX(0), weaponOffsetY(0), face(RIGHT), state(IDLE) {
}



void Player::Update(float deltaTime) {
    CheckState();
}

void Player::Collision(GameObject* gameObject) {

}

void Player::Render(sf::RenderWindow& window) {
    
}


double Player::GetHP() const {
    return hp;
}

double Player::GetMaxHP() const {
    return maxHp;
}

void Player::Attack() {
    if (weapon1) {
        // Perform attack using weapon1
        weapon1->Use();
    }
}

void Player::Poisoned(double poisonDamage) {
   
}

Player::State Player::CheckState() {
    if (hp <= 0) {
        state = DEAD;
    } else if (state == DEAD && hp > 0) {
        state = IDLE;
    }
    return state;
}

Player::Face Player::CheckFace() {
    return face;
}
