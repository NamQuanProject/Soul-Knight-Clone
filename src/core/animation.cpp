#include "animation.h"

Animation::Animation()
    : frameTime(0.1f), elapsedTime(0), currentFrame(0) {
}

void Animation::addFrame(const sf::IntRect& frameRect) {
    frames.push_back(frameRect);
}

void Animation::setFrameTime(float time) {
    frameTime = time;
}

void Animation::update(float deltaTime) {
    elapsedTime += deltaTime;
    if (elapsedTime >= frameTime) {
        currentFrame = (currentFrame + 1) % frames.size();
        elapsedTime = 0; // Reset elapsed time
    }
}

void Animation::reset() {
    currentFrame = 0;
    elapsedTime = 0;
}

sf::IntRect Animation::getCurrentFrame() const {
    if (frames.empty()) {
        throw std::runtime_error("No frames available");
    }
    return frames[currentFrame];
}
