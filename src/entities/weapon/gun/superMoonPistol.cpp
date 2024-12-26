#include "superMoonPistol.h"

#include <iostream>

SuperMoonPistol::SuperMoonPistol() {
    sf::Image imageRight, imageLeft;

    // Load the right-facing image
    if (!imageRight.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/weapon/bad_pistol/270.bmp")) {
        std::cerr << "Error: Could not load right-facing image!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    imageRight.createMaskFromColor(transparentColor);
    pistolTextureRight.loadFromImage(imageRight);

    // Load the left-facing image
    if (!imageLeft.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/weapon/bad_pistol/90.bmp")) {
        std::cerr << "Error: Could not load left-facing image!" << std::endl;
    }
    imageLeft.createMaskFromColor(transparentColor);
    pistolTextureLeft.loadFromImage(imageLeft);

    // Set the initial texture (default to right-facing)
    pistolSprite.setTexture(pistolTextureRight);

    offset = sf::Vector2f(5.f, 2.f);
}

void SuperMoonPistol::setOffset(double x, double y) {
    offset = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}

void SuperMoonPistol::Attack() {
    std::cout << "Attack" << std::endl;


    std::vector<Vec> all_position = ObjectManager::Instance()->getAllCurrentMonsterPosition();

    if (all_position.empty()) {
        if (ObjectManager::Instance()->GetPlayer()->CheckFace() == Knight::RIGHT) {
            Bullet* bullet = static_cast<SuperMoonBullet*>(
                ProjectilePool::Instance()->Acquire(ProjectileType::MOON)
            );
            bullet->SetPosition(position);
            bullet->SetSpeed(Vec(270, 0));  
            bullet->UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
        } else {
            Bullet* bullet = static_cast<SuperMoonBullet*>(
                ProjectilePool::Instance()->Acquire(ProjectileType::MOON)
            );
            bullet->SetPosition(position);
            bullet->SetSpeed(Vec(-270, 0));  
            bullet->UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
        }
    } else {
        Vec playerPosition = ObjectManager::Instance()->GetPlayer()->GetPosition();
        Vec nearestMonsterPosition;
        double nearestDistance = std::numeric_limits<double>::max();

        // Find the nearest monster
        for (Vec& monsterPosition : all_position) {
            Vec difference = playerPosition - monsterPosition;
            double distance = difference.GetLength();
            if (distance < nearestDistance) {
                nearestDistance = distance;
                nearestMonsterPosition = monsterPosition;
            }
        }

        // Shoot towards the nearest monster
        Bullet* bullet = static_cast<SuperMoonBullet*>(
            ProjectilePool::Instance()->Acquire(ProjectileType::MOON)
        );

        // Calculate direction vector
        Vec direction = nearestMonsterPosition - playerPosition;

        // Normalize the direction vector
        double length = direction.GetLength();
        if (length > 0) {
            direction.SetVec(direction.GetX() / length, direction.GetY() / length);
        }

        // Set bullet speed
        bullet->SetSpeed(direction * 360);

        bullet->UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
    }
}

void SuperMoonPistol::Initialize() {}

void SuperMoonPistol::Render(sf::RenderWindow& window) {
    window.draw(pistolSprite);
}


void SuperMoonPistol::Update(float deltaTime) {
    Vec playerPosition1 = ObjectManager::Instance()->GetPlayer()->GetPosition();
    sf::Vector2f pistolPosition = playerPosition + offset;
    pistolSprite.setPosition(pistolPosition);


    if (ObjectManager::Instance()->GetPlayer()->CheckFace() == Knight::RIGHT) {
        pistolSprite.setTexture(pistolTextureRight);
    } else {
        pistolSprite.setTexture(pistolTextureLeft);
    }

    position = Vec(float(pistolPosition.x), float(pistolPosition.y));
}

void SuperMoonPistol::Fire() {
    std::cout << "Firing the SuperMoonPistol!" << std::endl;
}

void SuperMoonPistol::Reload() {
    std::cout << "Reloading the SuperMoonPistol!" << std::endl;
}

void SuperMoonPistol::Collision(GameObject* gameObject) {
    std::cout << "SuperMoonPistol collided with a game object!" << std::endl;
}

double SuperMoonPistol::GetDamage() {
    return 10.0;
}

void SuperMoonPistol::setPlayerPosition(sf::Vector2f Position) {
    playerPosition = Position;
}
