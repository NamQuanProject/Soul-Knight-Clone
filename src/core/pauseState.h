#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "state.h"

class PauseState : public State {
public:
    void handleEvent(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    // Pause menu elements
};

#endif // PAUSESTATE_H