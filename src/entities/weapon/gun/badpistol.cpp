#include "badPistol.h"
#include <iostream>

BadPistol::BadPistol() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/weapon/bad_pistol/90.bmp")) {
        std::cerr << "Error: Could not load background image!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    pistolTexture.loadFromImage(image);
    pistolSprite.setTexture(pistolTexture);

    
    offset = sf::Vector2f(5.f, 2.f);
}

void BadPistol::setOffset(double x, double y) {
    offset = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}

void BadPistol::Render(sf::RenderWindow& window) {

    window.draw(pistolSprite);
}

void BadPistol::Use() {
    if (ammo > 0) {
        std::cout << "BadPistol: Bang! Fired a shot.\n";
        --ammo;
    } else {
        std::cout << "BadPistol: Out of ammo! Reload needed.\n";
    }
}

void BadPistol::Update(float deltaTime) {
    sf::Vector2f pistolPosition = playerPosition + offset;
    pistolSprite.setPosition(pistolPosition);
}


void BadPistol::Fire() {
    std::cout << "Firing the BadPistol!" << std::endl;
}

void BadPistol::Reload() {
    std::cout << "Reloading the BadPistol!" << std::endl;
}

void BadPistol::Collision(GameObject* gameObject) {
    std::cout << "BadPistol collided with a game object!" << std::endl;
}

double BadPistol::GetDamage() {
    return 10.0;
}

void BadPistol::setPlayerPosition(sf::Vector2f Position) {
    playerPosition = Position;
    return ;
}