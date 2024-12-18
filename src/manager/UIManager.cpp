#include "UIManager.h"



UIManager * UIManager ::instance = nullptr;

UIManager * UIManager ::Instance() {
    if (instance == nullptr) {
        instance = new UIManager ();
    }
    return instance;
}

UIManager::UIManager() : camera(500, 500) {}

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
    applyView(window);


    sf::Vector2f cameraCenter = camera.getView().getCenter(); 
    sf::Vector2f cameraSize = camera.getView().getSize();

    
    sf::Vector2f hpBarPosition(cameraCenter.x - cameraSize.x / 2 + 20, 
                               cameraCenter.y - cameraSize.y / 2 + 20);
    // HP bar fill
    float playerHP = ObjectManager::Instance()->GetPlayer()->GetHP();
    float playerMaxHP = ObjectManager::Instance()->GetPlayer()->GetMaxHP();


    float hpPercentage = playerHP / playerMaxHP;

    // Create the HP bar with a width proportional to the HP percentage
    sf::RectangleShape hpBar(sf::Vector2f(200 * hpPercentage, 20)); // 200 is the full width of the HP bar
    hpBar.setFillColor(sf::Color::Red);
    hpBar.setPosition(hpBarPosition);

    // Draw the HP bar background
    sf::RectangleShape hpBarBackground(sf::Vector2f(200, 20)); // Full width of the HP bar background
    hpBarBackground.setFillColor(sf::Color(50, 50, 50)); // Dark gray for background
    hpBarBackground.setPosition(hpBarPosition);

    // Draw the HP bar and background
    window.draw(hpBarBackground);
    window.draw(hpBar);
}

