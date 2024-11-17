#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include "../core/animation.h"

class AnimationManager {
public:
    AnimationManager();

    void addAnimation(const std::string& name, const Animation& animation);  // Add an animation
    void setAnimation(const std::string& name);  // Set the current animation
    void update(float deltaTime);  // Update the animation
    const sf::Sprite& getCurrentSprite() const;  // Get the current sprite for rendering

private:
    std::map<std::string, Animation> animations;  // All animations
    sf::Sprite currentSprite;  // The sprite that will be rendered
    std::string currentAnimationName;  // The name of the current animation
};

#endif // ANIMATIONMANAGER_H
