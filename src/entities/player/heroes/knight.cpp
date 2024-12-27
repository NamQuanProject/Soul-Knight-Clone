#include "knight.h"
#include <iostream>


Knight::Knight() : Player() {
    loadKnightAnimations();
    weapon1 = new BadPistol();
    weapon2 = new DragonBlade();  // Initialize weapon2 to be the same as weapon1
    
    animationManager.setAnimation("idle_right"); 
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/skill.bmp")) {
        std::cerr << "Failed to load skill effect texture!" << std::endl;
    }
    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    
    
    skillEffectTexture.loadFromImage(image);
    // Configure the skill effect sprite
    skillEffectSprite.setTexture(skillEffectTexture);
    skillEffectSprite.setOrigin(skillEffectTexture.getSize().x / 2, skillEffectTexture.getSize().y / 2);

    Point author = Point(position.x, position.y);
    Vec weapon_pos = Vec(position.x, position.y);
    hitbox = new HitBox(author); 
    AddTag(Tag::PLAYER);
    weapon1->SetPosition(weapon_pos);
    weapon2->SetPosition(weapon_pos);  // Set the position for weapon2 as well
    
    maxHp = 7;
    hp = maxHp;
    maxMana = 200;
    mana = maxMana;
    maxShield = 6;
    shield = maxShield;
    
}

void Knight::Initialize() {
    // loadKnightAnimations();
    // weapon1 = new BadPistol();
    
    // animationManager.setAnimation("idle_right"); 
    // animationManager.setOrigin();
    // sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    // Point author = Point(position.x, position.y);
    // Vec weapon_pos = Vec(position.x, position.y);
    // hitbox = new HitBox(author); 
    // AddTag(Tag::PLAYER);
    // weapon1->SetPosition(weapon_pos);
}

void Knight::UseSkill() {
    if (mana >= 50) {
        std::cout << "Knight uses skill!" << std::endl;
        isSkillActive = true;
        skillTimer = 500.f; // Set the skill duration to 5 seconds
        mana -= 50; // Deduct mana cost
        std::cout << "Mana: " << mana << std::endl;
    } else {
        std::cout << "Not enough mana to use skill!" << std::endl;
    }
}

Knight::~Knight() {
    if (weapon1) {
        delete weapon1;
        weapon1 = nullptr;
    }
    if (weapon2) {
        delete weapon2;
        weapon2 = nullptr;
    }
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
    
}

void Knight::Update(float deltaTime) {
    if (hp <= 0) {
        animationManager.setAnimation("dead");
        animationManager.update(deltaTime);
        return;
    }
    if (isSkillActive) {
        skillTimer -= deltaTime;

        // Keep the skill effect sprite centered on the player
        skillEffectSprite.setPosition(position.GetX(), position.GetY());

        if (skillTimer <= 0) {
            isSkillActive = false; // Deactivate the skill
            skillTimer = 0;
            std::cout << "Skill ended!" << std::endl;
        }
    }
    Vec currentPos = GetPosition();
    Vec new_pos = currentPos + speed;
    SetPosition(new_pos);

    // Handle shield recovery
    shieldTime -= deltaTime;
    if (shieldTime <= 0.0f && shield < maxShield) {
        shield += 1; // Increment shield by 1
        if (shield > maxShield) {
            shield = maxShield; // Cap shield to maxShield
        }
        shieldTime = 1500.f; // Reset shield recovery timer
    }

    if (isHit) {
        hitTimer -= deltaTime;
        if (hitTimer <= 0.0f) {
            isHit = false;
            animationManager.getCurrentSprite().setColor(sf::Color::White); 
        }
    }
    if (attackCooldown > 0.f) {
        attackCooldown -= deltaTime; // Decrease the cooldown timer
    }

    animationManager.update(deltaTime);
    
    if (face == Knight::RIGHT) {
        weapon1->setOffset(0, -4);
        weapon2->setOffset(3, 2);  // Ensure both weapons have the correct offset
    } else if (face == Knight::LEFT) {
        weapon1->setOffset(-25, -4);
        weapon2->setOffset(-23, 2);  // Ensure both weapons have the correct offset
    }

    // Update the active weapon
    if (usingWeapon1) {
        weapon1->Update(deltaTime);
    } else {
        weapon2->Update(deltaTime);
    }

    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::FloatRect bounds = sprite.getLocalBounds();

    hitbox->SetWidth(bounds.width - 17.f);
    hitbox->SetHeight(bounds.height - 1.f);

    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));
}




void Knight::loadKnightAnimations() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager

    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/idle/flip_4.bmp"
    };
    leftStandAnimation.loadAnimation(framePaths2);  
    animationManager.addAnimation("idle_left", leftStandAnimation);  
    
    // Right Running Animation
    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/4.bmp"
    };
    rightRunAnimation.loadAnimation(framePaths3);  // Load the running animation
    animationManager.addAnimation("run_right", rightRunAnimation);  // Add to animation manager

    // Left Running Animation (flipped)
    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/run/flip_4.bmp"
    };
    leftRunAnimation.loadAnimation(framePaths4);  // Load the flipped running animation
    animationManager.addAnimation("run_left", leftRunAnimation);  // Add to animation manager
    Animation deadAnimation;
    std::vector<std::string> framePaths5 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/dead/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/dead/2.bmp"
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/dead/3.bmp"
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/dragonwarrior/dead/4.bmp"
    };
    deadAnimation.loadAnimation(framePaths5);  // Load the flipped running animation
    animationManager.addAnimation("dead", deadAnimation);  // Add to animation manager
}

// Render the knight (called every frame)
void Knight::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    
    // Render the active weapon
    if (usingWeapon1) {
        weapon1->Render(window);
    } else {
        weapon2->Render(window);
    }
    if (isSkillActive) {
        window.draw(skillEffectSprite);
    }
    window.draw(sprite);

}

void Knight::SwitchWeapon() {
    usingWeapon1 = !usingWeapon1;  // Toggle between weapon1 and weapon2
}

void Knight::Attack() {
    if (attackCooldown <= 0.f) {  // Only attack if cooldown is finished
        if (isSkillActive) {
            std::vector<Vec> all_position = ObjectManager::Instance()->getAllCurrentMonsterPosition();

            if (all_position.empty()) {
                if (CheckFace() == Knight::RIGHT) {
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
            } 
            else {
                Vec playerPosition = position;
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
                bullet->SetPosition(position);
                bullet->SetSpeed(direction * 360);
                bullet->UpdateTag(bullet);
                
                ObjectManager::Instance()->AddObject(bullet);
            }
        }
        else {
            if (usingWeapon1) {
            weapon1->Attack();  // Use weapon1
            } else {
                weapon2->Attack();  // Use weapon2
            }
            mana -= 1;
            if (mana <= 0) {
                mana = 0;
            }
            attackCooldown = 20.f;  // Reset the cooldown timer
        }
    }
}



void Knight::runRight() {
    state = RUN;
    face = RIGHT;
    animationManager.setAnimation("run_right"); 
}

void Knight::runLeft() {
    state = RUN;
    face = LEFT;
    animationManager.setAnimation("run_left");  
}

void Knight::standRight() {
    animationManager.setAnimation("idle_right");  
}
 
void Knight::standLeft() {
    animationManager.setAnimation("idle_left"); 
}

void Knight::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::WALL) || (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD))) {
        Vec current = GetPosition();
        current = current - speed;
        SetPosition(current);
    }

    if (gameObject->HasTag(Tag::MONSTER_ATTACK)) {
        // Damage the shield first
        if (shield > 0) {
            shield -= 1;
            if (shield < 0) {
                shield = 0; // Ensure shield doesn't go negative
            }
        } else {
            // If shield is zero, reduce health
            hp -= 1;
            if (hp <= 0) {
                hp = 0; // Ensure health doesn't go negative
            }
        }

        // Trigger hit animation and effects
        isHit = true;
        hitTimer = hitDuration;
        animationManager.getCurrentSprite().setColor(sf::Color::Red);
    }
}

void Knight::SetBeforePosition(Vec a) {
    
}

void Knight::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    sf::Vector2f web_position(x, y);
    
    if (weapon1) {
        weapon1->setPlayerPosition(web_position); 
    } else {
        std::cout << "Weapon is not initialized!" << std::endl;
    }
    
    // Set the knight's animation sprite position
    animationManager.getCurrentSprite().setPosition(x, y);
}
