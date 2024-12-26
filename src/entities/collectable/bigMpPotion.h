#pragma once
#include "collectable.h"

class BigMpPotion : public  Collectable{
public:
    BigMpPotion();
    void Update(float deltaTime) override;
    void LoadResources();
    void Initialize() override;
    void Interactive(Player* player) override;
};
