#include <iostream>
using namespace std;

#ifndef ROGUE_H
#define ROGUE_H



class Rogue : public Character
{
private:
    int lockpickingSkill;
    int trapDetectionSkill;
    int pickpocketSkill;
    int dodgeChance;
public:
    Rogue(Character);
    int getLockPickingSkill()
    {
        return lockpickingSkill;
    }
    int getTrapDetectionSkill()
    {
        return trapDetectionSkill;
    }
    int getPickPocketingSkill()
    {
        return pickpocketSkill;
    }
    int getDodgeChance()
    {
        return dodgeChance;
    }
};

Rogue::Rogue(Character rogue)
{
    lockpickingSkill = rogue.getDexerity() / 2;
    trapDetectionSkill = rogue.getWisdom();
    pickpocketSkill = rogue.getDexerity() / 1.5;
    dodgeChance = rogue.getDexerity();
}





#endif // !1

