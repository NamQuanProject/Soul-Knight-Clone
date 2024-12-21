#pragma once
#include "weaponType.h"

class Weapon;

class WeaponFactory {
public:
    static Weapon* Create(WeaponType weaponType);
};