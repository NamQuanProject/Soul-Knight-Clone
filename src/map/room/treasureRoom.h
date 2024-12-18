#pragma once
#include "room.h"
#include "../../entities/gameObject.h"


class TreasureRoom : public Room {
public:
    TreasureRoom(Point leftTop, Point rightBot, int size);
    ~TreasureRoom();

private:
    GameObject* treasure;
};