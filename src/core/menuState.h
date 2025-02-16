#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include "../manager/soundManager.h" 
#include "../entities/player/player.h" 
#include "stateManager.h"

class MenuState : public State {
public:
    MenuState();  
    ~MenuState(); 
    void Initialize() override;
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    
    static const int playerSelect = 0;
private:
    sf::Font font;
    sf::Text title;

    sf::Texture backgroundTexture;  
    sf::Sprite backgroundSprite;   

    sf::Texture playButtonTexture;       
    sf::Texture exitButtonTexture;      
    sf::RectangleShape playButton;       
    sf::RectangleShape exitButton; 

    SoundManager soundManager; 

    sf::Clock animationClock;  
};

