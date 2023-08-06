
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
    Wizard(Character);
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

Wizard::Wizard(Character wizard)
{
    spellPower = wizard.getIntelligence() * 2;
    manaPool = (wizard.getIntelligence() * 2) + wizard.getWisdom();
    spellResistance = wizard.getWisdom();
    summoningProficiency = wizard.getCharisma();
}



#endif // !1


