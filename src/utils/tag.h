#pragma once

enum class Tag {
    NONE,
    PLAYER,
    PROJECTILE,
    MONSTER,
    WALL,
    
    DROP,
    TREASURE_CHEST,
    PLAYER_ATTACK,
    MONSTER_ATTACK,
    
    PLAYER_WEAPON,
    MONSTER_WEAPON,
    
    TRANSFER_GATE,
    OBSTACLE,

    PLAYER_ALERTABLE,
    INTERACTABLE,
    COLLECTABLE,
    POTION,
    DEAD,

    REMOVE_ON_NEXT_FRAME,


    Count 
};