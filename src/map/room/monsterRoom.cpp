// #include "monsterRoom.h"


// MonsterRoom::MonsterRoom(Point leftTop, Vec centerOffset, RoomSize size, int level, std::map<MonsterType, int> monsterMap, bool isBossRoom)
//     : Room(leftTop, centerOffset, size), level(level), isBossRoom(isBossRoom), monsterMap(monsterMap) {
//     SetMonsters();
//     SetDoors();
// }

// MonsterRoom::MonsterRoom(Point leftTop, Vec centerOffset, RoomSize size, int level, int stage, bool isBossRoom)
//     : Room(leftTop, centerOffset, size), level(level), isBossRoom(isBossRoom) {
//     GenerateMonsterMapRandomly(stage);
//     SetMonsters();
//     SetDoors();
// }

// MonsterRoom::~MonsterRoom() {
//     for (Wall* wall : walls)
//         delete wall;
//     for (Door* door : doors)
//         delete door;
//     for (Monster* monster : monsters)
//         delete monster;
// }

// void MonsterRoom::SetMonsters() {
//     for (const auto& pair : monsterMap) {
//         MonsterType type = pair.first;
//         int count = pair.second;

//         for (int i = 0; i < count; ++i) {
//             // Generate a random position for the monster within the room bounds
//             float x = leftTop.GetX() + (std::rand() % (centerOffset.x * 2));
//             float y = leftTop.GetY() + (std::rand() % (centerOffset.y * 2));
//             monsters.push_back(new Monster(type, Point(x, y), level));
//         }
//     }
// }

// void MonsterRoom::PlacedMonster() {
//     // Ensure monsters are properly positioned within the room and not overlapping
//     for (Monster* monster : monsters) {
//         // Adjust monster positions if necessary (logic can vary depending on game needs)
//         std::cout << "Monster placed at: (" << monster->GetPosition().GetX() << ", "
//                   << monster->GetPosition().GetY() << ")" << std::endl;
//     }
// }

// void MonsterRoom::SetDoors() {
//     // Example door placement logic (e.g., top, bottom, left, right walls)
//     doors.push_back(new Door(Point(leftTop.GetX(), leftTop.GetY() + centerOffset.y), Direction::UP));
//     doors.push_back(new Door(Point(leftTop.GetX() + centerOffset.x * 2, leftTop.GetY() + centerOffset.y), Direction::DOWN));
//     doors.push_back(new Door(Point(leftTop.GetX() + centerOffset.x, leftTop.GetY()), Direction::LEFT));
//     doors.push_back(new Door(Point(leftTop.GetX() + centerOffset.x, leftTop.GetY() + centerOffset.y * 2), Direction::RIGHT));
// }

// void MonsterRoom::GenerateMonsterMapRandomly(int stage) {
//     // Example logic for generating monsters randomly based on the stage
//     int numMonsters = 5 + stage; // Increase monster count with stage
//     for (int i = 0; i < numMonsters; ++i) {
//         MonsterType type = static_cast<MonsterType>(std::rand() % static_cast<int>(MonsterType::COUNT));
//         ++monsterMap[type];
//     }
// }

// void MonsterRoom::IsInside() {
//     if (!isInside) {
//         isInside = true;
//         std::cout << "Player has entered the MonsterRoom." << std::endl;
//     }
// }

// void MonsterRoom::IsCleared() {
//     if (!isCleared && monsters.empty()) {
//         isCleared = true;
//         std::cout << "The MonsterRoom has been cleared!" << std::endl;
//     }
// }

// void MonsterRoom::RelocatePlayerToNearestEdge() {
//     // Logic to move the player to the nearest edge in case of invalid positioning
//     // Example: Moving to the closest wall
//     std::cout << "Relocating player to nearest edge." << std::endl;
//     // Implement game-specific logic here
// }
