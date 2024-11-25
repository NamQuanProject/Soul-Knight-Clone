#include "projectile.h"

Projectile::Projectile(): isPoison(false), damage(0) {
}

Projectile::~Projectile() {
}

void Projectile::SetDamage(double damage) {
    this->damage = damage;
}

double Projectile::GetDamage() {
    return damage;
}

ProjectileType Projectile::GetProjectileType() {
    return static_cast<ProjectileType>(projectileType);
}

void Projectile::SetProjectileType(ProjectileType type) {
    projectileType = static_cast<int>(type);
}

void Projectile::SetPoison(bool isPoison) {
    this->isPoison = isPoison;
}

bool Projectile::GetPoison() {
    return isPoison;
}