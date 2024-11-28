#include "goblinGiant.h"
#include <iostream>

GoblinGiant::GoblinGiant(double level)
    : Monster(level, false) { // Passes level and isMeleeAttackMonster = false to the base class
    LoadResources();
    animationManager.setAnimation("idle_right");  // Default animation
}

void GoblinGiant::Update(float deltaTime) {
    animationManager.update(deltaTime); 
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
    
}

void GoblinGiant::InitializeWeapon() {
    return ;
}

void GoblinGiant::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    

    window.draw(sprite);  
    
}

void GoblinGiant::SetPosition(const Vec& position) {
    sf::Vector2f web_position(position.x, position.y);
    animationManager.getCurrentSprite().setPosition(position.x, position.y);
}