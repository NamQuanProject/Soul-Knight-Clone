#include "core/application.h"
#include "entities/player/heroes/knight.h"
#include "utils/vec.h"
#include "manager/soundManager.h"
#include "manager/camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Knight Test");
    
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/1-1.bmp")) {
        std::cerr << "Error: Could not load background image!" << std::endl;
        return -1;
    }

    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromImage(image)) {
        std::cerr << "Error: Could not load texture from image!" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    sf::FloatRect worldBounds(0, 0, backgroundTexture.getSize().x, backgroundTexture.getSize().y);

    Camera camera(1000, 700);
    camera.setZoom(1);
    camera.setWorldBounds(worldBounds);

    Knight knight1;

    sf::Clock clock;
    Vec knightPosition(105, 183);

    // Room bounds (x, y, width, height)
    float roomLeft = 16;
    float roomTop = 98;
    float roomRight = 192;
    float roomBottom = 273;
    SoundManager soundManager;
    soundManager.playMusic("background");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    knightPosition.x -= 75 * 0.1f;
                    knight1.runLeft();
                } else if (event.key.code == sf::Keyboard::Right) {
                    knightPosition.x += 75 * 0.1f;
                    knight1.runRight();
                } else if (event.key.code == sf::Keyboard::Up) {
                    knightPosition.y -= 75 * 0.1f;
                } else if (event.key.code == sf::Keyboard::Down) {
                    knightPosition.y += 75 * 0.1f;
                } else {
                    knight1.standRight();
                }
            } else if (sf::Event::KeyReleased) {
                knight1.standRight();
            }
        }

        // Enforce room boundaries
        if (knightPosition.x < roomLeft + 5) {
            knightPosition.x = roomLeft + 5;
        }
        if (knightPosition.x > roomRight - 5) {
            if ((knightPosition.y >= 151 && knightPosition.y <= 219) == false) {
                knightPosition.x = roomRight - 5;
            }
            
        }
        if (knightPosition.y < roomTop + 5) {
            knightPosition.y = roomTop + 5 ;
        }
        if (knightPosition.y > roomBottom - 5) {
            knightPosition.y = roomBottom - 5 ;
        }

        sf::Vector2f knightPos(knightPosition.x, knightPosition.y);
        camera.update(knightPos);

        window.clear();
        camera.applyView(window);
        window.draw(backgroundSprite);

        float deltaTime = clock.getElapsedTime().asSeconds();
        if (deltaTime > 0.1f) {
            knight1.Update(deltaTime);
            clock.restart();
        }
        knight1.SetPosition(knightPosition);
        knight1.Render(window);

        window.display();
    }

    return 0;
}
