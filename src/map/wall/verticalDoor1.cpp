#include "verticalDoor1.h"



void VerticalDoor1::LoadResources() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_1.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager
}

void VerticalDoor1::Update(float deltaTime) {
    return;
}

void VerticalDoor1::Render(sf::RenderWindow& window) {
    window.draw(animationManager.getCurrentSprite());
}