#include "redConicalBullet.h"
#include <iostream>
#include "../../../manager/objectManager.h"
#include <cmath>

RedConicalBullet::RedConicalBullet() {
    SetProjectileType(ProjectileType::RED_CIRCLE_BULLET);
    LoadResources();
    
    Point author = Point(105, 183);
    hitbox = new HitBox(author);
    if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
        hitbox->SetWidth(bulletTexture.getSize().x);
        hitbox->SetHeight(bulletTexture.getSize().y);
    }

    AddTag(Tag::MONSTER_ATTACK);
    initialPos = Vec(0.0, 0.0);
    maxDistance = 150.0f;
    homingStrength = 0.5f;
    textureLoaded = false;
}

void RedConicalBullet::Initialize() {
    return;
}

RedConicalBullet::~RedConicalBullet() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}



void RedConicalBullet::Update(float deltaTime) {
    GameObject* player = ObjectManager::Instance()->GetPlayer();
    if (player) {
        Vec playerPos = player->GetPosition();
        Vec direction = Vec(
            playerPos.GetX() - position.GetX(),
            playerPos.GetY() - position.GetY()
        );
        
        float length = std::sqrt(direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY());
        
        if (length > 0) {
            Vec normalizedDir = Vec(direction.GetX() / length, direction.GetY() / length);
            Vec targetSpeed = Vec(normalizedDir.GetX() * speed.GetLength(),
                                normalizedDir.GetY() * speed.GetLength());
                                
            speed = Vec(
                speed.GetX() * (1 - homingStrength) + targetSpeed.GetX() * homingStrength,
                speed.GetY() * (1 - homingStrength) + targetSpeed.GetY() * homingStrength
            );
        }
    }

    Vec movement = Vec(speed.GetX() * deltaTime * 0.01, speed.GetY() * deltaTime * 0.01);
    position = position + movement;
    bulletSprite.setPosition(position.GetX(), position.GetY());

    hitbox->SetPosition(Point(position.GetX(), position.GetY()));

    if (speed.GetX() != 0.f || speed.GetY() != 0.f) {
        float angle = std::atan2(speed.GetY(), speed.GetX()) * 180.f / 3.14159f;
        bulletSprite.setRotation(angle);
    }

    float distanceTraveled = std::sqrt(
        std::pow(position.GetX() - initialPos.GetX(), 2) + 
        std::pow(position.GetY() - initialPos.GetY(), 2)
    );
    
    if (distanceTraveled >= maxDistance) {
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void RedConicalBullet::Render(sf::RenderWindow& window) {
    window.draw(bulletSprite);
    // if (hitbox) {
    //     hitbox->Render(window);
    // }
}

void RedConicalBullet::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/red_conical_bullet/template/red_conical_bullet.bmp")) {
        std::cerr << "Error: Could not load bullet image!" << std::endl;
        textureLoaded = false;
        return;
    }
    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    
    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
    textureLoaded = true;
}

void RedConicalBullet::Collision(GameObject* gameObject) {
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        gameObject->HasTag(Tag::WALL)) {
        this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void RedConicalBullet::SetPosition(Vec& pos) {
    position = pos;
    initialPos = pos;
    bulletSprite.setPosition(position.GetX(), position.GetY());
    hitbox->SetPosition(Point(position.GetX(), position.GetY()));
}

void RedConicalBullet::SetSpeed(Vec newSpeed) {
    speed = newSpeed;
}

sf::Vector2f RedConicalBullet::GetPosition() {
    return sf::Vector2f(position.GetX(), position.GetY());
}