#include "objectManager.h"
#include "../core/selectionState.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>

ObjectManager* ObjectManager::instance = nullptr;

ObjectManager* ObjectManager::Instance() {
    if (instance == nullptr) {
        instance = new ObjectManager();
    }
    return instance;
}










ObjectManager::ObjectManager() : screenX(0), screenY(0), player(nullptr) {}

ObjectManager::~ObjectManager() {
    for (auto object : objects) {
        delete object;
    }
    objects.clear();
}


void ObjectManager::Initialize() {
    objects.reserve(1000);
    std::cout << "OBJECT MANAGER INITIALIZED" << std::endl;
    if (SelectionState::playerSelect == 1) {
        this->player = new Wukong();
    }
    else if (SelectionState::playerSelect == 2) {
        this->player = new Knight();
    }
    std::cout << "PLAYER CREATE" << std::endl;
    
    


    this->objects.emplace_back(this->player);

    std::cout << "PLAYER CREATE" << std::endl;
}


void ObjectManager::Update(float deltaTime) {
    DeleteObsoleteElements();
    if (KButtonPressed) {
        player->Attack();
    }



    for (auto object : objects) {
        object->Update(deltaTime);
    }
    CollisionDetection();
}

Player* ObjectManager::GetPlayer() {
    return player;
}


void ObjectManager::Render(sf::RenderWindow& window) {
    
    std::sort(objects.begin(), objects.end(), [](GameObject* a, GameObject* b) {
        return a->GetPosition().GetY() < b->GetPosition().GetY();
    });
    for (auto object : objects) {        
        object->Render(window);
    }
}

vector<GameObject*> ObjectManager::getAllCurrentMonster() {
    return currentMonsters;
}

vector<Vec> ObjectManager::getAllCurrentMonsterPosition() {
    vector<Vec> position;

    for (auto monster : currentMonsters) {
        position.push_back(monster->GetPosition());
    }
    return position;

}


void ObjectManager::SetPlayerPosition(Vec& position) {
    if (player) {
        player->SetPosition(position);
    }
}

void ObjectManager::CollisionDetection() {
    for (unsigned int i = 0; i < objects.size() - 1; i++) {
        for (unsigned int j = i + 1; j < objects.size(); j++) {
            if (objects[i]->GetHitBox()->IsCollision(objects[j]->GetHitBox())) {
                objects[i]->Collision(objects[j]);
                objects[j]->Collision(objects[i]);
            }
            
        }
    }
}




void ObjectManager::DeleteObsoleteElements() {
    for (auto object = objects.begin(); object != objects.end();) {
        if ((*object)->HasTag(Tag::MONSTER) && (*object)->HasTag(Tag::DEAD)) {
            auto it = std::find(currentMonsters.begin(), currentMonsters.end(), *object);
            if (it != currentMonsters.end()) {
                currentMonsters.erase(it);  // Remove the object from the vector
            }
        }


        if ((*object)->HasTag(Tag::REMOVE_ON_NEXT_FRAME)) {
            (*object)->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);
            
            delete *object;        
            *object = nullptr;      
            object = objects.erase(object);
        } else {
            ++object;
        }
    }
}


void ObjectManager::Clear() {
    for (auto object : objects) {
        if (object->HasTag(Tag::PLAYER) || object->HasTag(Tag::TRANSFER_GATE)) {
            continue;
        }
        object->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
    currentMonsters.clear();

}

void ObjectManager::getSize() {
    size_t length = objects.size();
    std::cout <<  length << std::endl;
}


void ObjectManager::DeleteAllObjects() {
    for (auto object : objects) {
        delete object;
    }
    objects.clear();
}

void ObjectManager::PushNewObjectsToList() {
    objects.insert(objects.end(), newObjects.begin(), newObjects.end());
    newObjects.clear();
    
}

void ObjectManager::AddObject(GameObject* gameObject) {
    if (!gameObject) {
        std::cerr << "Error: Attempted to add a null object to the manager!" << std::endl;
        return;
    }
    if (gameObject->HasTag(Tag::MONSTER)) {
        // Check if the monster is already in the list
        if (std::find(currentMonsters.begin(), currentMonsters.end(), gameObject) == currentMonsters.end()) {
            currentMonsters.push_back(gameObject);
        }
    }


    objects.push_back(gameObject);
}

void ObjectManager::KeyDown(char key) {
//     if (player->GetHP() <= 0) {
//         return;
//     }
//     switch (key) {
//     case 'A':
//         player->SetSpeedX(player->GetSpeed().GetX() - 5);
//         break;
//     case 'D':
//         player->SetSpeedX(player->GetSpeed().GetX() + 5);
//         break;
//     case 'W':
//         player->SetSpeedY(player->GetSpeed().GetY() - 5);
//         break;
//     case 'S':
//         player->SetSpeedY(player->GetSpeed().GetY() + 5);
//         break;
//     case 'E':
//         player->SwitchWeapon();
//         break;
//     case 'F':
//         player->SetInteractive(true);
//         break;
//     case 'Q':
//         player->UseSkill();
//         break;
//     case '1':
//         isDisplayHitBox = !isDisplayHitBox;
//         break;
//     case '2': {
//         player->RecoverMP(100);
//         break;
//     }
//     case '3': {
//         player->Healing(1);
//         break;
//     }
//     case '4': {
//         MakeMoney(100);
//         break;
//     }
//     case '5': {
//         player->SwitchInvincibleMode();
//         break;
//     }
//     case '6': {
//         player->SwitchThroughWallMode();
//         break;
//     }
//     case '7': {
//         InvisibleShockWave* shockWave = dynamic_cast<InvisibleShockWave*>(ProjectilePool::Instance()->Acquire(ProjectileType::INVISIBLE_SHOCK_WAVE));
//         shockWave->SetPosition(player->GetPosition());
//         shockWave->SetDamage(50);
//         shockWave->SetSize(1000);
        
//         shockWave->AddTag(Tag::PLAYER_ATTACK);
//         shockWave->RemoveTag(Tag::MONSTER_ATTACK);
//         AddObject(shockWave);
//         break;
//     }
//     case '8': {
//         GameObject* box = new TreasureChest(TreasureChest::BOSS_ROOM);
//         box->SetPosition(player->GetPosition());
//         AddObject(box);
//         break;
//     }
//     }
// }

// void ObjectManager::KeyUp(char key) {
//     if (player->GetHP() <= 0) {
//         return;
//     }
//     switch (key) {
//     case 'A':
//         player->SetSpeedX(player->GetSpeed().GetX() + 5);
//         break;
//     case 'D':
//         player->SetSpeedX(player->GetSpeed().GetX() - 5);
//         break;
//     case 'W':
//         player->SetSpeedY(player->GetSpeed().GetY() + 5);
//         break;
//     case 'S':
//         player->SetSpeedY(player->GetSpeed().GetY() - 5);
//         break;
//     case 'F':
//         player->SetInteractive(false);
//         break;
//     }
}

void ObjectManager::SetKButtonPress(bool isPress) {
    if (player->GetHP() <= 0) {
        return;
    }
    KButtonPressed = isPress;
}