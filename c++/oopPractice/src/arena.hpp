#ifndef ARENA_HPP
#define ARENA_HPP

#include "includes.hpp"

#include "knight.hpp"
#include "lama.hpp"
#include "zombie.hpp"
#include "dragon.hpp"

class Arena
{
public:
    Arena();
    Arena(vector<Monster*>& monsters);
    ~Arena();

    void startTournament();
    void registerMonster(Monster* monster);
    void printAllMonsters();

private:
    void clearArena();
    void duel(Monster *monsterOne, Monster *monsterTwo);

    vector<Monster*> _monsters;
};

#endif
