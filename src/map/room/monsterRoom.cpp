#include "monsterRoom.h"
#include "../../map/wall/horizontalDoor1.h"
#include "../../map/wall/horizontalDoor2.h"
#include "../../map/wall/horizontalDoor3.h"
#include "../../map/wall/horizontalDoor4.h"
#include "../../map/wall/verticalDoor1.h"
#include "../../map/wall/verticalDoor2.h"
#include "../../map/wall/verticalDoor3.h"
#include "../../map/wall/verticalDoor4.h"

MonsterRoom::MonsterRoom(Point topLeft, Vec centerOffset, RoomSize size, int level,
                         std::map<MonsterType, int> monsterMap,
                         bool isBossRoom):
    Room(topLeft, size, centerOffset), level(level), monsterMap(monsterMap), isBossRoom(isBossRoom) {
}

MonsterRoom::MonsterRoom(Point topLeft, Vec centerOffset, RoomSize size, int level, int stage, bool isBossRoom):
    Room(topLeft, size, centerOffset), level(level), isBossRoom(isBossRoom) {
    GenerateMonsterMapRandomly(stage);
}


MonsterRoom::~MonsterRoom() {
    // if (treasureChest) {
    //     treasureChest->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }
}

void MonsterRoom::IsInside() {
    // double x = ObjectManager::Instance()->GetPlayer()->GetPosition().GetX() + centerOffset.GetX();
    // double y = ObjectManager::Instance()->GetPlayer()->GetPosition().GetY() + centerOffset.GetY();
    // if (!isInside && !isCleared && x >= topLeft.GetX() && x <= topLeft.GetX() + 16 * (size + 2) && y >= topLeft.GetY()
    //     && y <= topLeft.GetY() + 16 * (size + 2)) {
    //     isInside = true;
    //     RelocatePlayerToNearestEdge();
    //     SetDoors();
    //     SetMonsters();
    // }
}

void MonsterRoom::IsCleared() {
    if (!isInside || isCleared) {
        return;
    }
    for (auto monster : monsters) {
        if (!monster->HasTag(Tag::DEAD)) {
            return;
        }
    }

    isCleared = true;

    // if (isBossRoom) {
    //     StageManager::Instance()->SetTransferGatePosition(
    //         topLeft + Point((size + 2) * 8, (size + 2) * 8) - centerOffset);
    // }

    // if (isBossRoom) {
    //     treasureChest = new TreasureChest(TreasureChest::BOSS_ROOM);
    //     treasureChest->SetPosition(topLeft + Point((size + 2) * 8, (size + 12) * 8) - centerOffset);
    // }
    // else {
    //     treasureChest = new TreasureChest(TreasureChest::NORMAL_ROOM);
    //     double minX = topLeft.GetX() + 16 - centerOffset.GetX();
    //     double minY = topLeft.GetY() + 16 - centerOffset.GetY();
    //     double maxX = topLeft.GetX() + 16 * (size + 1) - centerOffset.GetX();
    //     double maxY = topLeft.GetY() + 16 * (size + 1) - centerOffset.GetY();

    //     treasureChest->SetPosition(
    //         Point(Rand::Instance()->Get(minX + 16, maxX - 16), Rand::Instance()->Get(minY + 16, maxY - 16)));
    // }
    // ObjectManager::Instance()->AddObject(treasureChest);

    // for (auto door : invisibleDoors) {
    //     door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }

    // for (auto door : doors) {
    //     door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }

    // for (auto monster : monsters) {
    //     monster->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }
}

void MonsterRoom::SetMonsters() {
    // for (auto monster : monsterMap) {
    //     for (int i = 0; i < monster.second; i++) {
    //         Monster* monsterInstance = MonsterPool::Instance()->Acquire(monster.first, 1);
    //         monsters.push_back(monsterInstance);
    //     }
    // }
    // PlacedMonster();
    // for (auto monster : monsters) {
    //     ObjectManager::Instance()->AddObject(monster);
    // }
}

void MonsterRoom::PlacedMonster() {
    double minX = topLeft.GetX() + 16 - centerOffset.GetX();
    double minY = topLeft.GetY() + 16 - centerOffset.GetY();
    double maxX = topLeft.GetX() + 16 * (size + 1) - centerOffset.GetX();
    double maxY = topLeft.GetY() + 16 * (size + 1) - centerOffset.GetY();

    for (auto monster : monsters) {
        Vec pos = Vec(Rand::Instance()->Get(minX + 16, maxX - 16), Rand::Instance()->Get(minY + 16, maxY - 16));
        monster->SetPosition(pos);
    }
}

void MonsterRoom::SetDoors() {
    double x = topLeft.GetX() - centerOffset.GetX();
    double y = topLeft.GetY() - centerOffset.GetY();
    Wall* leftInvisibleDoor = new Wall(Point(x, y), Point(x + 16, y + 16 * (size + 2)));
    Wall* rightInvisibleDoor = new Wall(Point(x + 16 * (size + 1), y), Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    Wall* topInvisibleDoor = new Wall(Point(x, y), Point(x + 16 * (size + 2), y + 16));
    Wall* bottomInvisibleDoor = new Wall(Point(x, y + 16 * (size + 1)),
                                         Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    // invisibleDoors.push_back(leftInvisibleDoor);
    // invisibleDoors.push_back(rightInvisibleDoor);
    // invisibleDoors.push_back(topInvisibleDoor);
    // invisibleDoors.push_back(bottomInvisibleDoor);
    // ObjectManager::Instance()->AddObject(leftInvisibleDoor);
    // ObjectManager::Instance()->AddObject(rightInvisibleDoor);
    // ObjectManager::Instance()->AddObject(topInvisibleDoor);
    // ObjectManager::Instance()->AddObject(bottomInvisibleDoor);

    Door* leftDoor;
    Door* rightDoor;
    Door* topDoor;
    Door* bottomDoor;

    // switch (level) {
    // case 1:
    //     leftDoor = new VerticalDoor1();
    //     rightDoor = new VerticalDoor1();
    //     topDoor = new HorizontalDoor1();
    //     bottomDoor = new HorizontalDoor1();
    //     break;
    // case 2:
    //     leftDoor = new VerticalDoor2();
    //     rightDoor = new VerticalDoor2();
    //     topDoor = new HorizontalDoor2();
    //     bottomDoor = new HorizontalDoor2();
    //     break;
    // case 3:
    //     leftDoor = new VerticalDoor3();
    //     rightDoor = new VerticalDoor3();
    //     topDoor = new HorizontalDoor3();
    //     bottomDoor = new HorizontalDoor3();
    //     break;
    // case 4:
    //     leftDoor = new VerticalDoor4();
    //     rightDoor = new VerticalDoor4();
    //     topDoor = new HorizontalDoor4();
    //     bottomDoor = new HorizontalDoor4();
    // }



    doors.push_back(leftDoor);
    doors.push_back(rightDoor);
    doors.push_back(topDoor);
    doors.push_back(bottomDoor);
    // ObjectManager::Instance()->AddObject(leftDoor);
    // ObjectManager::Instance()->AddObject(rightDoor);
    // ObjectManager::Instance()->AddObject(topDoor);
    // ObjectManager::Instance()->AddObject(bottomDoor);
}

void MonsterRoom::RelocatePlayerToNearestEdge() {
    // Point roomCenterPoint = topLeft - centerOffset + Vec(size / 2 * 16, size / 2 * 16);
    // Vec transferPlayerDistance = roomCenterPoint - ObjectManager::Instance()->GetPlayer()->GetPosition();
    // transferPlayerDistance.SetLength(25);
    // ObjectManager::Instance()->GetPlayer()->SetPosition(
    //     ObjectManager::Instance()->GetPlayer()->GetPosition() + transferPlayerDistance);
}

void MonsterRoom::GenerateMonsterMapRandomly(int stage) {
    int monsterAmount = size == static_cast<int>(RoomSize::MEDIUM_SIZE) ? 8 : 16;
    switch (stage) {
    case 1:
        for (int i = 0; i < monsterAmount; i++) {
            monsterMap[static_cast<MonsterType>(Rand::Instance()->Get(1, 10))] += 1;
        }
        break;
    case 2:
        for (int i = 0; i < monsterAmount; i++) {
            monsterMap[static_cast<MonsterType>(Rand::Instance()->Get(11, 21))] += 1;
        }
        break;
    case 3:
        for (int i = 0; i < monsterAmount; i++) {
            monsterMap[static_cast<MonsterType>(Rand::Instance()->Get(23, 30))] += 1;
        }
        break;
    }
}
