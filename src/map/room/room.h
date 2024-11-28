#pragma once
#include "roomSize.h"
#include "../../utils/point.h"

class Room {
public:
    Room(Point leftTop, RoomSize size, Vec centerOffset);

protected:
    Point topLeft; 
    int size;
    Vec centerOffset;
};