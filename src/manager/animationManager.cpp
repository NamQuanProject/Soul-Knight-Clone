#include "animationManager.h"

AnimationManager::AnimationManager() {}

void AnimationManager::addAnimation(const std::string& name, const Animation& animation) {
    animations[name] = animation;  // Add an animation by its name
}

void AnimationManager::setAnimation(const std::string& name, const Animation& animation) {
    animations[name] = animation;  // Update the animation for a specific name
}

std::map<std::string, Animation>& AnimationManager::getAllAnimations() {
    return animations;  // Return all animations
}

void AnimationManager::update(float deltaTime) {
    for (auto& pair : animations) {
        pair.second.update(deltaTime);  // Update all animations
    }
}

const sf::IntRect& AnimationManager::getCurrentFrame(const std::string& name) const {
    auto it = animations.find(name);
    if (it != animations.end()) {
        return it->second.getCurrentFrame();  // Return the current frame of the animation
    }
    static sf::IntRect emptyFrame;  // Return an empty frame if the animation doesn't exist
    return emptyFrame;
}

bool AnimationManager::isAnimationSet(const std::string& name) const {
    return animations.find(name) != animations.end();  // Check if the animation is set
}

void AnimationManager::resetAnimation(const std::string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        it->second.reset();  // Reset the animation to its first frame
    }
}
