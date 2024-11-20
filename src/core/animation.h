#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animation {
public:
    // Constructor
    Animation();

    // Add a new frame to the animation
    void addFrame(const sf::Texture& texture);

    // Set the time between frames
    void setSpeed(float time);

    // Update the animation based on deltaTime
    void update(float deltaTime);

    // Reset the animation to the first frame
    void reset();

    // Check if the animation is looping
    bool isLooping() const;

    // Check if the animation has finished
    bool isFinished() const;

    // Set the looping behavior of the animation
    void setLooping(bool loop);

    // Set the frame speed (time per frame)
    void setFrameSpeed(float speed);

    // Get the texture of the current frame
    sf::Texture& getTexture();

    // Load animation frames from file paths
    bool loadAnimation(const std::vector<std::string>& framePaths);

    // Make a texture transparent by changing a specified color to transparent
    sf::Texture makeTransparent(const sf::Texture& texture, const sf::Color& transparentColor);

private:
    std::vector<sf::Texture> frames;   // Stores the animation frames
    float frameTime;                   // Time per frame (speed of animation)
    float elapsedTime;                 // Total time passed
    int currentFrame;                  // The index of the current frame
    bool loop;                         // Whether the animation loops
    sf::Texture currentTexture;        // The current frame's texture
};

#endif // ANIMATION_H
