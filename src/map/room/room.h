#pragma once
#include "roomSize.h"
#include "../../utils/Point.h"

class Room {
public:
    Room(Point leftTop, RoomSize size, Vec centerOffset);

protected:
    Point topLeft; 
    int size;
    Vec centerOffset;
};