#include "bigCompositePotion.h"
#include "../../manager/objectManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

BigCompositePotion::BigCompositePotion() {
    AddTag(Tag::POTION);

    if (!texture.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/collectable/big_composite_potion.bmp")) {
        std::cerr << "Error loading healing potion texture!" << std::endl;
    }
    texture.setSmooth(true); 
    sprite.setTexture(texture);

    sf::Image image;
    if (image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/collectable/big_composite_potion.bmp")) {
        image.createMaskFromColor(sf::Color(255, 255, 255));
        texture.loadFromImage(image);
    }

    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/ARIAL.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    interactiveText.setFont(font);
    interactiveText.setString("Press L to interact");
    interactiveText.setCharacterSize(9);

    interactiveText.setFillColor(sf::Color::White);  

    sf::Vector2f position = sprite.getPosition();
    interactiveText.setPosition(position.x - 45.f, position.y + 50.f);  
    
    // Initialize hitbox
    
    


    
    Point author = Point(position.x, position.y);
    hitbox = new HitBox(author);
    showingText = false;
}

BigCompositePotion::~BigCompositePotion() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}

void BigCompositePotion::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        showingText = true;  
        if (ObjectManager::Instance()->GetPlayer()->GetInteract() == true) {
            Interactive(ObjectManager::Instance()->GetPlayer());
        }
    }
    else {
        showingText = false;
    }
}

void BigCompositePotion::Initialize() {
    AddTag(Tag::POTION);

    // Reinitialize the hitbox
    sf::Vector2f position = sprite.getPosition();
    Point author = Point(position.x, position.y);
    hitbox = new HitBox(author);
}

void BigCompositePotion::Render(sf::RenderWindow& window) {
    window.draw(sprite);
    if (showingText == true) {
        window.draw(interactiveText);
    }
}

void BigCompositePotion::Update(float deltaTime) {
    Collectable::Update(deltaTime);

    // Update hitbox position
    sf::Vector2f position = sprite.getPosition();
    sf::FloatRect bounds = sprite.getLocalBounds();
    hitbox->SetWidth(bounds.width);
    hitbox->SetHeight(bounds.height);
    hitbox->SetPosition(Point(position.x, position.y));
}

void BigCompositePotion::LoadResources() {
    // Texture loading is handled in the constructor
}

void BigCompositePotion::Interactive(Player* player) {
    if (player) {
        player->Healing(2);  // Heal the player by 2
        AddTag(Tag::REMOVE_ON_NEXT_FRAME);  // Mark for removal
    }
}

void BigCompositePotion::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    interactiveText.setPosition(x - 45.f, y + 50.f);
    sprite.setPosition(x, y);
}
