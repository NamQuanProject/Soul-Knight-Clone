#include "application.h"
#include "menuState.h"
#include "gameState.h"
#include "pauseState.h"
#include <memory>

Application::Application()
    : window(sf::VideoMode(1024, 1024), "Soul Knight"), 
      deltaTime(0.0f) { 
    window.setFramerateLimit(2500);  // Set a reasonable framerate limit, 2500 might be too high
    stateManager = StateManager::Instance();
 
}

Application::~Application() {
    // No need to delete stateManager if it's a Singleton
    // stateManager will be cleaned up automatically when the application ends
}

void Application::run() {
    while (window.isOpen()) {
        processEvents();

        deltaTime = clock.getElapsedTime().asSeconds(); // Restart clock every frame to get accurate deltaTime

        update(deltaTime);
        render();
        if (deltaTime >= 0.1f) {
            clock.restart();
        }
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        stateManager->HandleEvent(event, window);
    }
}

void Application::update(float deltaTime) {
    stateManager->Update(deltaTime);
}

void Application::render() {
    window.clear();  // Clear the window

    stateManager->Render(window);  // Render the current state

    window.display();  // Display the rendered frame
}

void Application::changeState(StateType type) {
    stateManager->SwitchState(type);  // Switch to the requested state
}
