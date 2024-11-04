#include "application.h"
#include "menuState.h"
#include <memory>

Application::Application()
    : window(sf::VideoMode(800, 600), "Soul Knight"), currentState(std::make_unique<MenuState>()) {
}

void Application::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        currentState->handleEvent(event);
    }
}

void Application::update() {
    currentState->update();
}

void Application::render() {
    window.clear();
    currentState->render(window);
    window.display();
}

void Application::changeState(std::unique_ptr<State> newState) {
    currentState = std::move(newState);
}
