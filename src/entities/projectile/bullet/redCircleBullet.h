#pragma once
#include "../bullet.h"

class RedCircleBullet : public Bullet {
public:
    RedCircleBullet();
    ~RedCircleBullet();
    void Initialize() override;
    void Update(float deltaTime) override;  
    void LoadResources() override;    
    void SetSpeed(Vec newSpeed) override; 
    void Render(sf::RenderWindow& window) override; 
    void SetPosition(Vec& position) override; 
    void Collision(GameObject* gameObject) override;
    sf::Vector2f GetPosition() override;
    
private:
    sf::Texture bulletTexture; // Texture for the bullet
    sf::Sprite bulletSprite;   // Sprite for rendering     // Position of the bullet
    Vec speed;        // Speed of the bullet
    bool textureLoaded;
};
