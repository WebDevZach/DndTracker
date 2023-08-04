#include <iostream>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H



class Character
{
private:
	string name;
	string race;
	string backGround;
	int constitution;
	int strength;
	int wisdom;
	int charisma;
	int dexerity;
	int intelligence;
public:
	Character(string, string, string);
};

Character::Character(string name, string race, string backGround)
{
	srand(time(0));
	

	//Roll a 6 sided dice 4 times discard the lowest number total those numbers then allocated that number to a stat of your choice do this until all 6 stats are allocated
	for (int y = 0; y < 6; y++)
	{

		int total = 0;
		int lowestNumber = 6;

		for (int x = 0; x < 4; x++)
		{
			int randomNumber = (rand() % 6) + 1;
			if (lowestNumber > randomNumber)
			{
				lowestNumber = randomNumber;
			}

			cout << "random number: " << randomNumber << endl;

			total += randomNumber;
			cout << "total: " << total << endl;
		}

		cout << "lowest number: " << lowestNumber << endl;

		total -= lowestNumber;

		cout << "You have rolled: " << total << endl;
	}

}
















#endif // !1




