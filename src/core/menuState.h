#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
#include <SFML/Graphics.hpp>
#include "../manager/soundManager.h" 
#include "../entities/player/player.h" 

class MenuState : public State {
public:
    MenuState();  
    ~MenuState(); 

    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

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
};

#endif // MENUSTATE_H
