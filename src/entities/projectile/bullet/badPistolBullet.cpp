#include "badPistolBullet.h"
#include "../../../utils/point.h"
#include "../../../utils/tag.h"
#include <cmath>
#include <iostream>

BadPistolBullet::BadPistolBullet() {
    SetProjectileType(ProjectileType::BAD_PISTOL_BULLET); // Assign projectile type
    position = ObjectManager::Instance()->GetPlayer()->GetPosition(); // Initialize position
    speed = Vec(0.0, 0.0);     // Initialize speed
    LoadResources();       // Load resources for the bullet

    // Initialize hitbox
    Point author_pos = Point(position.GetX(), position.GetY());
    hitbox = new HitBox(author_pos);
    if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
        hitbox->SetWidth(bulletTexture.getSize().x);
        hitbox->SetHeight(bulletTexture.getSize().y);
    }

    AddTag(Tag::PLAYER_ATTACK); // Tag the bullet for gameplay logic
}

void BadPistolBullet::Initialize() {
    return ;
}

BadPistolBullet::~BadPistolBullet() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}

void BadPistolBullet::Update(float deltaTime) {
    // Update position
    sf::Vector2f movement(speed.GetX() * deltaTime * 0.01, speed.GetY() * deltaTime * 0.01);
    Vec temp = Vec(movement.x, movement.y);
    position = position + temp;
    bulletSprite.setPosition(position.GetX(), position.GetY());


    Point point = Point(position.GetX(), position.GetY());
    hitbox->SetPosition(point);

    if (speed.GetX() != 0.f || speed.GetY() != 0.f) {
        float angle = std::atan2(speed.GetY(), speed.GetX()) * 180.f / 3.14159f;
        bulletSprite.setRotation(angle);
    }
}

void BadPistolBullet::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/bad_bullet/template/bad_bullet.bmp")) {
        std::cerr << "Error: Could not load bullet image!" << std::endl;
        return;
    }

    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
}

void BadPistolBullet::Render(sf::RenderWindow& window) {
    // Render the bullet sprite
    window.draw(bulletSprite);

    // Optional: Render the hitbox for debugging
    if (hitbox) {
        hitbox->Render(window);
    }
}

void BadPistolBullet::SetPosition(Vec& pos) {
    position.SetX(pos.GetX());
    position.SetY(pos.GetY());
    sf::Vector2f bullet_pos(pos.GetX(), pos.GetY());
    bulletSprite.setPosition(bullet_pos);
    hitbox->SetPosition(Point(pos.GetX(), pos.GetY())); 
}

sf::Vector2f BadPistolBullet::GetPosition() {
    return sf::Vector2f(position.GetX(), position.GetY());
}

void BadPistolBullet::SetSpeed(Vec newSpeed) {
    speed = newSpeed;
}

void BadPistolBullet::Attack() {
    // Implementation for the attack mechanism
    // Define how the bullet behaves when "fired" or interacts with other objects
}
