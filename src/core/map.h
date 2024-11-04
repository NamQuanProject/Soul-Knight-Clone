#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    Map();
    void loadMap(const std::string& filename);
    void draw(); // Method to draw the map

private:
    // Map data structures (e.g., tiles, obstacles)
};

#endif // MAP_H
