#pragma once
#include "../weapon.h"
#include "../meleeWeapon.h"
#include "../../../manager/objectManager.h"
#include "../../player/heroes/knight.h"

class DragonBlade : public MeleeWeapon {
public:
    DragonBlade();
    virtual ~DragonBlade();

    // Initialization and state management
    void Initialize() override;
    void Update(float deltaTime) override;

    // Combat mechanics
    void Attack() override;             // Standard attack
    void SpecialAttack();               // Unique special attack
    double GetDamage() override;

    // Visual and collision
    void Render(sf::RenderWindow& window) override;
    void Collision(GameObject* gameObject) override;

    // Player-related functions
    void setPlayerPosition(sf::Vector2f Position) override;
    void setOffset(double x, double y) override;

    bool IsMonsterInSwingArc(const Vec& monsterPosition);

private:
    sf::Texture bladeTextureRight;      // Texture for right-facing blade
    sf::Texture bladeTextureLeft;       // Texture for left-facing blade
    sf::Sprite bladeSprite;             // Sprite representing the blade
    sf::Vector2f offset;                // Offset from the player position
    sf::Vector2f playerPosition;        // Player's current position
    int attackRange;                    // Range of the blade's attack
    double damageMultiplier;            // Damage multiplier for the blade
    bool isSwinging = false;
    float swingAngle = 0.0f;
    float swingSpeed = 1.0f; // Degrees per second
    float swingDuration = 100.f; // Seconds
    float swingTimer = 0.0f;
};
