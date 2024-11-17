#include "knife.h"
#include <iostream>

Knife::Knife() {
    damage = 15;           // Low damage compared to larger melee weapons
    durability = 100;      // High durability, a knife can withstand many uses
    sharpness = 100;       // Knife starts sharp
    range = 1.0;           // Short range for a knife
}

void Knife::Use() {
    // if (durability > 0) {
    //     std::cout << "Stabbing with knife for " << damage << " damage!" << std::endl;
    //     durability--;  // Decreases durability with each use
    //     // Optionally, you can add sharpness degradation logic over time
    //     if (sharpness > 0) {
    //         sharpness--;
    //     }
    // } else {
    //     std::cout << "Knife is broken! Durability is zero." << std::endl;
    // }
}

void Knife::SetSharpness(int sharpness) {
    this->sharpness = sharpness;
}

int Knife::GetSharpness() const {
    return sharpness;
}
