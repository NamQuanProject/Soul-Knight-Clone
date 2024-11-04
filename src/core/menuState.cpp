#include "menuState.h"
#include "../manager/soundManager.h" // Include the SoundManager
#include <SFML/Graphics.hpp>
#include <iostream>

// Create a static instance of SoundManager
static SoundManager soundManager;

MenuState::MenuState() {
    // Load the font
    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/arial/ARIAL.TTF")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Load the background texture
    if (!backgroundTexture.loadFromFile("../resources/start/first_page.bmp")) {
        std::cerr << "Error loading background image" << std::endl;
    } else {
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(0, 0); // Ensure the background is positioned correctly
    }

    soundManager.playMusic("background"); 


    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(30);
    playButton.setPosition(300, 250);
    playButton.setFillColor(sf::Color::Green); // Set play button color

    // Set up the exit button text
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(30);
    exitButton.setPosition(300, 350);
    exitButton.setFillColor(sf::Color::Red); // Set exit button color
}

MenuState::~MenuState() {
    soundManager.stopMusic(); // Ensure music stops when exiting
}

void MenuState::handleEvent(const sf::Event& event) {
    // Handle input (e.g., mouse clicks or key presses)
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            // Check if play button is clicked
            if (playButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                // Start the game or change to the game state
                std::cout << "Play button clicked." << std::endl;
                // TODO: Implement game state change here
            }
            // Check if exit button is clicked
            else if (exitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                // Exit the application
                std::cout << "Exit button clicked." << std::endl;
                // You might want to call a function to exit the game
                // For example: window.close();
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
