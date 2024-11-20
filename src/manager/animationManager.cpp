#include "animationManager.h"
#include <iostream>

// Constructor: Initializes the current animation to an empty string
AnimationManager::AnimationManager() : currentAnimationName("") {}

// Adds an animation to the manager with the given name
void AnimationManager::addAnimation(const std::string& name, const Animation& animation) {
    animations[name] = animation;  // Store the animation in the map
}

// Sets the current animation by name and updates the sprite accordingly
void AnimationManager::setAnimation(const std::string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        // Only update if the animation has changed
        if (currentAnimationName != name) {
            currentAnimationName = name;  // Set the current animation
            currentSprite.setTexture(it->second.getTexture());  // Set the sprite texture from the animation
        }
    } else {
        std::cerr << "Animation not found: " << name << std::endl;
    }
}

// Updates the current animation (called every frame)
void AnimationManager::update(float deltaTime) {
    if (!currentAnimationName.empty()) {
        // Update the current animation's state (frames, timing)
        animations[currentAnimationName].update(deltaTime);
        currentSprite.setTexture(animations[currentAnimationName].getTexture());
    }
}

// Returns the current sprite for rendering
sf::Sprite& AnimationManager::getCurrentSprite() {
    return currentSprite;  // Return the sprite for rendering
}

// Optional: You may want to add getter functions for currentAnimationName, or other attributes.
std::string AnimationManager::getCurrentAnimationName() const {
    return currentAnimationName;
}
