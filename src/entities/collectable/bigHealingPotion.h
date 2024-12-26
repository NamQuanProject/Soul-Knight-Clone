#pragma once
#include "collectable.h"

class BigHealingPotion : public Collectable {
public:
    BigHealingPotion();
    void Update(float deltaTime) override;
    void LoadResources();
    void Initialize() override;
    void Interactive(Player* player) override;
};
