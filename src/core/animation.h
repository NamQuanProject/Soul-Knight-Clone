#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animation {
public:
    Animation();

    void addFrame(const sf::Texture& texture);

    void setSpeed(float time);

    void update(float deltaTime);

    void reset();

    bool isLooping() const;

    bool isFinished() const;

    void setLooping(bool loop);
    void pause();
    void resume();
    void setFrameSpeed(float speed);

    sf::Texture& getTexture();
    bool loadAnimation(const std::vector<std::string>& framePaths);
    sf::Texture makeTransparent(const sf::Texture& texture, const sf::Color& transparentColor);

private:
    std::vector<sf::Texture> frames;   
    float frameTime;                  
    float elapsedTime;                
    int currentFrame;                  
    bool loop;                        
    bool isPaused = false;
    sf::Texture currentTexture;     


};

#endif // ANIMATION_H
