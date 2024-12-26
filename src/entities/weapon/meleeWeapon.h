#pragma once

#include "weapon.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../utils/vec.h"

class MeleeWeapon : public Weapon {
public:
    MeleeWeapon();
    virtual ~MeleeWeapon();

    void Attack() override;
    void Render(sf::RenderWindow& window) override;
    void Update(float deltaTime) override;
    void Collision(GameObject* gameObject) override;
    double GetDamage() override;
    void setPlayerPosition(sf::Vector2f position) override;

protected:
    sf::Vector2f playerPosition;
    sf::Sprite weaponSprite;
    sf::Texture weaponTexture;
    sf::Vector2f offset;
};