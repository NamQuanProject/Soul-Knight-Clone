#pragma once
#include "../../monster.h"
#include "../../../../manager/animationManager.h"
#include "../../../../utils/vec.h"

class GoblinGiant : public Monster {
public:
    GoblinGiant(double level = 1);
    ~GoblinGiant();
    void Start();
    void Update(float deltaTime) override;
    void LoadResources();
    void AutoMation() override;
    void InitializeWeapon() override;
    void SetPosition(Vec& position) override;   
    void Render(sf::RenderWindow& window) override;

private:
    AnimationManager animationManager;

};
