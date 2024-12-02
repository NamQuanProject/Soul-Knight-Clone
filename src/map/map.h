#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../utils/vec.h"

// Forward declaration of Knight class if needed

class Map {
public:
    Map(const std::string& backgroundTexturePath, float screenWidth, float screenHeight);

    // Method to initialize the map with the background texture
    void initialize();

    // Method to handle object placements (e.g., obstacles, items)
    void placeObjects();

    // Draw method to render the background and objects
    void draw(sf::RenderWindow& window);

    // Set the starting position of the player
    Vec getStartingPosition() const;

    // Collision detection method
    bool checkCollision(const sf::FloatRect& playerRect);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::FloatRect worldBounds;

    std::vector<sf::RectangleShape> obstacles;  // For holding obstacles
    Vec startingPosition;  // The initial position of the player
};

#endif
