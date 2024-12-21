#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>  
#include "state.h"
#include "stateManager.h"

class Application {
public:
    Application();  
    ~Application(); 

    void run();  
    void Initialize();
    void processEvents();  
    void update(float deltaTime);  
    void render();  
    void changeState(StateType type);  

private:
    sf::RenderWindow window; 
    float deltaTime; 
    sf::Clock clock;  
    StateManager* stateManager;  
};

#endif // APPLICATION_H
