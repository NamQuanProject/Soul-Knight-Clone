#include "bullet.h"
#include <iostream>

Bullet::Bullet(double damage, double speed, Vec direction, GameObject* owner)
    : damage(damage), speed(speed), direction(direction), owner(owner) {
    // Initialization of bullet properties
}

void Bullet::Update() {
    // Update the bullet's position based on its speed and direction
    // For example, you can move it in the direction it's pointing at
    
}

void Bullet::Collision(GameObject* gameObject) {
    // Handle collision logic here
    // For example, check if bullet hits an enemy or an obstacle
    
}



