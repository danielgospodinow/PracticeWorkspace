#include "polearm.hpp"

Polearm::Polearm():
    Weapon(Utils::getRandomNumber(20, 150))
{
}

Polearm::Polearm(enums::PolearmTypes type)
{
    _damage = (int) type;
}
