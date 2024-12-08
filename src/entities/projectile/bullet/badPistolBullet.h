#pragma once
#include <SFML/Graphics.hpp>
#include "../bullet.h"

class BadPistolBullet : public Bullet {
public:
    BadPistolBullet();
    ~BadPistolBullet();
    void Initialize() override;
    void Update(float deltaTime) override;  
    void LoadResources() override;    
    void SetSpeed(const sf::Vector2f& newSpeed) override; 
    void Render(sf::RenderWindow& window) override; 
    void SetPosition(const sf::Vector2f& position); 
    sf::Vector2f GetPosition() override;
    
private:
    sf::Texture bulletTexture; // Texture for the bullet
    sf::Sprite bulletSprite;   // Sprite for rendering
    sf::Vector2f position;     // Position of the bullet
    sf::Vector2f speed;        // Speed of the bullet
    bool textureLoaded;
};

