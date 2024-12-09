#include "goblinGiant.h"
#include <iostream>

GoblinGiant::GoblinGiant(double level)
    : Monster(level, false) {
    LoadResources();
    animationManager.setAnimation("idle_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    AddTag(Tag::MONSTER);
}

void GoblinGiant::Initialize() {
    LoadResources();
    animationManager.setAnimation("idle_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    AddTag(Tag::MONSTER);
}


GoblinGiant::~GoblinGiant() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
    
}

void GoblinGiant::Update(float deltaTime) {
    
    animationManager.update(deltaTime); 
    if (HasTag(Tag::DEAD)) {
        animationManager.setAnimation("dead");
    }
    sf::Vector2f knightPosition = animationManager.getCurrentSprite().getPosition();
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::FloatRect bounds = sprite.getLocalBounds();

    hitbox->SetWidth(bounds.width - 9.f);
    hitbox->SetHeight(bounds.height - 1.f);

    // Update the hitbox position to match the sprite
    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));
    
    AutoMation();
}

void GoblinGiant::LoadResources() {
     Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1); 
    animationManager.addAnimation("idle_right", rightStandAnimation);

    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/idle/flip_4.bmp"
    };
    leftStandAnimation.loadAnimation(framePaths2);  
    animationManager.addAnimation("idle_left", leftStandAnimation);  
    
    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/4.bmp"
    };
    rightRunAnimation.loadAnimation(framePaths3);
    animationManager.addAnimation("run_right", rightRunAnimation);  

    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_4.bmp"
    };
    leftRunAnimation.loadAnimation(framePaths4); 
    animationManager.addAnimation("run_left", leftRunAnimation);  

    Animation dead;
    std::vector<std::string> framePaths5 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/dead.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_2.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_3.bmp",
        // "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/monster/floor_1/goblin_giant/run/flip_4.bmp"
    };
    dead.loadAnimation(framePaths5);
    animationManager.addAnimation("dead", dead);  
}


void GoblinGiant::AutoMation() {
    if (!HasTag(Tag::DEAD)) {
            // Get the player's position
        Vec playerPos = ObjectManager::Instance()->GetPlayer()->GetPosition();

        // Get the Goblin Giant's current position
        Vec goblinPos = Vec(animationManager.getCurrentSprite().getPosition().x, 
                            animationManager.getCurrentSprite().getPosition().y);

        // Calculate the direction vector from Goblin to Player
        Vec direction = playerPos - goblinPos;

        // Calculate the distance between the Goblin and the Player
        double distance = std::sqrt(direction.GetX() * direction.GetX() + 
                                    direction.GetY() * direction.GetY());

        // Check if the distance is greater than zero to avoid division by zero
        if (distance > 0) {
            // Normalize the direction vector manually by dividing each component by the distance
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






void GoblinGiant::InitializeWeapon() {
    return ;
}

void GoblinGiant::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    window.draw(sprite);  


    // if (hitbox) {
    //     hitbox->Render(window);
    // }
    
}

void GoblinGiant::SetPosition(Vec& position) {
    double x = position.GetX();
    double y = position.GetY();
    sf::Vector2f web_position(x, y);
    animationManager.getCurrentSprite().setPosition(position.GetX(), position.GetY());
}