#pragma once
#include <SFML/Graphics.hpp>
#include "../bullet.h"

class BadPistolBullet : public Bullet {
public:
    BadPistolBullet();

    void Start() override;
    void Update() override;
    void LoadResources() override;

private:
    sf::Texture bulletTexture;
    sf::Sprite bulletSprite;
};
