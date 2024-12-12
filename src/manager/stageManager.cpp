#include "stageManager.h"




StageManager* StageManager::instance = nullptr;

StageManager* StageManager::Instance() {
    if (instance == nullptr) {
        instance = new StageManager();
    }
    return instance;
}

StageManager::StageManager(): level(0), stage(0), success(false) {

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

void StageManager::Initialize() {
    transferGate = new TransferGate();
    transferGate->Initialize();
    Vec vector = Vec(0.0, 0.0);
    transferGate->SetPosition(vector);
    ObjectManager::Instance()->AddObject(transferGate);
    NextStage();
    
}

void StageManager::NextStage() {
    ObjectManager::Instance()->Clear();
    stage++;
    
    if (gameStage != nullptr) {
        delete gameStage;
        gameStage = nullptr;  
    }


    if (stage == 2) {
        std::cout << "STAGE 2" << std::endl;
        gameStage = new Stage_1_2();
        gameStage->Initialize();
    }
    else {
        gameStage = new Stage_1_1();
        gameStage->Initialize();
    }
    
}

void StageManager::SetTransferGatePosition(Vec position) {
    transferGate->SetPosition(position);
}

bool StageManager::GetSuccess() {
    return success;
}