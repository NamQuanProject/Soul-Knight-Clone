#include "gameState.h"

void GameState::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed) {
            window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "UP RIGHT" << std::endl;        



                    
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "UP LEFT" << std::endl;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "DOWN RIGHT" << std::endl;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "DOWN LEFT"<< std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        std::cout << "UP" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        std::cout << "DOWN" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "LEFT" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "RIGHT" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        std::cout << "K" << std::endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        std::cout << "L" << std::endl;
    }
}


void GameState::Initialize() {
    // objectManager->Start();
    // projectilePool->Initialize();
    // monsterPool->Initialize();
    // dropPoll->Initialize();
    // stageManager->Initiliaze();
    // uiManager.Start();
}
GameState::GameState() {

}




void GameState::update(float deltaTime) {
   
}

void GameState::render(sf::RenderWindow& window) {
    // Render gameplay elements
}
