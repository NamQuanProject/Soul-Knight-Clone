#pragma once
#include <SFML/Graphics.hpp>
#include "state.h"

class StateManager {
public:
    StateManager();
    static StateManager* Instance();
    void Initialize();
    void Update(float deltaTime);
    void Render(sf::RenderWindow& window);
    void HandleEvent(const sf::Event& event, sf::RenderWindow& window);
    void SwitchState(StateType type);
    State* GetCurrentState();
    ~StateManager();

private:
    State* currentState;
    static StateManager* instance;
};
