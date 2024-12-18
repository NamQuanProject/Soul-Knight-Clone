#include "UIManager.h"



UIManager * UIManager ::instance = nullptr;

UIManager * UIManager ::Instance() {
    if (instance == nullptr) {
        instance = new UIManager ();
    }
    return instance;
}

UIManager::UIManager() : camera(1000, 1000) {}

UIManager::~UIManager() {}

void UIManager::Initialize() {


}

void UIManager::setWorldBounds(sf::FloatRect worldBounds) {
    camera.setWorldBounds(worldBounds);
}


void UIManager::Update(float deltaTime) {
    sf::Vector2f knightPos(ObjectManager::Instance()->GetPlayer()->GetPosition().GetX(), ObjectManager::Instance()->GetPlayer()->GetPosition().GetY());
    camera.update(knightPos);
}

void UIManager::applyView(sf::RenderWindow& window) {
    camera.applyView(window);
}

void UIManager::Render(sf::RenderWindow& window) {
    // Apply the camera's view to render the game world
    applyView(window);

    // Render game objects here (e.g., background, player, enemies, etc.)
    // Example: window.draw(gameObjects);

    // Switch back to the default view for UI renderin

    // Render UI elements (HP, Mana, etc.) here

    sf::Text hpText;
    hpText.setString("HP: " + std::to_string(ObjectManager::Instance()->GetPlayer()->GetHP()));
    hpText.setCharacterSize(30); // Set text size
    hpText.setFillColor(sf::Color::Red); // Set text color
    hpText.setPosition(183, 183); // Fixed position on the screen

    window.draw(hpText);

    // You can render other UI elements (like Mana) similarly
}
