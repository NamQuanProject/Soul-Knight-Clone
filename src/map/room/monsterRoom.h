#pragma once
#include <vector>
#include <map>

#include "room.h"
#include "../../entities/monster/monsterType.h"
#include "../../utils/point.h"

class Door;
enum class RoomSize;
class Wall;
class Monster;

class MonsterRoom : public Room {
public:
    MonsterRoom(Point leftTop, Vec centerOffset, RoomSize size, int level, std::map<MonsterType, int> monsterMap,
                bool isBossRoom = false);
    MonsterRoom(Point leftTop, Vec centerOffset, RoomSize size, int level, int stage, bool isBossRoom = false);
    ~MonsterRoom();
    void IsInside();
    void IsCleared();

private:
    int level;
    bool isBossRoom = false;
    bool isInside = false;
    bool isCleared = false;
    std::vector<Wall*> invisibleDoors;
    std::vector<Door*> doors;
    std::map<MonsterType, int> monsterMap;
    std::vector<Monster*> monsters;
    void SetMonsters();
    void PlacedMonster();
    void SetDoors();
    void RelocatePlayerToNearestEdge();
    void GenerateMonsterMapRandomly(int stage);
};