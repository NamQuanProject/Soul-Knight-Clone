#include "transferGate.h"
#include "../../manager/objectManager.h"
#include "../../manager/stageManager.h"
#include <SFML/Graphics.hpp>

TransferGate::TransferGate() {
    AddTag(Tag::TRANSFER_GATE);
    
    LoadResources();
    animationManager.setAnimation("door_animation");

   
    if (!font.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/ARIAL.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    interactiveText.setFont(font);
    interactiveText.setString("Press L to interact");
    interactiveText.setCharacterSize(9);  // Set text size

    interactiveText.setFillColor(sf::Color::White);  
// Make the text bold
    
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    interactiveText.setPosition(position.x - 45.f, position.y + 90.f);  
    
    Point author = Point(position.x, position.y);
    Vec weapon_pos = Vec(position.x, position.y);
    hitbox = new HitBox(author); 
    
    showingText = false;
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
    if (showingText) {
        window.draw(interactiveText);
    }
    
}

void TransferGate::Update(float deltaTime) {
    animationManager.update(deltaTime); 
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::Vector2f gatePosition = sprite.getPosition();
    interactiveText.setPosition(gatePosition.x - 45.f, gatePosition.y + 50.f);  
    
    sf::FloatRect bounds = sprite.getLocalBounds();
    hitbox->SetWidth(bounds.width - 25.f);
    hitbox->SetHeight(bounds.height - 25.f);

    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));
    showingText = false;
}

void TransferGate::LoadResources() {
    Animation doorAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/object/transfer_gate/transferGate2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/object/transfer_gate/transferGate2.bmp",
    };
    doorAnimation.loadAnimation(framePaths1); 
    animationManager.addAnimation("door_animation", doorAnimation);  
}

void TransferGate::Interactive(Player* player) {
    StageManager::Instance()->NextStage();
}

void TransferGate::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        showingText = true;  
        if (ObjectManager::Instance()->GetPlayer()->GetInteract() == true) {
            StageManager::Instance()->NextStage();
        }
    }
}

void TransferGate::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    animationManager.getCurrentSprite().setPosition(x, y);
}
