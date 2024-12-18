// #include "stdafx.h"
// #include "TreasureRoom.h"

// #include "../manager/ObjectManager.h"
// #include "../manager/StageManager.h"
// #include "../shop/Businessman.h"
// #include "../shop/TreasureChest.h"
// #include "../utils/Rand.h"
#include "treasureRoom.h"
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "room.h"
#include "../wall/wall.h"
#include "../wall/door.h"
#include "../../utils/point.h"
#include "../../utils/vec.h"
#include "../../utils/random.h"
#include "../../utils/tag.h"

#include "../../manager/objectManager.h"

TreasureRoom::TreasureRoom(Point leftTop, Point rightBot, int size)
    : Room(leftTop, rightBot, size) {
    // Calculate the center of the room
    Point center(
        (leftTop.GetX() + rightBot.GetX()) / 2,
        (leftTop.GetY() + rightBot.GetY()) / 2
    );

    // Set the treasure position to the center of the room
    // treasure->SetPosition(center);
    
    // Add the treasure to the object manager
    ObjectManager::Instance()->AddObject(treasure);
}

TreasureRoom::~TreasureRoom() {
    treasure->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}