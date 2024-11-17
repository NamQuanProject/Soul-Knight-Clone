#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animation {
public:
    Animation();  
    void addFrame(const sf::IntRect& frameRect);  // Add frame rect
    void setFrameTime(float time);  // Set time per frame
    void update(float deltaTime);  // Update the animation based on deltaTime
    void reset();  // Reset the animation to the first frame
    sf::IntRect getCurrentFrame() const;  // Get the current frame as an sf::IntRect
    bool isLooping() const;  // Check if the animation is looping
    bool isFinished() const;  // Check if the animation has finished
    void setLooping(bool loop);  // Set looping behavior
    void setFrameSpeed(float speed);  // Set the frame speed
    sf::Texture& getTexture();
    bool loadAnimation(const std::vector<std::string>& framePaths);  // Load the animation frames from file paths

private:
    std::vector<sf::IntRect> frames;  // Stores the frames for the animation
    float frameTime;  // Time to display each frame
    float elapsedTime;  // Accumulated time for frame switching
    int currentFrame;  // The current frame index
    bool loop;  // Whether the animation loops
    sf::Texture currentTexture;  // Texture for the current frame
};

#endif // ANIMATION_H
