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

void Player::SwitchWeapon() {
    
}
void Player::UseSkill() {
    
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


int Player::GetHP() const {
    return hp;
}

int Player::GetMaxHP() const {
    return maxHp;
}

int Player::GetMana() const {
    return mana;
}

int Player::GetMaxMana() const {
    return maxMana;
}

int Player::GetShield() const {
    return shield;
}

int Player::GetMaxShield() const {
    return maxShield;
}

void Player::Attack() {
    
}

void Player::ManaRegen(int add_mana) {
    mana = mana + mana;
}

void Player::ShieldRegen(int add_shield) {
    shield = shield + add_shield;
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
    if (hp > maxHp) {
        hp = maxHp;
    }
}
