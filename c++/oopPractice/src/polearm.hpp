#ifndef POLEARM_HPP
#define POLEARM_HPP

#include "weapon.hpp"

class Polearm : public Weapon
{
public:
    Polearm();
    Polearm(enums::PolearmTypes type);
};

#endif
