#include "axe.hpp"

Axe::Axe():
    Weapon(Utils::getRandomNumber(60, 120))
{
}

Axe::Axe(enums::AxeTypes type)
{
    _damage = (int) type;
}
