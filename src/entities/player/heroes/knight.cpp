#include "knight.h"

// Constructor
Knight::Knight() : Player() {
    loadKnightAnimations();
    animationManager.setAnimation("idle_right");
}

void Knight::Update(float deltaTime) {
    animationManager.update(deltaTime);
}

// // Render method (overridden)
// void Knight::Render(sf::RenderWindow& window) {
//     Player::Render(window);
// }

// Method to load knight-specific animations
void Knight::loadKnightAnimations() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add it to the manager

    // Idle animation (flip)
    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_4.bmp"
    };
    leftStandAnimation.loadAnimation(framePaths2);  // Load the flip idle animation
    animationManager.addAnimation("idle_left", leftStandAnimation);  // Add to manager

    // Running animation
    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/4.bmp"
    };
    rightRunAnimation.loadAnimation(framePaths3);  // Load the running animation
    animationManager.addAnimation("run_right", rightRunAnimation);  // Add to manager

    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_4.bmp"
    };
    leftRunAnimation.loadAnimation(framePaths4);  
    animationManager.addAnimation("run_left", leftRunAnimation);  
}

void Knight::Render(sf::RenderWindow& window) {
    window.draw(animationManager.getCurrentSprite());
}


void Knight::runRight() {
    animationManager.setAnimation("run_right");
}

void Knight::runLeft() {
    animationManager.setAnimation("run_left");
}

void Knight::standRight() {
    animationManager.setAnimation("idle_right");
}

void Knight::standLeft() {
    animationManager.setAnimation("idle_left");
}
void Knight::Attack() {

}