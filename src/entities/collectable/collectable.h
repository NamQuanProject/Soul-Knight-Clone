#pragma once
#include <SFML/Graphics.hpp>
#include "../gameObject.h"
#include "../player/player.h"

class Collectable : public GameObject{
public:
    Collectable();
    virtual ~Collectable() = default;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
    virtual void Interactive(Player* player) = 0;
};
