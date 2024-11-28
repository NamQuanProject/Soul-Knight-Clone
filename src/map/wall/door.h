#pragma once
#include "../../entities/invinsibleObject.h"

class Door : public InvisibleObject {
public:
    virtual void LoadResources() = 0;
};