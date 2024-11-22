#include <SFML/Graphics.hpp>
#include "../../utils/point.h"
#include "../room/monsterRoom.h"



class Monster;
class Wall;
class VendingMachine;

class Stage {
public:
    Stage();
    virtual ~Stage();
    sf::Sprite GetBackground();
    void Initialize();
    void Show(Point screenPositoin);
    void AddWall(Point point1, Point point2);
    void IsInsideRoom();
    void IsRoomCleared();

protected:
    sf::Sprite background;
    Vec centerOffset;
    virtual void GenerateWall() = 0;
    virtual void SetPlayerPosition() = 0;
    virtual void SetTransferGate() = 0;
    virtual void GenerateObstacle() = 0;
    // std::vector<MonsterRoom*> monsterRooms;
    // TreasureRoom* treasureRoom;
    std::vector<Wall*> walls;
    VendingMachine* vendingMachine;
};