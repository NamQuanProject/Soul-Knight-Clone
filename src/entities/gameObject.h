#pragma once

#include "../utils/vec.h"
#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject();
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Collision(GameObject* gameObject);
    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void SetPosition(const Vec& position);
    
    Vec GetPosition() const;

    void Translate(const Vec& delta);
    
    bool IsActive() const;
    void SetActive(bool active);

    void SetSize(const Vec& size);
    Vec GetSize() const;

    void SetRotation(float angle);
    float GetRotation() const;

    void SetTag(const std::string& tag);
    std::string GetTag() const;

protected:
    Vec position;       
    Vec size;           
    float rotation = 0; 
    bool active = true; 
    std::string tag;  
};
