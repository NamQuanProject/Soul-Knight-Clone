#pragma once
#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>


#include "../entities/player/playerType.h"
#include "../entities/gameObject.h"
#include "../entities/projectile/bullet.h"
#include "../utils/point.h"
#include "../utils/vec.h"
#include "../entities/player/player.h"
#include "../entities/monster/monster.h"

using std::vector;

class Monster;
class Player;

class ObjectManager {
public:
    static ObjectManager* Instance();
    ObjectManager();
    ~ObjectManager();
    Player* GetPlayer();
    Point* GetScreenPoint();
    void AddObject(GameObject* object);
    void Start();
    void Update();
    void Show();
    void KeyDown(char key);
    void KeyUp(char key);
    void SetLButtonPress(bool isPressed);
    void SetPlayerVision(Vec vision);
    void SetPlayerPosition(Point playerPosition);
    void MakeMoney(int money);
    bool SpendMoney(int money);
    int GetMoney();
    void Clear();

    PlayerType GetPlayerType();
    void SetPlayerType(PlayerType playerType);

private:
    int screenX = 0;
    int screenY = 0;
    bool LButtonPressed;
    bool isDisplayHitBox;
    static ObjectManager* instance;
    Player* player;
    vector<GameObject*> objects;
    vector<GameObject*> newObjects;
    PlayerType playerType;

    void DeleteObsoleteElements();
    void PushNewObjectsToList();
    void CollisionDetection();
};