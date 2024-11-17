#pragma once

#include "../utils/vec.h" 
#include <SFML/Graphics.hpp>
class GameObject {
public:
    GameObject();                        
    virtual ~GameObject() = default;      
     
    virtual void Update(float deltaTime) = 0;         
    virtual void Collision(GameObject* gameObject) = 0; 
    virtual void Render(sf::RenderWindow& window) = 0;
  
    Vec GetPosition() const;              
    void SetPosition(const Vec& position); 
    void Translate(const Vec& delta);     

    
    bool IsActive() const;               
    void SetActive(bool active);        
protected:
    Vec position;                         
    bool active = true;                              
};
