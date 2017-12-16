#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "monster.hpp"

class Dragon: public Monster
{
public:
    Dragon(const char* name);

    void yieldCurrentMonsterProperties() override;
    void deathSpeech() override;
};

#endif
