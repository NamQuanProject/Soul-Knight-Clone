#pragma once
#include "../../monster.h"
#include "../../../../manager/animationManager.h"
#include "../../../../utils/vec.h"

class GoblinShaman : public Monster {
public:
    GoblinShaman(double level = 1);
    void Initialize() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void AutoMation() override;
    void InitializeWeapon() override;
    void Render(sf::RenderWindow& window) override;
    void SetPosition(Vec& position) override;   
private:
    AnimationManager animationManager;
};
