#include "stage.h"


// Stage::Stage() : treasureRoom(nullptr), vendingMachine(nullptr) {
    // int level = StageManager::Instance()->GetLevelNumber();
    // int stage = StageManager::Instance()->GetStageNumber();

    // // vending machine
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
// }

Stage::~Stage() {
    // for (auto room : monsterRooms) {
    //     delete room;
    // }
    // if (treasureRoom) {
    //     delete treasureRoom;   
    // }
    // for (auto wall : walls) {
    //     wall->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }
    // if (vendingMachine) {
    //     vendingMachine->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    // }
}

sf::Sprite Stage::GetBackground() {
    return background;
}

void Stage::Initialize() {
    GenerateWall();
    SetPlayerPosition();
    SetTransferGate();
    GenerateObstacle();
}

void Stage::Show(Point screenPositoin) {
    // background.SetTopLeft(static_cast<int>(-screenPositoin.GetX() - static_cast<double>(background.GetWidth()) / 2),
    //                       static_cast<int>(-screenPositoin.GetY() - static_cast<double>(background.GetHeight()) / 2));
    // background.ShowBitmap();
}

void Stage::AddWall(Point point1, Point point2) {
    // Wall* wall = new Wall(point1 - centerOffset, point2 - centerOffset);
    // walls.push_back(wall);
    // ObjectManager::Instance()->AddObject(wall);
}

void Stage::IsInsideRoom() {
    // for (auto room : monsterRooms) {
    //     room->IsInside();
    // }
}

void Stage::IsRoomCleared() {
    // for (auto room : monsterRooms) {
    //     room->IsCleared();
    // }
}