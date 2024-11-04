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
    void update();
    void render();
    void changeState(std::unique_ptr<State> newState); 

    sf::RenderWindow window;
    std::unique_ptr<State> currentState;
};

#endif
