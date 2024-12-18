#ifndef STAGE_1_3_H
#define STAGE_1_3_H

#include "stage.h"

class Stage_1_3 : public Stage {
public:
    Stage_1_3();
    ~Stage_1_3();
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

#endif // STAGE_1_3_H
