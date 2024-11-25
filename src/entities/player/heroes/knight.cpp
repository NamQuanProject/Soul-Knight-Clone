#include "knight.h"
#include <iostream>

// Constructor
Knight::Knight() : Player() {
    loadKnightAnimations();
    weapon1 = new BadPistol();
    animationManager.setAnimation("idle_right");  // Default animation
    
    
}
Knight::~Knight() {
    // Clean up dynamically allocated weapon
    if (weapon1) {
        delete weapon1;
        weapon1 = nullptr;
    }
}

// Update the knight animation
void Knight::Update(float deltaTime) {
    animationManager.update(deltaTime);  // Update the current animation
}

void Knight::loadKnightAnimations() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager

    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_4.bmp"
    };
    leftStandAnimation.loadAnimation(framePaths2);  
    animationManager.addAnimation("idle_left", leftStandAnimation);  
    
    // Right Running Animation
    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/4.bmp"
    };
    rightRunAnimation.loadAnimation(framePaths3);  // Load the running animation
    animationManager.addAnimation("run_right", rightRunAnimation);  // Add to animation manager

    // Left Running Animation (flipped)
    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_4.bmp"
    };
    leftRunAnimation.loadAnimation(framePaths4);  // Load the flipped running animation
    animationManager.addAnimation("run_left", leftRunAnimation);  // Add to animation manager
}

// Render the knight (called every frame)
void Knight::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    
    weapon1->Render(window);

    window.draw(sprite);  // Draw the current animation sprite
}


void Knight::runRight() {
    state = RUN;
    face = RIGHT;
    animationManager.setAnimation("run_right");  // Switch to running right animation
}

void Knight::runLeft() {
    state = RUN;
    face = LEFT;
    animationManager.setAnimation("run_left");  // Switch to running left animation
}

void Knight::standRight() {
    animationManager.setAnimation("idle_right");  // Switch to idle right animation
}
 
void Knight::standLeft() {
    animationManager.setAnimation("idle_left");  // Switch to idle left animation
}

void Knight::SetPosition(const Vec& position) {
    // Convert Vec to sf::Vector2f for weapon position
    sf::Vector2f web_position(position.x, position.y);
    
    // Ensure weapon1 is valid and of the correct type
    if (weapon1) {
        weapon1->setPlayerPosition(web_position);  // Update weapon position
    } else {
        std::cout << "Weapon is not initialized!" << std::endl;
    }
    
    // Set the knight's animation sprite position
    animationManager.getCurrentSprite().setPosition(position.x, position.y);
}
