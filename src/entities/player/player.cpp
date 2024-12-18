#include "player.h"
#include <iostream>

Player::Player()
    : hp(100), maxHp(100), weaponOffsetX(0), weaponOffsetY(0), face(RIGHT), state(IDLE), speed(Vec(0.0, 0.0)) {
}
void Player::Update(float deltaTime) {
    CheckState();
}

void Player::Collision(GameObject* gameObject) {
    // std::cout << "CoLLISON" << std::endl;
}

void Player::setSpeed(Vec newSpeed) {
    speed = newSpeed;
}



void Player::SetInteractive(bool new_isInteract) {
    isInteract = new_isInteract;
}



Vec Player::getSpeed() {
    return speed;
}

void Player::setSpeedX(double x) {
    speed.SetX(x); // Set only the x-component of the velocity
}

bool Player::GetInteract() {
    return isInteract;
}


void Player::setSpeedY(double y) {
    speed.SetY(y);
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


void Player::Healing(int health) {
    hp = hp + health;
}
