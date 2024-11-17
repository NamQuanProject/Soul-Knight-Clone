#include "animationManager.h"

// Constructor: Initializes the current animation to an empty string
AnimationManager::AnimationManager() : currentAnimationName("") {}

// Adds an animation to the manager with the given name
void AnimationManager::addAnimation(const std::string& name, const Animation& animation) {
    animations[name] = animation;  // Store the animation in the map
}

// Sets the current animation by name and updates the sprite accordingly
void AnimationManager::setAnimation(const std::string& name) {
    // Check if the animation exists in the map
    auto it = animations.find(name);
    if (it != animations.end()) {
        currentAnimationName = name;  // Set the current animation
        currentSprite.setTexture(it->second.getTexture());  // Set the sprite texture from the animation
    }
}

// Updates the current animation (called every frame)
void AnimationManager::update(float deltaTime) {
    if (!currentAnimationName.empty()) {
        animations[currentAnimationName].update(deltaTime);
        const sf::IntRect& frame = animations[currentAnimationName].getCurrentFrame();
        currentSprite.setTextureRect(frame);  // Set the texture rectangle to the current frame
    }
}

// Returns the current sprite for rendering
const sf::Sprite& AnimationManager::getCurrentSprite() const {
    return currentSprite;
}
