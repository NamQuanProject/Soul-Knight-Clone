#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "../entities/player/playerType.h"
#include "../entities/gameObject.h"
#include "../entities/player/player.h"
#include "../entities/player/heroes/knight.h"
#include "../entities/monster/monster.h"
#include "../utils/point.h"
#include "../utils/vec.h"

using std::vector;

class ObjectManager {
public:
    static ObjectManager* Instance();
    ObjectManager();
    ~ObjectManager();  

    void Initialize();

    
    Player* GetPlayer();
    void AddObject(GameObject* object);
    void Update(float deltaTime);
    void Render(sf::RenderWindow& window);
    void SetPlayerPosition(Vec& playerposition);
    void DeleteObsoleteElements();
    void getSize();

    void KeyDown(char key);
    void KeyUp(char key);
    void SetKButtonPress(bool isPress);
    void Clear();

    PlayerType GetPlayerType();
    void SetPlayerType(PlayerType playerType);
    vector<GameObject*> getAllCurrentMonster();
    vector<Vec> getAllCurrentMonsterPosition();
    void PushNewObjectsToList();
private:
    static ObjectManager* instance;
    int screenX = 0;
    int screenY = 0;
    
    bool KButtonPressed;
    


    Player* player;
    PlayerType playerType;
    vector<GameObject*> objects;
    vector<GameObject*> currentMonsters;
    vector<GameObject*> newObjects;
    void CollisionDetection();
    void DeleteAllObjects();
    

};
