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
    void runRight();            
    void runLeft();             
    void standRight();           
    void standLeft();     
    void SetPosition(Vec& position) override;      
    void Collision(GameObject* gameObject) override;
    void SetBeforePosition(Vec before);
private:
    void loadKnightAnimations();       // Load knight-specific animations
    Weapon* weapon1;
    AnimationManager animationManager;  // Animation manager for handling animations
};

#endif // KNIGHT_H
