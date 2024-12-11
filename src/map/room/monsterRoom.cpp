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
    // SetMonsters();
}


MonsterRoom::~MonsterRoom() {
    // if (treasureChest) {
    //     treasureChest->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }
    
}



void MonsterRoom::Update(float deltaTime) {
    // for (auto monster : monsters) {
    //     monster->Update(deltaTime); // Render each monster on the provided window
    // }
    for (auto door: doors) {
        door->Update(deltaTime);
    }
}

void MonsterRoom::Show(sf::RenderWindow& window) {
    
    // for (auto monster : monsters) {
    //     monster->Render(window);
    // }
    // for (auto door: doors) {
    //     door->Render(window);
    // }
}

void MonsterRoom::IsInside() {
    double playerX = ObjectManager::Instance()->GetPlayer()->GetPosition().GetX();
    double playerY = ObjectManager::Instance()->GetPlayer()->GetPosition().GetY();

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
    std::cout << "CLEAR NOW" << std::endl;

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




    // treasureChest = new TreasureChest(TreasureChest::NORMAL_ROOM);
    // double minX = topLeft.GetX() + 16 - centerOffset.GetX();
    // double minY = topLeft.GetY() + 16 - centerOffset.GetY();
    // double maxX = topLeft.GetX() + 16 * (size + 1) - centerOffset.GetX();
    // double maxY = topLeft.GetY() + 16 * (size + 1) - centerOffset.GetY();

    // treasureChest->SetPosition(
    //     Point(Rand::Instance()->Get(minX + 16, maxX - 16), Rand::Instance()->Get(minY + 16, maxY - 16)));
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
        ObjectManager::Instance()->AddObject(monster);
    }
}

void MonsterRoom::PlacedMonster() {
    // Calculate the adjusted bounds of the room
    double bufferZone = 32.0; // Adjust this value to increase/decrease the distance from the wall

// Calculate the valid placement bounds, keeping the buffer zone in mind
    double minX = leftTop.GetX() + bufferZone;
    double minY = leftTop.GetY() + bufferZone;
    double maxX = rightBot.GetX() - bufferZone;
    double maxY = rightBot.GetY() - bufferZone;

    // Iterate over each monster and place it within the new bounds
    for (auto monster : monsters) {
        Vec pos = Vec(
            Rand::Instance()->Get(minX, maxX), // Random X-coordinate within bounds
            Rand::Instance()->Get(minY, maxY)  // Random Y-coordinate within bounds
        );
        monster->SetPosition(pos); // Set the monster's position
    }
}

void MonsterRoom::SetDoors() {
    
    double wallThickness = 10;      // Thickness of the wall segments
    double doorHeight = 70;         // Height of the gap for vertical gates
    double doorWidth = 70;          // Width of the gap for horizontal gates
    double offset = 10;


    double midX = (leftTop.GetX() + rightBot.GetX()) / 2.0;
    double midY = (leftTop.GetY() + rightBot.GetY()) / 2.0;

    Wall* leftDoor = new Wall(
        Point(leftTop.GetX() - offset, midY - doorHeight / 2), 
        Point(leftTop.GetX() + wallThickness - offset, midY + doorHeight / 2)
    );


    Wall* rightDoor = new Wall(
        Point(rightBot.GetX() - wallThickness + offset, midY - doorHeight / 2), 
        Point(rightBot.GetX() + offset, midY + doorHeight / 2)
    );

    // Top door
    Wall* topDoor = new Wall(
        Point(midX - doorWidth / 2, leftTop.GetY() - offset), 
        Point(midX + doorWidth / 2, leftTop.GetY() + wallThickness - offset)
    );

    // Bottom door
    Wall* bottomDoor = new Wall(
        Point(midX - doorWidth / 2, rightBot.GetY() - wallThickness + offset), 
        Point(midX + doorWidth / 2, rightBot.GetY() + offset)
    );

    ObjectManager::Instance()->AddObject(leftDoor);
    ObjectManager::Instance()->AddObject(rightDoor);
    ObjectManager::Instance()->AddObject(topDoor);
    ObjectManager::Instance()->AddObject(bottomDoor);

    doors.push_back(leftDoor);
    doors.push_back(rightDoor);
    doors.push_back(topDoor);
    doors.push_back(bottomDoor);
    // ObjectManager::Instance()->AddObject(leftInvisibleDoor);
    // ObjectManager::Instance()->AddObject(rightInvisibleDoor);
    // ObjectManager::Instance()->AddObject(topInvisibleDoor);
    // ObjectManager::Instance()->AddObject(bottomInvisibleDoor);
    
}

void MonsterRoom::RelocatePlayerToCenter() {
    double centerX = (leftTop.GetX() + rightBot.GetX()) / 2.0;
    double centerY = (leftTop.GetY() + rightBot.GetY()) / 2.0;

    Vec centerPosition(centerX, centerY);
    Vec cur_position = ObjectManager::Instance()->GetPlayer()->GetPosition();
    Vec transferPlayerDistance = centerPosition - cur_position ;
    
    transferPlayerDistance.SetLength(25);

    Vec temp_position = cur_position + transferPlayerDistance;

    ObjectManager::Instance()->GetPlayer()->SetPosition(temp_position);
}


void MonsterRoom::GenerateMonsterMapRandomly(int stage) {
    int monsterAmount;
    if (size == 1) {
        monsterAmount = 4;
    }
    if (size == 2) {
        monsterAmount = 8;
    }
    switch (stage) {
    case 1:
        for (int i = 0; i < monsterAmount; i++) {
            monsterMap[static_cast<MonsterType>(Rand::Instance()->Get(0, 1))] += 1;
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
