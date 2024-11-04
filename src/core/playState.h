#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"

class PlayState : public State {
public:
    void handleEvent(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    // Gameplay elements (e.g., player, enemies)
};

#endif // PLAYSTATE_H
