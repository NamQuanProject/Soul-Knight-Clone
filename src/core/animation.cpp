#include "animation.h"
#include <iostream>

Animation::Animation()
    : frameTime(0.1f), elapsedTime(0.f), currentFrame(0), loop(true) {}

void Animation::addFrame(const sf::Texture& texture) {
    frames.push_back(texture);  // Add the texture as a frame to the animation
}

void Animation::setSpeed(float time) {
    frameTime = time;  // Set the time per frame (frame speed)
}

void Animation::update(float deltaTime) {
    currentFrame = (currentFrame + 1) % frames.size(); 
   
    currentTexture = frames[currentFrame];  // Set the current texture/frame
}

void Animation::reset() {
    currentFrame = 0;  // Reset animation to the first frame
    elapsedTime = 0.f;  // Reset elapsed time
}

bool Animation::isLooping() const {
    return loop;  // Return whether the animation loops
}

bool Animation::isFinished() const {
    return !loop && currentFrame == frames.size() - 1;  // Check if the animation has finished (non-looping)
}

void Animation::setLooping(bool shouldLoop) {
    loop = shouldLoop;  // Set whether the animation should loop
}

void Animation::setFrameSpeed(float speed) {
    frameTime = speed;  // Set the frame speed (time per frame)
}

sf::Texture& Animation::getTexture() {
    return frames[currentFrame];  // Return the current texture for the frame
}

bool Animation::loadAnimation(const std::vector<std::string>& framePaths) {
    frames.clear();  // Clear any existing frames
    
    for (const std::string& path : framePaths) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            std::cout << "Failed to load texture from " << path << std::endl;
            return false;  // If a texture fails to load, return false
        }
        addFrame(makeTransparent(texture, sf::Color::White));  // Make transparent and add to frames
    }

    return true;  // Return true if all frames are successfully loaded
}

sf::Texture Animation::makeTransparent(const sf::Texture& texture, const sf::Color& transparentColor) {
    sf::Image image = texture.copyToImage();  // Copy texture to image for manipulation

    // Loop through each pixel and change the transparentColor to transparent
    unsigned int width = image.getSize().x;
    unsigned int height = image.getSize().y;

    for (unsigned int x = 0; x < width; ++x) {
        for (unsigned int y = 0; y < height; ++y) {
            if (image.getPixel(x, y) == transparentColor) {
                image.setPixel(x, y, sf::Color(0, 0, 0, 0));  // Set the transparent color to fully transparent
            }
        }
    }

    // Create a new texture from the modified image and return it
    sf::Texture newTexture;
    newTexture.loadFromImage(image);
    return newTexture;
}
