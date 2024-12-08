#include "knight.h"
#include <iostream>

// Constructor
Knight::Knight() : Player() {
    loadKnightAnimations();
    weapon1 = new BadPistol();
    
    animationManager.setAnimation("idle_right"); 
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    Vec weapon_pos = Vec(position.x, position.y);
    hitbox = new HitBox(author); 
    AddTag(Tag::PLAYER);
    weapon1->SetPosition(weapon_pos);
}

void Knight::Initialize() {
    loadKnightAnimations();
    weapon1 = new BadPistol();
    
    animationManager.setAnimation("idle_right"); 
    animationManager.setOrigin();
    sf::Vector2f position = animationManager.getCurrentSprite().getPosition();
    
    Point author = Point(position.x, position.y);
    Vec weapon_pos = Vec(position.x, position.y);
    hitbox = new HitBox(author); 
    AddTag(Tag::PLAYER);
    weapon1->SetPosition(weapon_pos);
}

Knight::~Knight() {
    if (weapon1) {
        delete weapon1;
        weapon1 = nullptr;
    }
    if (hitbox) {
        delete hitbox;
        hitbox = nullptr;
    }
    
}

// Update the knight animation
void Knight::Update(float deltaTime) {
    animationManager.update(deltaTime); 

    
    if (face == Knight::RIGHT) {
        // weapon1->setRight();
        weapon1->setOffset(5 , 2);
    }
    else if (face == Knight::LEFT){
        // weapon1->SetLeft();
        weapon1->setOffset(-15, 2);
    }
    weapon1->Update(deltaTime);
    

    sf::Vector2f knightPosition = animationManager.getCurrentSprite().getPosition();
    sf::Sprite sprite = animationManager.getCurrentSprite();
    sf::FloatRect bounds = sprite.getLocalBounds();

    hitbox->SetWidth(bounds.width - 9.f);
    hitbox->SetHeight(bounds.height - 1.f);

    sf::Vector2f hitboxPosition = sprite.getPosition();
    hitbox->SetPosition(Point(hitboxPosition.x, hitboxPosition.y));
}

void Knight::loadKnightAnimations() {
    Animation rightStandAnimation;
    std::vector<std::string> framePaths1 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/4.bmp"
    };
    rightStandAnimation.loadAnimation(framePaths1);  // Load the idle animation
    animationManager.addAnimation("idle_right", rightStandAnimation);  // Add to animation manager

    Animation leftStandAnimation;
    std::vector<std::string> framePaths2 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/idle/flip_4.bmp"
    };
    leftStandAnimation.loadAnimation(framePaths2);  
    animationManager.addAnimation("idle_left", leftStandAnimation);  
    
    // Right Running Animation
    Animation rightRunAnimation;
    std::vector<std::string> framePaths3 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/4.bmp"
    };
    rightRunAnimation.loadAnimation(framePaths3);  // Load the running animation
    animationManager.addAnimation("run_right", rightRunAnimation);  // Add to animation manager

    // Left Running Animation (flipped)
    Animation leftRunAnimation;
    std::vector<std::string> framePaths4 = {
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_1.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_2.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_3.bmp",
        "/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/player/knight/run/flip_4.bmp"
    };
    leftRunAnimation.loadAnimation(framePaths4);  // Load the flipped running animation
    animationManager.addAnimation("run_left", leftRunAnimation);  // Add to animation manager
}

// Render the knight (called every frame)
void Knight::Render(sf::RenderWindow& window) {
    sf::Sprite sprite = animationManager.getCurrentSprite();
    

    weapon1->Render(window);

    window.draw(sprite);

    if (hitbox) {
        hitbox->Render(window); // Render the hitbox
    }
}


void Knight::runRight() {
    state = RUN;
    face = RIGHT;
    animationManager.setAnimation("run_right"); 
}

void Knight::runLeft() {
    state = RUN;
    face = LEFT;
    animationManager.setAnimation("run_left");  
}

void Knight::standRight() {
    animationManager.setAnimation("idle_right");  
}
 
void Knight::standLeft() {
    animationManager.setAnimation("idle_left"); 
}

void Knight::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::WALL)) {
        Vec current = GetPosition();
        current = current - speed;


        SetPosition(current);
    }
}



void Knight::SetBeforePosition(Vec a) {
    
}

void Knight::SetPosition(Vec& newPosition) {
    position = newPosition;
    double x = newPosition.GetX();
    double y = newPosition.GetY();
    sf::Vector2f web_position(x, y);
    
    if (weapon1) {
        weapon1->setPlayerPosition(web_position); 
    } else {
        std::cout << "Weapon is not initialized!" << std::endl;
    }
    
    // Set the knight's animation sprite position
    animationManager.getCurrentSprite().setPosition(x, y);
}
