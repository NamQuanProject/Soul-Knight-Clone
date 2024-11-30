// #include <SFML/Graphics.hpp>
// #include <vector>
// #include <iostream>

// struct ClickableArea {
//     sf::IntRect rect;  // The rectangle area
//     std::string action;  // Action or title to identify the area (e.g., "wall", "door1")
// };

// int main()
// {
//     // Create the SFML window
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Image Map Example");

//     // Load the texture and create a sprite
//     sf::Texture texture;
//     if (!texture.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/1-1.bmp")) {
//         return -1; // Error loading image
//     }
//     sf::Sprite sprite(texture);

//     // Define the clickable areas (coordinates as in your HTML map)
//     std::vector<ClickableArea> areas = {
//         {sf::IntRect(4, 82, 203, 15), "wall1"},
//         {sf::IntRect(0, 97, 16, 175), "wall2"},
//         {sf::IntRect(0, 273, 207, 13), "wall3"},
//         {sf::IntRect(192, 96, 15, 46), "wall4"},
//         {sf::IntRect(191, 224, 17, 49), "wall5"},
//         {sf::IntRect(210, 128, 315, 14), "wall6"},
//         {sf::IntRect(210, 225, 317, 13), "wall7"},
//         {sf::IntRect(529, 16, 16, 126), "wall8"},
//         {sf::IntRect(529, 225, 14, 127), "wall9"},
//         {sf::IntRect(529, 2, 365, 14), "wall10"},
//         {sf::IntRect(527, 351, 144, 18), "wall11"},
//         {sf::IntRect(768, 353, 126, 14), "wall12"},
//         {sf::IntRect(882, 16, 12, 126), "wall13"},
//         {sf::IntRect(878, 225, 18, 125), "wall14"},
//         {sf::IntRect(898, 129, 317, 14), "wall15"},
//         {sf::IntRect(898, 225, 317, 16), "wall16"},
//         {sf::IntRect(1218, 66, 13, 73), "wall17"},
//         {sf::IntRect(1216, 228, 15, 77), "wall18"},
//         {sf::IntRect(1216, 46, 271, 18), "wall19"},
//         {sf::IntRect(1216, 305, 95, 14), "wall20"},
//         {sf::IntRect(1409, 304, 78, 13), "wall21"},
//         {sf::IntRect(1469, 66, 18, 76), "wall22"},
//         {sf::IntRect(1473, 226, 14, 77), "wall23"},
//         {sf::IntRect(1491, 128, 317, 16), "wall24"},
//         {sf::IntRect(1491, 224, 315, 15), "wall25"},
//         {sf::IntRect(1809, 96, 15, 48), "wall26"},
//         {sf::IntRect(1809, 224, 15, 47), "wall27"},
//         {sf::IntRect(1808, 82, 206, 14), "wall28"},
//         {sf::IntRect(1809, 273, 206, 14), "wall29"},
//         {sf::IntRect(2000, 96, 14, 175), "wall30"},
//         {sf::IntRect(655, 370, 16, 317), "wall31"},
//         {sf::IntRect(753, 371, 17, 316), "wall32"},
//         {sf::IntRect(595, 687, 76, 19), "wall33"},
//         {sf::IntRect(753, 689, 77, 15), "wall34"},
//         {sf::IntRect(579, 689, 12, 253), "wall35"},
//         {sf::IntRect(832, 687, 16, 257), "wall36"},
//         {sf::IntRect(579, 942, 267, 16), "wall37"},
//         {sf::IntRect(1297, 319, 16, 317), "wall38"},
//         {sf::IntRect(1393, 317, 14, 322), "wall39"},
//         {sf::IntRect(1215, 641, 96, 14), "wall40"},
//         {sf::IntRect(1393, 639, 94, 17), "wall41"},
//         {sf::IntRect(1215, 652, 16, 244), "wall42"},
//         {sf::IntRect(1471, 656, 16, 241), "wall43"},
//         {sf::IntRect(1215, 898, 272, 14), "wall44"},
//         {sf::IntRect(191, 142, 19, 81), "door1"},
//         {sf::IntRect(529, 146, 14, 77), "door2"},
//         {sf::IntRect(673, 353, 77, 16), "door3"},
//         {sf::IntRect(878, 144, 18, 80), "door4"},
//         {sf::IntRect(1216, 144, 15, 80), "door5"},
//         {sf::IntRect(1473, 144, 16, 82), "door6"},
//         {sf::IntRect(1313, 304, 78, 16), "door7"},
//         {sf::IntRect(1808, 144, 17, 80), "door8"},
//         {sf::IntRect(673, 688, 79, 15), "door9"},
//         {sf::IntRect(1313, 641, 78, 14), "door10"},
//         {sf::IntRect(102, 183, 1, 1), "startpoint"}  // Single point for start
//     };

//     // Main loop
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }

//             if (event.type == sf::Event::MouseButtonPressed) {
//                 if (event.mouseButton.button == sf::Mouse::Left) {
//                     sf::Vector2i mousePos = sf::Mouse::getPosition(window);

//                     // Check each clickable area
//                     for (const auto& area : areas) {
//                         if (area.rect.contains(mousePos)) {
//                             std::cout << "Clicked on: " << area.action << std::endl;
//                             // Perform action based on area.action (like opening a new screen, etc.)
//                             if (area.action == "startpoint") {
//                                 // Example: start a new game or load a new scene
//                                 std::cout << "Starting game!" << std::endl;
//                             }
//                             break; // Exit loop once clicked area is found
//                         }
//                     }
//                 }
//             }
//         }

//         // Clear the window
//         window.clear();
        
//         // Draw the sprite
//         window.draw(sprite);

//         // Display everything we've drawn
//         window.display();
//     }

//     return 0;
// }
