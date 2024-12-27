#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include "../manager/soundManager.h" 
#include "../manager/animationManager.h" 
#include "../entities/player/player.h" 
#include "stateManager.h"


class SelectionState : public State {
public:
    SelectionState();  
    ~SelectionState(); 
    void Initialize() override;
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    static int playerSelect;
    

private:
    sf::Font font;
    sf::Text title;

    sf::Texture backgroundTexture;  
    sf::Sprite backgroundSprite;   

    sf::Texture playButtonTexture;   
    sf::Texture startButtonTexture;         
    sf::Texture exitButtonTexture;      
    sf::RectangleShape playButton;       
    sf::RectangleShape exitButton; 
    sf::RectangleShape startButton;       


    sf::RectangleShape rectangleForSelectionPlayer;          
    // sf::RectangleShape rectangleSpriteForSelectionPlayer;    

    SoundManager soundManager; 
    AnimationManager animationManager;
    sf::Clock animationClock;  
    int index = 0;
    
};

