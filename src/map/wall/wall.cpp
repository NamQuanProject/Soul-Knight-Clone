#include "wall.h"

Wall::Wall(Point start, Point end)
    : hitbox(start) {  // Initialize hitbox with the start point
    // Set up the wall's rectangle shape
    float width = static_cast<float>(end.GetX() - start.GetX());
    float height = static_cast<float>(end.GetY() - start.GetY());

    wallShape.setSize(sf::Vector2f(width, height));
    wallShape.setPosition(static_cast<float>(start.GetX()), static_cast<float>(start.GetY()));

    // Set the hitbox width and height
    hitbox.SetWidth(width);
    hitbox.SetHeight(height);
}

void Wall::Draw(sf::RenderWindow& window) {
    window.draw(wallShape);
}

HitBox* Wall::GetHitbox() {
    return &hitbox;  // Return the hitbox for collision checks
}
