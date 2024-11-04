#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    Animation();
    void addFrame(const sf::IntRect& frameRect); // Add a frame
    void setFrameTime(float time); // Set duration for each frame
    void update(float deltaTime); // Update the animation based on time
    void reset(); // Reset the animation to the first frame
    sf::IntRect getCurrentFrame() const; // Get the current frame rectangle

private:
    std::vector<sf::IntRect> frames; // Frames of the animation
    float frameTime; // Time each frame is displayed
    float elapsedTime; // Accumulated time
    size_t currentFrame; // Index of the current frame
};

#endif // ANIMATION_H
