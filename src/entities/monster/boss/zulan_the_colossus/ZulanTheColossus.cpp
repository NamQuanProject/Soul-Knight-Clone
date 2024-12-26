#include "ZulanTheColossus.h"
#include "../../monster.h"
#include "../../../../manager/animationManager.h"
#include "../../../../manager/objectManager.h"
#include "../../../../utils/vec.h"
#include "../../../../entities/projectile/bullet/redRectangleBullet.h"
#include "../../../../entities/projectile/bullet/spearWave.h"
#include "../../../../entities/projectile/bullet/redCircleBullet.h"
#include "../../../../entities/projectile/bullet/redConicalBullet.h"
#include "../../../../entities/projectile/bullet/superMoonBullet.h"
#include "../../../../utils/random.h"
#include <iostream>

ZulanTheColossus::ZulanTheColossus(double level)
    : Monster(level, false), attackTimer(0), attack_time_2(0), random_choice(0) {
    LoadResources();
    animationManager.setAnimation("normal_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    AddTag(Tag::MONSTER);

    hp = 1000;
}

void ZulanTheColossus::Initialize() {
    LoadResources();
    animationManager.setAnimation("normal_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    AddTag(Tag::MONSTER);
}

ZulanTheColossus::~ZulanTheColossus() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}

void ZulanTheColossus::Update(float deltaTime) {
    attackTimer += deltaTime; 
    animationManager.update(deltaTime);

    if (hp == 0) {
        AddTag(Tag::DEAD);
        animationManager.setAnimation("dead");
    }

    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::FloatRect bounds = sprite.getLocalBounds();

    hitbox->SetWidth(bounds.width - 9.f);
    hitbox->SetHeight(bounds.height - 1.f);

    // Update the hitbox position to match the sprite
    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));

    Attack();
    AutoMation();
}

void ZulanTheColossus::LoadResources() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus/normal/1.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus/normal/2.bmp",
    };
    rightStandAnimation.loadAnimation(framePaths1); 
    animationManager.addAnimation("normal_right", rightStandAnimation);

    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus/normal/flip_1.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus/normal/flip_2.bmp",
    };
    leftStandAnimation.loadAnimation(framePaths2);  
    animationManager.addAnimation("normal_left", leftStandAnimation);  

    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus//angry/1.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus//angry/2.bmp",
    };
    rightRunAnimation.loadAnimation(framePaths3);
    animationManager.addAnimation("angry_right", rightRunAnimation);  

    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus//angry/flip_1.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus//angry/flip_2.bmp",
    };
    leftRunAnimation.loadAnimation(framePaths4); 
    animationManager.addAnimation("angry_left", leftRunAnimation);  

    Animation dead;
    std::vector<std::string> framePaths5 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/boss/zulan_the_colossus/zulan_the_colossus//dead.bmp",
    };
    dead.loadAnimation(framePaths5);
    animationManager.addAnimation("dead", dead);  
}
void ZulanTheColossus::Attack() {
    if (!HasTag(Tag::DEAD) && attackTimer >= attackCooldown) {
        if (attack_time_2 <= 0) {
            random_choice = Rand::Instance()->Get(1, 5);  
        } else {
            random_choice = Rand::Instance()->Get(1, 5);
        }

        std::vector<ProjectileType> bulletTypes = {
            ProjectileType::RED_RECTANGLE_BULLET,
            ProjectileType::SPEAR_WAVE,
            ProjectileType::RED_CIRCLE_BULLET,
            ProjectileType::RED_CONICAL_BULLET,
        };

        if (random_choice == 1) {
            std::cout << "Monster Attack 1: Single Target (Random Bullet)" << std::endl;

            // Attack 1: Single random bullet towards the player
            ProjectileType chosenType = bulletTypes[Rand::Instance()->Get(0, bulletTypes.size() - 1)];
            Bullet* bullet = static_cast<Bullet*>(
                ProjectilePool::Instance()->Acquire(chosenType)
            );
            if (bullet != nullptr) {
                Vec monster_position = position;
                Vec player_position = ObjectManager::Instance()->GetPlayer()->GetPosition();

                bullet->SetPosition(monster_position);

                Vec direction = player_position - monster_position;
                float magnitude = std::sqrt(direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY());
                if (magnitude != 0) {
                    direction.SetX(direction.GetX() / magnitude);
                    direction.SetY(direction.GetY() / magnitude);
                }

                float bullet_speed;
                if (chosenType == ProjectileType::RED_CONICAL_BULLET) {
                    bullet_speed = Rand::Instance()->Get(50.0f, 100.0f);  // Super slow speed for RED_CONICAL_BULLET
                } else {
                    bullet_speed = Rand::Instance()->Get(200.0f, 350.0f);  // Standard speed range for other types
                }

                // Calculate velocity
                Vec velocity = Vec(direction.GetX() * bullet_speed, direction.GetY() * bullet_speed);
                bullet->SetSpeed(velocity);

                bullet->SetDamage(30);  // Standardized damage for simplicity

                ObjectManager::Instance()->AddObject(bullet);
            }

            attackTimer = 0.0f;
        } else if (random_choice == 2) {
            std::cout << "Monster Attack 2: Circular Barrage (Random Bullets)" << std::endl;

            // Attack 2: Circular barrage of random bullets
            const float radianConversion = 3.14159f / 180.0f;
            for (int i = 0; i < 24; ++i) {  // Increased number of bullets
                ProjectileType chosenType = bulletTypes[Rand::Instance()->Get(0, bulletTypes.size() - 1)];
                Bullet* bullet = static_cast<Bullet*>(
                    ProjectilePool::Instance()->Acquire(chosenType)
                );

                if (bullet != nullptr) {
                    bullet->SetPosition(position);
                    
                    float angle = i * 15; 
                    float radianAngle = angle * radianConversion;
                    float speedX = Rand::Instance()->Get(200.0f, 300.0f) * std::cos(radianAngle);  // Randomized speed
                    float speedY = Rand::Instance()->Get(200.0f, 300.0f) * std::sin(radianAngle);
                    Vec speed = Vec(speedX, speedY);

                    bullet->SetSpeed(speed);

                    bullet->SetDamage(20);  // Lower damage for barrage

                    ObjectManager::Instance()->AddObject(bullet);
                }
            }

            attackTimer = 300.f;
            attack_time_2 -= 1;
            std::cout << attack_time_2 << std::endl;
        } else if (random_choice == 3) {
            std::cout << "Monster Attack 3: Homing Missile (Random Bullet)" << std::endl;

            // Attack 3: Homing missile with random bullet type
            ProjectileType chosenType = bulletTypes[Rand::Instance()->Get(0, bulletTypes.size() - 1)];
            Bullet* bullet = static_cast<Bullet*>(
                ProjectilePool::Instance()->Acquire(chosenType)
            );
            if (bullet != nullptr) {
                Vec monster_position = position;
                Vec player_position = ObjectManager::Instance()->GetPlayer()->GetPosition();

                bullet->SetPosition(monster_position);

                Vec direction = player_position - monster_position;
                float magnitude = std::sqrt(direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY());
                if (magnitude != 0) {
                    direction.SetX(direction.GetX() / magnitude);
                    direction.SetY(direction.GetY() / magnitude);
                }

                float bullet_speed = Rand::Instance()->Get(250.0f, 300.0f);  
                Vec velocity = Vec(direction.GetX() * bullet_speed, direction.GetY() * bullet_speed);
                bullet->SetSpeed(velocity);

                bullet->SetDamage(40); 

                ObjectManager::Instance()->AddObject(bullet);
            }

            attackTimer = 100.f;
            attack_time_2 = Rand::Instance()->Get(1, 5);
        } else if (random_choice == 4) {
            std::cout << "Monster Attack 4: Explosive Bullet (Random Bullet)" << std::endl;

            // Attack 4: Explosive bullet with random type
            ProjectileType chosenType = bulletTypes[Rand::Instance()->Get(0, bulletTypes.size() - 1)];
            Bullet* bullet = static_cast<Bullet*>(
                ProjectilePool::Instance()->Acquire(chosenType)
            );
            if (bullet != nullptr) {
                Vec monster_position = position;
                bullet->SetPosition(monster_position);

                float bullet_speed = Rand::Instance()->Get(250.0f, 400.0f);  // Randomized speed
                Vec direction = Vec(1, 0);  // Shoot straight for simplicity
                bullet->SetSpeed(direction * bullet_speed);

                bullet->SetDamage(70);  // Higher damage for explosive bullet

                ObjectManager::Instance()->AddObject(bullet);
            }

            attackTimer = 200.f;
        } else if (random_choice == 5) {
            std::cout << "Monster Attack 5: Ground Slam (Randomized Effects)" << std::endl;

            // Ground slam with random effects
            std::cout << "Ground slam attack: Creating shockwaves!" << std::endl;

            attackTimer = 400.f;
        }
    }
}


void ZulanTheColossus::AutoMation() {
    if (!HasTag(Tag::DEAD)) {
        Vec playerPos = ObjectManager::Instance()->GetPlayer()->GetPosition();
        Vec goblinPos = Vec(animationManager.getCurrentSprite().getPosition().x, 
                            animationManager.getCurrentSprite().getPosition().y);

        Vec direction = playerPos - goblinPos;
        double distance = std::sqrt(direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY());

        if (distance > 0) {
            direction.SetX(direction.GetX() / distance);
            direction.SetY(direction.GetY() / distance);
        }

        double attackRange = 50.0;
        double speed = 0.0015;

        if (distance > attackRange) {
            Vec movement = direction * speed;  
            goblinPos = goblinPos + movement;             
            SetPosition(goblinPos);           

            if (direction.GetX() > 0) {
                animationManager.setAnimation("angry_right");
            } else {
                animationManager.setAnimation("angry_left");
            }
        } else {
            animationManager.setAnimation("normal_right");  
        }
    }
}

void ZulanTheColossus::InitializeWeapon() {
    return;
}

void ZulanTheColossus::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    window.draw(sprite);  
}

void ZulanTheColossus::SetPosition(Vec& new_position) {
    position = new_position;
    double x = new_position.GetX();
    double y = new_position.GetY();
    sf::Vector2f web_position(x, y);
    animationManager.getCurrentSprite().setPosition(new_position.GetX(), new_position.GetY());
}
