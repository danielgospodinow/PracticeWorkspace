#include "monster.hpp"

// Monster::Monster(const char* name, int healthPoints):
//     _name(name), _healthPoints(healthPoints)
// {
//     _alreadyDead = false;
//     _attackPoints = 0;
//     _armorPoints = 0;
//     _type = enums::MonsterType::Default;
//     _durability = _healthPoints + _armorPoints;
// }

// Monster::Monster(const char *name, int healthPoints, Shield* shield):
//     Monster(name, healthPoints)
// {
//     _shield = shield;
//     _armorPoints += _shield->getArmorPoints();
//     _durability += _armorPoints;
// }

// Monster::Monster(const char* name, int healthPoints, Shield* shield, std::vector<Weapon*>& weapons):
//     Monster(name, healthPoints, shield)
// {
//     _weapons = weapons;

//     for(uint i=0; i<_weapons.size(); i++)
//         _attackPoints += static_cast<Weapon*>(_weapons[i])->getDamagePoints();
// }

Monster::Monster(const char* name, int healthPoints, Shield* shield, std::vector<Weapon*> weapons):
    _weapons(weapons), _shield(shield), _name(name), _healthPoints(healthPoints)
{
    _alreadyDead = false;
    _attackPoints = 0;
    _armorPoints = 0;
    _type = enums::MonsterType::Default;
    _durability = _healthPoints + _armorPoints;

    _shield?_armorPoints += _shield->getArmorPoints():_armorPoints += 0;
    for(uint i=0; i<_weapons.size(); i++)
        _attackPoints += static_cast<Weapon*>(_weapons[i])->getDamagePoints();
}

Monster::~Monster()
{
    clearWeapons();
    delete _shield;
}

void Monster::applyDamage(int damage)
{
    if(_alreadyDead)
        return;

    if(_durability - damage >= 0)
    {
        _durability -= damage;
        return;
    }

    _alreadyDead = true;
    cout << _name << ": ";
    deathSpeech();
}

const char* Monster::getMonsterStrType(Monster* monster)
{
    switch (monster->getMonsterType())
    {
    case enums::MonsterType::Dragon: return "Dragon"; break;
    case enums::MonsterType::Knight: return "Knight"; break;
    case enums::MonsterType::Lama: return "Lama"; break;
    case enums::MonsterType::Zombie: return "Zombie"; break;
    default: return "Default";
    }
}

void Monster::deathSpeech()
{
    cout << "I died like the casual monster I am." << endl;
}

void Monster::addWeapon(Weapon* wep)
{
    _weapons.push_back(wep);
    _attackPoints += wep->getDamagePoints();
}

void Monster::clearWeapons()
{
    for(uint i=0; i<_weapons.size(); i++)
    {
        Weapon* currWep = _weapons.back();
        _weapons.pop_back();
        delete currWep;
    }
}

int Monster::getHP()
{
    return _healthPoints;
}

int Monster::getAD()
{
    return _attackPoints;
}

int Monster::getArmor()
{
    return _armorPoints;
}

bool Monster::isDead()
{
    return _alreadyDead;
}
