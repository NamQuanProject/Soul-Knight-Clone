#pragma once
#include "../weapon.h"
#include "../../gameObject.h"
#include "../rangeWeapon.h"
  // Include rangeWeapon.h because BadPistol inherits from it

class BadPistol : public RangeWeapon {
public:
    BadPistol();
    void Use() override;
    void Render(sf::RenderWindow& window) override ;  // Implement the Render function
    void Collision(GameObject* gameObject) override; // Implement Collision
    double GetDamage() override;                     // Implement GetDamage
    void Fire() override;                            // Implement Fire
    void Reload() override;  
    void setPlayerPosition(sf::Vector2f Position) override;                   // Implement Reload
private:
    sf::Texture pistolTexture; // Texture for the pistol
    sf::Sprite pistolSprite;   // Sprite for the pistol
    sf::Vector2f offset;       // Offset relative to the player position
    sf::Vector2f playerPosition;
};
