#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../manager/camera.h"
#include "../manager/objectManager.h"
#include "../manager/stageManager.h"
#include "../manager/keyboardManager.h"
#include "../manager/UIManager.h"
#include "../utils/random.h"
#include "../manager/soundManager.h"
// #include "../manager/UIManager.h"
// #include "../pool/dropPool.h"
#include "../pool/monsterPool.h"
#include "../pool/projectilePool.h"
#include <cmath>







class GameState : public State {
public:
    GameState();
    ~GameState();
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void Initialize() override;
    
protected:
    Rand* randGen = Rand::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();
    StageManager* stageManager = StageManager::Instance();
    UIManager* uiManager = UIManager::Instance();
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    MonsterPool* monsterPool = MonsterPool::Instance();
    SoundManager soundManager;
    int gameFinishCounter;
    
};

#endif // GAMESTATE_H
