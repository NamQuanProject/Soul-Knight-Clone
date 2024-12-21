
#pragma once
#include "../bullet.h"

class SpearWave : public Bullet {
public:
    SpearWave();
    ~SpearWave();
    void Initialize() override;
    void Update(float deltaTime) override;  
    void LoadResources() override;    
    void SetSpeed(Vec newSpeed) override; 
    void Render(sf::RenderWindow& window) override; 
    void SetPosition(Vec& position) override; 
    void Collision(GameObject* gameObject) override;
    sf::Vector2f GetPosition() override;
    
private:
    sf::Texture bulletTexture; 
    sf::Sprite bulletSprite;  
    Vec speed;
    bool textureLoaded;
};
