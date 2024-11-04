# Let's save the provided directory structure into a text file so the user can view it.

marker = """└──"""
directory_structure = """SoulKnight/
├── core/                                // Core game components
│   ├── application.cpp
│   ├── application.h                  // Main application loop and setup
│   ├── game.cpp
│   ├── game.h                         // Main gameplay logic and initialization
│   ├── state.h                        // Base class for states (Menu, Playing)
│   ├── menuState.cpp
│   ├── menuState.h                    // Menu screen state
│   ├── playState.cpp
│   ├── playState.h                    // Gameplay state
│   ├── pauseState.cpp
│   ├── pauseState.h                   // Pause screen state
│   ├── map.h                          
│   ├── map.cpp                        // Map layout and obstacles
│
├── entities/                            // Entities and characters
│   ├── player/
│   │   ├── player.cpp
│   │   ├── player.h                   // Main player class
│   │   ├── hero.cpp
│   │   ├── hero.h                     // hero classes (subclass of Player)
│   │   ├── heroes/                    // Specific hero
│   │   │   ├── knight.h                 
│   │   │   ├── knight.cpp                   
│   │   │   ├── archer.h                 
│   │   │   ├── archer.cpp             
│   ├── monster/
│   │   ├── Enemy.cpp
│   │   ├── Enemy.h                    // Base enemy class
│   │   ├── Monster.cpp
│   │   ├── Monster.h                  // Common enemies (derived from Enemy)
│   │   ├── Boss.cpp
│   │   ├── Boss.h                     // Boss enemies (derived from Enemy with special abilities)
│   │   └── Minion.cpp
│           Minion.h                   // Smaller enemies (e.g., minions, derived from Enemy)
│   ├── weapon/
│   │   ├── weapon.h
│   │   ├── weapon.cpp                  
│   │   ├── rangeWeapon.h
│   │   ├── rangeWeapon.cpp       
│   │   ├── meleeWeapon.h    
│   │   ├── meleeWeapon.cpp  
│   │   ├── gun/
│   │   │   ├── badpistol.h    
│   │   │   ├── badpistol.cpp   
│   │   ├── melee/
│   │   │   ├── knife.cpp
│   │   │   ├── knife.h   
│   └── collectables/
│       ├── CollectableItem.cpp
│       ├── CollectableItem.h          // Base class for items
│       ├── HealthPack.cpp
│       ├── HealthPack.h               // Health pack item
│       └── PowerUp.cpp
│           PowerUp.h                  // Power-up item (speed, strength boosts)
│
├── managers/                            // Game operations and management
│   ├── EventManager.cpp
│   ├── EventManager.h                 // Input and event handling
│   ├── CollisionManager.cpp
│   ├── CollisionManager.h             // Collision detection
│   ├── GameManager.cpp
│   ├── GameManager.h                  // Score, level progression, and state management
│   ├── AIManager.cpp
│   ├── AIManager.h                    // AI for enemies
│   └── AudioManager.cpp
│       AudioManager.h                 // Sound management
│
├── utils/                               // Utilities and helpers
│   ├── TextureCache.cpp
│   ├── TextureCache.h                 // Texture caching for performance
│   ├── SoundCache.cpp
│   ├── SoundCache.h                   // Sound caching
│   ├── Config.cpp
│   ├── Config.h                       // Game settings configuration
│   ├── Logger.cpp
│   ├── Logger.h                       // Logging utility
│   ├── Random.cpp
│   ├── Random.h                       // Random number generation
│   └── Math.cpp
│       Math.h                         // Math helper functions
│
└── main.cpp                             // Main entry point of the application
"""

# Save to a text file
with open("SoulKnight_Structure.txt", "w") as file:
    file.write(directory_structure)
