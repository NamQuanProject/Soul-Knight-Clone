#include "monsterRoom.h"
#include "../../map/wall/horizontalDoor1.h"
#include "../../map/wall/horizontalDoor2.h"
#include "../../map/wall/horizontalDoor3.h"
#include "../../map/wall/horizontalDoor4.h"
#include "../../map/wall/verticalDoor1.h"
#include "../../map/wall/verticalDoor2.h"
#include "../../map/wall/verticalDoor3.h"
#include "../../map/wall/verticalDoor4.h"

MonsterRoom::MonsterRoom(Point leftTop, Point rightBot, int size, int level, std::map<MonsterType, int> monsterMap,
                bool isBossRoom):
    Room(leftTop, rightBot, size), level(level), monsterMap(monsterMap), isBossRoom(isBossRoom) {
    
}

MonsterRoom::MonsterRoom(Point leftTop, Point rightBot, int size, int level, int stage, bool isBossRoom):
    Room(leftTop, rightBot, size), level(level), isBossRoom(isBossRoom) {
    GenerateMonsterMapRandomly(stage);
    SetMonsters();
}


MonsterRoom::~MonsterRoom() {
    // if (treasureChest) {
    //     treasureChest->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }
    
}



void MonsterRoom::Update(float deltaTime) {
    for (auto monster : monsters) {
        monster->Update(deltaTime); // Render each monster on the provided window
    }
}

void MonsterRoom::Show(sf::RenderWindow& window) {
    for (auto monster : monsters) {
        monster->Render(window); // Render each monster on the provided window
    }
}

void MonsterRoom::IsInside() {
    double playerX = objectManager.GetPlayer()->GetPosition().GetX();
    double playerY = objectManager.GetPlayer()->GetPosition().GetY();

    // Check if the player is inside the room boundaries
    if (!isInside && !isCleared &&
        playerX >= leftTop.GetX() && playerX <= rightBot.GetX() &&
        playerY >= leftTop.GetY() && playerY <= rightBot.GetY()) {
        
        isInside = true;
        RelocatePlayerToCenter(); 
        SetDoors();   
        SetMonsters();               
    }
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

    for (auto door : walls) {
        door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }

    for (auto door : doors) {
        door->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }

    for (auto monster : monsters) {
        monster->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void MonsterRoom::SetMonsters() {
    for (auto monster : monsterMap) {
        for (int i = 0; i < monster.second; i++) {
            Monster* monsterInstance = MonsterPool::Instance()->Acquire(monster.first, 1);
            monsters.push_back(monsterInstance);
        }
    }
    PlacedMonster();
    for (auto monster : monsters) {
        std::cout << "YES" << std::endl;
    }
}

void MonsterRoom::PlacedMonster() {
    // Calculate the adjusted bounds of the room
    double minX = leftTop.GetX() + 16;
    double minY = leftTop.GetY() + 16;
    double maxX = rightBot.GetX() - 16;
    double maxY = rightBot.GetY() - 16;

    // Iterate over each monster and place it within the bounds
    for (auto monster : monsters) {
        Vec pos = Vec(
            Rand::Instance()->Get(minX, maxX), // Random X-coordinate within bounds
            Rand::Instance()->Get(minY, maxY) // Random Y-coordinate within bounds
        );
        monster->SetPosition(pos); // Set the monster's position
    }
}

void MonsterRoom::SetDoors() {
    // double leftTopX = leftTop.GetX();
    // double leftTopY = leftTop.GetY();
    // double rightBot
    // Wall* leftInvisibleDoor = new Wall(Point(x, y), Point(x + 16, y + 16 * (size + 2)));
    // Wall* rightInvisibleDoor = new Wall(Point(x + 16 * (size + 1), y), Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    // Wall* topInvisibleDoor = new Wall(Point(x, y), Point(x + 16 * (size + 2), y + 16));
    // Wall* bottomInvisibleDoor = new Wall(Point(x, y + 16 * (size + 1)),
    //                                      Point(x + 16 * (size + 2), y + 16 * (size + 2)));
    // invisibleDoors.push_back(leftInvisibleDoor);
    // invisibleDoors.push_back(rightInvisibleDoor);
    // invisibleDoors.push_back(topInvisibleDoor);
    // invisibleDoors.push_back(bottomInvisibleDoor);
    // ObjectManager::Instance()->AddObject(leftInvisibleDoor);
    // ObjectManager::Instance()->AddObject(rightInvisibleDoor);
    // ObjectManager::Instance()->AddObject(topInvisibleDoor);
    // ObjectManager::Instance()->AddObject(bottomInvisibleDoor);

    // Door* leftDoor;
    // Door* rightDoor;
    // Door* topDoor;
    // Door* bottomDoor;

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



    // doors.push_back(leftDoor);
    // doors.push_back(rightDoor);
    // doors.push_back(topDoor);
    // doors.push_back(bottomDoor);
    // // ObjectManager::Instance()->AddObject(leftDoor);
    // // ObjectManager::Instance()->AddObject(rightDoor);
    // // ObjectManager::Instance()->AddObject(topDoor);
    // // ObjectManager::Instance()->AddObject(bottomDoor);
}

void MonsterRoom::RelocatePlayerToCenter() {
    double centerX = (leftTop.GetX() + rightBot.GetX()) / 2.0;
    double centerY = (leftTop.GetY() + rightBot.GetY()) / 2.0;

    Vec centerPosition(centerX, centerY);

    ObjectManager::Instance()->GetPlayer()->SetPosition(centerPosition);


}

void MonsterRoom::GenerateMonsterMapRandomly(int stage) {
    int monsterAmount;
    if (size == 1) {
        monsterAmount = 8;
    }
    if (size == 2) {
        monsterAmount = 16;
    }
    switch (stage) {
    case 1:
        for (int i = 0; i < monsterAmount; i++) {
            monsterMap[MonsterType::GOBLIN_GIANT] += 1;
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
