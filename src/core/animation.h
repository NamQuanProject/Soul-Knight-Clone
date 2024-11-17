#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    Animation();  // Constructor to initialize the animation

    // Add a frame to the animation
    void addFrame(const sf::IntRect& frameRect);

    // Set the time duration for each frame
    void setFrameTime(float time);

    // Update the animation based on elapsed time
    void update(float deltaTime);

    // Reset the animation to the first frame
    void reset();

    // Get the current frame's rectangle to display
    sf::IntRect getCurrentFrame() const;

    // Check if the animation is looping
    bool isLooping() const;

    // Check if the animation is finished (non-looping)
    bool isFinished() const;

    // Set whether the animation should loop
    void setLooping(bool loop);

    // Set the speed of the animation (frame time)
    void setFrameSpeed(float speed);

    // Draw the current frame on the screen
    void draw(sf::RenderWindow& window, sf::Sprite& sprite);

private:
    std::vector<sf::IntRect> frames;  // List of frames (each frame is a sub-rectangle)
    float frameTime;                  // Time per frame (frame speed)
    float elapsedTime;                // Accumulated time to track frame changes
    size_t currentFrame;              // Index of the current frame
    bool loop;                        // Whether the animation loops
};

#endif // ANIMATION_H
