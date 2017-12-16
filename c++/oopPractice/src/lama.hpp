#ifndef LAMA_HPP
#define LAMA_HPP

#include "monster.hpp"

class Lama: public Monster
{
public:
    Lama(const char* name);

    void yieldCurrentMonsterProperties() override;
    void deathSpeech() override;
};

#endif
