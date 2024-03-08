#include <iostream>
#include "Character.h"
#include "allcharacters.h"
#include "Map.h"
#include "MapObserver.h"
#include <vector>

void printCharacter(Character* character){

    std::cout << "---Character Characteristics---" << std::endl;
    std::cout << "Name: ";
    std::cout << character->getName() << std::endl;
    std::cout << "Class: ";
    std::cout << character->getCharacterClass() << std::endl;
    std::cout << "Level: ";
    std::cout << character->getLevel() << std::endl;
    std::cout << "Hit Points: ";
    std::cout << character->getHitPoints() << std::endl;
    std::cout << "Armor Class: ";
    std::cout << character->getArmorClass() << std::endl;
    std::cout << "Attack Bonus: ";
    std::cout << character->getAttackBonus() << std::endl;
    std::cout << "Damage Bonus: ";
    std::cout << character->getDamageBonus() << std::endl;

    std::cout << "---Armor---" << std::endl;
    std::cout << "Helmet: ";
    std::cout << character->getHelmet() << std::endl;
    std::cout << "Boots: ";
    std::cout << character->getBoots() << std::endl;
    std::cout << "Armor: ";
    std::cout << character->getArmor() << std::endl;
    std::cout << "Shield: ";
    std::cout << character->getShield() << std::endl;
    std::cout << "Weapon: ";
    std::cout << character->getWeapon() << std::endl;
    std::cout << "Ring: ";
    std::cout << character->getRing() << std::endl;

    std::cout << "---Ability Scores---" << std::endl;
    std::cout << "Strength Score: ";
    std::cout << character->getStrengthScore() << std::endl;
    std::cout << "Dexterity Score: ";
    std::cout << character->getDexterityScore() << std::endl;
    std::cout << "Constitution Score: ";
    std::cout << character->getConstitutionScore() << std::endl;
    std::cout << "Intelligence Score: ";
    std::cout << character->getIntelligenceScore() << std::endl;
    std::cout << "Wisdom Score: ";
    std::cout << character->getWisdomScore() << std::endl;
    std::cout << "Charisma Score: ";
    std::cout << character->getCharismaScore() << std::endl;

    std::cout << "---Ability Modifiers---" << std::endl;
    std::cout << "Strength Modifier: ";
    std::cout << character->getStrengthModifier() << std::endl;
    std::cout << "Dexterity Modifier: ";
    std::cout << character->getDexterityModifier() << std::endl;
    std::cout << "Constitution Modifier: ";
    std::cout << character->getConstitutionModifier() << std::endl;
    std::cout << "Intelligence Modifier: ";
    std::cout << character->getIntelligenceModifier() << std::endl;
    std::cout << "Wisdom Modifier: ";
    std::cout << character->getWisdomModifier() << std::endl;
    std::cout << "Charisma Modifier: ";
    std::cout << character->getCharismaModifier() << std::endl;


}

Character* createNewCharacter(std::vector<Character*> & createdCharacterArray){

    Character* newCharacter;

    std::cout << "Please fill in the following options to create a new player:" << std::endl;
    std::cout << "Enter a name for your character: " << std::endl;
    // take input for name of character
    std::string name = "Jacky Chan";



    std::cout << "Enter a level for your character: " << std::endl;
    // take input for level of character
    int level = 11;



    std::cout << "Enter number of class from list below: " << std::endl;
    std::cout << "'1' for Barbarian" << std::endl;
    std::cout << "'2' for Bard" << std::endl;
    std::cout << "'3' for Cleric" << std::endl;
    std::cout << "'4' for Druid" << std::endl;
    std::cout << "'5' for Fighter" << std::endl;
    std::cout << "'6' for Monk" << std::endl;
    std::cout << "'7' for Paladin" << std::endl;
    std::cout << "'8' for Ranger" << std::endl;
    std::cout << "'9' for Rogue" << std::endl;
    std::cout << "'10' for Sorcerer" << std::endl;
    std::cout << "'11' for Wizard" << std::endl;
    std::cout << "Enter option here: " << std::endl;
    // Get input for class
    int characterClass = 5;


    switch(characterClass) {
        case 1:
            newCharacter = new Barbarian(level, name);
            break;
        case 2:
            newCharacter = new Bard(level, name);
            break;
        case 3:
            newCharacter = new Cleric(level, name);
            break;
        case 4:
            newCharacter = new Druid(level, name);
            break;
        case 5:
            newCharacter = new Fighter(level, name);
            break;
        case 6:
            newCharacter = new Monk(level, name);
            break;
        case 7:
            newCharacter = new Paladin(level, name);
            break;
        case 8:
            newCharacter = new Ranger(level, name);
            break;
        case 9:
            newCharacter = new Rogue(level, name);
            break;
        case 10:
            newCharacter = new Sorcerer(level, name);
            break;
        case 11:
            newCharacter = new Wizard(level, name);
            break;
        default:
            std::cout << "--- No character created ----" << std::endl;
            return nullptr;
    }

    std::cout << "---New character has been created---" << std::endl;
    createdCharacterArray.push_back(newCharacter);
    printCharacter(newCharacter);
    return newCharacter;

}
void displayCreatedCharacterList(std::vector<Character*> & createdCharacterArray){
    for(int i = 0; i < createdCharacterArray.size(); i++){
        std::cout << "Name: ";
        std::cout << createdCharacterArray.at(i)->getName();
        std::cout << " || Class: ";
        std::cout << createdCharacterArray.at(i)->getCharacterClass() << std::endl;
    }
}

void createCharacterInterface() {

    std::cout << "Welcome to D&D character creation!" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    std::vector<Character*> createdCharacterArray;

    for (int i = 0; i < 3; i++) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Enter '1' to create a new character" << std::endl;
        std::cout << "2. Enter '2' to list all created characters" << std::endl;
        std::cout << "3. Enter '3' to select a created character" << std::endl;
        std::cout << "4. Enter '4' to quit the program" << std::endl;

        char userSelection = '1';

        if (userSelection == '1') {
            createNewCharacter(createdCharacterArray);
        }else if (userSelection == '2'){
            displayCreatedCharacterList(createdCharacterArray);
        }else if (userSelection == '3'){

        }else if (userSelection == '4'){

        }else{
            continue;
        }
    }

}

int main() {

    Map * newMap = new Map(100, 100);
    MapObserver newObserver;
    newObserver.to_string(newMap);





    
    Backpack backpk(4);
    backpk.printItem();

    return 0;
}
