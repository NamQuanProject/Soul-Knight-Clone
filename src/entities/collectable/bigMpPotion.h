#pragma once
#include "collectable.h"

class BigMpPotion : public Collectable {
public:
    BigMpPotion();
    ~BigMpPotion();
    void Initialize() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void Render(sf::RenderWindow& window) override;
    void Interactive(Player* player) override;
    void SetPosition(Vec& newPosition) override;
    void Collision(GameObject* gameObject) override; 
private:
    sf::Text interactiveText;
    bool showingText;
    sf::Font font;
    sf::Texture texture;
    sf::Sprite sprite;
};
