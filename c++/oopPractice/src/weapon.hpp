#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "includes.hpp"

class Weapon
{
public:
    Weapon();
    Weapon(int damage);
    virtual ~Weapon();

    int getDamagePoints();

protected:
    int _damage;
};

#endif
