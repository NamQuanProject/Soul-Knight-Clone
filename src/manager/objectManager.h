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

    Player* GetPlayer();
    void AddObject(GameObject* object);
    void Update(float deltaTime);
    void Render(sf::RenderWindow& window);
    void SetPlayerPosition(Vec& playerposition);
    void DeleteObsoleteElements();
private:
    int screenX = 0;
    int screenY = 0;
    static ObjectManager* instance;
    Player* player;
    vector<GameObject*> objects;

    void CollisionDetection();
    void DeleteAllObjects();
};
