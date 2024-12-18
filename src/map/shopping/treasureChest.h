#pragma once
#include <SFML/Graphics.hpp>
#include "../../entities/gameObject.h"
#include "../../manager/animationManager.h"
#include "../../utils/vec.h"

// #include "../utils/InteractableDevice.h"
// #include "../utils/object/OnceAnimationObject.h"

class TreasureChest : public GameObject {
public:
    enum Type {
        NORMAL_ROOM,
        BOX_ROOM,
        BOSS_ROOM
    };
    TreasureChest();
    ~TreasureChest();
    void Initialize() override;
    void Update(float deltaTime) override;
    void LoadResources();
    void Collision(GameObject* gameObject) override;
    void Render(sf::RenderWindow& window) override;
    void SetPosition(Vec& newPosition) override;
private:
    Type type;
    bool isCreateContents;
    void CreateContents();
    void CreateContentsNormalRoom();
    void CreateContentsBoxRoom();
    void CreateContentsBossRoom();
    void CreatePotion();
    void CreateWeapon();
    bool playedAnimation = false;
    bool showingText = false;
    AnimationManager animationManager;
    sf::Font font;
    sf::Text interactiveText;
    
};