
// #include "dropPool.h"

// #include "../entities/drop/dropFactory.h"
// #include "../entities/drop/dropType.h"
// #include "../entities/drop/Drop.h"

// #define PREALLOCATIONS 20

// DropPool* DropPool::instance = nullptr;

// DropPool* DropPool::Instance() {
//     if (instance == nullptr) {
//         instance = new DropPool();
//     }
//     return instance;
// }

// DropPool::DropPool() {
//     pool = std::vector<std::vector<Drop*>>(static_cast<int>(DropType::COUNT));
// }

// DropPool::~DropPool() {
//     for (auto& vector : pool) {
//         for (auto drop : vector) {
//             delete drop;
//         }
//         vector.clear();
//     }
//     pool.clear();
// }

// void DropPool::Initialize() {
//     for (int i = 0; i < static_cast<int>(DropType::COUNT); i++) {
//         std::vector<Drop*> drops;
//         for (int j = 0; j < PREALLOCATIONS; j++) {
//             Drop* drop = DropFactory::Create(static_cast<DropType>(i));
//             drops.emplace_back(drop);
//         }
//         pool.emplace_back(drops);
//     }
// }

// Drop* DropPool::Acquire(DropType type) {
//     int index = static_cast<int>(type);
//     if (pool[index].empty()) {
//         pool[index].emplace_back(DropFactory::Create(type));
//     }
//     Drop* drop = pool[index].back();
//     pool[index].pop_back();
//     return drop;
// }

// void DropPool::Release(Drop* drop) {
//     pool[static_cast<int>(drop->GetDropType())].emplace_back(drop);
// }