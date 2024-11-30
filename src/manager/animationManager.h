#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "../core/animation.h"

class AnimationManager {
public:
    AnimationManager();

    void addAnimation(const std::string& name, const Animation& animation); 
    void setAnimation(const std::string& name);  
    void update(float deltaTime);  
    sf::Sprite& getCurrentSprite();  
    std::string getCurrentAnimationName() const;

private:
    std::unordered_map<std::string, Animation> animations;
    sf::Sprite currentSprite;  
    std::string currentAnimationName;  
};

#endif 
