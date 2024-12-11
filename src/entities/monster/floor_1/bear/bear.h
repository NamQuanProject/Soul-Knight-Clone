#pragma once
#include "../../monster.h"
#include "../../../../manager/animationManager.h"
#include "../../../../manager/objectManager.h"
#include "../../../../utils/vec.h"
#include "../../../../entities/projectile/bullet/redCircleBullet.h"
#include "../../../../utils/random.h"

class Bear : public Monster {
public:
    Bear(double level = 1);
    ~Bear();
    void Start();
    void Initialize() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void AutoMation() override;
    void InitializeWeapon() override;
    void SetPosition(Vec& position) override;   
    void Render(sf::RenderWindow& window) override;
    void Attack() override;

private:
    AnimationManager animationManager;
    bool collideOnObstacle = false;
    float attackCooldown = 500.0f;  // Cooldown time in seconds
    float attackTimer = 0.0f;     // Time since last attack
    float fireCooldown;
    int attack_time_2;
    int random_choice;
};
