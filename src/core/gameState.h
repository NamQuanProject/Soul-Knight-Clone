#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../manager/objectManager.h"
#include "../manager/stageManager.h"
#include "../manager/keyboardManager.h"
// #include "../manager/UIManager.h"
// #include "../pool/dropPool.h"
#include "../pool/monsterPool.h"
#include "../pool/projectilePool.h"






class GameState : public State {
public:
    GameState();
    ~GameState();
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void Initialize() override;
    
protected:
    ObjectManager* objectManager = ObjectManager::Instance();
    StageManager* stageManager = StageManager::Instance();

    ProjectilePool* projectilePool = ProjectilePool::Instance();
    MonsterPool* monsterPool = MonsterPool::Instance();
    
    int gameFinishCounter;
};

#endif // GAMESTATE_H
