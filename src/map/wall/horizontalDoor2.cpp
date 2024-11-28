#include "horizontalDoor2.h"



void HorizontalDoor2::LoadResources() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_2.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager
}

void HorizontalDoor2::Update(float deltaTime) {
    return;
}

void HorizontalDoor2::Render(sf::RenderWindow& window) {
    window.draw(animationManager.getCurrentSprite());
}