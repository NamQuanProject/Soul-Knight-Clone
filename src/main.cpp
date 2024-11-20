#include "core/application.h"
#include "entities/player/heroes/knight.h"
#include "utils/vec.h"
#include <SFML/Graphics.hpp>  // Include for SFML classes like RenderWindow, Event, etc.
#include <iostream>
int main() {
    // Application app;
    // app.run();        

    // Create an SFML window with size 800x600 and title "Knight Test"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Knight Test");

    // Create a Knight object
    Knight knight1;
    Knight knight2;

    // Clock to track the time between frames
    sf::Clock clock;
    
    // Main loop that runs as long as the window is open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check if the close event is triggered (e.g., window close button clicked)
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window
            }
        }

        // Calculate the elapsed time in seconds since the last frame
        float deltaTime = clock.getElapsedTime().asSeconds();

        knight1.SetPosition(Vec(300, 400));
        knight1.runLeft();

        knight2.SetPosition(Vec(600, 400));
        knight2.runRight();


        // Set the background color to blue
        window.clear(sf::Color::Blue);  // Clears the window with blue color

        // Reset the clock every 0.1 seconds
        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            knight1.Update(deltaTime);
            knight2.Update(deltaTime);
            clock.restart();  // Reset the clock
        }

        // Render the knight onto the window
        knight1.Render(window);
        knight2.Render(window);


        
        // Set the knight's position (this might need adjustments based on your Vec class implementation)

        // Display the updated window content
        window.display();
    }

    return 0;
}
