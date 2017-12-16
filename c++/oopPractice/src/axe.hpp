#ifndef AXE_HPP
#define AXE_HPP

#include "weapon.hpp"

class Axe: public Weapon
{
public:
    Axe();
    Axe(enums::AxeTypes type);
};

#endif
