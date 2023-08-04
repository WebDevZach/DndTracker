#include <iostream>
#include <vector>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H



class Character
{
public:
	string name;
	string race;
	string backGround;
	int constitution;
	int strength;
	int wisdom;
	int charisma;
	int dexerity;
	int intelligence;

	Character(string, string, string);
	void allocatePoint(int, string, int[], int& size);
};

Character::Character(string name, string race, string backGround)
{
	srand(time(0));

	const int SIZE = 6;
	
	int newSize = 6; 

	int stats[SIZE];

	//Roll a 6 sided dice 4 times discard the lowest number total those numbers then allocated that number to a stat of your choice do this until all 6 stats are allocated
	for (int y = 0; y < 6; y++)
	{
		int choice;
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

		stats[y] = totalRoll;
	}

	

	string stat;

	for (int y = 0; y < SIZE; y++)
	{
		switch (y)
		{
		case 1:
		{
			stat = "strength";
			allocatePoint(strength, stat, stats, newSize);
			break;
		}
		case 2:
		{
			stat = "constitution";
			allocatePoint(constitution, stat, stats, newSize);
			break;
		}
		case 3:
		{
			stat = "intelligence";
			allocatePoint(intelligence, stat, stats, newSize);
			break;
		}
		case 4:
		{
			stat = "wisdom";
			allocatePoint(wisdom, stat, stats, newSize);
			break;
		}
		case 5:
		{
			stat = "dexerity";
			allocatePoint(dexerity, stat, stats, newSize);
			break;
		}
		case 6:
		{
			stat = "charisma";
			allocatePoint(charisma, stat, stats, newSize);
			break;
		}
		}


	}

	
}

//switch places using a vector then pop
void Character::allocatePoint(int stat, string statValue, int stats[], int& size)
{

	int found = -1;
	int choice;

	try
	{
		do {
			for (int z = 0; z < size; z++) {
				cout << stats[z] << " ";
			}

			cout << "\nAllocate a number above for your " << statValue << " stat: ";
			cin >> choice;

			for (int z = 0; z < size; z++) {
				if (stats[z] == choice) {
					found = 1;
					stat = stats[z];
					stats[z] = -1;

					size--;

					int* newArray = new int[size];

					for (int x = 0; x < z; x++) {
						newArray[x] = stats[x];
					}

					for (int x = size - 1; x > z; x--) {
						newArray[x] = stats[x];
					}

					
					stats = newArray;
				}
			}
		} while (found == -1);
	}
	catch (...)
	{
		cout << "meeep";
	}



}






















#endif // !1




