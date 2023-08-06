#include <iostream>
#include <vector>
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
	void allocatePoint(int&, string, vector<int>&);
	int getStrength()
	{return strength;}
};

Character::Character(string name, string race, string backGround)
{
	srand(time(0));

	const int SIZE = 6;
	
	int newSize = 6; 

	vector<int> stats;

	//Roll a 6 sided dice 4 times discard the lowest number total those numbers then allocated that number to a stat of your choice do this until all 6 stats are allocated
	for (int y = 0; y < 6; y++)
	{

		int totalRoll = 0;
		int lowestNumber = 6;

		for (int x = 0; x < 4; x++)
		{
			int randomNumber = (rand() % 6) + 1;
			if (lowestNumber > randomNumber)
			{
				lowestNumber = randomNumber;
			}

			cout << "random number: " << randomNumber << endl;

			totalRoll += randomNumber;
			cout << "total: " << totalRoll << endl;
		}

		cout << "lowest number: " << lowestNumber << endl;

		totalRoll -= lowestNumber;

		cout << "You have rolled: " << totalRoll << endl;

		stats.push_back(totalRoll);
	}

	

	string stat;

	for (int y = 0; y < SIZE; y++)
	{
		switch (y)
		{
		case 0:
		{
			stat = "strength";
			allocatePoint(strength, stat, stats);
			break;
		}
		case 1:
		{
			stat = "constitution";
			allocatePoint(constitution, stat, stats);
			break;
		}
		case 2:
		{
			stat = "intelligence";
			allocatePoint(intelligence, stat, stats);
			break;
		}
		case 3:
		{
			stat = "wisdom";
			allocatePoint(wisdom, stat, stats);
			break;
		}
		case 4:
		{
			stat = "dexerity";
			allocatePoint(dexerity, stat, stats);
			break;
		}
		case 5:
		{
			stat = "charisma";
			allocatePoint(charisma, stat, stats);
			break;
		}
		}


	}

	
}


void Character::allocatePoint(int& stat, string statValue, vector<int>& stats)
{

	int found = -1;
	int choice;

	size_t numOfStats = stats.size();
	
		do {
			for (int z = 0; z < numOfStats; z++) {
				cout << stats[z] << " ";
			}

			cout << "\nAllocate a number above for your " << statValue << " stat: ";
			cin >> choice;

			for (int z = 0; z < numOfStats && found == -1; z++) {
				if (stats[z] == choice) {
					found = 1;
					stat = stats[z];
					int lastValue = stats[numOfStats - 1];
					int temp = lastValue;
					lastValue = stats[z];
					stats[z] = temp;
				}
			}
		} while (found == -1);
		
		stats.pop_back();
}






















#endif // !1




