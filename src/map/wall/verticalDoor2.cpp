#include "verticalDoor2.h"



void VerticalDoor2::LoadResources() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_2.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager
}

void VerticalDoor2::Update(float deltaTime) {
    return;
}

void VerticalDoor2::Render(sf::RenderWindow& window) {
    window.draw(animationManager.getCurrentSprite());
}