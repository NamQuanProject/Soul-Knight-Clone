#include "treasureChest.h"
#include "../../entities/collectable/potionFactory.h"
#include "../../entities/drop/coin.h"
#include "../../manager/objectManager.h"
#include "../../pool/dropPool.h"
#include "../../utils/random.h"
// #include "../../weapon/weaponFactory.h"





TreasureChest::TreasureChest() {
    std::cout << "INitialize" << std::endl;
    Initialize();
   
}

TreasureChest::~TreasureChest() {
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
}


void TreasureChest::Initialize() {
    AddTag(Tag::TREASURE_CHEST);
    LoadResources();
    animationManager.setAnimation("open_animation");
    animationManager.setOrigin();
   
    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/ARIAL.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    interactiveText.setFont(font);
    interactiveText.setString("Press L to open");
    interactiveText.setCharacterSize(9);  

    interactiveText.setFillColor(sf::Color::White);  
    
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    interactiveText.setPosition(position.x - 45.f, position.y + 50.f);  
    
    Point author = Point(position.x, position.y);
    hitbox = new HitBox(author); 
    
    showingText = false;
}

void TreasureChest::Update(float deltaTime) {
    animationManager.update(deltaTime); 
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::Vector2f gatePosition = sprite.getPosition();
    interactiveText.setPosition(gatePosition.x - 30.f, gatePosition.y + 35.f);  
    
    sf::FloatRect bounds = sprite.getLocalBounds();
    hitbox->SetWidth(bounds.width - 45.f);
    hitbox->SetHeight(bounds.height - 15.f);

    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));
    showingText = false;
    if (animationManager.isFinished("open_animation")) {
        animationManager.pauseAnimation("open_animation");
    }
    // if (isAnimationFinished && !isCreateContents) {
    //     isCreateContents = true;
    //     CreateContents();
    // }
}

void TreasureChest::LoadResources() {
    Animation openAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/4.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/5.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/6.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/7.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/8.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/9.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/Resources/object/treasure_chest/animate/10.bmp",
    };
    openAnimation.loadAnimation(framePaths1); 
    animationManager.addAnimation("open_animation", openAnimation);  
    animationManager.pauseAnimation("open_animation");
}




void TreasureChest::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        if (playedAnimation == false) {
            showingText = true;  
            if (ObjectManager::Instance()->GetPlayer()->GetInteract() == true) {
                animationManager.playAnimation("open_animation"); 
                CreateContents();
                playedAnimation = true;
            }
        }
    }
}

void TreasureChest::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    window.draw(sprite);
    if (showingText) {
        window.draw(interactiveText);
    }
    if (hitbox) {
        hitbox->Render(window);
    }
}


void TreasureChest::CreateContents() {
    // switch (type) {
    // case NORMAL_ROOM:
    //     CreateContentsNormalRoom();
    //     break;
    // case BOX_ROOM:
    //     CreateContentsBoxRoom();
    //     break;
    // case BOSS_ROOM:
    //     CreateContentsBossRoom();
    // }
    ObjectManager::Instance()->GetPlayer()->Healing(1);
}

void TreasureChest::CreateContentsNormalRoom() {
    int rand = Rand::Instance()->Get(1, 10);
    // if (rand <= 7) {
    //     GameObject* contents;
    //     for (int i = 0; i < Rand::Instance()->Get(3, 9); i++) {
    //         contents = DropPool::Instance()->Acquire(DropType::COIN);
    //         contents->SetPosition(
    //             this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
    //         ObjectManager::Instance()->AddObject(contents);
    //     }
    //     for (int i = 0; i < Rand::Instance()->Get(3, 9); i++) {
    //         contents = DropPool::Instance()->Acquire(DropType::MAGIC_BALL);
    //         contents->SetPosition(
    //             this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
    //         ObjectManager::Instance()->AddObject(contents);
    //     }
    // }
    // else if (rand <= 9) {
    //     CreatePotion();
    // }
    // else if (rand <= 10) {
    //     CreateWeapon();
    // }
}

void TreasureChest::CreateContentsBoxRoom() {
    // int rand = Rand::Instance()->Get(1, 10);
    // if (rand <= 4) {
    //     CreatePotion();
    // }
    // else if (rand <= 10) {
    //     CreateWeapon();
    // }
}

void TreasureChest::CreateContentsBossRoom() {
    // CreateWeapon();
}

void TreasureChest::CreatePotion() {
    // GameObject* contents;
    // int potionId = Rand::Instance()->Get(0, static_cast<int>(PotionFactory::PotionType::Count) - 1);
    // contents = PotionFactory::Create(static_cast<PotionFactory::PotionType>(potionId));
    // contents->SetPosition(this->position + Point(0, 1));
    // ObjectManager::Instance()->AddObject(contents);
}

void TreasureChest::CreateWeapon() {
    // GameObject* contents;
    // int weaponId = Rand::Instance()->Get(0, static_cast<int>(WeaponType::Count) - 1);
    // contents = WeaponFactory::Create(static_cast<WeaponType>(weaponId));
    // contents->SetPosition(this->position + Point(0, 1));
    // ObjectManager::Instance()->AddObject(contents);
}
void TreasureChest::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    animationManager.getCurrentSprite().setPosition(x, y);
}