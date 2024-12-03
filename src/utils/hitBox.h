#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"

class HitBox {
public:
    HitBox(Point& authorPoint);
    void SetWidth(double width);
    void SetHeight(double height);
    double GetHalfHeight();
    double GetHalfWidth();
    bool IsCollision(HitBox* otherHitBox);
    void Render(sf::RenderWindow& window); 
    Point GetPosition();
    void SetPosition(const Point& newPoint);
private:
    Point& authorPoint;
    double halfWidth;
    double halfHeight;
    bool isCollisionInThisFrame;
};