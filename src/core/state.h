#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

enum class StateType {
    MENU_STATE,
    GAME_STATE,
    PAUSE_STATE,
};


class State {
public:
    virtual ~State() {}
    virtual void Initialize() = 0;
    virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif // STATE_H
