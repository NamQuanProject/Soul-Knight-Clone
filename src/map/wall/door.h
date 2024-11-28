#pragma once
#include "../../entities/invinsibleObject.h"

class Door : public InvisibleObject {
public:
    void Update(float deltaTime) override;
    void LoadResources();
};