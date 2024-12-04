#pragma once

#include "../utils/vec.h"
#include "../utils/hitBox.h"
#include "../utils/tag.h"
#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject();
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Collision(GameObject* gameObject);
    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void SetPosition(Vec& position);
    
    Vec GetPosition();

    void Translate(const Vec& delta);
    
    bool IsActive() const;
    void SetActive(bool active);

    void SetSize(const Vec& size);
    Vec GetSize() const;

    void SetRotation(float angle);
    float GetRotation() const;
    void SetHitBox(const HitBox& hitbox); 
    HitBox* GetHitBox();
    void SetTag(const std::string& tag);
    std::string GetTag() const;

protected:
    Vec position;       
    Vec size;           
    float rotation = 0; 
    bool active = true; 
    std::string tag;  
    HitBox* hitbox = nullptr; 
    std::bitset<static_cast<int>(Tag::Count)> tags;
};
