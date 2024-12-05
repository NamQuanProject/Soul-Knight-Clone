#pragma once
#include "collectable.h"

class BigMpPotion : public  Collectable{
public:
    BigMpPotion();
    void Start() override;
    void Update(float deltaTime) override;
    void LoadResources();

    void Interactive(Player* player) override;
};
