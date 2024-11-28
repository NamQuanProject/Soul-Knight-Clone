#pragma once
#include "../../entities/invinsibleObject.h"

class Door : public InvisibleObject {
public:
    void Start() override;
    void Update() override;
    void LoadResources() override = 0;
    virtual void SetTopLeft(Point leftTop) = 0;
};