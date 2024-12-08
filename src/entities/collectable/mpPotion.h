#pragma once
#include "collectable.h"

class MpPotion : public Collectable {
public:
    MpPotion();
    void Start() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void Initialize() override;
    void Interactive(Player* player) override;
};
