#include "weapon.hpp"

Weapon::Weapon()
{
    _damage = 5;
}

Weapon::Weapon(int damage):
    _damage(damage)
{
}

Weapon::~Weapon()
{
}

int Weapon::getDamagePoints()
{
    return _damage;
}
