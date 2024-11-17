#include "gameObject.h"


GameObject::GameObject() {
    position = Vec(0, 0); // Default position
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
