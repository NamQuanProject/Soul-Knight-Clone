#include "selectionState.h"
#include "../utils/vec.h"
#include "../manager/soundManager.h" 
#include <SFML/Graphics.hpp>
#include <iostream>



int SelectionState::playerSelect = 1; 
SelectionState::SelectionState() {
    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/arial/ARIAL.TTF")) {
        std::cerr << "Error loading font" << std::endl;
    }

    
    if (!backgroundTexture.loadFromFile("../resources/start/1.bmp")) {
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

        Animation wukongAnimation;
        std::vector<std::string> framePaths1 = {
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/wukong/1.bmp",
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/wukong/2.bmp",
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/wukong/3.bmp",
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/wukong/4.bmp"
        };
        wukongAnimation.loadAnimation(framePaths1);  // Load the idle animation
        animationManager.addAnimation("wukong", wukongAnimation);  // Add to animation manager

        Animation dragonAnimation;
        std::vector<std::string> framePaths2 = {
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/yulan/1.bmp",
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/yulan/2.bmp",
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/yulan/3.bmp",
            "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/selectionBackground/yulan/4.bmp"
        };
        dragonAnimation.loadAnimation(framePaths2);  // Load the idle animation
        animationManager.addAnimation("dragonwarrior", dragonAnimation);  // Add to animation manager

    }
    

    if (!playButtonTexture.loadFromFile("../resources/start/begin.png")) {
        std::cerr << "Error loading play button texture" << std::endl;
    }
    if (!exitButtonTexture.loadFromFile("../resources/start/flip_begin.png")) {
        std::cerr << "Error loading exit button texture" << std::endl;
    }
    if (!startButtonTexture.loadFromFile("../resources/start/start.png")) {
        std::cerr << "Error loading start button texture" << std::endl;
    }

    playButton.setSize(sf::Vector2f(150, 50)); 
    playButton.setTexture(&playButtonTexture); 
    playButton.setPosition(750, 700);
    
    title.setFont(font);
    title.setString("Select your character");
    title.setFillColor(sf::Color::White);
    title.setPosition(380, 100);


    startButton.setSize(sf::Vector2f(150, 50)); 
    startButton.setTexture(&startButtonTexture); 
    startButton.setPosition(450, 700);
    


    exitButton.setSize(sf::Vector2f(150, 50)); // Set the size of the exit button
    exitButton.setTexture(&exitButtonTexture); // Apply the texture
    exitButton.setPosition(150, 700); // Position the button
    std::cout << "MENU SETUP"  << std::endl;


    
    rectangleForSelectionPlayer.setSize(sf::Vector2f(300, 300));
    rectangleForSelectionPlayer.setFillColor(sf::Color::White);
    rectangleForSelectionPlayer.setOutlineColor(sf::Color::Red);
    rectangleForSelectionPlayer.setOutlineThickness(5);
    rectangleForSelectionPlayer.setPosition(650, 200);

    animationManager.setAnimation("wukong");
    animationManager.setOrigin();
    soundManager.playMusic("wukong");

}

SelectionState::~SelectionState() {
    // soundManager.stopMusic(); // Ensure music stops when exiting
}

void SelectionState::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    // Handle input (e.g., mouse clicks or key presses)
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (playButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
               
                playerSelect = 1;
                animationManager.setAnimation("wukong");
                soundManager.playMusic("wukong");
            }
            else if (exitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                std::cout << "Exit button clicked. Exiting the program." << std::endl;
                playerSelect = 2;
                animationManager.setAnimation("dragonwarrior");
            }
            if (startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                std::cout << "Play button clicked." << std::endl;
                StateManager::Instance()->SwitchState(StateType::GAME_STATE);
            }
        }
    }
}

void SelectionState::update(float deltaTime) {
    animationManager.update(deltaTime); 
}

void SelectionState::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    window.draw(title);
    // window.draw(title);
    window.draw(playButton);
    window.draw(exitButton);
    window.draw(startButton);
    // window.draw(rectangleForSelectionPlayer);
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sprite.setPosition(530, 400);
    window.draw(sprite);
    
}


void SelectionState::Initialize() {
    std::cout << "Initialize" << std::endl;
}