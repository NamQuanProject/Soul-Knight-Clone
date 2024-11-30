#pragma once

#include "weapon.h"
#include "../../utils/vec.h"

class RangeWeapon : public Weapon {
public:
    RangeWeapon();
    virtual ~RangeWeapon() = default;

    virtual void Fire() = 0;                 
    virtual void Reload() = 0;                 

    void SetAmmo(int ammoCount);               
    int GetAmmo();                        
    void SetWeaponDirection(Vec& direction);
    Vec GetWeaponDirection();             
    Vec PointAtEnemy(Vec& enemyPosition); 
    Vec GetBulletPosition();              
    void Use() override;                       
    void Update(float deltaTime) override;      
    
protected:
    int ammo;                                  
    double fireRate;                           
    double muzzleOffset;                        
    double timeSinceLastFire;                  
    Vec weaponDirection;                        
};
