#ifndef KNIGHT_H
#define KNIGHT_H

#include "../player.h"
#include "../../weapon/gun/badPistol.h"
#include "../../../core/animation.h"
#include "../../../manager/animationManager.h"
#include "../../../utils/point.h"
#include <SFML/Graphics.hpp>


class Knight : public Player {
public:
    Knight();  
    ~Knight();     
    void Initialize() override;             // Constructor
    void Update(float deltaTime) override;  // Update method
    void Render(sf::RenderWindow& window) override;  // Render method
    void runRight() override;            
    void runLeft() override;              
    void standRight() override;           
    void standLeft() override;     
    void SetPosition(Vec& position) override;      
    void Collision(GameObject* gameObject) override;
    void Attack() override;
    void SetBeforePosition(Vec before);
private:
    void loadKnightAnimations();       // Load knight-specific animations
    Weapon* weapon1;
    AnimationManager animationManager;  // Animation manager for handling animations
    bool isHit = false; // Tracks if the knight is hit
    float hitTimer = 5.f; // Timer for how long the red effect lasts
    const float hitDuration = 5.f; 
};

#endif // KNIGHT_H
