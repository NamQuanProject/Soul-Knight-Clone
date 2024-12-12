
#include "transferGate.h"

#include "../../manager/objectManager.h"
#include "../../manager/stageManager.h"

#include "transferGate.h"

TransferGate::TransferGate() {
    AddTag(Tag::TRANSFER_GATE);
    animationManager.setAnimation("door_animation");
    LoadResources();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    Vec weapon_pos = Vec(position.x, position.y);
    hitbox = new HitBox(author); 
}

void TransferGate::Initialize() {
    AddTag(Tag::TRANSFER_GATE);
    LoadResources();
    
    animationManager.setAnimation("door_animation");
    animationManager.setOrigin();
    
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    Vec weapon_pos = Vec(position.x, position.y);
    hitbox = new HitBox(author); 
}

void TransferGate::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    window.draw(sprite);

    if (hitbox) {
        hitbox->Render(window);
    }
}

void TransferGate::Update(float deltaTime) {
    animationManager.update(deltaTime); 
    sf::Vector2f knightPosition = animationManager.getCurrentSprite().getPosition();
    sf::Sprite sprite = animationManager.getCurrentSprite();

    sf::FloatRect bounds = sprite.getLocalBounds();


    hitbox->SetWidth(bounds.width - 25.f);
    hitbox->SetHeight(bounds.height - 25.f);

    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));
}



void TransferGate::LoadResources() {
    Animation doorAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/object/transfer_gate/transfergate.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/object/transfer_gate/transfergate.bmp",
    };
    doorAnimation.loadAnimation(framePaths1); 
    animationManager.addAnimation("door_animation", doorAnimation);  
}

void TransferGate::Interactive(Player* player) {
    StageManager::Instance()->NextStage();
}

void TransferGate::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        StageManager::Instance()->NextStage();
    }
    
}

void TransferGate::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    animationManager.getCurrentSprite().setPosition(x, y);
}
