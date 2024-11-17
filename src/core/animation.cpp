#include "animation.h"

Animation::Animation()
    : frameTime(0.1f), elapsedTime(0.0f), currentFrame(0), loop(true) {}

void Animation::addFrame(const sf::IntRect& frameRect) {
    frames.push_back(frameRect);  // Add a frame to the animation
}

void Animation::setFrameTime(float time) {
    frameTime = time;  // Set the duration for each frame
}

void Animation::update(float deltaTime) {
    elapsedTime += deltaTime;  // Accumulate time

    if (elapsedTime >= frameTime) {
        elapsedTime -= frameTime;  // Reset the time counter
        currentFrame++;            // Move to the next frame

        if (currentFrame >= frames.size()) {
            if (loop) {
                currentFrame = 0;  // Loop back to the first frame
            } else {
                currentFrame = frames.size() - 1;  // Stay on the last frame if not looping
            }
        }
    }
}

void Animation::reset() {
    currentFrame = 0;  // Reset to the first frame
    elapsedTime = 0.0f; // Reset elapsed time
}

sf::IntRect Animation::getCurrentFrame() const {
    return frames[currentFrame];  // Get the current frame's rectangle
}

bool Animation::isLooping() const {
    return loop;  // Return whether the animation is looping
}

bool Animation::isFinished() const {
    return !loop && currentFrame == frames.size() - 1;  // Check if animation is finished
}

void Animation::setLooping(bool loopFlag) {
    loop = loopFlag;  // Set whether the animation should loop
}

void Animation::setFrameSpeed(float speed) {
    frameTime = speed;  // Adjust the speed of the animation (time per frame)
}

void Animation::draw(sf::RenderWindow& window, sf::Sprite& sprite)  {
    sprite.setTextureRect(getCurrentFrame());  // Set the texture rectangle for the current frame
    window.draw(sprite);  // Draw the sprite with the current frame
}
