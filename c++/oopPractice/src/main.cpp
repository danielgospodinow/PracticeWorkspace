#include "arena.hpp"

int main(int argc, char *argv[])
{
    //Po princip Monster klasa bi trqbwalo da e abstrakten, no go ostawix normalen w sluchai che iskame "custom" chudowishta s "custom"
    //broi i wid oryjiq
    //          Monster ----> virtual void yieldCurrentMonsterProperties() = 0;

    Monster *randomMonsterTwo = new Monster("Gantz", 100, new Shield(ShieldType::Steel)),
            *randomMonsterOne = new Monster("Genata", 60, new Shield(ShieldType::Wooden));
    randomMonsterTwo->addWeapon(new Polearm());
    randomMonsterTwo->addWeapon(new Axe(enums::AxeTypes::Scisors));
    randomMonsterOne->addWeapon(new Axe());

    Knight* knightOne = new Knight("Danio");
    Monster* knightTwo = new Knight("Hakankata", new Axe(enums::AxeTypes::Spoon));
    Lama* lama = new Lama("Strahil");
    Zombie* zombie = new Zombie("Gosho");
    Monster* dragon = new Dragon("Mincho");

    Arena arena;
    arena.registerMonster(randomMonsterOne);
    arena.registerMonster(knightTwo);
    arena.registerMonster(lama);
    arena.registerMonster(zombie);
    arena.registerMonster(randomMonsterTwo);
    arena.registerMonster(dragon);
    arena.registerMonster(knightOne);

    arena.printAllMonsters();

    cout << endl << endl;

    arena.startTournament();

    return 0;
}
