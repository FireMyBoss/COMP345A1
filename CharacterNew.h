#pragma once

using namespace std;

class CharacterNew {

	public:
	
		CharacterNew();
		CharacterNew(int characterClass, int isPlayer, int characterStrategy, string characterName, int* characterAttributes, int* characterCoordinates, int* characterAbilityScores, int* characterAbilityModifiers);
		~CharacterNew();
		
		int getCharacterClass();
		void setCharacterClass();
		
		int getIsPlayer();
		int setIsPlayer();
		
		
	private:
		
		int characterClass; //Starting from 0, indicates: Barbarian, Bard, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer, Wizard
		int isPlayer;
		int characterStrategy;
		
		string characterName;

		
		int* characterAttributes; //[characterLevel, hitpoints, armorClass, attackBonus, damageBonus]
		int* characterCoordinates; //[xCoord, yCoord]
		int* characterAbilityScores; //[strengthScore, dexterityScore, constitutionScore, intelligenceScore, wisdomScore, charismaScore]
		int* characterAbilityModifiers; //[strengthModifier, dexterityModifier, constitutionModifier, intelligenceModifier, wisdomModifier, charismaModifier]
		//item equippedItems here
		//item backpack here

};

