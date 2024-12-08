#pragma once
#include <SFML/Graphics.hpp>
#include "../../utils/point.h"
#include "../../utils/hitBox.h"
#include "../../entities/invinsibleObject.h"

class Wall: public InvisibleObject{
public:
    Wall(Point start, Point end);
    void Initialize() override;
    void Draw(sf::RenderWindow& window);
    void Collision(GameObject* gameObject) override;
    bool CheckCollision(GameObject* gameObject);
private:
    sf::RectangleShape wallShape;
    HitBox hitbox;
};
