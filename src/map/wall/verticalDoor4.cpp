#include "verticalDoor4.h"



void VerticalDoor4::LoadResources() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_4.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_4.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_4.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/door/vertical_4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager
}

void VerticalDoor4::Update(float deltaTime) {
    return;
}

void VerticalDoor4::Render(sf::RenderWindow& window) {
    window.draw(animationManager.getCurrentSprite());
}