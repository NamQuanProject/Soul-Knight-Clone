#ifndef GAME_H
#define GAME_H

#include <vector>
#include "map.h"

class Game {
public:
    Game();
    void initialize();
    void start();

private:
    Map gameMap; // Instance of the game map
    // Other game-related members
};

#endif // GAME_H
