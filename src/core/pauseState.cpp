#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "pauseState.h"


PauseState::PauseState() {
    Initialize();
}

PauseState::~PauseState() {
    // Cleanup
}


void PauseState::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    
    
}

void PauseState::update(float deltaTime) {
    std::cout << "UPDATE" << std::endl;
}

void PauseState::render(sf::RenderWindow& window) {
    

    window.draw(resumeButton);
    window.draw(quitButton);
    window.draw(resumeText);
    window.draw(quitText);

}

void PauseState::Initialize() {
    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/ARIAL.TTF")) { 
        std::cerr << "Error loading font\n";
        return;
    }

    // Setup Resume Button and Text
    resumeButton.setSize(sf::Vector2f(200, 50));
    resumeButton.setFillColor(sf::Color::Green);
    resumeButton.setPosition(300, 200);

    resumeText.setFont(font);
    resumeText.setString("Resume");
    resumeText.setCharacterSize(24);
    resumeText.setFillColor(sf::Color::White);
    resumeText.setPosition(350, 210);

    // Setup Quit Button and Text
    quitButton.setSize(sf::Vector2f(200, 50));
    quitButton.setFillColor(sf::Color::Red);
    quitButton.setPosition(300, 300);

    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(24);
    quitText.setFillColor(sf::Color::White);
    quitText.setPosition(375, 310);
}

