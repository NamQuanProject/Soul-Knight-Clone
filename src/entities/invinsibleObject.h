#pragma once
#include "gameObject.h"

class InvisibleObject : public GameObject{
public:
    void Update(float deltaTime) override;
    void LoadResources();
    void Render(sf::RenderWindow& window) override;
    void SetHitBoxByRatio(double heightRatio, double widthRatio);  
    

protected:
    bool invinsible = true;
    void SetCenter();
    
};