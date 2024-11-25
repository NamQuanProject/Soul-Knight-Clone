#ifndef KNIGHT_H
#define KNIGHT_H

#include "../player.h"
#include "../../weapon/gun/badPistol.h"
#include "../../../core/animation.h"
#include "../../../manager/animationManager.h"
#include <SFML/Graphics.hpp>


class Knight : public Player {
public:
    Knight();  
    ~Knight();                  // Constructor
    void Update(float deltaTime) override;  // Update method
    void Render(sf::RenderWindow& window) override;  // Render method
    void runRight();            
    void runLeft();             
    void standRight();           
    void standLeft();     
    void SetPosition(const Vec& position) override;      
private:
    void loadKnightAnimations();       // Load knight-specific animations
    Weapon* weapon1;
    AnimationManager animationManager;  // Animation manager for handling animations
};

#endif // KNIGHT_H
