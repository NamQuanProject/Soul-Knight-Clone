#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <map>
#include <string>
#include "../core/animation.h"

class AnimationManager {
public:
    AnimationManager();

    // Add an animation to the manager
    void addAnimation(const std::string& name, const Animation& animation);

    // Set the current animation by name
    void setCurrentAnimation(const std::string& name);

    // Update the current animation based on delta time
    void update(float deltaTime);

    // Get the current frame of the animation for rendering
    const sf::IntRect& getCurrentFrame() const;

    // Check if the current animation is set
    bool isAnimationSet() const;

private:
    std::map<std::string, Animation> animations; // Store animations by name
    Animation* currentAnimation; // Pointer to the currently active animation
};

#endif // ANIMATIONMANAGER_H
