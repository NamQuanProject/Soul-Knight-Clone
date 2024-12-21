#include "UIManager.h"



UIManager* UIManager::instance = nullptr;

UIManager* UIManager::Instance() {
    if (instance == nullptr) {
        instance = new UIManager ();
    }
    return instance;
}

UIManager::UIManager() : camera(500, 500) {}

UIManager::~UIManager() {
    sf::Vector2f pos(0, 0);
    camera.update(pos);
    
}

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

    // Get camera center and size
    sf::Vector2f cameraCenter = camera.getView().getCenter(); 
    sf::Vector2f cameraSize = camera.getView().getSize();

    // Calculate the starting position for the bars
    sf::Vector2f barPosition(cameraCenter.x - cameraSize.x / 2 + 20, 
                             cameraCenter.y - cameraSize.y / 2 + 20);

    // === HP Bar ===
    int playerHP = ObjectManager::Instance()->GetPlayer()->GetHP();
    int playerMaxHP = ObjectManager::Instance()->GetPlayer()->GetMaxHP();
    float hpPercentage = float(playerHP) / float(playerMaxHP);

    sf::RectangleShape hpBar(sf::Vector2f(150 * hpPercentage, 5)); // HP bar
    hpBar.setFillColor(sf::Color::Red);
    hpBar.setPosition(barPosition);

    sf::RectangleShape hpBarBackground(sf::Vector2f(150, 5)); // HP background
    hpBarBackground.setFillColor(sf::Color(50, 50, 50));
    hpBarBackground.setPosition(barPosition);

    // === Mana Bar ===
    float playerMana = ObjectManager::Instance()->GetPlayer()->GetMana();
    float playerMaxMana = ObjectManager::Instance()->GetPlayer()->GetMaxMana();
    float manaPercentage = playerMana / playerMaxMana;

    sf::RectangleShape manaBar(sf::Vector2f(150 * manaPercentage, 5)); // Mana bar
    manaBar.setFillColor(sf::Color::Blue);
    manaBar.setPosition(sf::Vector2f(barPosition.x, barPosition.y + 10)); // Offset below HP bar

    sf::RectangleShape manaBarBackground(sf::Vector2f(150, 5)); // Mana background
    manaBarBackground.setFillColor(sf::Color(50, 50, 50));
    manaBarBackground.setPosition(sf::Vector2f(barPosition.x, barPosition.y + 10));

    // === Shield Bar ===
    int playerShield = ObjectManager::Instance()->GetPlayer()->GetShield();
    int playerMaxShield = ObjectManager::Instance()->GetPlayer()->GetMaxShield();
    float shieldPercentage = float(playerShield) / float(playerMaxShield);

    sf::RectangleShape shieldBar(sf::Vector2f(150 * shieldPercentage, 5)); // Shield bar
    shieldBar.setFillColor(sf::Color::Cyan);
    shieldBar.setPosition(sf::Vector2f(barPosition.x, barPosition.y + 20)); // Offset below Mana bar

    sf::RectangleShape shieldBarBackground(sf::Vector2f(150, 5)); // Shield background
    shieldBarBackground.setFillColor(sf::Color(50, 50, 50));
    shieldBarBackground.setPosition(sf::Vector2f(barPosition.x, barPosition.y + 20));

    // Draw all bars
    window.draw(hpBarBackground);
    window.draw(hpBar);
    window.draw(manaBarBackground);
    window.draw(manaBar);
    window.draw(shieldBarBackground);
    window.draw(shieldBar);
}


