#include "lama.hpp"

Lama::Lama(const char *name):
    Monster(name, Utils::getRandomNumber(0, 700))
{
    yieldCurrentMonsterProperties();
}

void Lama::yieldCurrentMonsterProperties()
{
    _type = enums::MonsterType::Lama;
    _healthPoints += Utils::getRandomNumber(100, 150);
    _armorPoints += Utils::getRandomNumber(100, 200);
    _attackPoints += Utils::getRandomNumber(50, 120);
}

void Lama::deathSpeech()
{
    cout << "*lama death sound*" << endl;
}
