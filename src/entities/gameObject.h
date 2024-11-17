#pragma once

#include "Vec.h" 

class GameObject {
public:
    GameObject();                        
    virtual ~GameObject() = default;      

    
    virtual void Start() = 0;            
    virtual void Update() = 0;         
    virtual void Collision(GameObject* gameObject) = 0; 

  
    Vec GetPosition() const;              
    void SetPosition(const Vec& position); 
    void Translate(const Vec& delta);     

    
    bool IsActive() const;               
    void SetActive(bool active);        
protected:
    Vec position;                         
    bool active = true;             

private:
    int id;                             
    static int nextId;                   
};
