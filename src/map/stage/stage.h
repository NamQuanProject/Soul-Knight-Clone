#pragma once 
#include <SFML/Graphics.hpp>
#include "../../utils/point.h"
#include "../wall/wall.h"
#include "../../manager/objectManager.h"
#include "../room/monsterRoom.h"
#include "../room/treasureRoom.h"





class Stage {
public:
    Stage();
    virtual ~Stage();
    virtual void Update(float deltaTime) = 0;
    virtual void setBackground() = 0;
    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void Initialize();
    void Show(Point screenPositoin);
    void AddWall(Point point1, Point point2);
    void IsInsideRoom();
    void IsRoomCleared();

protected:
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    Vec centerOffset;
    std::vector<Wall*> walls;
    std::vector<MonsterRoom*> monsterRooms;
    
    virtual void GenerateWall() = 0;
    virtual void SetPlayerPosition() = 0;
    virtual void SetTransferGate() = 0;
    virtual void GenerateObstacle() = 0;
    
    TreasureRoom* treasureRoom;
private:
    
    
};