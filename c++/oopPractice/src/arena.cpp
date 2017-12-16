#include "arena.hpp"

Arena::Arena()
{

}

Arena::Arena(vector<Monster *>& monsters):
    _monsters(monsters)
{

}

Arena::~Arena()
{
    clearArena();
    cout << "Arena closed!" << endl;
}

void Arena::startTournament()
{
    if(_monsters.size() == 0)
    {
        cout << "No monsters registered in the tournament!" << endl;
        return;
    }

    while(_monsters.size() > 1)
    {
        int iOne = Utils::getRandomNumber(0, _monsters.size() - 1),
                iTwo = Utils::getRandomNumber(0, _monsters.size() - 1);

        if(iOne == iTwo)
            continue;

        Monster *monsterOne = static_cast<Monster*>(_monsters[iOne]),
                *monsterTwo = static_cast<Monster*>(_monsters[iTwo]);

        duel(monsterOne, monsterTwo);

        if(monsterOne->isDead() && monsterTwo->isDead())
        {
            int maxI = max(iOne, iTwo);
            int minI = min(iOne, iTwo);

            _monsters.erase(_monsters.begin() + maxI);
            _monsters.erase(_monsters.begin() + minI);
            delete monsterOne;
            delete monsterTwo;
        }
        else if(monsterTwo->isDead())
        {
            _monsters.erase(_monsters.begin() + iTwo);
            delete monsterTwo;
        }
        else
        {
            _monsters.erase(_monsters.begin() + iOne);
            delete monsterOne;
        }
    }

    cout << endl;
    cout << "End of tournament" << endl;
    cout << endl;
    if(_monsters.size() == 0)
    {
        cout << "All contestants died. Sorry!" << endl << endl;
        return;
    }
    cout << "Winner: " << endl;
    static_cast<Monster*>(_monsters[0])->print();
    cout << "Monster durability left: " << static_cast<Monster*>(_monsters[0])->getDurability() << endl;
    cout << endl;
}

void Arena::duel(Monster* monsterOne, Monster* monsterTwo)
{
    while(!monsterOne->isDead() && !monsterTwo->isDead())
    {
        monsterOne->applyDamage(monsterTwo->getAD());
        monsterTwo->applyDamage(monsterOne->getAD());
    }
}

void Arena::registerMonster(Monster *monster)
{
    _monsters.push_back(monster);
}

void Arena::printAllMonsters()
{
    for(uint i=0; i<_monsters.size(); i++)
    {
        cout << "(" << i + 1 << ")";
        static_cast<Monster*>(_monsters[i])->print();
    }
}

void Arena::clearArena()
{
    for(uint i=0; i<_monsters.size(); i++)
    {
        Monster* currMonster = _monsters.back();
        _monsters.pop_back();
        delete currMonster;
    }
}
