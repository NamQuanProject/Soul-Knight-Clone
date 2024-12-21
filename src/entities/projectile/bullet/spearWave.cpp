#include "spearWave.h"
#include <iostream>
#include "../../../manager/objectManager.h"

SpearWave::SpearWave() {
    SetProjectileType(ProjectileType::SPEAR_WAVE); // Assign projectile type
    LoadResources();       // Load resources for the bullet
    
    Point author = Point(105, 183);
    hitbox = new HitBox(author);
    if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
        hitbox->SetWidth(bulletTexture.getSize().x);
        hitbox->SetHeight(bulletTexture.getSize().y);
    }

    AddTag(Tag::MONSTER_ATTACK); 
}

void SpearWave::Initialize() {
    return ;
}

SpearWave::~SpearWave() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}

void SpearWave::Update(float deltaTime) {
   // Update position
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

void SpearWave::Render(sf::RenderWindow& window) {
    window.draw(bulletSprite);
    // if (hitbox) {
    //     hitbox->Render(window);
    // }
}

void SpearWave::LoadResources() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/spear_wave/template/SpearWave.bmp")) {
        std::cerr << "Error: Could not load bullet image!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    
    bulletTexture.loadFromImage(image);
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
}

void SpearWave::Collision(GameObject* gameObject) {
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        gameObject->HasTag(Tag::WALL)) {
        this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void SpearWave::SetPosition(Vec& pos) {
    position = pos;  
    bulletSprite.setPosition(position.GetX(), position.GetY()); 
    hitbox->SetPosition(Point(position.GetX(), position.GetY()));  
}

void SpearWave::SetSpeed(Vec newSpeed) {
    speed = newSpeed;
}

sf::Vector2f SpearWave::GetPosition() {
    return sf::Vector2f(position.GetX(), position.GetY());
}
