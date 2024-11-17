#include "player.h"

Player::Player()
    : hp(0), maxHp(0), weapon1(nullptr), weaponOffsetX(0), weaponOffsetY(0), face(RIGHT), state(IDLE), poisonedIcon(nullptr) {
    poison = {0.0, 0, 0};
}

void Player::Start() {
    // Initialize player-specific logic
}

void Player::Update() {
    CheckState();
    CheckFace();
    // if (poison.damageRemainingTimes > 0) {
    //     poison.counter++;
    //     if (poison.counter >= poison.damageInterval) {
    //         poison.counter = 0;
    //         hp -= poison.damage;
    //         poison.damageRemainingTimes--;
    //         if (poisonedIcon) {
    //             // Update poisoned UI
    //         }
    //         if (hp <= 0) {
    //             state = DEAD;
    //         }
    //     }
    // }
}

void Player::Collision(GameObject* gameObject) {
    // Handle collision with other game objects
}

double Player::GetHP() const {
    return hp;
}

double Player::GetMaxHP() const {
    return maxHp;
}

void Player::Attack() {
    // if (weapon1) {
    //     // Perform attack using weapon1
    // }
}

void Player::Poisoned(double poisonDamage) {
    // poison.damage = poisonDamage;
    // poison.damageRemainingTimes = 5; // Example: Apply poison 5 times
    // poison.counter = 0;
    // if (!poisonedIcon) {
    //     // Initialize poisoned UI
    // }
}

void Player::CheckState() {
    if (hp <= 0) {
        state = DEAD;
    } else if (state == DEAD && hp > 0) {
        state = IDLE;
    }
}

void Player::CheckFace() {
    if (vision.x >= 0) {
        face = RIGHT;
    } else {
        face = LEFT;
    }
}
