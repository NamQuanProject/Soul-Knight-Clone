#pragma once

#include "../rangeWeapon.h"

class BadPistol : public RangeWeapon {
public:
    BadPistol();
    void Use() override;  // Override the Use method to reflect the bad pistol's behavior
};