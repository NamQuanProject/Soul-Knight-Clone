#ifndef KNIGHT_H
#define KNIGHT_H

#include "../player.h"
#include "../../../core/animation.h"
#include "../../../manager/animationManager.h"
#include <SFML/Graphics.hpp>

class Knight : public Player {
public:
    Knight();                    // Constructor
    void Update(float deltaTime) override;  // Update method
    void Render(sf::RenderWindow& window) override;  // Render method
    void Attack() override;               // Method to attack
    void runRight();             // Run right animation
    void runLeft();              // Run left animation
    void standRight();           // Stand right animation
    void standLeft();            // Stand left animation

private:
    void loadKnightAnimations();       // Load knight-specific animations
    AnimationManager animationManager;  // Animation manager for handling animations
};

#endif // KNIGHT_H
