#pragma once
#include <SFML/Graphics.hpp>
#include "../bullet.h"
#include "../../../manager/objectManager.h"
class BadPistolBullet : public Bullet {
public:
    BadPistolBullet();
    ~BadPistolBullet();
    void Initialize() override;
    void Update(float deltaTime) override;  
    void LoadResources() override;    
    void SetSpeed(Vec newSpeed) override; 
    void Render(sf::RenderWindow& window) override; 
    void SetPosition(Vec& position) override; 
    sf::Vector2f GetPosition() override;
    void Attack();
    
private:
    sf::Texture bulletTexture; // Texture for the bullet
    sf::Sprite bulletSprite;   // Sprite for rendering
    Vec position;     // Position of the bullet
    Vec speed;        // Speed of the bullet
    bool textureLoaded;
};

