#include "meleeWeapon.h"
MeleeWeapon::MeleeWeapon() : offset(0.f, 0.f) {
    // Default constructor implementation
}

MeleeWeapon::~MeleeWeapon() {
    // Cleanup logic, if needed
}
void MeleeWeapon::Render(sf::RenderWindow& window) {
    window.draw(weaponSprite);
}

double MeleeWeapon::GetDamage() {
    return 0;
    // Default implementation, if necessary
}

void MeleeWeapon::Update(float deltaTime) {
    sf::Vector2f weaponPosition = playerPosition + offset;
    weaponSprite.setPosition(weaponPosition);
}

void MeleeWeapon::setPlayerPosition(sf::Vector2f position) {
    playerPosition = position;
}

void MeleeWeapon::Collision(GameObject* gameObject) {
    std::cout << "MeleeWeapon collided with a game object!" << std::endl;
}

void MeleeWeapon::Attack() {
    // Default implementation, if necessary
}
