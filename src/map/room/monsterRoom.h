#pragma once
#include <vector>
#include <map>

#include "room.h"
#include "../wall/wall.h"
#include "../wall/door.h"
#include "../../entities/monster/monster.h"
#include "../../entities/monster/monsterType.h"
#include "../../entities/monster/monsterFactory.h"

#include "../../pool/monsterPool.h"
#include "../../utils/point.h"
#include "../../utils/vec.h"
#include "../../utils/random.h"
#include "../../utils/tag.h"

#include "../../manager/objectManager.h"



class MonsterRoom : public Room {
public:
    MonsterRoom(Point leftTop, Point rightBot, int level, std::map<MonsterType, int> monsterMap,
                bool isBossRoom = false);
    MonsterRoom(Point leftTop, Point rightBot, int level, int stage, bool isBossRoom = false);
    ~MonsterRoom();
    void IsInside();
    void IsCleared();

private:
    int level;
    bool isBossRoom = false;
    bool isInside = false;
    bool isCleared = false;
    std::vector<Wall*> walls;
    std::vector<Door*> doors;
    std::map<MonsterType, int> monsterMap;
    std::vector<Monster*> monsters;
    void SetMonsters();
    void PlacedMonster();
    void SetDoors();
    void RelocatePlayerToNearestEdge();
    void GenerateMonsterMapRandomly(int stage);
};