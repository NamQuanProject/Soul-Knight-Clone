#include "stage.h"


Stage::Stage() {
    // int level = StageManager::Instance()->GetLevelNumber();
    // int stage = StageManager::Instance()->GetStageNumber();

    // vending machine
    // switch (Rand::Instance()->Get(0, 2)) {
    // case 0:
    //     vendingMachine = new WeaponVendingMachine(level, stage);
    //     break;
    // case 1:
    //     vendingMachine = new PotionVendingMachine(level, stage);
    //     break;
    // default:
    //     vendingMachine = nullptr;
    // }
    // if (vendingMachine) {
    //     ObjectManager::Instance()->AddObject(vendingMachine);
    // }
}

Stage::~Stage() {
    for (auto wall : walls) {
        if (wall) {
            delete wall;
        }
    }
}

// sf::Sprite Stage::GetBackground() {
//     return background;
// }

void Stage::Initialize() {
    // GenerateWall();
    // SetPlayerPosition();
    // SetTransferGate();
    // GenerateObstacle();
}

// void Stage::Show(Point screenPositoin) {
//     // background.SetTopLeft(static_cast<int>(-screenPositoin.GetX() - static_cast<double>(background.GetWidth()) / 2),
//     //                       static_cast<int>(-screenPositoin.GetY() - static_cast<double>(background.GetHeight()) / 2));
//     // background.ShowBitmap();
// }

void Stage::AddWall(Point point1, Point point2) {
    Wall* wall = new Wall(point1, point2);
    walls.push_back(wall);
    std::cout << "Wall Add YES" << std::endl;
    ObjectManager::Instance()->AddObject(wall);
}

void Stage::IsInsideRoom() {
    for (auto room : monsterRooms) {
        room->IsInside();
    }
}

void Stage::IsRoomCleared() {
    for (auto room : monsterRooms) {
        room->IsCleared();
    }
    
}