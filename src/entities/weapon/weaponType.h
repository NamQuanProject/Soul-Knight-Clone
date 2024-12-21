#include "weaponFactory.h"

#pragma once

enum class WeaponType {
    // common: white
    CURVED_SWORD,
    BAD_PISTOL,

    // uncommon: green
    HOE,
    SPEAR,
    P250,
    STAFF_OF_LIGHT,
    SPLITTER_CANNON,
    BAZOOKA,

    // rare: blue
    HAMMER,
    BOW,
    BLOWPIPE,

    // epic: purple
    RED_LIGHT_SABER,
    GATLING_GUN,
    PLUNGER_PLUS,

    // legendary: orange
    SHOTGUN,
    SNOW_FOX_VINTAGE,

    // mythic: red
    LONG_BLADE_40M,

    Count
};