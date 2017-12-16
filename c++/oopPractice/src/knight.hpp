#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "monster.hpp"

class Knight: public Monster
{
public:
    Knight(const char *name);
    Knight(const char *name, Weapon* wep);

    void yieldCurrentMonsterProperties() override;
    void deathSpeech() override;
};

#endif
