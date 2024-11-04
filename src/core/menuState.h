#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
#include <SFML/Graphics.hpp>
#include "../manager/soundManager.h" 


class MenuState : public State {
public:
    MenuState();  
    ~MenuState(); 

    void handleEvent(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    // Add private members for menu components
    sf::Font font;
    sf::Text title;
    sf::Text playButton;
    sf::Text exitButton;

    sf::Texture backgroundTexture;  
    sf::Sprite backgroundSprite;     
    SoundManager soundManager; 
};

#endif // MENUSTATE_H
