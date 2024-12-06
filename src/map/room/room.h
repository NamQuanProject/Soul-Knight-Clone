#pragma once
#include "roomSize.h"
#include "../../utils/point.h"

class Room {
public:
    Room(Point leftTop, Point rightBot, int size);

protected:
    int size;
    Point leftTop; 
    Point rightBot;
};