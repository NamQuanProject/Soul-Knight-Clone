#ifndef STAGE_1_2_H
#define STAGE_1_2_H

#include "stage.h"

class Stage_1_2 : public Stage {
public:
    Stage_1_2();
    ~Stage_1_2();
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

#endif // STAGE_1_2_H
