﻿#include "goblinShaman.h"
#include "../../monster.h"
#include "../../../../manager/animationManager.h"
#include "../../../../manager/objectManager.h"
#include "../../../../utils/vec.h"
#include "../../../../entities/projectile/bullet/redCircleBullet.h"
#include "../../../../utils/random.h"
#include <iostream>

GoblinShaman::GoblinShaman(double level)
    : Monster(level, false) { 
    LoadResources();
    animationManager.setAnimation("idle_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    AddTag(Tag::MONSTER);

    hp = 10;

}

void GoblinShaman::Update(float deltaTime) {
    attackTimer += deltaTime; // Increment the attack timer
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
void GoblinShaman::Initialize() {
    LoadResources();
    animationManager.setAnimation("idle_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    AddTag(Tag::MONSTER);
}

void GoblinShaman::LoadResources() {
     Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1); 
    animationManager.addAnimation("idle_right", rightStandAnimation);

    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/idle/flip_4.bmp"
    };
    leftStandAnimation.loadAnimation(framePaths2);  
    animationManager.addAnimation("idle_left", leftStandAnimation);  
    
    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/4.bmp"
    };
    rightRunAnimation.loadAnimation(framePaths3);
    animationManager.addAnimation("run_right", rightRunAnimation);  

    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/run/flip_4.bmp"
    };
    leftRunAnimation.loadAnimation(framePaths4); 
    animationManager.addAnimation("run_left", leftRunAnimation);  


    Animation dead;
    std::vector<std::string> framePaths5 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_shaman/dead.bmp",
        
    };
    dead.loadAnimation(framePaths5);
    animationManager.addAnimation("dead", dead);  
}


void GoblinShaman::Attack() {
    if (!HasTag(Tag::DEAD))
    if (attackTimer >= attackCooldown) {
        if (attack_time_2 <= 0) {
            random_choice = Rand::Instance()->Get(1, 3);
        }
        else {
            random_choice = 2;
        }
        
        if (random_choice == 1) {
            std::cout << "Monster Attack 1" << std::endl;
            
            Bullet* bullet = static_cast<RedCircleBullet*>(
                ProjectilePool::Instance()->Acquire(ProjectileType::RED_CIRCLE_BULLET)
            );
            if (bullet != nullptr) {
                Vec monster_position = position; 
            Vec player_position = ObjectManager::Instance()->GetPlayer()->GetPosition();

            bullet->SetPosition(monster_position);

            Vec direction = player_position - monster_position;

            float magnitude = std::sqrt(direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY());
            if (magnitude != 0) {
                double x = direction.GetX() / magnitude ;
                double y = direction.GetY() / magnitude ;
                direction.SetX(x);
                direction.SetY(y);
            }

            float bullet_speed = 270.0f;
            Vec velocity = Vec(direction.GetX() * bullet_speed, direction.GetY() * bullet_speed);

            bullet->SetSpeed(velocity);

            ObjectManager::Instance()->AddObject(bullet);
            }
            

            attackTimer = 0.0f;
            
        }
        else if (random_choice == 2) {
            std::cout << "Monster attack 2" << std::endl;
            const float radianConversion = 3.14159f / 180.0f;
            int angle = Rand::Instance()->Get(1, 360);
            Bullet* bullet = static_cast<RedCircleBullet*>(
                ProjectilePool::Instance()->Acquire(ProjectileType::RED_CIRCLE_BULLET)
            );



            bullet->SetPosition(position);

            float radianAngle = angle * radianConversion;
            float speedX = 270 * std::cos(radianAngle);
            float speedY = 270 * std::sin(radianAngle);
            Vec speed = Vec(speedX, speedY);

            bullet->SetSpeed(speed);

            ObjectManager::Instance()->AddObject(bullet);

            attackTimer = 490.f;
            attack_time_2 = attack_time_2 - 1;
            std::cout << attack_time_2 << std::endl;
        }        
        else if (random_choice == 3) {
            std::cout << "Monster Attack 3" << std::endl;
            attackTimer = 100.f;
            attack_time_2 = Rand::Instance()->Get(1, 5);
        }
    }
}


void GoblinShaman::AutoMation() {

    if (!HasTag(Tag::DEAD)) {
            // Get the player's position
        Vec playerPos = ObjectManager::Instance()->GetPlayer()->GetPosition();

        // Get the Goblin Giant's current position
        Vec goblinPos = Vec(animationManager.getCurrentSprite().getPosition().x, 
                            animationManager.getCurrentSprite().getPosition().y);

        // Calculate the direction vector from Goblin to Player
        Vec direction = playerPos - goblinPos;


        double distance = std::sqrt(direction.GetX() * direction.GetX() + 
                                    direction.GetY() * direction.GetY());

        if (distance > 0) {
            direction.SetX(direction.GetX() / distance);
            direction.SetY(direction.GetY() / distance);
        }

        // Define the attack range and movement speed
        double attackRange = 50.0;
        double speed = 0.0015;


        if (distance > attackRange) {
            Vec movement = direction * speed;  
            goblinPos = goblinPos + movement;             
            SetPosition(goblinPos);           

            // Update animation based on movement direction
            if (direction.GetX() > 0) {
                animationManager.setAnimation("run_right");
            } else {
                animationManager.setAnimation("run_left");
            }
        } 
        // If within attack range, stop and use idle/attack animation
        else {
            animationManager.setAnimation("idle_right");  // Replace with "attack" if needed
        }

        
        
    }
    
    
}






void GoblinShaman::InitializeWeapon() {
    return ;
}

void GoblinShaman::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    window.draw(sprite);  


    // if (hitbox) {
    //     hitbox->Render(window);
    // }
    
}

void GoblinShaman::SetPosition(Vec& new_position) {
    position = new_position;
    double x = new_position.GetX();
    double y = new_position.GetY();
    sf::Vector2f web_position(x, y);
    animationManager.getCurrentSprite().setPosition(new_position.GetX(), new_position.GetY());



}