#include "goblinGiant.h"
#include <iostream>

GoblinGiant::GoblinGiant(double level)
    : Monster(level, false) { // Passes level and isMeleeAttackMonster = false to the base class
    LoadResources();
    animationManager.setAnimation("idle_right");  // Default animation
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    
    hitbox = new HitBox(author); 
    tag = Tag::MONSTER;
}


GoblinGiant::~GoblinGiant() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
    
}

void GoblinGiant::Update(float deltaTime) {
    animationManager.update(deltaTime); 

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
}


void GoblinGiant::AutoMation() {
    // static sf::Vector2f targetPosition;  // Current target position
    // static bool hasTarget = false;       // Whether a target is set
    // static float speed = 2.f;            // Reduced movement speed in pixels per second
    // static float tolerance = 5.f;        // Tolerance to consider the target reached

    // // Initialize random seed (one-time setup)
    // static bool seeded = false;
    // if (!seeded) {
    //     std::srand(static_cast<unsigned>(std::time(nullptr)));
    //     seeded = true;
    // }

    // // Define movement boundaries
    // float minX = 0.f, maxX = 1024.f;  
    // float minY = 0.f, maxY = 1024.f; 

    // sf::Vector2f currentPosition = animationManager.getCurrentSprite().getPosition();

    // // Check if the sprite hits a wall and reverse direction
    // if (currentPosition.x <= minX || currentPosition.x >= maxX) {
    //     targetPosition.x = currentPosition.x <= minX ? maxX : minX;  // Reverse direction
    //     hasTarget = true;
    //     animationManager.setAnimation(currentPosition.x <= minX ? "run_right" : "run_left");
    // }
    // if (currentPosition.y <= minY || currentPosition.y >= maxY) {
    //     targetPosition.y = currentPosition.y <= minY ? maxY : minY;  // Reverse direction
    //     hasTarget = true;
    // }

    // // If no target or target reached, set a new random target
    // if (!hasTarget || 
    //     std::abs(currentPosition.x - targetPosition.x) < tolerance &&
    //     std::abs(currentPosition.y - targetPosition.y) < tolerance) {

    //     // Generate new target within bounds
    //     targetPosition.x = minX + static_cast<float>(std::rand() % static_cast<int>(maxX - minX + 1));
    //     targetPosition.y = minY + static_cast<float>(std::rand() % static_cast<int>(maxY - minY + 1));
    //     hasTarget = true;

    //     // Change animation based on target direction
    //     if (targetPosition.x > currentPosition.x) {
    //         animationManager.setAnimation("run_right");
    //     } else {
    //         animationManager.setAnimation("run_left");
    //     }
    // }

    // // Move towards the target
    // sf::Vector2f direction = targetPosition - currentPosition;
    // float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // if (length > 0.f) {
    //     sf::Vector2f normalizedDirection = direction / length;
    //     currentPosition += normalizedDirection * speed * 0.016f;  // Assuming 60 FPS
    // }

    // // Update sprite position
    // animationManager.getCurrentSprite().setPosition(currentPosition);
}



void GoblinGiant::InitializeWeapon() {
    return ;
}

void GoblinGiant::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    window.draw(sprite);  


    if (hitbox) {
        hitbox->Render(window); // Render the hitbox
    }
    
}

void GoblinGiant::SetPosition(Vec& position) {
    double x = position.GetX();
    double y = position.GetY();
    sf::Vector2f web_position(x, y);
    animationManager.getCurrentSprite().setPosition(position.GetX(), position.GetY());
}