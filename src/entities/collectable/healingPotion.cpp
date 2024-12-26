#include "healingPotion.h"
#include "../../manager/objectManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

HealingPotion::HealingPotion() {
    AddTag(Tag::POTION);

    // Load texture and set up sprite
    if (!texture.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/collectable/healing_potion.bmp")) {
        std::cerr << "Error loading healing potion texture!" << std::endl;
    }
    texture.setSmooth(true);  // Optional: makes the texture look smoother when scaled
    sprite.setTexture(texture);

    // Create a mask for the white color in the image
    sf::Image image;
    if (image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/collectable/healing_potion.bmp")) {
        image.createMaskFromColor(sf::Color(255, 255, 255));
        texture.loadFromImage(image);
    }

    // Initialize hitbox
    sf::Vector2f position = sprite.getPosition();
    Point author = Point(position.x, position.y);
    hitbox = new HitBox(author);
    showingText = false;
}

HealingPotion::~HealingPotion() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}

void HealingPotion::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        showingText = true;  
        if (ObjectManager::Instance()->GetPlayer()->GetInteract() == true) {
            Interactive(ObjectManager::Instance()->GetPlayer());
        }
    }
}

void HealingPotion::Initialize() {
    AddTag(Tag::POTION);

    // Reinitialize the hitbox
    sf::Vector2f position = sprite.getPosition();
    Point author = Point(position.x, position.y);
    hitbox = new HitBox(author);
}

void HealingPotion::Render(sf::RenderWindow& window) {
    window.draw(sprite);
}

void HealingPotion::Update(float deltaTime) {
    Collectable::Update(deltaTime);

    // Update hitbox position
    sf::Vector2f position = sprite.getPosition();
    sf::FloatRect bounds = sprite.getLocalBounds();
    hitbox->SetWidth(bounds.width);
    hitbox->SetHeight(bounds.height);
    hitbox->SetPosition(Point(position.x, position.y));
}

void HealingPotion::LoadResources() {
    // Texture loading is handled in the constructor
}

void HealingPotion::Interactive(Player* player) {
    if (player) {
        player->Healing(2);  // Heal the player by 2
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);  // Mark for removal
    }
}

void HealingPotion::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    sprite.setPosition(x, y);
}
