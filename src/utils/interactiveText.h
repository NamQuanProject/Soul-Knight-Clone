#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "point.h"

class InteractiveText {
public:
    enum Rarity {
        COMMON = sf::Color(255, 255, 255),   // white
        UNCOMMON = sf::Color(0, 200, 0),     // green
        RARE = sf::Color(0, 100, 255),       // blue
        EPIC = sf::Color(146, 38, 213),      // purple
        LEGENDARY = sf::Color(254, 193, 64), // orange
        MYTHIC = sf::Color(255, 0, 0)        // red
    };

    InteractiveText(std::string displayText, Rarity rarity = Rarity::COMMON, int verticalOffset = -25);
    void Render(Point screenPoint);
    void Interactive();

private:
    
    std::string displayText;
    COLORREF color;
    bool isInteractive;
    Point displayOffset;
};