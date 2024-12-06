#pragma once
#include <vector>
#include "../entities/projectile/projectileType.h"
#include "../entities/projectile/projectile.h"


class ProjectilePool {
public:
    static ProjectilePool* Instance();
    ProjectilePool();
    ~ProjectilePool();
    void Initialize();
    Projectile* Acquire(ProjectileType type);
    void Release(Projectile* projectile);

private:
    void Refresh(Projectile* projectile);
    static ProjectilePool* instance;
    std::vector<std::vector<Projectile*>> pool;
};