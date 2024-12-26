#include "superMoonBullet.h"
#include <iostream>
#include "../../../manager/objectManager.h"

SuperMoonBullet::SuperMoonBullet() {
    SetProjectileType(ProjectileType::MOON); // Assign projectile type
    LoadResources();       // Load resources for the bullet
    
    Point author = Point(105, 183);
    hitbox = new HitBox(author);
    if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
        hitbox->SetWidth(bulletTexture.getSize().x);
        hitbox->SetHeight(bulletTexture.getSize().y);
    }
    SetDamage(10.0);
    AddTag(Tag::PLAYER_ATTACK); 
}

void SuperMoonBullet::Initialize() {
    return ;
}

SuperMoonBullet::~SuperMoonBullet() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}

void SuperMoonBullet::Update(float deltaTime) {
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

void SuperMoonBullet::Render(sf::RenderWindow& window) {
    window.draw(bulletSprite);
}

void SuperMoonBullet::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/moon/2.bmp")) {
        std::cerr << "Error: Could not load bullet image!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    
    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
}



void SuperMoonBullet::SetPosition(Vec& pos) {
    position = pos;  
    bulletSprite.setPosition(position.GetX(), position.GetY()); 
    hitbox->SetPosition(Point(position.GetX(), position.GetY()));  
}

void SuperMoonBullet::SetSpeed(Vec newSpeed) {
    speed = newSpeed;
}

sf::Vector2f SuperMoonBullet::GetPosition() {
    return sf::Vector2f(position.GetX(), position.GetY());
}
