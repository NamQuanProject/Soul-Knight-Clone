#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>  
#include "state.h"

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void changeState(StateType type);

    sf::RenderWindow window;
    std::unique_ptr<State> currentState;
    float deltaTime;
    sf::Clock clock;

};

#endif
