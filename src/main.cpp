#include "core/application.h"
#include "entities/player/heroes/knight.h"
#include "utils/vec.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create an SFML window with size 800x600 and title "Knight Test"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Knight Test");

    // Create a Knight object
    Knight knight1;

    // Clock to track the time between frames
    sf::Clock clock;

    // Initial position of the knight
    Vec knightPosition(400, 300);



    
    // Main loop that runs as long as the window is open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check if the close event is triggered (e.g., window close button clicked)
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    knightPosition.x -= 75 * 0.1f; // Adjusting position for left movement
                    knight1.runLeft();            // Animation for left movement
                    std::cout << "Moving left to position: " << knightPosition.x << ", " << knightPosition.y << std::endl;
                }
                
                else if (event.key.code == sf::Keyboard::Right) {
                    knightPosition.x += 75 * 0.1f; // Adjusting position for right movement
                    knight1.runRight();            // Animation for right movement
                    std::cout << "Moving right to position: " << knightPosition.x << ", " << knightPosition.y << std::endl;
                }
                
                else if (event.key.code == sf::Keyboard::Up) {
                    knightPosition.y -= 75 * 0.1f; // Adjusting position for upward movement          // Animation for upward movement
                    std::cout << "Moving up to position: " << knightPosition.x << ", " << knightPosition.y << std::endl;
                }
                
                else if (event.key.code == sf::Keyboard::Down) {
                    knightPosition.y += 75 * 0.1f; // Adjusting position for downward movement           // Animation for downward movement
                    std::cout << "Moving down to position: " << knightPosition.x << ", " << knightPosition.y << std::endl;
                }
                else {
                    knight1.standRight();
                }
            }

        }

        // Handle keyboard inputs for movement
        

        // Set the knight's position
        knight1.SetPosition(knightPosition);

        // Clear the window with a blue background
        window.clear(sf::Color::Blue);

        // Update and render the knight
        float deltaTime = clock.getElapsedTime().asSeconds();
        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            knight1.Update(deltaTime);
            clock.restart();  
        }  // Update knight with deltaTime
        knight1.Render(window);  // Render knight at updated position

        // Display the updated window content
        window.display();

        // Debug output
        
    }

    return 0;
}
