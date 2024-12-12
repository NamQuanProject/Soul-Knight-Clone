#pragma once
#include <SFML/Graphics.hpp>
#include "../../entities/gameObject.h"
#include "../../manager/animationManager.h"

class Player;



class TransferGate : public GameObject {
public:
    TransferGate();
    void Initialize() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void Render(sf::RenderWindow& window) override;
    void Interactive(Player* player);
    void SetPosition(Vec& newPosition) override;
    void Collision(GameObject* gameObject) override; 
private:
    AnimationManager animationManager;
};