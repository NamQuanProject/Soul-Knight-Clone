#include "horizontalDoor3.h"



void HorizontalDoor3::LoadResources() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/horizontal_3.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager
}

void HorizontalDoor3::Update(float deltaTime) {
    return;
}

void HorizontalDoor3::Render(sf::RenderWindow& window) {
    window.draw(animationManager.getCurrentSprite());
}