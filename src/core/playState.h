#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "state.h"

class PlayState : public State {
public:
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:    
    
};

#endif // PLAYSTATE_H
