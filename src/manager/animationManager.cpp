#include "animationManager.h"

// Constructor
AnimationManager::AnimationManager() : currentAnimation(nullptr) {}

// Add an animation to the manager
void AnimationManager::addAnimation(const std::string& name, const Animation& animation) {
    animations[name] = animation;
}

// Set the current animation by name
void AnimationManager::setCurrentAnimation(const std::string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        currentAnimation = &it->second;
        currentAnimation->update(0.f); 
    }
}

// Update the current animation based on delta time
void AnimationManager::update(float deltaTime) {
    if (currentAnimation) {
        currentAnimation->update(deltaTime);
    }
}

// Get the current frame of the animation for rendering
const sf::IntRect& AnimationManager::getCurrentFrame() const {
   if (currentAnimation) {
            return currentAnimation->getCurrentFrame(); // Return the current frame's texture
        }
        throw std::runtime_error("No current animation set");
}

// Check if the current animation is set
bool AnimationManager::isAnimationSet() const {
    return currentAnimation != nullptr;
}
