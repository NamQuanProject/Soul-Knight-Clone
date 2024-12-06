#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State {
public:
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:    
    
};

#endif // GAMESTATE_H
