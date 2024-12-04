#include "stage_1_1.h"
#include "../../manager/objectManager.h"
// #include "../../manager/stageManager.h"
#include "../room/roomSize.h"

Stage_1_1::Stage_1_1() {
    setBackground();
    AddWallsToMap();
}



Stage_1_1::~Stage_1_1() {
    
}

void Stage_1_1::AddWallsToMap() {
    // Add walls using the AddWall method
    AddWall(Point(4, 82), Point(207, 97));
    AddWall(Point(0, 97), Point(16, 272));
    AddWall(Point(0, 273), Point(207, 286));
    AddWall(Point(192, 96), Point(207, 142));
    AddWall(Point(191, 224), Point(208, 273));
    AddWall(Point(210, 128), Point(525, 142));
    AddWall(Point(210, 225), Point(527, 238));
    AddWall(Point(529, 16), Point(545, 142));
    AddWall(Point(529, 225), Point(543, 352));
    AddWall(Point(529, 2), Point(894, 16));
    AddWall(Point(527, 351), Point(671, 369));
    AddWall(Point(753, 353), Point(894, 367));
    AddWall(Point(882, 16), Point(894, 142));
    AddWall(Point(878, 225), Point(896, 350));
    AddWall(Point(898, 129), Point(1215, 142));
    AddWall(Point(898, 225), Point(1215, 241));
    AddWall(Point(1218, 66), Point(1231, 139));
    AddWall(Point(1216, 228), Point(1231, 305));
    AddWall(Point(1216, 46), Point(1487, 64));
    AddWall(Point(1216, 305), Point(1311, 319));
    AddWall(Point(1393, 304), Point(1487, 317));
    AddWall(Point(1469, 66), Point(1487, 142));
    AddWall(Point(1473, 226), Point(1487, 303));
    AddWall(Point(1491, 128), Point(1808, 144));
    AddWall(Point(1491, 224), Point(1806, 239));
    AddWall(Point(1809, 96), Point(1824, 144));
    AddWall(Point(1809, 224), Point(1824, 271));
    AddWall(Point(1808, 82), Point(2014, 96));
    AddWall(Point(1809, 273), Point(2014, 287));
    AddWall(Point(2000, 96), Point(2014, 271));
    AddWall(Point(655, 370), Point(671, 687));
    AddWall(Point(753, 371), Point(768, 687));
    AddWall(Point(595, 687), Point(671, 706));
    AddWall(Point(753, 689), Point(830, 704));
    AddWall(Point(579, 689), Point(591, 942));
    AddWall(Point(832, 687), Point(848, 944));
    AddWall(Point(579, 942), Point(846, 958));
    AddWall(Point(1297, 319), Point(1313, 636));
    AddWall(Point(1393, 317), Point(1407, 639));
    AddWall(Point(1215, 641), Point(1311, 655));
    AddWall(Point(1393, 639), Point(1487, 656));
    AddWall(Point(1215, 652), Point(1232, 896));
    AddWall(Point(1471, 656), Point(1487, 897));
    AddWall(Point(1215, 898), Point(1487, 912));
}

void Stage_1_1::setBackground() {
    sf::Image image;
    if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/map/1-1.bmp")) {
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

void Stage_1_1::Render(sf::RenderWindow& window) {

    // Draw all walls
    // for (Wall* wall : walls) {
    //     wall->Draw(window);  // Assuming the Wall class has a Draw method that draws wallShape
    // }

}


void Stage_1_1::Collision(GameObject* gameObject) {
    for (Wall* wall : walls) {
        wall->Collision(gameObject);  // Check if the player collides with each wall
    }
}
// void Stage_1_1::SetPlayerPosition() {
//     // ObjectManager::Instance()->SetPlayerPosition(Point(345, 300));
// }

// void Stage_1_1::SetTransferGate() {
//     // StageManager::Instance()->SetTransferGatePosition(Point(-900, -300));
// }

// void Stage_1_1::GenerateObstacle() {
//     // Implementation for obstacles if needed
// }