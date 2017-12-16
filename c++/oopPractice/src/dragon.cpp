#include "dragon.hpp"

Dragon::Dragon(const char *name):
    Monster(name, Utils::getRandomNumber(60, 80))
{
    yieldCurrentMonsterProperties();
}

void Dragon::yieldCurrentMonsterProperties()
{
    _type = enums::MonsterType::Dragon;
    _armorPoints += Utils::getRandomNumber(60,80);
    _attackPoints += Utils::getRandomNumber(50, 80);
}

void Dragon::deathSpeech()
{
    cout << "*last dragon fire breathe*" << endl;
}
