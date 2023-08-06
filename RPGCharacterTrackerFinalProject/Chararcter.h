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
	Character();
	Character(string, string, string);
	void deserialize(fstream&);
	void serialize(fstream&) const;
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
	string getBackground()
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

Character::Character()
{}

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

void Character::serialize(fstream& stream) const
{
	// Serialize each member variable
	int nameSize = name.size();
	int raceSize = race.size();
	int backgroundSize = background.size();

	stream.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
	stream.write(name.c_str(), nameSize);

	stream.write(reinterpret_cast<const char*>(&raceSize), sizeof(raceSize));
	stream.write(race.c_str(), raceSize);

	stream.write(reinterpret_cast<const char*>(&backgroundSize), sizeof(backgroundSize));
	stream.write(background.c_str(), backgroundSize);

	stream.write(reinterpret_cast<const char*>(&constitution), sizeof(constitution));
	stream.write(reinterpret_cast<const char*>(&strength), sizeof(strength));
	stream.write(reinterpret_cast<const char*>(&wisdom), sizeof(wisdom));
	stream.write(reinterpret_cast<const char*>(&charisma), sizeof(charisma));
	stream.write(reinterpret_cast<const char*>(&dexerity), sizeof(dexerity));
	stream.write(reinterpret_cast<const char*>(&intelligence), sizeof(intelligence));
	// Repeat for other member variables...
}

void Character::deserialize(fstream& stream)
{
	// Deserialize each member variable
	int nameSize;
	stream.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
	char* nameBuffer = new char[nameSize + 1];
	stream.read(nameBuffer, nameSize);
	nameBuffer[nameSize] = '\0';
	name = nameBuffer;
	delete[] nameBuffer;

	int raceSize;
	stream.read(reinterpret_cast<char*>(&raceSize), sizeof(raceSize));
	char* raceBuffer = new char[raceSize + 1];
	stream.read(raceBuffer, raceSize);
	raceBuffer[raceSize] = '\0';
	race = raceBuffer;
	delete[] raceBuffer;
	 
	int backgroundSize;
	stream.read(reinterpret_cast<char*>(&backgroundSize), sizeof(backgroundSize));
	char* backgroundBuffer = new char[backgroundSize + 1];
	stream.read(backgroundBuffer, backgroundSize);
	backgroundBuffer[backgroundSize] = '\0';
	background = backgroundBuffer;
	delete[] backgroundBuffer;

	stream.read(reinterpret_cast<char*>(&constitution), sizeof(constitution));
	stream.read(reinterpret_cast<char*>(&strength), sizeof(strength));
	stream.read(reinterpret_cast<char*>(&wisdom), sizeof(wisdom));
	stream.read(reinterpret_cast<char*>(&charisma), sizeof(charisma));
	stream.read(reinterpret_cast<char*>(&dexerity), sizeof(dexerity));
	stream.read(reinterpret_cast<char*>(&intelligence), sizeof(intelligence));
	// Repeat for other member variables...

	cout << "\nCharacter name: " << name << endl;
	cout << "Character race: " << race << endl;
	cout << "Character background: " << background << endl;
	cout << "Constitution: " << constitution << endl;
	cout << "Strength: " << strength << endl;
	cout << "Wisdom: " << wisdom << endl;
	cout << "Charisma: " << charisma << endl;
	cout << "Dexterity: " << dexerity << endl;
	cout << "Intelligence: " << intelligence << endl;
}

#endif // !1




