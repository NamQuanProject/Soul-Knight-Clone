#include "badPistolBullet.h"
#include "../../../utils/point.h"
#include <cmath>
#include <iostream>

BadPistolBullet::BadPistolBullet() {
    SetProjectileType(ProjectileType::BAD_PISTOL_BULLET); // Assign projectile type
    position = sf::Vector2f(0.f, 0.f); // Initialize position
    speed = sf::Vector2f(0.f, 0.f);   // Initialize speed
    LoadResources();

    Point author = Point(0.0, 0.0);
    hitbox = new HitBox(author);
    if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
        hitbox->SetWidth(bulletTexture.getSize().x);
        hitbox->SetHeight(bulletTexture.getSize().y);
        
    }
}

BadPistolBullet::~BadPistolBullet() {
    if (hitbox) {
        delete hitbox;
    }
}

void BadPistolBullet::Update(float deltaTime) {
    // Update position
    sf::Vector2f movement = speed * deltaTime; // Scale speed with deltaTime
    position += movement;                      // Update position
    bulletSprite.setPosition(position);   


    Point point = Point(position.x, position.y);
    hitbox->SetPosition(point);
    // Update hitbox position
    

    // Set rotation based on direction of movement
    if (speed.x != 0.f || speed.y != 0.f) {
        float angle = std::atan2(speed.y, speed.x) * 180.f / 3.14159f; 
        bulletSprite.setRotation(angle);
    }
}

void BadPistolBullet::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/bad_bullet/template/bad_bullet.bmp")) {
        std::cerr << "Error: Could not load bullet image!" << std::endl;
    }

    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
}

void BadPistolBullet::Render(sf::RenderWindow& window) {
    // Render the bullet sprite
    window.draw(bulletSprite);

    // Render the hitbox for debugging (if needed)
    if (hitbox) {
        hitbox->Render(window);
    }
}

void BadPistolBullet::SetPosition(const sf::Vector2f& pos) {
    position = pos;
    bulletSprite.setPosition(position);
    hitbox->SetPosition(Point(position.x, position.y)); 
}

void BadPistolBullet::SetSpeed(const sf::Vector2f& newSpeed) {
    speed = newSpeed;
}

sf::Vector2f BadPistolBullet::GetPosition() {
    return position;
}

