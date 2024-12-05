#include "hitBox.h"
#include <cmath>

HitBox::HitBox(Point& authorPoint)
    : authorPoint(authorPoint), halfWidth(0), halfHeight(0),
      isCollisionInThisFrame(false) {
    hitboxRect.setFillColor(sf::Color::Transparent);
    hitboxRect.setOutlineThickness(2);
}

void HitBox::SetWidth(double width) {
    this->halfWidth = width / 2;
    hitboxRect.setSize(sf::Vector2f(width, hitboxRect.getSize().y));
}

void HitBox::SetHeight(double height) {
    this->halfHeight = height / 2;
    hitboxRect.setSize(sf::Vector2f(hitboxRect.getSize().x, height));
}

double HitBox::GetHalfWidth() {
    return halfWidth;
}

double HitBox::GetHalfHeight() {
    return halfHeight;
}

bool HitBox::IsCollision(HitBox* otherHitBox) {
    double x1Min = authorPoint.GetX() - halfWidth;
    double x1Max = authorPoint.GetX() + halfWidth; 
    double y1Min = authorPoint.GetY() - halfHeight;
    double y1Max = authorPoint.GetY() + halfHeight;  


    double x2Min = otherHitBox->authorPoint.GetX() - otherHitBox->GetHalfWidth();
    double x2Max = otherHitBox->authorPoint.GetX() + otherHitBox->GetHalfWidth();
    double y2Min = otherHitBox->authorPoint.GetY() - otherHitBox->GetHalfHeight();
    double y2Max = otherHitBox->authorPoint.GetY() + otherHitBox->GetHalfHeight();


    if (x1Max <= x2Min || x1Min >= x2Max) {
        return false; 
    }

    if (y1Max <= y2Min || y1Min >= y2Max) {
        return false;
    }

    
    isCollisionInThisFrame = true;
    otherHitBox->isCollisionInThisFrame = true;
    return true;
}






void HitBox::Render(sf::RenderWindow& window) {
    hitboxRect.setPosition(authorPoint.GetX() - halfWidth,
                           authorPoint.GetY() - halfHeight);

    hitboxRect.setOutlineColor(
        isCollisionInThisFrame ? sf::Color(235, 16, 0) : sf::Color(8, 249, 24));

    window.draw(hitboxRect);
}

Point HitBox::GetPosition() {
    return authorPoint;
}

void HitBox::SetPosition(const Point& newPoint) {
    authorPoint = newPoint; 
}
