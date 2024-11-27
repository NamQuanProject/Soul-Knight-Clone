#pragma once
#include "../../../monster.h"
#include "../../../../../manager/animationManager.h"

class GoblinShaman : public Monster {
public:
    GoblinShaman(double level = 1);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;

private:
    AnimationManager animationManager;
};
