
#pragma once
#include "../bullet.h"

class RedRectangleBullet : public Bullet {
public:
    RedRectangleBullet();
    ~RedRectangleBullet();
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
