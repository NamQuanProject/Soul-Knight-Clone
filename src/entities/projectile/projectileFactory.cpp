#include "projectileFactory.h"

#include "projectileType.h"
#include "projectile.h"
// #include "bullet/Arrow.h"
#include "bullet/badPistolBullet.h"
#include "bullet/redCircleBullet.h"
// #include "bullet/BigRedCircleBullet.h"
// #include "bullet/BigYellowCircleBullet.h"
// #include "bullet/GasBlasterBullet.h"
// #include "bullet/GreenRectangleBullet.h"
// #include "bullet/RedCircleBullet.h"
// #include "bullet/RedConicalBullet.h"
// #include "bullet/RedDiamondBullet.h"
// #include "bullet/RedHollowCircleBullet.h"
// #include "bullet/RedRectangleBullet.h"
// #include "bullet/RedSplinterBullet.h"
// #include "bullet/RedSquareBullet.h"
// #include "bullet/RedTriangleBullet.h"
// #include "bullet/RPG.h"
// #include "bullet/Shit.h"
// #include "bullet/SmallYellowCircleBullet.h"
// #include "bullet/SpiralBullet.h"
// #include "bullet/SplitterCannonBullet.h"
// #include "bullet/YellowRectangleBullet.h"
// #include "bullet/ZulanAngryBullet.h"
// #include "shock_wave/BlowUp.h"
// #include "shock_wave/HammerWave.h"

Projectile* ProjectileFactory::Create(ProjectileType type) {
    switch (type) {
    // bullet
    // case ProjectileType::ARROW:
    //     return new Arrow();
    case ProjectileType::BAD_PISTOL_BULLET:
        return new BadPistolBullet();
    case ProjectileType::RED_CIRCLE_BULLET:
        return new RedCircleBullet();
    // case ProjectileType::RED_DIAMOND_BULLET:
    //     // return new RedCircleBullet();
    

    // case ProjectileType::RED_DIAMOND_BULLET:
    //     return new RedDiamondBullet();
    // case ProjectileType::RED_RECTANGLE_BULLET:
    //     return new RedRectangleBullet();
    
    // case ProjectileType::RED_SPLINTER_BULLET:
    //     return new RedSplinterBullet();
    // case ProjectileType::GAS_BLASTER_BULLET:
    //     return new GasBlasterBullet();
    // case ProjectileType::RED_SQUARE_BULLET:
    //     return new RedSquareBullet();
    // case ProjectileType::BIG_RED_CIRCLE_BULLET:
    //     return new BigRedCircleBullet();
    // case ProjectileType::RED_HOLLOW_CIRCLE_BULLET:
    //     return new RedHollowCircleBullet();
    // case ProjectileType::RED_CONICAL_BULLET:
    //     return new RedConicalBullet();
    // case ProjectileType::SPIRAL_BULLET:
    //     return new SpiralBullet();
    // case ProjectileType::ZULAN_ANGRY_BULLET:
    //     return new ZulanAngryBullet();
    // case ProjectileType::RED_TRIANGLE_BULLET:
    //     return new RedTriangleBullet();
    // case ProjectileType::GREEN_RECTANGLE_BULLET:
    //     return new GreenRectangleBullet();
    // case ProjectileType::YELLOW_RECTANGLE_BULLET:
    //     return new YellowRectangleBullet();
    // case ProjectileType::SMALL_YELLOW_CIRCLE_BULLET:
    //     return new SmallYellowCircleBullet();
    // case ProjectileType::BIG_YELLOW_CIRCLE_BULLET:
    //     return new BigYellowCircleBullet();
    // case ProjectileType::SPLITTER_CANNON_BULLET:
    //     return new SplitterCannonBullet();
    // case ProjectileType::RPG:
    //     return new RPG();
    // case ProjectileType::SHIT:
    //     return new Shit();
    // // shock wave
    // case ProjectileType::HAMMER_WAVE:
    //     return new HammerWave();
    // case ProjectileType::BLOW_UP:
    //     return new BlowUp();
    // // other
    // case ProjectileType::INVISIBLE_SHOCK_WAVE:
    //     return new InvisibleShockWave();
    default:
        return nullptr;
    }
}