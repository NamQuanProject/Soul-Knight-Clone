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
private:
    void loadKnightAnimations();       
    Weapon* weapon1;
    AnimationManager animationManager;  
    bool isHit = false; 
    float hitTimer = 0.f;
    const float hitDuration = 10.f; 
};

#endif // KNIGHT_H
