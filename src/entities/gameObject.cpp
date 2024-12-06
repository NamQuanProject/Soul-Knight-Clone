#include "gameObject.h"

GameObject::GameObject() : position(0.0, 0.0), active(true) {
    position = Vec(0.0, 0.0);
}

Vec GameObject::GetPosition() {
    return position;
}

void GameObject::SetPosition(Vec& position) {
    this->position = position;
}

void GameObject::Translate(const Vec& delta) {
    return ;
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
HitBox* GameObject::GetHitBox() {
    return hitbox;
}


void GameObject::AddTag(Tag tag) {
    tags[static_cast<int>(tag)] = true;
}

void GameObject::RemoveTag(Tag tag) {
    tags[static_cast<int>(tag)] = false;
}

bool GameObject::HasTag(Tag tag) {
    return tags[static_cast<int>(tag)];
}


// void GameObject::Debug() const {
//     std::cout << "Position: (" << position.x << ", " << position.y << "), Active: " << active << "\n";
// }
