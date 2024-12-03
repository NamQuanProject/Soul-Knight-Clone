
#include "hitBox.h"
#include <cmath>

HitBox::HitBox(Point& authorPoint) : authorPoint(authorPoint), halfWidth(0), halfHeight(0),
                                     isCollisionInThisFrame(false) {
}

void HitBox::SetWidth(double width) {
    this->halfWidth = width / 2;
}

void HitBox::SetHeight(double height) {
    this->halfHeight = height / 2;
}

double HitBox::GetHalfWidth() {
    return halfWidth;
}

double HitBox::GetHalfHeight() {
    return halfHeight;
}

bool HitBox::IsCollision(HitBox* otherHitBox) {
    bool XOverLap = false;
    bool YOverLap = false;
    if (abs(this->authorPoint.GetX() - otherHitBox->authorPoint.GetX()) < this->halfWidth + otherHitBox->halfWidth) {
        XOverLap = true;
    }
    if (abs(this->authorPoint.GetY() - otherHitBox->authorPoint.GetY()) < this->halfHeight + otherHitBox->halfHeight) {
        YOverLap = true;
    }
    if (XOverLap && YOverLap) {
        isCollisionInThisFrame = true; // TODO: Test code for HitBox collision visualization
        otherHitBox->isCollisionInThisFrame = true;
        return true;
    }
    else {
        return false;
    }
}


void HitBox::Render(sf::RenderWindow& window) {
    // Calculate screen position of the hitbox
    double screenX = this->authorPoint.GetX();
    double screenY = this->authorPoint.GetY(); 

    // Check if the hitbox is within the screen bounds
    if (screenX > 0 && screenX < 2000 && screenY > 0 && screenY < 2000) {
        sf::RectangleShape hitboxRect(sf::Vector2f(halfWidth * 2, halfHeight * 2));
        hitboxRect.setPosition(screenX - halfWidth, screenY - halfHeight);
        hitboxRect.setFillColor(sf::Color::Transparent);
        hitboxRect.setOutlineThickness(2);
        hitboxRect.setOutlineColor(isCollisionInThisFrame ? sf::Color(235, 16, 0) : sf::Color(8, 249, 24));
        window.draw(hitboxRect);
        isCollisionInThisFrame = false;
    }
}

Point HitBox::GetPosition() {
    return authorPoint;  // Return the position of the author point
}

void HitBox::SetPosition(const Point& newPoint) {
    authorPoint = newPoint;  // Update the position of the hitbox
}