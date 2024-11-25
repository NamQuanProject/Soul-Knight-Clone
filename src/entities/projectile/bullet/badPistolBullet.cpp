#include "badPistolBullet.h"
#include <iostream>

BadPistolBullet::BadPistolBullet() {
    SetProjectileType(ProjectileType::BAD_PISTOL_BULLET);
}

void BadPistolBullet::Start() {
    Bullet::Start();
    // Set initial position, velocity, or other properties if needed.
}

void BadPistolBullet::Update() {
    // Bullet::Update();
}

void BadPistolBullet::LoadResources() {
    if (!bulletTexture.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/bad_bullet/template/bad_bullet.bmp")) {
        std::cerr << "Error: Could not load bullet texture!" << std::endl;
    } else {
        bulletSprite.setTexture(bulletTexture);
        bulletSprite.setOrigin(bulletTexture.getSize().x / 2, bulletTexture.getSize().y / 2);
    }
}
