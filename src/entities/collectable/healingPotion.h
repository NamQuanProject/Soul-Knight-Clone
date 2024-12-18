#pragma once
#include "collectable.h"

class HealingPotion : public Collectable {
public:
    HealingPotion();
    void Start() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void Initialize() override;
    void Interactive(Player* player) override;
};
