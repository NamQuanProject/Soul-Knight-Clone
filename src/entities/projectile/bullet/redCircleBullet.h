#pragma once
#include "../bullet.h"

class RedCircleBullet : public Bullet {
public:
    RedCircleBullet();
    ~RedCircleBullet();
    void Update(float deltaTime) override;  
    void LoadResources() override;    
    void SetSpeed(const sf::Vector2f& newSpeed) override; 
    void Render(sf::RenderWindow& window) override; 
    void SetPosition(const sf::Vector2f& position); 
    void Collision(GameObject* gameObject) override;
    sf::Vector2f GetPosition() override;
    
private:
    sf::Texture bulletTexture; // Texture for the bullet
    sf::Sprite bulletSprite;   // Sprite for rendering
    sf::Vector2f position;     // Position of the bullet
    sf::Vector2f speed;        // Speed of the bullet
    bool textureLoaded;
};