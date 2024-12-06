#pragma once
#include "../map/stage/transferGate.h"
#include <iostream>

#include "objectManager.h"
#include "../map/stage/stageFactory.h"
#include "../map/stage/stage_1_1.h"
#include "../entities/player/player.h"
#include "../utils/point.h"
#include "../utils/vec.h"


class StageManager {
public:
    static StageManager* Instance();
    StageManager();
    ~StageManager();
    void Update(float deltaTime);
    Stage* GetStage();
    int GetStageNumber();
    int GetLevelNumber();
    void Initiliaze();
    void NextStage();
    void SetTransferGatePosition(Vec position);
    bool GetSuccess();

private:
    static StageManager* instance;
    int level;
    int stage;
    Stage* gameStage = nullptr;
    TransferGate* transferGate = nullptr;
    bool success;
};