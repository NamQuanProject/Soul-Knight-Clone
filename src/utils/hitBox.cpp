#include "hitBox.h"
#include <cmath>

HitBox::HitBox(Point& authorPoint)
    : authorPoint(authorPoint), halfWidth(0), halfHeight(0),
      isCollisionInThisFrame(false) {
    hitboxRect.setFillColor(sf::Color::Transparent); // Default to transparent
    hitboxRect.setOutlineThickness(2); // Default outline thickness
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
    // Get the bounds of the current hitbox (top-left)
    double x1Min = authorPoint.GetX();
    double x1Max = authorPoint.GetX() + 2 * halfWidth;  // Full width from top-left
    double y1Min = authorPoint.GetY();
    double y1Max = authorPoint.GetY() + 2 * halfHeight;  // Full height from top-left

    // Get the bounds of the other hitbox (centered position)
    // Adjust the other hitbox so that its position is its top-left corner
    double x2Min = otherHitBox->authorPoint.GetX() - otherHitBox->GetHalfWidth();
    double x2Max = otherHitBox->authorPoint.GetX() + otherHitBox->GetHalfWidth();
    double y2Min = otherHitBox->authorPoint.GetY() - otherHitBox->GetHalfHeight();
    double y2Max = otherHitBox->authorPoint.GetY() + otherHitBox->GetHalfHeight();

    // Check if there is no horizontal overlap (boxes are separated on x-axis)
    if (x1Max <= x2Min || x1Min >= x2Max) {
        return false; // No horizontal overlap, so no collision
    }

    // Check if there is no vertical overlap (boxes are separated on y-axis)
    if (y1Max <= y2Min || y1Min >= y2Max) {
        return false; // No vertical overlap, so no collision
    }

    // If there is overlap in both x and y directions, it is a collision
    isCollisionInThisFrame = true;
    otherHitBox->isCollisionInThisFrame = true;
    return true;  // Collision detected
}





void HitBox::Render(sf::RenderWindow& window) {
    // Update hitbox position and dimensions
    hitboxRect.setPosition(authorPoint.GetX() - halfWidth,
                           authorPoint.GetY() - halfHeight);

    // Set outline color based on collision state
    hitboxRect.setOutlineColor(
        isCollisionInThisFrame ? sf::Color(235, 16, 0) : sf::Color(8, 249, 24));

    // Draw the hitbox
    window.draw(hitboxRect);
}

Point HitBox::GetPosition() {
    return authorPoint;
}

void HitBox::SetPosition(const Point& newPoint) {
    authorPoint = newPoint; // Update the position of the hitbox
}
