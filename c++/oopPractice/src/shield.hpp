#ifndef SHIELD_HPP
#define SHIELD_HPP

enum ShieldType { Wooden = 5, Steel = 20 };

class Shield
{
public:
    Shield(ShieldType shieldType);

    int getArmorPoints();

private:
    int _defensePoints;
};

#endif
