#include "dragonSword.h"
#include <cmath>
#include <iostream>

DragonBlade::DragonBlade() {
    sf::Image imageRight, imageLeft;

    // Load the right-facing texture
    if (!imageRight.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/weapon/dragon_sword/1.bmp")) {
        std::cerr << "Error: Could not load right-facing DragonBlade image!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    imageRight.createMaskFromColor(transparentColor);
    bladeTextureRight.loadFromImage(imageRight);

    // Load the left-facing texture
    if (!imageLeft.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/weapon/dragon_sword/flip_1.bmp")) {
        std::cerr << "Error: Could not load left-facing DragonBlade image!" << std::endl;
    }
    imageLeft.createMaskFromColor(transparentColor);
    bladeTextureLeft.loadFromImage(imageLeft);

    bladeSprite.setTexture(bladeTextureRight);
    bladeSprite.setOrigin(0, bladeSprite.getLocalBounds().height / 2); // Pivot point for swinging

    attackRange = 50;
    damageMultiplier = 2.0;
    Point author_pos = Point(0.0, 0.0);

    hitbox = new HitBox(author_pos);
    if (bladeTextureRight.getSize().x > 0 && bladeTextureRight.getSize().y > 0) {
        hitbox->SetWidth(bladeTextureRight.getSize().x);
        hitbox->SetHeight(bladeTextureRight.getSize().y);
    }

    isSwinging = false;
    swingAngle = 0.0f;
    swingSpeed = 20.0f; // Degrees per second
    swingDuration = 40.f; // Seconds for the wipe effect
    swingTimer = 0.0f;

    AddTag(Tag::PLAYER_ATTACK);
}

void DragonBlade::Initialize() {
    std::cout << "DragonBlade initialized!" << std::endl;
}

void DragonBlade::Update(float deltaTime) {
    auto* player = ObjectManager::Instance()->GetPlayer();
    if (!player) {
        std::cerr << "Error: Player not found!" << std::endl;
        return;
    }

    // Update the blade's position relative to the player
    playerPosition.x = player->GetPosition().GetX();
    playerPosition.y = player->GetPosition().GetY();
    sf::Vector2f bladePosition = playerPosition + offset;
    bladeSprite.setPosition(bladePosition);

    // Update blade texture based on player's facing direction
    if (player->CheckFace() == Knight::RIGHT) {
        bladeSprite.setTexture(bladeTextureRight);
        Point temp = Point(playerPosition.x + 18, playerPosition.y);
        hitbox->SetPosition(temp);  // Update hitbox position for right-facing
    } else {
        bladeSprite.setTexture(bladeTextureLeft);
        Point temp = Point(playerPosition.x - 18, playerPosition.y);
        hitbox->SetPosition(temp);  // Update hitbox position for left-facing
    }

    // Handle swinging animation
   // Handle swinging animation
    if (isSwinging) {
        swingTimer += deltaTime;

        // Calculate the current swing angle (swing between -45 and +45 degrees)
        float angle = std::sin(swingTimer * swingSpeed * (M_PI / 180.0f)) * 45.0f;

        // Check player's facing direction and adjust the swing direction
        if (player->CheckFace() == Knight::RIGHT) {
            bladeSprite.setRotation(angle); // Swing right
        } else {
            bladeSprite.setRotation(-angle); // Swing left (invert the angle)
        }

        if (swingTimer >= swingDuration) {
            isSwinging = false;
            bladeSprite.setRotation(0.0f); // Reset rotation
        }
    }

}

void DragonBlade::Render(sf::RenderWindow& window) {
    window.draw(bladeSprite);
    // if (hitbox != nullptr) {
    //     hitbox->Render(window);
    // }
}

void DragonBlade::Attack() {
    std::cout << "DragonBlade: Swinging the blade!" << std::endl;

    // Start the swinging animation
    isSwinging = true;
    swingTimer = 0.0f;

    // Get the player's position from ObjectManager
    auto* player = ObjectManager::Instance()->GetPlayer();
    if (!player) {
        std::cerr << "Error: Player not found!" << std::endl;
        return;
    }

    Vec playerPosition = player->GetPosition();
    
    // Example: Check for monsters within range and apply damage
    std::vector<Vec> allMonsterPositions = ObjectManager::Instance()->getAllCurrentMonsterPosition();

    for (size_t i = 0; i < allMonsterPositions.size(); ++i) {
        Vec& monsterPosition = allMonsterPositions[i];
        Vec difference = playerPosition - monsterPosition;
        double distance = difference.GetLength();

        if (distance <= attackRange) {
            std::cout << "DragonBlade hit a monster at distance " << distance << "!" << std::endl;

            // Retrieve the monster object from ObjectManager
            std::vector<GameObject*> currentMonsters = ObjectManager::Instance()->getAllCurrentMonster();
            Monster* monster = static_cast<Monster*>(currentMonsters[i]);
            if (i < currentMonsters.size()) {
                if (monster) {
                    // Apply damage to the monster
                    monster->takeDamage(GetDamage());
                }
            }
        }
    }
}

void DragonBlade::SpecialAttack() {
    std::cout << "DragonBlade: Unleashing a powerful special attack!" << std::endl;

    // Get the player's position from ObjectManager
    auto* player = ObjectManager::Instance()->GetPlayer();
    if (!player) {
        std::cerr << "Error: Player not found!" << std::endl;
        return;
    }

    Vec playerPosition = player->GetPosition();

    // Example: Area-of-effect attack logic
    std::vector<Vec> allMonsterPositions = ObjectManager::Instance()->getAllCurrentMonsterPosition();

    for (Vec& monsterPosition : allMonsterPositions) {
        Vec difference = playerPosition - monsterPosition;
        double distance = difference.GetLength();

        if (distance <= attackRange * 1.5) { // Extended range for special attack
            std::cout << "Special attack hit a monster at distance " << distance << "!" << std::endl;
            // Apply enhanced damage logic here
        }
    }
}

double DragonBlade::GetDamage() {
    return 20.0 * damageMultiplier; // Example base damage
}

void DragonBlade::Collision(GameObject* gameObject) {
    std::cout << "DragonBlade collided with a game object!" << std::endl;
    // Handle collision logic here
}

void DragonBlade::setOffset(double x, double y) {
    offset = sf::Vector2f(x, y);
}

void DragonBlade::setPlayerPosition(sf::Vector2f position) {
    playerPosition = position; // Assuming `Vec` is used for `playerPosition`
}

DragonBlade::~DragonBlade() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}
