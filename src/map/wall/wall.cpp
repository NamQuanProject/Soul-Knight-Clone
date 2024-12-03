#include "wall.h"
#include "../../entities/player/player.h"
#include <iostream>



Wall::Wall(Point start, Point end)
    : hitbox(start) {  // Initialize hitbox with the start point
    // Set up the wall's rectangle shape
    float width = static_cast<float>(end.GetX() - start.GetX());
    float height = static_cast<float>(end.GetY() - start.GetY());

    wallShape.setSize(sf::Vector2f(width, height));
    wallShape.setPosition(static_cast<float>(start.GetX()), static_cast<float>(start.GetY()));

    // Set the hitbox width and height
    wallShape.setFillColor(sf::Color::Green);
    wallShape.setOutlineThickness(2);
    hitbox.SetWidth(width);
    hitbox.SetHeight(height);
    
}



bool Wall::CheckCollision(GameObject* gameObject) {
    if (!gameObject) return false;

    HitBox* objectHitbox = gameObject->GetHitBox();
    if (!objectHitbox) return false;
    
    return hitbox.IsCollision(objectHitbox);
}

// Collision handling (Just turn the wall red)
void Wall::Collision(GameObject* gameObject) {

    if (gameObject == nullptr) return;
    Player* player = dynamic_cast<Player*>(gameObject);
    // Check for a collision with the wall using the CheckCollision method
    if (player) {
        // Check for a collision with the wall using the CheckCollision method
        if (CheckCollision(gameObject)) {
            std::cout << "Collision Detected!" << std::endl;
            wallShape.setFillColor(sf::Color::Red);
        } else {
            wallShape.setFillColor(sf::Color::Green);
        }
    }
}




void Wall::Draw(sf::RenderWindow& window) {
    window.draw(wallShape);
}


