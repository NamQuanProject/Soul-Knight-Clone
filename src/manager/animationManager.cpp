#include "animationManager.h"
#include <iostream>

AnimationManager::AnimationManager() : currentAnimationName("") {}


void AnimationManager::addAnimation(const std::string& name, const Animation& animation) {
    animations[name] = animation; 
}

void AnimationManager::setOrigin() {
    sf::FloatRect bounds = currentSprite.getLocalBounds();
    currentSprite.setOrigin(bounds.width / 2, bounds.height / 2);
}
void AnimationManager::setAnimation(const std::string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {

        if (currentAnimationName != name) {
            currentAnimationName = name;  
            currentSprite.setTexture(it->second.getTexture());  
        }
    } else {
        std::cerr << "Animation not found: " << name << std::endl;
    }
}

void AnimationManager::update(float deltaTime) {
    if (!currentAnimationName.empty()) {
        animations[currentAnimationName].update(deltaTime);
        currentSprite.setTexture(animations[currentAnimationName].getTexture());
    }
    
}

bool AnimationManager::isFinished(const std::string& name) {
    auto it = animations.find(name);
    return it->second.isFinished();
}

void AnimationManager::pauseAnimation(const std::string& name) {
    auto it = animations.find(name);
    it->second.pause();
}

void AnimationManager::playAnimation(const std::string& name) {
    auto it = animations.find(name);
    it->second.resume();
}



sf::Sprite& AnimationManager::getCurrentSprite() {
    return currentSprite; 
}

std::string AnimationManager::getCurrentAnimationName() const {
    return currentAnimationName;
}
