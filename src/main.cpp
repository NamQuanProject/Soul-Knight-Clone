#include "core/application.h"
#include "entities/player/heroes/knight.h"
#include "utils/vec.h"
#include "manager/soundManager.h"
#include "manager/camera.h"
#include <SFML/Graphics.hpp>
#include "entities/projectile/bullet/badPistolBullet.h"
#include "entities/monster/floor_1/goblin_shaman/goblinShaman.h"
#include <iostream>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Knight Test");

    GoblinShaman goblin_shaman1;
    goblin_shaman1.SetPosition(Vec(200, 200));

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

    bool bulletActive = false;
    sf::Vector2f bulletInitialPosition;
    const float bulletMaxDistance = 500.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            knightPosition.x += 0.5 * 0.1f;  
            knightPosition.y -= 0.5 * 0.1f; 
            knight1.runRight();           
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            
            knightPosition.x -= 1 * 0.1f;  
            knightPosition.y -= 1 * 0.1f; 
            knight1.runLeft();            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            knightPosition.x += 1 * 0.1f;  
            knightPosition.y += 1 * 0.1f; 
            knight1.runRight();            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            knightPosition.x -= 1 * 0.1f;
            knightPosition.y += 1 * 0.1f;  
            knight1.runLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            knightPosition.y -= 1 * 0.1f; 
            if (knight1.CheckFace() == Knight::RIGHT) {
                knight1.runRight();        
            } else {
                knight1.runLeft();         
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            knightPosition.y += 1 * 0.1f;  
            if (knight1.CheckFace() == Knight::RIGHT) {
                knight1.runRight();        
            } else {
                knight1.runLeft();        
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            knightPosition.x -= 1 * 0.1f; 
            knight1.runLeft();            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            knightPosition.x += 1 * 0.1f;  
            knight1.runRight();            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!bulletActive) {
                bullet.SetPosition(sf::Vector2f(knightPosition.x, knightPosition.y));
                bullet.SetSpeed(sf::Vector2f(25.f, 0.f));
                bulletInitialPosition = bullet.GetPosition();
                bulletActive = true;
            }
        } else {
            if (knight1.CheckFace() == Knight::RIGHT) {
                knight1.standRight();
            } else {
                knight1.standLeft();
            }
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

        if (bulletActive) {
            bullet.Render(window);
        }

        window.display();
    }
}
