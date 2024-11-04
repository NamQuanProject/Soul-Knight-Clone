#include "menuState.h"
#include "../manager/soundManager.h" // Include the SoundManager
#include <SFML/Graphics.hpp>
#include <iostream>

// Create a static instance of SoundManager
static SoundManager soundManager;

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

    // Set up exit button rectangle
    exitButton.setSize(sf::Vector2f(150, 50)); // Set the size of the exit button
    exitButton.setTexture(&exitButtonTexture); // Apply the texture
    exitButton.setPosition(300, 700); // Position the button

}

MenuState::~MenuState() {
    soundManager.stopMusic(); // Ensure music stops when exiting
}

void MenuState::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    // Handle input (e.g., mouse clicks or key presses)
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (playButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                std::cout << "Play button clicked." << std::endl;
            }
            else if (exitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                std::cout << "Exit button clicked. Exiting the program." << std::endl;
                window.close();
            }
        }
    }
}

void MenuState::update() {
    // Update logic if necessary
}

void MenuState::render(sf::RenderWindow& window) {
    // Draw the background
    window.draw(backgroundSprite);

    // Draw the text elements
    window.draw(title);
    window.draw(playButton);
    window.draw(exitButton);
}
