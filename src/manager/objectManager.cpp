#include "objectManager.h"
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
    this->player = new Knight();


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
    for (auto object : objects) {
        object->Render(window);
    }
}

void ObjectManager::SetPlayerPosition(Vec& position) {
    if (player) {
        player->SetPosition(position);
    }
}

void ObjectManager::CollisionDetection() {
    
    for (int i = 0; i < objects.size(); i++) {
        for (int j = i + 1; j < objects.size(); j++) {
            if (objects[i]->GetHitBox()->IsCollision(objects[j]->GetHitBox())) {
                objects[i]->Collision(objects[j]);
                objects[j]->Collision(objects[i]);
            }
        }
    }
}
void ObjectManager::DeleteObsoleteElements() {
    for (vector<GameObject*>::iterator object = objects.begin(); object != objects.end();) {
        if ((*object)->HasTag(Tag::REMOVE_ON_NEXT_FRAME)) {
            (*object)->RemoveTag(Tag::REMOVE_ON_NEXT_FRAME);

            
            delete *object;
            *object = nullptr;
            
            object = objects.erase(object);
        }
        else { ++object; }
    }
}


void ObjectManager::Clear() {
    for (auto object : objects) {
        if (object->HasTag(Tag::PLAYER) || object->HasTag(Tag::TRANSFER_GATE)) {
            continue;
        }
        object->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
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