#include "stageManager.h"



StageManager::StageManager(): level(0), stage(5), success(false) {

}

StageManager::~StageManager() {
    delete gameStage;
}

void StageManager::Update(float deltaTime) {
    gameStage->IsInsideRoom();
    gameStage->IsRoomCleared();
}

Stage* StageManager::GetStage() {
    return gameStage;
}

int StageManager::GetStageNumber() {
    return stage;
}

int StageManager::GetLevelNumber() {
    return level;
}

void StageManager::Initiliaze() {
    // transferGate = new TransferGate();
    // transferGate->SetPosition(Point(0, 0));
    // ObjectManager::Instance()->AddObject(transferGate);
    // NextStage();
}

void StageManager::NextStage() {
    // ObjectManager::Instance()->Clear();
    // stage++;
    // if (stage > 5 && level != 3) {
    //     stage = 1;
    //     level++;
    // }
    // if (level == 3 && stage == 7) {
    //     success = true;
    // }
    // else {
    //     delete gameStage;
    //     gameStage = StageFactory::Create(level, stage);
    //     if (!gameStage) {
    //         gameStage = new Stage_1_1();
    //     }
    //     gameStage->Initialize();
    // }
    
}

void StageManager::SetTransferGatePosition(Vec position) {
    transferGate->SetPosition(position);
}

bool StageManager::GetSuccess() {
    return success;
}