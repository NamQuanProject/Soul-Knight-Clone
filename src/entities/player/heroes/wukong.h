#ifndef KNIGHT_H
#define KNIGHT_H

#include "../player.h"
#include "../../weapon/gun/badPistol.h"
#include "../../weapon/melee/dragonSword.h"
#include "../../../core/animation.h"
#include "../../projectile/bullet/superMoonBullet.h"
#include "../../../manager/animationManager.h"
#include "../../../utils/point.h"
#include <SFML/Graphics.hpp>

class Knight : public Player {
public:
    Knight();  
    ~Knight();     
    void Initialize() override;           
    void Update(float deltaTime) override;  
    void Render(sf::RenderWindow& window) override;  
    void runRight() override;            
    void runLeft() override;              
    void standRight() override;           
    void standLeft() override;     
    void SetPosition(Vec& position) override;      
    void Collision(GameObject* gameObject) override;
    void Attack() override;
    void SetBeforePosition(Vec before);
    void SwitchWeapon() override;

    void UseSkill() override; // New function to activate skill
    void StopSkill(); // New function to deactivate skill

private:
    void loadKnightAnimations();       
    Weapon* weapon1;
    Weapon* weapon2;
    AnimationManager animationManager;  
    bool isHit = false; 
    float hitTimer = 0.f;
    const float hitDuration = 10.f; 
    float shieldTime = 1500.f;
    float skillTime = 30.f;
    float attackCooldown = 20.f;
    bool usingWeapon1 = true;

    bool isSkillActive = true;      // Tracks if the skill is active
    float skillTimer = 200;        // Time remaining for the skill
    float skillDuration;  
    sf::Sprite skillEffectSprite; // Special sprite for skill effect
    sf::Texture skillEffectTexture; // Texture for skill effect
};

#endif // KNIGHT_H
