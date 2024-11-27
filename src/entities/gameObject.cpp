#include "gameObject.h"

GameObject::GameObject() : position(0, 0), active(true) {
    position = Vec(0, 0);
}

Vec GameObject::GetPosition() const {
    return position;
}

void GameObject::SetPosition(const Vec& position) {
    this->position = position;
}

void GameObject::Translate(const Vec& delta) {
    position.x += delta.x;
    position.y += delta.y;
}

bool GameObject::IsActive() const {
    return active;
}

void GameObject::SetActive(bool active) {
    this->active = active;
}

void GameObject::Collision(GameObject* other) {
    return;
}

// void GameObject::Debug() const {
//     std::cout << "Position: (" << position.x << ", " << position.y << "), Active: " << active << "\n";
// }
