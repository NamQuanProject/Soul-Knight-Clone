#pragma once
#include "../../manager/animationManager.h"
#include "../../core/animation.h"
#include "door.h"
#include <SFML/graphics.hpp>


class VerticalDoor1 : public Door {
public:
    void LoadResources() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
protected:
    AnimationManager animationManager;
};