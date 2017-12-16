#include "shield.hpp"

#include <iostream>

Shield::Shield(ShieldType shieldType)
{
    _defensePoints = (int) shieldType;
}

int Shield::getArmorPoints()
{
    return _defensePoints;
}
