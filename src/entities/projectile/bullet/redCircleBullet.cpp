#include "redCircleBullet.h"
#include <iostream>


RedCircleBullet::RedCircleBullet() {
    SetProjectileType(ProjectileType::BIG_RED_CIRCLE_BULLET);
    position = sf::Vector2f(0.f, 0.f);
    speed = sf::Vector2f(0.f, 0.f);   
    LoadResources();

    Point author = Point(0.0, 0.0);
    hitbox = new HitBox(author);
    if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
        hitbox->SetWidth(bulletTexture.getSize().x);
        hitbox->SetHeight(bulletTexture.getSize().y);
    }
    AddTag(Tag::MONSTER_ATTACK);
}

void RedCircleBullet::Initialize() {

}

RedCircleBullet::~RedCircleBullet() {
    if (hitbox) {
        delete hitbox;
    }
}

void RedCircleBullet::Update(float deltaTime) {
    // Update position
    sf::Vector2f movement = speed * deltaTime; // Scale speed with deltaTime
    position += movement;                      // Update position
    bulletSprite.setPosition(position);   


    Point point = Point(position.x, position.y);
    hitbox->SetPosition(point);
    

    // Set rotation based on direction of movement
    if (speed.x != 0.f || speed.y != 0.f) {
        float angle = std::atan2(speed.y, speed.x) * 180.f / 3.14159f; 
        bulletSprite.setRotation(angle);
    }
}

void RedCircleBullet::Render(sf::RenderWindow& window) {
    window.draw(bulletSprite);
}

void RedCircleBullet::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/red_circle_bullet/template/red_circle_bullet.bmp")) {
        std::cerr << "Error: Could not load bullet image!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    
    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
}

void RedCircleBullet::Collision(GameObject* gameObject) {
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD) && this->HasTag(Tag::PLAYER_ATTACK)) ||
        gameObject->HasTag(Tag::OBSTACLE)) {
        this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void RedCircleBullet::SetPosition(const sf::Vector2f& pos) {
    position = pos;
    bulletSprite.setPosition(position);
    hitbox->SetPosition(Point(position.x, position.y)); 
}

void RedCircleBullet::SetSpeed(const sf::Vector2f& newSpeed) {
    speed = newSpeed;
}

sf::Vector2f RedCircleBullet::GetPosition() {
    return position;
}
