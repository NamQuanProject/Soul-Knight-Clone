#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

sf::Texture makeTransparent(const sf::Texture& texture, const sf::Color& transparentColor) {
    // Convert texture to image
    sf::Image image = texture.copyToImage();

    // Get dimensions of the image
    unsigned int width = image.getSize().x;
    unsigned int height = image.getSize().y;

    // Loop through each pixel and change the transparentColor to transparent
    for (unsigned int x = 0; x < width; ++x) {
        for (unsigned int y = 0; y < height; ++y) {
            if (image.getPixel(x, y) == transparentColor) {
                image.setPixel(x, y, sf::Color(0, 0, 0, 0)); // Set pixel to transparent
            }
        }
    }

    sf::Texture newTexture;
    newTexture.loadFromImage(image);
    return newTexture;
}

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BMP Animation");

    // Load BMP textures
    std::vector<sf::Texture> textures(4);
    for (int i = 0; i < 4; ++i) {
        std::string filename = "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/player/knight/run/" + std::to_string(i + 1) + ".bmp";
        if (!textures[i].loadFromFile(filename)) {
            std::cerr << "Error loading " << filename << std::endl;
            return -1;
        }
        // Make the white color transparent
        textures[i] = makeTransparent(textures[i], sf::Color::White);
    }

    // Create a sprite for the current texture
    sf::Sprite sprite;
    sprite.setTexture(textures[0]);

    // Animation control
    int currentTextureIndex = 0;
    sf::Clock clock;  // For timing

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the sprite texture every 0.2 seconds
        if (clock.getElapsedTime().asSeconds() >= 0.1f) {
            currentTextureIndex = (currentTextureIndex + 1) % 4; // Cycle through textures
            sprite.setTexture(textures[currentTextureIndex]);
            sprite.setPosition(350, 350); // Adjust position if needed
            clock.restart(); // Reset the clock
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Draw the current sprite
        window.draw(sprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
