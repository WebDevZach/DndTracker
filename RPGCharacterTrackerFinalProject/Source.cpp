/*
Zachary Leyes

8/4/2023


Final Project RPG/Dnd character party tracker

1202 201

*/

#include <iostream>
#include <fstream>
#include <string>
#include "Chararcter.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Rogue.h"

using namespace std;

int displayMenu();
void addNewCharacterToFile(fstream&);
void displayParty(fstream&);

int main()
{
	fstream file;
	file.open("DnDParty.txt", ios::out | ios::in | ios::binary | ios::app);

	if (!file)
	{
		cout << "No file found you dummy" << endl;
	}

	int selection;

	do
	{
		selection = displayMenu();

		switch (selection)
		{
		case 1:
			addNewCharacterToFile(file);
			break;
		case 2:
			displayParty(file);
			break;

		}
	} while (selection != 3);


	return 0;
}

int displayMenu()
{
	int selection;

	cout << "1) Enter a new character";
	cout << "\n2) Display all party members";
	cout << "\n3) Exit the program" << endl;
	cin >> selection;
	while (selection < 1 || selection > 3)
	{
		cout << "Invalid selection: ";
		cin >> selection;
	}

	return selection;

}


void addNewCharacterToFile(fstream& file)
{

	file.clear();
	file.seekg(0, ios::beg);

	int role;
	string name;
	string race;
	string background;

	cin.ignore();

	cout << "Enter character name: ";
	getline(cin, name);

	cout << "Enter character race: ";
	getline(cin, race);

	cout << "Enter character's background: ";
	getline(cin, background);

	cout << "Enter character's role 1) Rogue, 2) Warrior, 3) Wizard: ";
	cin >> role;
	while (role < 1 || role > 3)
	{
		cout << "Invalid selection, enter your role: ";
		cin >> role;
	}

	Character newCharacter(name, race, background);  // Create a new character object

	// Serialize the newCharacter directly
	newCharacter.serialize(file);
	file.write(reinterpret_cast<const char*>(&role), sizeof(int));
}

void displayParty(fstream& file)
{
	Character newCharacter;
	int role;

	file.clear();
	file.seekg(0, ios::beg);

	while (file.peek() != EOF)
	{
		Character character;
		character.deserialize(file);
		file.read(reinterpret_cast<char*>(&role), sizeof(int));

		switch (role)
		{
		case 1:
		{
			cout << "Class: Rogue";
			Rogue rogue = Rogue(character);
			cout << "\nLock picking skill: " << rogue.getLockPickingSkill();
			cout << "\nTrap detection skill: " << rogue.getTrapDetectionSkill();
			cout << "\nPick pocket skill: " << rogue.getPickPocketingSkill();
			cout << "\nDodge chance: " << rogue.getDodgeChance() << endl << endl;
			break;
		}
		case 2:
		{
			cout << "Class: Warrior";
			Warrior warrior = Warrior(character);
			cout << "\nHealth regeneration rate: " << warrior.getHealthRegenerationRate();
			cout << "\nParry chance: " << warrior.getParryChance();
			cout << "\nResistance to magic: " << warrior.getResistanceToMagic();
			cout << "\nBlock chance: " << warrior.getBlockChance() << endl << endl;
			break;
		}
		case 3:
			cout << "Class: Wizard";
			Wizard wizard = Wizard(character);
			cout << "\nSpell power: " << wizard.getSpellPower();
			cout << "\nMana pool: " << wizard.getManaPool();
			cout << "\nSpell resistance: " << wizard.getSpellResistance();
			cout << "\nSummoning proficiency: " << wizard.getSummoningProficiency() << endl << endl;
			break;
		}

	}
}
