#pragma once
#include <SFML/Graphics.hpp>
#include "../../utils/point.h"
#include "../../utils/hitBox.h"

class Wall {
public:
    Wall(Point start, Point end);
    void Draw(sf::RenderWindow& window);
    HitBox* GetHitbox();  // Return a pointer to the hitbox

private:
    sf::RectangleShape wallShape;
    HitBox hitbox;
};
