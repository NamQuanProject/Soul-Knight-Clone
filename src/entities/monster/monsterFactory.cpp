#include "monsterFactory.h"

// #include "boss/zulan_the_colossus/ZulanTheColossus.h"
#include "floor_1/goblin_giant/goblinGiant.h"
#include "floor_1/bear/bear.h"
// #include "/floor_1/boar/DireBoar.h"
// #include "/floor_1/boar/NormalBoar.h"
// #include "/floor_1/devils_snare/DevilsSnare.h"
// #include "/floor_1/elite_goblin_guard/EliteGoblinGuardDart.h"
// #include "/floor_1/elite_goblin_guard/EliteGoblinGuardHoe.h"
// #include "/floor_1/elite_goblin_guard/EliteGoblinGuardShotgun.h"
// #include "/floor_1/goblin_guard/GoblinGuardBow.h"
// #include "/floor_1/goblin_guard/GoblinGuardPistol.h"
// #include "/floor_1/goblin_guard/GoblinGuardSpear.h"
#include "floor_1/goblin_shaman/goblinShaman.h"
#include "floor_2/skeleton/skeleton.h"
#include "floor_2/spider/spider.h"
#include "floor_3/valkoryn/valkoryn.h"
// #include "/floor_2/battery/Battery.h"
// #include "/floor_2/big_skeleton/BigSkeleton.h"
// #include "/floor_2/elite_skeleton/EliteSkeletonCurvedSword.h"
// #include "/floor_2/elite_skeleton/EliteSkeletonRifle.h"
// #include "/floor_2/elite_skeleton/EliteSkeletonShotgun.h"
// #include "/floor_2/skeleton/SkeletonBow.h"
// #include "/floor_2/skeleton/SkeletonCurvedSword.h"
// #include "/floor_2/skeleton/SkeletonShotgun.h"
// #include "/floor_2/skeleton_shaman/SkeletonShaman.h"
// #include "/floor_2/spider/PoisonSpider.h"
// #include "/floor_2/spider/Spider.h"
// #include "/floor_3/alien/AlienMachineGun.h"
// #include "/floor_3/alien/AlienRedLightsaber.h"
// #include "/floor_3/goblin/Goblin.h"
// #include "/floor_3/goblin_fly/GoblinFly.h"
// #include "/floor_3/ufo/UFO.h"

// #include "/floor_3/varkolyn_guard/VarkolynGuardAxe.h"
// #include "/floor_3/varkolyn_guard/VarkolynGuardMachinGun.h"

Monster* MonsterFactory::Create(MonsterType type, double level) {
    switch (type) {
    // level 1
    // case Type::DEVELS_SNARE:
    //     return new DevilsSnare(level);
    case MonsterType::GOBLIN_GIANT:
        return new GoblinGiant(level);
    case MonsterType::NORMAL_BOAR:
        return new Bear(level);
    case MonsterType::GOBLIN_SHAMAN:
        return new GoblinShaman(level);
    
    // case Type::GOBLIN_GUARD_SPEAR:
    //     return new GoblinGuardSpear(level);
    // case Type::GOBLIN_GUARD_PISTOL:
    //     return new GoblinGuardPistol(level);
    // case Type::GOBLIN_GUARD_BOW:
    //     return new GoblinGuardBow(level);

    // case Type::ELITE_GOBLIN_GUARD_SHOTGUN:
    //     return new EliteGoblinGuardShotgun(level);
    // case Type::ELITE_GOBLIN_GUARD_DART:
    //     return new EliteGoblinGuardDart(level);
    // case Type::ELITE_GOBLIN_GUARD_HOE:
    //     return new EliteGoblinGuardHoe(level);

    

    
    // case Type::DIRE_BOAR:
    //     return new DireBoar(level);

    // level 2
    case MonsterType::SKELETON_BOW:
        return new Skeleton(level);
    
    // case Type::SKELETON_CURVED_SWORD:
    //     return new SkeletonCurvedSword(level);
    // case Type::SKELETON_SHOTGUN:
    //     return new SkeletonShotgun(level);
    // case Type::ELITE_SKELETON_CURVED_SWORD:
    //     return new EliteSkeletonCurvedSword(level);
    // case Type::ELITE_SKELETON_RIFLE:
    //     return new EliteSkeletonRifle(level);
    // case Type::ELITE_SKELETON_SHOTGUN:
    //     return new EliteSkeletonShotgun(level);
    // case Type::BIG_SKELETON:
    //     return new BigSkeleton(level);
    // case Type::SKELETON_SHAMAN:
    //     return new SkeletonShaman(level);
    case MonsterType::SPIDER:
        return new Spider(level);
    // case Type::POISON_SPIDER:
    //     return new PoisonSpider(level);
    // case Type::BATTERY:
    //     return new Battery(level);

    // case Type::ZULAN:
    //     return new ZulanTheColossus();
    // case Type::ALIEN_MACHINE_GUN:
    //     return new AlienMachineGun(level);
    // case Type::ALIEN_RED_LIGHTSABER:
    //     return new AlienRedLightsaber(level);
    // case Type::UFO:
    //     return new UFO(level);
    // case Type::VARKOLYN_GUARD_AXE:
    //     return new VarkolynGuardAxe(level);
    // case Type::VARKOLYN_GUARD_MACHINE_GUN:
    //     return new VarkolynGuardMachinGun(level);
    case MonsterType::VARKOLYN:
        return new Valkoryn(level);
    // case Type::GOBLIN:
    //     return new Goblin(level);
    // case Type::GOBLIN_FLY:
    //     return new GoblinFly(level);
    default:
        return nullptr;
    }
}