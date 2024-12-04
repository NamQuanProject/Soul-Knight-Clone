#include "core/application.h"
#include "entities/player/heroes/knight.h"
#include "utils/vec.h"
#include "manager/soundManager.h"
#include "manager/camera.h"
#include <SFML/Graphics.hpp>
#include "entities/projectile/bullet/badPistolBullet.h"
#include "entities/monster/floor_1/goblin_shaman/goblinShaman.h"
#include "map/stage/stage_1_1.h"
#include <iostream>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Knight Test");
    Stage_1_1 stage;
    
    window.setFramerateLimit(3000);
    
    GoblinShaman goblin_shaman1;
    Vec mons_position = Vec(200.0, 200.0);
    goblin_shaman1.SetPosition(mons_position);

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

    Knight* knight1 = new Knight();  // Initialize knight1 as a new instance

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
        Vec before = knightPosition;
        knight1->SetBeforePosition(before);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            knightPosition.SetX(knightPosition.GetX() + 0.5f * 0.1f);
            knightPosition.SetY(knightPosition.GetY() - 0.5f * 0.1f);
            knight1->runRight();  
            knight1->setSpeed(Vec(0.05, -0.05));



                     
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            knightPosition.SetX(knightPosition.GetX() - 0.5f * 0.1f);
            knightPosition.SetY(knightPosition.GetY() - 0.5f * 0.1f);
            knight1->runLeft();            
            knight1->setSpeed(Vec(-0.05, -0.05));

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            knightPosition.SetX(knightPosition.GetX() + 0.5f * 0.1f);  
            knightPosition.SetY(knightPosition.GetY() + 0.5f * 0.1f);  
            knight1->runRight();          


            knight1->setSpeed(Vec(0.05, 0.05));  
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            knightPosition.SetX(knightPosition.GetX() - 0.5f * 0.1f);
            knightPosition.SetY(knightPosition.GetY() + 0.5f * 0.1f);  
            knight1->runLeft();

            knight1->setSpeed(Vec(-0.05, 0.05));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            knightPosition.SetY(knightPosition.GetY() - 0.5f * 0.1f);  


            knight1->setSpeed(Vec(0.0, -0.05));
            if (knight1->CheckFace() == Knight::RIGHT) {
                knight1->runRight();        
            } else {
                knight1->runLeft();         
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            knightPosition.SetY(knightPosition.GetY() + 0.5f * 0.1f);  
            knight1->setSpeed(Vec(0.0, 0.05));
            if (knight1->CheckFace() == Knight::RIGHT) {
                knight1->runRight();        
            } else {
                knight1->runLeft();        
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            knightPosition.SetX(knightPosition.GetX() - 0.5f * 0.1f);
            knight1->runLeft();    
            knight1->setSpeed(Vec(-0.05, 0.0));        
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            knightPosition.SetX(knightPosition.GetX() + 0.5f * 0.1f);  
            knight1->runRight();    
            knight1->setSpeed(Vec(0.05, 0.0));            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!bulletActive) {
                bullet.SetPosition(sf::Vector2f(knightPosition.GetX(), knightPosition.GetY()));
                bullet.SetSpeed(sf::Vector2f(5.f, 0.f));
                bulletInitialPosition = bullet.GetPosition();
                bulletActive = true;
            }
        } else {
            // Make the knight stand still if no keys are pressed
            if (knight1->CheckFace() == Knight::RIGHT) {
                knight1->setSpeed(Vec(0.0, 0.0));        
                knight1->standRight();
            } else {
                knight1->standLeft();
            }
        }

        sf::Vector2f knightPos(knightPosition.GetX(), knightPosition.GetY());
        knight1->SetPosition(knightPosition);
        camera.update(knightPos);

        window.clear();
        camera.applyView(window);
        window.draw(backgroundSprite);
        
        float deltaTime = clock.getElapsedTime().asSeconds();
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

        
        knight1->Update(deltaTime);
        goblin_shaman1.Update(deltaTime);
        
        stage.Collision(knight1);


        knightPosition = knight1->GetPosition();

        knight1->SetPosition(knightPosition);
        stage.Render(window);
        
        knight1->Render(window);
        goblin_shaman1.Render(window);


        if (deltaTime > 0.1f) {
            clock.restart();
        }
        if (bulletActive) {
            bullet.Render(window);
        }

        window.display();
    }
    
    delete knight1; 
}
