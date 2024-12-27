#include "menuState.h"
#include "../utils/vec.h"
#include "../manager/soundManager.h" 
#include <SFML/Graphics.hpp>
#include <iostream>


MenuState::MenuState() {
    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/arial/ARIAL.TTF")) {
        std::cerr << "Error loading font" << std::endl;
    }
    if (!backgroundTexture.loadFromFile("../resources/start/first_page.bmp")) {
        std::cerr << "Error loading background image" << std::endl;
    } else {
        backgroundSprite.setTexture(backgroundTexture);

        const float windowWidth = 1100;
        const float windowHeight = 800; 

       
        backgroundSprite.setScale(
            windowWidth / backgroundTexture.getSize().x,
            windowHeight / backgroundTexture.getSize().y
        );

        backgroundSprite.setPosition(0, 0);
    }
    soundManager.playMusic("background");

    if (!playButtonTexture.loadFromFile("../resources/start/begin.png")) {
        std::cerr << "Error loading play button texture" << std::endl;
    }
    if (!exitButtonTexture.loadFromFile("../resources/start/exit.png")) {
        std::cerr << "Error loading exit button texture" << std::endl;
    }

    playButton.setSize(sf::Vector2f(150, 50)); 
    playButton.setTexture(&playButtonTexture); 
    playButton.setPosition(50, 700);

    exitButton.setSize(sf::Vector2f(150, 50)); // Set the size of the exit button
    exitButton.setTexture(&exitButtonTexture); // Apply the texture
    exitButton.setPosition(300, 700); // Position the button
    std::cout << "MENU SETUP"  << std::endl;
}

MenuState::~MenuState() {
    // soundManager.stopMusic(); // Ensure music stops when exiting
}

void MenuState::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    // Handle input (e.g., mouse clicks or key presses)
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (playButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                std::cout << "Play button clicked." << std::endl;
                StateManager::Instance()->SwitchState(StateType::SELECTION_STATE);
            }
            else if (exitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                std::cout << "Exit button clicked. Exiting the program." << std::endl;
                window.close();
            }
        }
    }
}

void MenuState::update(float deltaTime) {
}

void MenuState::render(sf::RenderWindow& window) {
    window.setView(window.getDefaultView());
    window.draw(backgroundSprite);
    window.draw(title);
    window.draw(playButton);
    window.draw(exitButton);

}


void MenuState::Initialize() {
    std::cout << "Initialize" << std::endl;
}