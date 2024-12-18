#include "stage_1_3.h"
#include "../../manager/objectManager.h"
#include "../../manager/UIManager.h"
#include "../../manager/stageManager.h"
#include "../room/roomSize.h"
#include "../room/monsterRoom.h"

Stage_1_3::Stage_1_3() {
    setBackground();
    SetPlayerPosition();
    AddWallsToMap();
    SetTransferGate();
    // MonsterRoom* room1 = new MonsterRoom(Point(543, 14), Point(880, 353), 1, 1, 1);
    // MonsterRoom* room2 = new MonsterRoom(Point(1229, 655), Point(1473, 896), 1, 1, 1);
    // monsterRooms.push_back(room1);
    // monsterRooms.push_back(room2);


    
    


}

void Stage_1_3::Initialize() {
    setBackground();
    AddWallsToMap();
    SetPlayerPosition();
    SetTransferGate();



    MonsterRoom* room1 = new MonsterRoom(Point(542, 608), Point(882, 947), 1, 1, 3);
    MonsterRoom* room2 = new MonsterRoom(Point(1824, 607), Point(2159, 947), 1, 1, 3);
    MonsterRoom* room3 = new MonsterRoom(Point(1226, 652), Point(1474, 898), 1, 1, 3);
    monsterRooms.push_back(room1);
    monsterRooms.push_back(room2);
    monsterRooms.push_back(room3);
}

Stage_1_3::~Stage_1_3() {
    
}

void Stage_1_3::AddWallsToMap() {
    AddWall(Point(2, 672), Point(208, 688));
    AddWall(Point(0, 689), Point(15, 878));
    AddWall(Point(15, 864), Point(208, 880));
    AddWall(Point(192, 689), Point(208, 736));
    AddWall(Point(192, 815), Point(208, 867));
    AddWall(Point(208, 722), Point(529, 738));
    AddWall(Point(208, 816), Point(529, 832));
    AddWall(Point(529, 592), Point(544, 737));
    AddWall(Point(529, 816), Point(544, 959));
    AddWall(Point(542, 592), Point(673, 607));
    AddWall(Point(752, 592), Point(896, 608));
    AddWall(Point(878, 607), Point(896, 736));
    AddWall(Point(880, 815), Point(896, 960));
    AddWall(Point(542, 944), Point(673, 960));
    AddWall(Point(752, 944), Point(882, 960));
    AddWall(Point(894, 722), Point(1232, 736));
    AddWall(Point(896, 816), Point(1232, 832));
    AddWall(Point(1217, 641), Point(1232, 724));
    AddWall(Point(1217, 830), Point(1232, 913));
    AddWall(Point(1228, 640), Point(1488, 656));
    AddWall(Point(1472, 651), Point(1488, 736));
    AddWall(Point(1230, 896), Point(1311, 914));
    AddWall(Point(1390, 895), Point(1488, 911));
    AddWall(Point(1472, 815), Point(1488, 896));
    AddWall(Point(1486, 722), Point(1824, 736));
    AddWall(Point(1488, 816), Point(1824, 832));
    AddWall(Point(1809, 592), Point(1824, 723));
    AddWall(Point(1820, 592), Point(2174, 608));
    AddWall(Point(2157, 606), Point(2175, 960));
    AddWall(Point(1809, 831), Point(1824, 960));
    AddWall(Point(1824, 944), Point(2174, 960));
    AddWall(Point(577, 0), Point(848, 15));
    AddWall(Point(577, 14), Point(592, 272));
    AddWall(Point(832, 15), Point(848, 271));
    AddWall(Point(592, 256), Point(673, 271));
    AddWall(Point(752, 256), Point(836, 271));
    AddWall(Point(655, 959), Point(673, 1280));
    AddWall(Point(752, 957), Point(769, 1280));
    AddWall(Point(657, 270), Point(673, 593));
    AddWall(Point(752, 272), Point(769, 593));
    AddWall(Point(577, 1280), Point(673, 1295));
    AddWall(Point(752, 1280), Point(846, 1297));
    AddWall(Point(577, 1297), Point(592, 1551));
    AddWall(Point(830, 1297), Point(848, 1551));
    AddWall(Point(586, 1534), Point(838, 1551));
    AddWall(Point(1296, 912), Point(1311, 1233));
    AddWall(Point(1392, 912), Point(1407, 1235));
    AddWall(Point(1249, 1233), Point(1313, 1248));
    AddWall(Point(1392, 1233), Point(1455, 1248));
    AddWall(Point(1248, 1242), Point(1263, 1440));
    AddWall(Point(1440, 1249), Point(1455, 1441));
    AddWall(Point(1263, 1425), Point(1440, 1440));
}

void Stage_1_3::Update(float deltaTime) {
    for (auto room : monsterRooms) {
        room->Update(deltaTime);
    }
    
}


void Stage_1_3::setBackground() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/new_map/map3.bmp")) {
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

  
    sf::Vector2u imageSize = image.getSize(); 
    sf::FloatRect worldBounds(0, 0, static_cast<float>(imageSize.x), static_cast<float>(imageSize.y));
    UIManager::Instance()->setWorldBounds(worldBounds);
}

void Stage_1_3::Render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    
    // for (Wall* wall : walls) {
    //     wall->Render(window); 
    // }
    // for (auto room : monsterRooms) {
    //     room->Show(window);
    // }
    
    
}


void Stage_1_3::Collision(GameObject* gameObject) {
    for (Wall* wall : walls) {
        wall->Collision(gameObject);
    }
}



void Stage_1_3::SetPlayerPosition() {

    
    Vec knightPosition(1353,1339);
    ObjectManager::Instance()->SetPlayerPosition(knightPosition);
}


void Stage_1_3::SetTransferGate() {
   StageManager::Instance()->SetTransferGatePosition(Vec(713, 124));
}

void Stage_1_3::GenerateObstacle() {
    
}

void Stage_1_3::GenerateWall() {

}
