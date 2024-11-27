#pragma once
#include "../../../../../manager/animationManager.h"
#include "../../../monster.h"

class GoblinGiant : public Monster {
public:
    GoblinGiant(double level);
    void Start() override;
    void Update() override;
    void LoadResources() override;
    void AutoMation() override;
    void InitializeWeapon() override;


private:
    animationManager animationManager;

};
