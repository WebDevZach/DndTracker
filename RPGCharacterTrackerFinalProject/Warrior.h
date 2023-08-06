#include <iostream>
#include <cmath>
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H



class Warrior : public Character
{
private:
    int healthRegenerationRate;
    int parryChance;
    int resistanceToMagic;
    int blockChance;
public:
    Warrior(Character);
    int getHealthRegenerationRate()
    {
        return healthRegenerationRate;
    }
    int getParryChance()
    {
        return parryChance;
    }
    int getResistanceToMagic()
    {
        return resistanceToMagic;
    }
    int getBlockChance()
    {
        return blockChance;
    }
};

Warrior::Warrior(Character warrior)
    
{
    healthRegenerationRate = round(warrior.getConstitution() / 6);
    parryChance = (warrior.getStrength() / 2) + (warrior.getDexerity() / 2);
    resistanceToMagic = warrior.getConstitution();
    blockChance = warrior.getStrength() * 2;
}

  


#endif // !1


