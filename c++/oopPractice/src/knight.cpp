#include "knight.hpp"

Knight::Knight(const char* name):
    Monster(name, Utils::getRandomNumber(100, 200))
{
    _shield = new Shield(ShieldType::Steel);
    addWeapon(new Polearm());

    yieldCurrentMonsterProperties();
}

Knight::Knight(const char *name, Weapon *wep):
    Knight(name)
{
    _attackPoints = wep->getDamagePoints();
}

void Knight::yieldCurrentMonsterProperties()
{
    _type = enums::MonsterType::Knight;
    _armorPoints += Utils::getRandomNumber(30, 50);
}

void Knight::deathSpeech()
{
    cout << "I died with honor!" << endl;
}
