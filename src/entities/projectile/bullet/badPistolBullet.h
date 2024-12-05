#pragma once
#include <SFML/Graphics.hpp>
#include "../bullet.h"

class BadPistolBullet : public Bullet {
public:
    BadPistolBullet();
    ~BadPistolBullet();
    void Update(float deltaTime) override;  // Update bullet position and state
    void LoadResources() override;    
    void SetSpeed(const sf::Vector2f& newSpeed) override; // Add this method
    void Render(sf::RenderWindow& window) override; // Render bullet to the window
    void SetPosition(const sf::Vector2f& position); // Set bullet position
    sf::Vector2f GetPosition() override;
    
private:
    sf::Texture bulletTexture; // Texture for the bullet
    sf::Sprite bulletSprite;   // Sprite for rendering
    sf::Vector2f position;     // Position of the bullet
    sf::Vector2f speed;        // Speed of the bullet
    bool textureLoaded;
};

