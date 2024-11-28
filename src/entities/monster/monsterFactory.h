#pragma once
#include "monster.h"
#include "monsterType.h"

class MonsterFactory {
public:
    static Monster* Create(MonsterType type, double level = 1);
};