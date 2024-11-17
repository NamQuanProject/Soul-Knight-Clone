#include "animation.h"
#include <iostream>

Animation::Animation()
    : frameTime(0.1f), elapsedTime(0.f), currentFrame(0), loop(true) {}

void Animation::addFrame(const sf::IntRect& frameRect) {
    frames.push_back(frameRect);
}

void Animation::setFrameTime(float time) {
    frameTime = time;
}

void Animation::update(float deltaTime) {
    elapsedTime += deltaTime;  // Add the time that has passed to the total elapsed time

    if (elapsedTime >= frameTime && !frames.empty()) {  // If enough time has passed to move to the next frame
        elapsedTime -= frameTime;  // Subtract the frame time from elapsed time

        // Move to the next frame
        currentFrame = (currentFrame + 1) % frames.size();  // Cycle through frames, wrap around if necessary

        // If the animation doesn't loop, stop at the last frame
        if (!loop && currentFrame == 0) {
            currentFrame = frames.size() - 1;  // Stop at the last frame if not looping
        }
    }
}

sf::Texture& Animation::getTexture() {
    return currentTexture;
}

sf::IntRect Animation::getCurrentFrame() const {
    if (frames.empty()) {
        return sf::IntRect();  // Return an empty rectangle if no frames
    }
    return frames[currentFrame];  // Return the current frame as an IntRect
}

bool Animation::isFinished() const {
    return !loop && currentFrame == frames.size() - 1;  // Check if the animation has finished (non-looping)
}

void Animation::setFrameSpeed(float speed) {
    frameTime = speed;
}

bool Animation::loadAnimation(const std::vector<std::string>& framePaths) {
    frames.clear();
    
    for (const std::string& path : framePaths) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            std::cerr << "Failed to load texture from " << path << std::endl;
            return false;
        }


        sf::IntRect frameRect(0, 0, texture.getSize().x, texture.getSize().y);  // Define the frame as an IntRect
        frames.push_back(frameRect);  // Add the frame to the frames vector
    }
    return true;
}

void Animation::reset() {
    
}