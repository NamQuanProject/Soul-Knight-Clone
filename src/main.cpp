#include "core/application.h"
#include "entities/player/heroes/knight.h"
#include "utils/vec.h"
#include "manager/soundManager.h"
#include "manager/camera.h"
#include <SFML/Graphics.hpp>
#include "entities/projectile/bullet/badPistolBullet.h"
#include "entities/monster/floor_1/goblin_shaman/goblinShaman.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Knight Test");


    GoblinShaman goblin_shaman1;
    goblin_shaman1.SetPosition(Vec(200,200));

    

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
    camera.setWorldBounds(worldBounds);

    Knight knight1;

    sf::Clock clock;
    Vec knightPosition(105, 183);
    
    float roomLeft = 16;
    float roomTop = 98;
    float roomRight = 192;
    float roomBottom = 273;

    BadPistolBullet bullet;
    bullet.LoadResources();

    bool bulletActive = false; // Flag to check if the bullet is active

    // Add a new variable to track the initial position of the bullet
sf::Vector2f bulletInitialPosition;
const float bulletMaxDistance = 500.0f; // Set the maximum distance the bullet can travel

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
                if (knight1.CheckFace() == Knight::RIGHT) {
                    knight1.runRight();
                } else {
                    knight1.runLeft();
                }
                knightPosition.y -= 75 * 0.1f;
            } else if (event.key.code == sf::Keyboard::Down) {
                if (knight1.CheckFace() == Knight::RIGHT) {
                    knight1.runRight();
                } else {
                    knight1.runLeft();
                }
                knightPosition.y += 75 * 0.1f;
            } else if (event.key.code == sf::Keyboard::Space) { 
                // Fire the bullet when SPACE is pressed
                if (!bulletActive) { // Only create the bullet if it's inactive
                    bullet.SetPosition(sf::Vector2f(knightPosition.x, knightPosition.y)); // Set bullet at knight's position
                    bullet.SetSpeed(sf::Vector2f(25.f, 0.f)); // Set bullet speed
                    bulletInitialPosition = bullet.GetPosition(); // Save the initial position
                    bulletActive = true; // Activate the bullet
                }
            } else {
                knight1.standRight();
            }
        } else if (sf::Event::KeyReleased) {
            if (knight1.CheckFace() == Knight::RIGHT) {
                knight1.standRight();
            } else {
                knight1.standLeft();
            }
        }
    }

    // Ensure the knight stays within room boundaries
    if (knightPosition.x < roomLeft + 5) {
        knightPosition.x = roomLeft + 5;
    }
    if (knightPosition.x > roomRight - 5) {
        if ((knightPosition.y >= 151 && knightPosition.y <= 219) == false) {
            knightPosition.x = roomRight - 5;
        }
    }
    if (knightPosition.y < roomTop + 5) {
        knightPosition.y = roomTop + 5;
    }
    if (knightPosition.y > roomBottom - 5) {
        knightPosition.y = roomBottom - 5;
    }

    sf::Vector2f knightPos(knightPosition.x, knightPosition.y);
    camera.update(knightPos);

    window.clear();
    camera.applyView(window);
    window.draw(backgroundSprite);

    float deltaTime = clock.getElapsedTime().asSeconds();
    if (deltaTime > 0.09f) {
        if (bulletActive) {
            bullet.Update(deltaTime);

            // Deactivate the bullet if it travels beyond the maximum distance
            sf::Vector2f bulletPos = bullet.GetPosition();
            float distanceTraveled = std::sqrt(
                std::pow(bulletPos.x - bulletInitialPosition.x, 2) + 
                std::pow(bulletPos.y - bulletInitialPosition.y, 2)
            );
            if (distanceTraveled > bulletMaxDistance) {
                bulletActive = false;
            }
        }
    }
    if (deltaTime > 0.1f) {
        knight1.Update(deltaTime);
        goblin_shaman1.Update(deltaTime);
        clock.restart();
    }

    knight1.SetPosition(knightPosition);
    knight1.Render(window);
    goblin_shaman1.Render(window);

    // Render bullet only if it's active
    if (bulletActive) {
        bullet.Render(window);
    }

    window.display();
}

}