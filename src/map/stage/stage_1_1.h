#pragma once
#include "stage.h"

class Stage_1_1 : public Stage {
public:
    Stage_1_1();
    ~Stage_1_1();
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
    void Collision(GameObject* gameObject);

protected:
    void setBackground() override;
    void AddWallsToMap();
    
    void GenerateWall() override;
    void SetPlayerPosition() override;
    void SetTransferGate() override;
    void GenerateObstacle() override;

};