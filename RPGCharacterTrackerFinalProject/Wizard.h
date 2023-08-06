#include <iostream>
using namespace std;

#ifndef WIZARD_H
#define WIZARD_H



class Wizard : public Character
{
private:
    int spellPower;           
    int manaPool;            
    int spellResistance;      
    int summoningProficiency; 
public:
    Wizard(string, string ,string);
    int getSpellPower()
    {
        return spellPower;
    }
    int getManaPool()
    {
        return manaPool;
    }
    int getSpellResistance()
    {
        return spellResistance;
    }
    int getSummoningProficiency()
    {
        return summoningProficiency;
    }
};

Wizard::Wizard(string name, string race, string background)
    : Character(name, race, background)
{
    spellPower = getIntelligence() * 2;
    manaPool = (getIntelligence() * 2) + getWisdom();
    spellResistance = getWisdom();
    summoningProficiency = getCharisma();
}



#endif // !1


