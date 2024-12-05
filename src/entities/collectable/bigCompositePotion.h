#pragma once
#include "collectable.h"

class BigCompositePotion : public Collectable {
public:
    BigCompositePotion();
    void Start() override;
    void Update(float deltaTime) override;
    void LoadResources();

    void Interactive(Player* player) override;
};
