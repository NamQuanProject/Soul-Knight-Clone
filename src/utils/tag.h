#pragma once

enum class Tag {
    NONE,
    PLAYER,
    MONSTER,
    WALL,
    PROJECTILE,
    DROP,
    
    PLAYER_ATTACK,
    MONSTER_ATTACK,
    
    PLAYER_WEAPON,
    MONSTER_WEAPON,
    
    TRANSFER_GATE,
    OBSTACLE,

    PLAYER_ALERTABLE,
    INTERACTABLE,
    COLLECTABLE,

    DEAD,

    REMOVE_ON_NEXT_FRAME,


    Count 
};