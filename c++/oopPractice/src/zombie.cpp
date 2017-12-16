#include "zombie.hpp"

Zombie::Zombie(const char *name):
    Monster(name, Utils::getRandomNumber(200, 400))
{
    yieldCurrentMonsterProperties();
}

void Zombie::yieldCurrentMonsterProperties()
{
    _type = enums::MonsterType::Zombie;
    _attackPoints = Utils::getRandomNumber(150, 300);
    _diedOnce = false;
}

void Zombie::deathSpeech()
{
    cout << "Arggrghhheh.. nevermind, I was dead in the first place." << endl;
}
