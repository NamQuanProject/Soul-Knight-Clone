#pragma once

#include "../meleeWeapon.h"

class Knife : public MeleeWeapon {
public:
    Knife();
    void Use() override;            // Override the Use method to perform the knife's attack
    void SetSharpness(int sharpness); // Set the sharpness of the knife (affects damage)
    int GetSharpness() const;        // Get the current sharpness of the knife

private:
    int sharpness;                   // Represents the sharpness of the knife
};
