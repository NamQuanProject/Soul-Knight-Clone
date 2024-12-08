#pragma once
#include "collectable.h"

class BigHealingPotion : public Collectable {
public:
    BigHealingPotion();
    void Start() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void Initialize() override;
    void Interactive(Player* player) override;
};
