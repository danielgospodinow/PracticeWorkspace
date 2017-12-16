#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "includes.hpp"

#include "weapon.hpp"
#include "shield.hpp"
#include "polearm.hpp"
#include "axe.hpp"

class Monster
{
public:
//     Monster(const char *name, int healthPoints);
//     Monster(const char *name, int healthPoints, Shield* shield);
//     Monster(const char *name, int healthPoints, Shield* shield, vector<Weapon*>& weapons);
    Monster(const char *name, int healthPoints, Shield* shield = NULL, vector<Weapon*> weapons = vector<Weapon*>());
    virtual ~Monster();

    static const char* getMonsterStrType(Monster *monster);

    void addWeapon(Weapon* wep);
    void print() { cout << _name << "           \t   " << "Type:" << getMonsterStrType(this) << "\t    HP:" << _healthPoints << "\t    AP:" << _attackPoints << "\t    Armor:" << _armorPoints << endl;}
    void applyDamage(int damage);

    enums::MonsterType getMonsterType() {return _type;}

    virtual void yieldCurrentMonsterProperties() {}
    virtual void deathSpeech();

    int getHP();
    int getAD();
    int getArmor();
    int getDurability() { return _durability; }
    const char* getName() {return _name;}

    bool isDead();

protected:
    std::vector<Weapon*> _weapons;
    Shield* _shield;

    const char*  _name;

    int _healthPoints;
    int _attackPoints;
    int _armorPoints;

    int _durability;

    enums::MonsterType _type;

    bool _alreadyDead;

private:
    void clearWeapons();
};

#endif
