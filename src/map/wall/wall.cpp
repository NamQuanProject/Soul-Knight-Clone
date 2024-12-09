#include "wall.h"
#include "../../entities/player/player.h"
#include <iostream>



Wall::Wall(Point start, Point end) {  // Initialize hitbox with the start point
    // Set up the wall's rectangle shape
    float width = static_cast<float>(end.GetX() - start.GetX());
    float height = static_cast<float>(end.GetY() - start.GetY());

    wallShape.setSize(sf::Vector2f(width, height));
    wallShape.setPosition(static_cast<float>(start.GetX()), static_cast<float>(start.GetY()));
    wallShape.setFillColor(sf::Color::Green);
    wallShape.setOutlineThickness(2);


    float hitboxCenterX = start.GetX() + width / 2;
    float hitboxCenterY = start.GetY() + height / 2;


    Point authorPoint = Point(hitboxCenterX, hitboxCenterY);
    hitbox = new HitBox(authorPoint);
    hitbox->SetWidth(width);
    hitbox->SetHeight(height);



    AddTag(Tag::WALL);
}

Wall::~Wall() {
    if (hitbox) {
        delete hitbox;
    }
    
}


void Wall::Initialize() {
    // // Set up the wall's rectangle shape
    // float width = static_cast<float>(end.GetX() - start.GetX());
    // float height = static_cast<float>(end.GetY() - start.GetY());

    // wallShape.setSize(sf::Vector2f(width, height));
    // wallShape.setPosition(static_cast<float>(start.GetX()), static_cast<float>(start.GetY()));
    // wallShape.setFillColor(sf::Color::Green);
    // // wallShape.setOutlineThickness(2);

    // float hitboxCenterX = start.GetX() + width / 2;
    // float hitboxCenterY = start.GetY() + height / 2;
    
    // hitbox.SetWidth(width);
    // hitbox.SetHeight(height);
    // hitbox.SetPosition(Point(hitboxCenterX, hitboxCenterY));



    // AddTag(Tag::WALL);
}


bool Wall::CheckCollision(GameObject* gameObject) {
    if (!gameObject) return false;

    HitBox* objectHitbox = gameObject->GetHitBox();
    if (!objectHitbox) return false;
    
    return hitbox->IsCollision(objectHitbox);
}

void Wall::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER) || gameObject->HasTag(Tag::MONSTER) || gameObject->HasTag(Tag::PROJECTILE)) {
        gameObject->Collision(this);
        wallShape.setFillColor(sf::Color::Red);
    } else {
        // wallShape.setFillColor(sf::Color::Green);
    }
}




void Wall::Render(sf::RenderWindow& window) {
    window.draw(wallShape);
}


