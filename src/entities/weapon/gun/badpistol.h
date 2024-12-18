#pragma once
#include "../weapon.h"
#include "../../gameObject.h"
#include "../rangeWeapon.h"
#include "../../../manager/objectManager.h"
#include "../../../pool/projectilePool.h"
#include "../../projectile/bullet.h"
#include "../../projectile/bullet/badPistolBullet.h"
#include "../../player/heroes/knight.h"


class BadPistol : public RangeWeapon {
public:
    BadPistol();
    void Initialize() override;
    void Use() override;
    void Render(sf::RenderWindow& window) override ; 
    void Collision(GameObject* gameObject) override; 
    double GetDamage() override;                    
    void Fire() override;                           
    void Reload() override;  
    void setPlayerPosition(sf::Vector2f Position) override;     
    void setOffset(double x , double y) override;
    void Update(float deltaTime) override;   
    void Attack() override;         // Implement Reload
private:
    sf::Texture pistolTexture; // Texture for the pistol
    sf::Sprite pistolSprite;   // Sprite for the pistol
    sf::Vector2f offset;       // Offset relative to the player position
    sf::Vector2f playerPosition;
};
