#include "application.h"
#include "menuState.h"
#include "gameState.h"
#include "pauseState.h"
#include <memory>

Application::Application()
    : window(sf::VideoMode(1024, 1024), "Soul Knight"), 
      currentState(std::make_unique<GameState>()), // Initialize with MenuState
      deltaTime(0.0f) { // Initialize deltaTime
}

void Application::run() {
    while (window.isOpen()) {
        processEvents();

        // Update deltaTime
        deltaTime = clock.restart().asSeconds();

        update(deltaTime);
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Delegate event handling to the current state
        currentState->handleEvent(event, window);
    }
}

void Application::update(float deltaTime) {
    // Delegate update logic to the current state
    currentState->update(deltaTime);
}

void Application::render() {
    window.clear();

    // Delegate rendering logic to the current state
    currentState->render(window);

    window.display();
}

void Application::changeState(StateType type) {
    // Switch to the appropriate state
    switch (type) {
        case StateType::MENU_STATE:
            currentState = std::make_unique<MenuState>();
            break;
        case StateType::GAME_STATE:
            currentState = std::make_unique<GameState>();
            break;
        case StateType::PAUSE_STATE:
            currentState = std::make_unique<PauseState>();
            break;
        default:
            throw std::runtime_error("Unknown state type!"); // Error handling for invalid state types
    }
}
