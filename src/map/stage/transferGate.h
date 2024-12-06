#pragma once
#include <SFML/Graphics.hpp>
#include "../../entities/gameObject.h"

class Player;



class TransferGate : public GameObject {
public:
    TransferGate();
    void Update(float deltaTime) override;
    void LoadResources();
    void Render(sf::RenderWindow& window) override;
    void Interactive(Player* player);
};