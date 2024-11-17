#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <map>
#include <string>
#include <vector>
#include "../core/animation.h"

class AnimationManager {
public:
    AnimationManager();  // Constructor

    // Add an animation to the manager
    void addAnimation(const std::string& name, const Animation& animation);

    // Set an animation to be the active one (single animation per object)
    void setAnimation(const std::string& name, const Animation& animation);

    // Get all animations by name
    std::map<std::string, Animation>& getAllAnimations();

    // Update the animations based on delta time
    void update(float deltaTime);

    // Get the current frame of a specific animation for rendering
    const sf::IntRect& getCurrentFrame(const std::string& name) const;

    // Check if a specific animation is set
    bool isAnimationSet(const std::string& name) const;

    // Reset a specific animation to its first frame
    void resetAnimation(const std::string& name);

private:
    std::map<std::string, Animation> animations;  // Store animations by name
};

#endif // ANIMATIONMANAGER_H
