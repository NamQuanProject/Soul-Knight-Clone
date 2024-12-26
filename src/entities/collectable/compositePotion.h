#pragma once
#include "collectable.h"

class CompositePotion : public  Collectable{
public:
    CompositePotion();
    void Update(float deltaTime) override;
    
    void LoadResources();
    void Initialize() override;
    void Interactive(Player* player) override;
};
