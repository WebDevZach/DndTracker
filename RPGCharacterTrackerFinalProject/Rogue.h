#include <iostream>
using namespace std;

#ifndef ROGUE_H
#define ROGUE_H



class Rogue : public Character
{
private:
    bool isStealth;        
    int lockpickingSkill;   
    int trapDetectionSkill;
    bool dualWielding;    
    int pickpocketSkill;    
    int dodgeChance;
public:
    void enterStealthMode();
    void exitStealthMode();
    bool attemptLockpicking(int difficulty);
    bool detectTraps();
    void enableDualWielding();
    void disableDualWielding();
};



#endif // !1

