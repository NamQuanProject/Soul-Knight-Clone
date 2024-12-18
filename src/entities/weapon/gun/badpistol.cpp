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

void BadPistol::Attack() {
    std::cout << "Attack" << std::endl;

    // Get all current monster positions
    std::vector<Vec> all_position = ObjectManager::Instance()->getAllCurrentMonsterPosition();

    if (all_position.empty()) {
        if (ObjectManager::Instance()->GetPlayer()->CheckFace() == Knight::RIGHT) {
            Bullet* bullet = static_cast<BadPistolBullet*>(
                ProjectilePool::Instance()->Acquire(ProjectileType::BAD_PISTOL_BULLET)
            );
            bullet->SetSpeed(Vec(270, 0));  
            bullet->UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
        }
        else {
            Bullet* bullet = static_cast<BadPistolBullet*>(
                ProjectilePool::Instance()->Acquire(ProjectileType::BAD_PISTOL_BULLET)
            );
            bullet->SetSpeed(Vec(-270, 0));  
            bullet->UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
        }


        
    } else {
        
        Vec playerPosition = ObjectManager::Instance()->GetPlayer()->GetPosition();
        Vec nearestMonsterPosition;
        double nearestDistance = std::numeric_limits<double>::max();  // Start with a very large distance

        // Find the nearest monster by comparing distances
        for (Vec& monsterPosition : all_position) {
            Vec difference = playerPosition - monsterPosition;
            double distance = difference.GetLength();  // Calculate distance to the monster
            if (distance < nearestDistance) {
                nearestDistance = distance;
                nearestMonsterPosition = monsterPosition;
            }
        }

        // Shoot towards the nearest monster
        Bullet* bullet = static_cast<BadPistolBullet*>(
            ProjectilePool::Instance()->Acquire(ProjectileType::BAD_PISTOL_BULLET)
        );

        // Calculate direction vector to the nearest monster
        Vec direction = nearestMonsterPosition - playerPosition;

        // Normalize the direction vector
        double length = direction.GetLength();
        if (length > 0) {
            direction.SetVec(direction.GetX() / length, direction.GetY() / length);
        }

        // Set bullet speed in the direction of the nearest monster
        bullet->SetSpeed(direction * 360);  // Adjust speed to match the desired bullet speed

        bullet->UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
    }
}




void BadPistol::Initialize() {
    return ;
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