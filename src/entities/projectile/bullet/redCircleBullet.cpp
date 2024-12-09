// #include "redCircleBullet.h"
// #include <iostream>


// RedCircleBullet::RedCircleBullet() {
//     SetProjectileType(ProjectileType::RedCircleBullet); // Assign projectile type
//     position = Vec(0.0, 0.0);  // Initialize position
//     speed = Vec(0.0, 0.0);     // Initialize speed
//     LoadResources();       // Load resources for the bullet

//     // Initialize hitbox
//     Point author = Point(0.0, 0.0);
//     hitbox = new HitBox(author);
//     if (bulletTexture.getSize().x > 0 && bulletTexture.getSize().y > 0) {
//         hitbox->SetWidth(bulletTexture.getSize().x);
//         hitbox->SetHeight(bulletTexture.getSize().y);
//     }

//     AddTag(Tag::MONSTER_ATTACK); // Tag the bullet for gameplay logic
// }

// void RedCircleBullet::Initialize() {

// }

// RedCircleBullet::~RedCircleBullet() {
//     if (hitbox) {
//         delete hitbox;
//     }
// }

// void RedCircleBullet::Update(float deltaTime) {
//     // Update position
//     sf::Vector2f movement(speed.GetX() * deltaTime, speed.GetY() * deltaTime);
//     Vec temp = Vec(movement.x, movement.y);
//     position = position + temp;
//     bulletSprite.setPosition(position.GetX(), position.GetY());


//     Point point = Point(position.GetX(), position.GetY());
//     hitbox->SetPosition(point);

//     if (speed.GetX() != 0.f || speed.GetY() != 0.f) {
//         float angle = std::atan2(speed.GetY(), speed.GetX()) * 180.f / 3.14159f;
//         bulletSprite.setRotation(angle);
//     }
// }

// void RedCircleBullet::Render(sf::RenderWindow& window) {
//     window.draw(bulletSprite);
//     if (hitbox) {
//         hitbox->Render(window);
//     }
// }

// void RedCircleBullet::LoadResources() {
//     sf::Image image;
//     if (!image.loadFromFile("/Users/quannguyennam/Documents/Projects/Soul Knight Clone/resources/bullet/red_circle_bullet/template/red_circle_bullet.bmp")) {
//         std::cerr << "Error: Could not load bullet image!" << std::endl;
//     }
//     sf::Color transparentColor(255, 255, 255);
//     image.createMaskFromColor(transparentColor);
    
//     bulletTexture.loadFromImage(image);
//     bulletSprite.setTexture(bulletTexture);
//     bulletSprite.setOrigin(bulletTexture.getSize().x / 2.f, bulletTexture.getSize().y / 2.f);
// }

// void RedCircleBullet::Collision(GameObject* gameObject) {
//     if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
//         (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD) && this->HasTag(Tag::PLAYER_ATTACK)) ||
//         gameObject->HasTag(Tag::OBSTACLE)) {
//         this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
//     }
// }

// void RedCircleBullet::SetPosition(const sf::Vector2f& pos) {
//     position = pos;
//     bulletSprite.setPosition(position);
//     hitbox->SetPosition(Point(position.x, position.y)); 
// }

// void RedCircleBullet::SetSpeed(const sf::Vector2f& newSpeed) {
//     speed = newSpeed;
// }

// sf::Vector2f RedCircleBullet::GetPosition() {
//     return position;
// }
