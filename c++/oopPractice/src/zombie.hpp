#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "monster.hpp"

class Zombie: public Monster
{
public:
    Zombie(const char* name);

    void yieldCurrentMonsterProperties() override;
    void deathSpeech() override;

    bool hasDiedOnce() {return _diedOnce;}

private:
    bool _diedOnce;
};

#endif
