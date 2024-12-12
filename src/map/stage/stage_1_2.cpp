#include "stage_1_2.h"
#include "../../manager/objectManager.h"
#include "../../manager/stageManager.h"
#include "../room/roomSize.h"
#include "../room/monsterRoom.h"

Stage_1_2::Stage_1_2() {
    setBackground();
    SetPlayerPosition();
    AddWallsToMap();
    SetTransferGate();
    // MonsterRoom* room1 = new MonsterRoom(Point(543, 14), Point(880, 353), 1, 1, 1);
    // MonsterRoom* room2 = new MonsterRoom(Point(1229, 655), Point(1473, 896), 1, 1, 1);
    // monsterRooms.push_back(room1);
    // monsterRooms.push_back(room2);


    
    


}

void Stage_1_2::Initialize() {
    setBackground();
    SetPlayerPosition();
    AddWallsToMap();
    SetTransferGate();


    MonsterRoom* room1 = new MonsterRoom(Point(622, 541), Point(961, 882), 1, 1, 1);
    MonsterRoom* room2 = new MonsterRoom(Point(1311, 588), Point(1552, 834), 1, 1, 1);
    monsterRooms.push_back(room1);
    monsterRooms.push_back(room2);
}

Stage_1_2::~Stage_1_2() {
    
}

void Stage_1_2::AddWallsToMap() {
    AddWall(Point(17, 576), Point(31, 848));
    AddWall(Point(31, 575), Point(287, 591));
    AddWall(Point(270, 589), Point(287, 672));
    AddWall(Point(30, 830), Point(287, 847));
    AddWall(Point(272, 751), Point(287, 833));
    AddWall(Point(287, 656), Point(607, 670));
    AddWall(Point(287, 751), Point(609, 768));
    AddWall(Point(607, 528), Point(624, 671));
    AddWall(Point(609, 750), Point(624, 895));
    AddWall(Point(622, 527), Point(752, 543));
    AddWall(Point(831, 528), Point(976, 543));
    AddWall(Point(626, 879), Point(750, 895));
    AddWall(Point(831, 880), Point(976, 895));
    AddWall(Point(959, 751), Point(976, 881));
    AddWall(Point(959, 540), Point(976, 672));
    AddWall(Point(974, 656), Point(1311, 671));
    AddWall(Point(976, 750), Point(1313, 768));
    AddWall(Point(1296, 575), Point(1311, 656));
    AddWall(Point(1311, 575), Point(1568, 591));
    AddWall(Point(1296, 766), Point(1311, 848));
    AddWall(Point(1552, 591), Point(1568, 671));
    AddWall(Point(1311, 832), Point(1566, 847));
    AddWall(Point(1552, 752), Point(1568, 832));
    AddWall(Point(1568, 655), Point(1903, 672));
    AddWall(Point(1568, 752), Point(1903, 767));
    AddWall(Point(1889, 607), Point(1903, 657));
    AddWall(Point(1903, 608), Point(2094, 623));
    AddWall(Point(2079, 622), Point(2094, 814));
    AddWall(Point(1889, 764), Point(1903, 816));
    AddWall(Point(1900, 799), Point(2081, 817));
    AddWall(Point(687, 0), Point(896, 15));
    AddWall(Point(689, 12), Point(702, 208));
    AddWall(Point(700, 192), Point(752, 208));
    AddWall(Point(880, 14), Point(896, 208));
    AddWall(Point(831, 191), Point(881, 207));
    AddWall(Point(735, 205), Point(752, 529));
    AddWall(Point(831, 207), Point(848, 529));
    AddWall(Point(735, 894), Point(754, 1216));
    AddWall(Point(830, 894), Point(848, 1216));
    AddWall(Point(655, 1214), Point(754, 1231));
    AddWall(Point(833, 1216), Point(928, 1231));
    AddWall(Point(655, 1227), Point(670, 1486));
    AddWall(Point(911, 1231), Point(928, 1486));
    AddWall(Point(668, 1470), Point(913, 1487));
}

void Stage_1_2::Update(float deltaTime) {
    for (auto room : monsterRooms) {
        room->Update(deltaTime);
    }
    
}


void Stage_1_2::setBackground() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/new_map/map2.bmp")) {
        std::cerr << "Error: Could not load background image!" << std::endl;
        return;
    }

    sf::Color transparentColor(255, 255, 255);
    image.createMaskFromColor(transparentColor);
    if (!backgroundTexture.loadFromImage(image)) {
        std::cerr << "Error: Could not load texture from image!" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
}


void Stage_1_2::Render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    
    // for (Wall* wall : walls) {
    //     wall->Render(window); 
    // }
    // for (auto room : monsterRooms) {
    //     room->Show(window);
    // }
    
    
}


void Stage_1_2::Collision(GameObject* gameObject) {
    for (Wall* wall : walls) {
        wall->Collision(gameObject);
    }
}



void Stage_1_2::SetPlayerPosition() {
    Vec knightPosition(792,91);
    ObjectManager::Instance()->SetPlayerPosition(knightPosition);
}


void Stage_1_2::SetTransferGate() {
   StageManager::Instance()->SetTransferGatePosition(Vec(1913, 184));
}

void Stage_1_2::GenerateObstacle() {
    
}

void Stage_1_2::GenerateWall() {

}
