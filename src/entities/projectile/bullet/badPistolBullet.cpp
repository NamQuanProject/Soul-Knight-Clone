#include "badPistolBullet.h"
#include <cmath>
#include <iostream>

BadPistolBullet::BadPistolBullet() {
    SetProjectileType(ProjectileType::BAD_PISTOL_BULLET); // Assign projectile type
    position = sf::Vector2f(0.f, 0.f); // Initialize position
    speed = sf::Vector2f(0.f, 0.f);   // Initialize speed
    LoadResources();
}

void BadPistolBullet::Start() {
    Bullet::Start();
}

void BadPistolBullet::Update(float deltaTime) {
    sf::Vector2f movement = speed * deltaTime; // Scale speed with deltaTime
    position += movement;                      // Update the position
    bulletSprite.setPosition(position);        // Update sprite's position

    // Set rotation based on direction of movement
    if (speed.x != 0.f || speed.y != 0.f) {
        float angle = std::atan2(speed.y, speed.x) * 180.f / 3.14159f; 
        bulletSprite.setRotation(angle);
    }
}

void BadPistolBullet::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/bad_bullet/template/bad_bullet.bmp")) {
        std::cerr << "Error: Could not load background image!" << std::endl;
    }

    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);

}

void BadPistolBullet::Render(sf::RenderWindow& window) {
    window.draw(bulletSprite);
}

void BadPistolBullet::SetPosition(const sf::Vector2f& pos) {
    position = pos;
    bulletSprite.setPosition(position);
}

void BadPistolBullet::SetSpeed(const sf::Vector2f& newSpeed) {
    speed = newSpeed;
}
sf::Vector2f BadPistolBullet::GetPosition() {
    return position;
}
