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
	string background;
	int constitution;
	int strength;
	int wisdom;
	int charisma;
	int dexerity;
	int intelligence;
public:
	Character(string, string, string);
	void setName(string newName);
	void setBackground(string background);
	void setRace(string race);
	void allocatePoint(int&, string, vector<int>&);
	string getName()
	{
		return name;
	}
	string getRace()
	{
		return race;
	}
	string getBackGround()
	{
		return background;
	}
	int getStrength()
	{
		return strength;
	}
	int getConstitution()
	{
		return constitution;
	}
	int getWisdom()
	{
		return wisdom;
	}
	int getCharisma()
	{
		return charisma;
	}
	int getDexerity()
	{
		return dexerity;
	}
	int getIntelligence()
	{
		return intelligence;
	}
	void rollStats();
};


Character::Character(string characterName, string characterRace, string characterBackGround)
{
	name = characterName;
	race = characterRace;
	background = characterBackGround;
	rollStats();
}

void Character::setName(string newName)
{
	name = newName;
}

void Character::setBackground(string newBackground)
{
	background = newBackground;
}

void Character::setRace(string newRace)
{
	race = newRace;
}

void Character::rollStats()
{
	srand(time(0));

	const int SIZE = 6;

	int newSize = 6;

	vector<int> stats;

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

			totalRoll += randomNumber;
		}

		totalRoll -= lowestNumber;

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




