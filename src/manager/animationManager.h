#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "../core/animation.h"

class AnimationManager {
public:
    AnimationManager();

    void addAnimation(const std::string& name, const Animation& animation);  // Add an animation
    void setAnimation(const std::string& name);  // Set the current animation
    void update(float deltaTime);  // Update the animation
    sf::Sprite& getCurrentSprite();  // Get the current sprite for rendering
    std::string getCurrentAnimationName() const;

private:
    std::unordered_map<std::string, Animation> animations;
    sf::Sprite currentSprite;  // The sprite that will be rendered
    std::string currentAnimationName;  // The name of the current animation
};

#endif // ANIMATIONMANAGER_H
