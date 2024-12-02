#include "map.h"
#include <iostream>

Map::Map(const std::string& backgroundTexturePath, float screenWidth, float screenHeight)
    : startingPosition(400, 300) {  // Default starting position at (400, 300)
    // Load background texture
    if (!backgroundTexture.loadFromFile(backgroundTexturePath)) {
        std::cerr << "Error: Could not load background texture!" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);

    // Set world bounds based on background size
    worldBounds = sf::FloatRect(0, 0, backgroundTexture.getSize().x, backgroundTexture.getSize().y);
    // backgroundSprite.setScale(screenWidth / backgroundTexture.getSize().x, screenHeight / backgroundTexture.getSize().y);
}

void Map::initialize() {
    placeObjects();
}

void Map::placeObjects() {
    sf::RectangleShape obstacle(sf::Vector2f(50.f, 50.f)); 
    obstacle.setFillColor(sf::Color::Red);
    obstacle.setPosition(1024.f, 1024.f);
    obstacles.push_back(obstacle);  

    // Add more obstacles or items as needed...
}

void Map::draw(sf::RenderWindow& window) {
    // Draw the background first
    window.draw(backgroundSprite);

    // Draw obstacles or other objects
    for (const auto& obstacle : obstacles) {
        window.draw(obstacle);
    }
}

Vec Map::getStartingPosition() const {
    return startingPosition;
}

bool Map::checkCollision(const sf::FloatRect& playerRect) {
    // Check collision with obstacles
    for (const auto& obstacle : obstacles) {
        if (playerRect.intersects(obstacle.getGlobalBounds())) {
            return true;  // Collision detected
        }
    }
    return false;  // No collision
}
