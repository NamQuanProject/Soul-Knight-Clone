#include "objectManager.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::Instance() {
    if (instance == nullptr) {
        instance = new ObjectManager();
    }
    return instance;
}

ObjectManager::ObjectManager() : screenX(0), screenY(0), player(nullptr) {}

ObjectManager::~ObjectManager() {
    for (auto object : objects) {
        delete object;
    }
    objects.clear();
}


void ObjectManager::Update(float deltaTime) {
    for (auto object : objects) {
        object->Update(deltaTime);
    }
    CollisionDetection();
}

void ObjectManager::Render(sf::RenderWindow& window) {
    // Sort objects by Y-coordinate for proper rendering order
    for (auto object : objects) {
        object->Render(window);
    }
}

void ObjectManager::SetPlayerPosition(Vec& position) {
    if (player) {
        player->SetPosition(position);
    }
}

void ObjectManager::CollisionDetection() {
    for (size_t i = 0; i < objects.size(); i++) {
        for (size_t j = i + 1; j < objects.size(); j++) {
            if (objects[i]->GetHitBox()->IsCollision(objects[j]->GetHitBox())) {
                objects[i]->Collision(objects[j]);
                objects[j]->Collision(objects[i]);
            }
        }
    }
}

void ObjectManager::DeleteAllObjects() {
    for (auto object : objects) {
        delete object;
    }
    objects.clear();
}
