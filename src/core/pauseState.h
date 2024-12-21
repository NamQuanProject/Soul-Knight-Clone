#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "state.h"
#include <SFML/Graphics.hpp>

class PauseState : public State {
public:
    PauseState();
    ~PauseState();
    void Initialize() override;
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    // Pause menu elements
    sf::Font font;  // Font for text
    sf::Text resumeText;  // Text for the resume button
    sf::Text quitText;  // Text for the quit button
    sf::RectangleShape resumeButton;  // Rectangle for the resume button
    sf::RectangleShape quitButton;  // Rectangle for the quit button
};

#endif // PAUSESTATE_H
