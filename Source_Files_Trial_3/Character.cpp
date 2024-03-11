//
// Created by Nicholas Kamra on 2/7/24.
//
#include "Character.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <utility>
#include <iostream>
#include "allcharacters.h"

// Constructors
Character::Character(){

    // Player coordinates
    this->x = 0;
    this->y = 0;

    // Initializing player attributes
    this->characterClass = "None";
    this->name = "";
    this->level = 0;
    this->hitPoints = 0;
    this->armorClass = 0;
    this->attackBonus = 0;
    this->damageBonus = 0;

    // Initializing armor slots to NULL
    this->helmet = nullptr;
    this->boots = nullptr;
    this->armor = nullptr;
    this->shield = nullptr;
    this->weapon = nullptr;
    this->ring = nullptr;
    this->belt = nullptr;

    // Initialization of ability scores
    this->strengthScore = 0;
    this->dexterityScore = 0;
    this->constitutionScore = 0;
    this->intelligenceScore = 0;
    this->wisdomScore = 0;
    this->charismaScore = 0;

    // Initialization of ability modifiers
    this->strengthModifier = 0;
    this->dexterityModifier = 0;
    this->constitutionModifier = 0;
    this->intelligenceModifier = 0;
    this->wisdomModifier = 0;
    this->charismaModifier = 0;
}
Character::Character(int levelToSet, std::string & name) : level(levelToSet){

    // Player coordinates
    this->x = 0;
    this->y = 0;

    // Initializing player attributes
    this->characterClass = "None";
    setName(name);
    this->hitPoints = 0;
    setArmorClass();
    this->attackBonus = 0;
    setDamageBonus();

    // Initializing armor slots to NULL
    this->helmet = nullptr;
    this->boots = nullptr;
    this->armor = nullptr;
    this->shield = nullptr;
    this->weapon = nullptr;
    this->ring = nullptr;
    this->belt = nullptr;

    // Initialization of ability scores
    time_t t;
    srand((unsigned) time(&t));
    this->strengthScore = rand() % 16 + 3;
    this->dexterityScore = rand() % 16 + 3;
    this->constitutionScore = rand() % 16 + 3;
    this->intelligenceScore = rand() % 16 + 3;
    this->wisdomScore = rand() % 16 + 3;
    this->charismaScore = rand() % 16 + 3;

    // Initialization of ability modifiers
    setStrengthModifier();
    setDexterityModifier();
    setConstitutionModifier();
    setIntelligenceModifier();
    setWisdomModifier();
    setCharismaModifier();
}

// Getters
std::string Character::getCharacterClass() const {return characterClass;}
std::string Character::getName() const {return name;}
int Character::getLevel() const {return level;}
int Character::getHitPoints() const {return hitPoints;}
int Character::getArmorClass() const {return armorClass;}
int Character::getAttackBonus() const {return attackBonus;}
int Character::getDamageBonus() const {return damageBonus;}
Helmet* Character::getHelmet() {return helmet;}
Boots* Character::getBoots() {return boots;}
Armor* Character::getArmor() {return armor;}
Shield* Character::getShield() {return shield;}
Weapon* Character::getWeapon() {return weapon;}
Ring* Character::getRing() {return ring;}
Belt* Character::getBelt() {return belt;}
int Character::getStrengthScore() const {return strengthScore;}
int Character::getDexterityScore() const {return dexterityScore;}
int Character::getConstitutionScore() const {return constitutionScore;}
int Character::getIntelligenceScore() const {return intelligenceScore;}
int Character::getWisdomScore() const {return wisdomScore;}
int Character::getCharismaScore() const {return charismaScore;}
int Character::getStrengthModifier() const {return strengthModifier;}
int Character::getDexterityModifier() const {return dexterityModifier;}
int Character::getConstitutionModifier() const {return constitutionModifier;}
int Character::getIntelligenceModifier() const {return intelligenceModifier;}
int Character::getWisdomModifier() const {return wisdomModifier;}
int Character::getCharismaModifier() const {return charismaModifier;}


// Setters
void Character::setCharacterClass(std::string newCharacterClassToSet) {this->characterClass = newCharacterClassToSet;}
void Character::setName(std::string & nameToSet) {this->name = nameToSet;}
void Character::setLevel(int levelForUpdate) {this->level = levelForUpdate;}
void Character::setHitPoints() {}
void Character::setArmorClass() {this->armorClass = getDexterityModifier() + 10;}
void Character::setAttackBonus() {}
void Character::setDamageBonus() {this->damageBonus = getStrengthModifier();}
void Character::setHelmet(Helmet* helmetToAdd) {this->helmet = helmetToAdd;}
void Character::setBoots(Boots* bootsToAdd) {this->boots = bootsToAdd;}
void Character::setArmor(Armor* armorToAdd) {this->armor = armorToAdd;}
void Character::setShield(Shield* shieldToAdd) {this->shield = shieldToAdd;}
void Character::setWeapon(Weapon* weaponToAdd) {this->weapon = weaponToAdd;}
void Character::setRing(Ring* ringToAdd) {this->ring = ringToAdd;}
void Character::setBelt(Belt* beltToAdd) {this->belt = beltToAdd;}
void Character::setStrengthScore(int strengthScoreForUpdate){this->strengthScore = strengthScoreForUpdate;}
void Character::setDexterityScore(int dexterityScoreForUpdate){this->dexterityScore = dexterityScoreForUpdate;}
void Character::setConstitutionScore(int constitutionScoreForUpdate){this->constitutionScore = constitutionScoreForUpdate;}
void Character::setIntelligenceScore(int intelligenceScoreForUpdate){this->intelligenceScore = intelligenceScoreForUpdate;}
void Character::setWisdomScore(int wisdomScoreForUpdate){this->wisdomScore = wisdomScoreForUpdate;}
void Character::setCharismaScore(int charismaScoreForUpdate){this->charismaScore = charismaScoreForUpdate;}
void Character::setStrengthModifier() {this->strengthModifier = calculateModifier(getStrengthScore());}
void Character::setDexterityModifier() {this->dexterityModifier = calculateModifier(getDexterityScore());}
void Character::setConstitutionModifier() {this->constitutionModifier = calculateModifier(getConstitutionScore());}
void Character::setIntelligenceModifier() {this->intelligenceModifier = calculateModifier(getIntelligenceScore());}
void Character::setWisdomModifier() {this->wisdomModifier = calculateModifier(getWisdomScore());}
void Character::setCharismaModifier() {this->charismaModifier = calculateModifier(getCharismaScore());}

// Calculates the modifier based on d20 rules
int Character::calculateModifier(int abilityScore) {return floor((abilityScore - 10) / 2);}

// UI for menu

void Character::printCharacter(Character* character){

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

    std::cout << "" << std::endl;

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

    std::cout << "" << std::endl;

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

    std::cout << "" << std::endl;

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

    std::cout << "" << std::endl;

}

Character* Character::createNewCharacter(std::vector<Character*> & createdCharacterArray) {

    Character *newCharacter;

    std::cout << "Please fill in the following options to create a new player:" << std::endl;

    std::cout << "" << std::endl;

    std::cout << "Enter a name for your character: " << std::endl;
    // take input for name of character
    std::string name = "";
    std::cin >> name;

    std::cout << "" << std::endl;


    std::cout << "Enter a level for your character: " << std::endl;


    // take input for level of character
    int level = 0;
    for (;;){
        try {
            std::cin >> level;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter an integer.");
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    std::cout << "" << std::endl;

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

    std::cout << "" << std::endl;

    // Get input for class
    int characterClass;
    for (;;){
        try {
            std::cin >> characterClass;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter an integer.");
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }


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
    std::cout << "" << std::endl;
    createdCharacterArray.push_back(newCharacter);
    printCharacter(newCharacter);
    return newCharacter;

}
void Character::displayCreatedCharacterList(std::vector<Character*> & createdCharacterArray){
    for(int i = 0; i < createdCharacterArray.size(); i++){
        std::cout << "Name: ";
        std::cout << createdCharacterArray.at(i)->getName();
        std::cout << " || Class: ";
        std::cout << createdCharacterArray.at(i)->getCharacterClass() << std::endl;
    }
}

void Character::createCharacterInterface() {

    std::cout << "Welcome to D&D character creation!" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    std::vector<Character*> createdCharacterArray;

    for (;;) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Enter '1' to create a new character" << std::endl;
        std::cout << "2. Enter '2' to list all created characters" << std::endl;
        std::cout << "3. Enter '3' to quit the program" << std::endl;

        std::cout << "" << std::endl;

        // take input for user selection
        char userSelection;
        for (;;){
            try {
                std::cin >> userSelection;
                if(cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }

        if (userSelection == '1') {
            createNewCharacter(createdCharacterArray);
        }else if (userSelection == '2'){
            displayCreatedCharacterList(createdCharacterArray);
        }else if (userSelection == '3'){
            for(int i = 0; i < createdCharacterArray.size(); i++){
                delete createdCharacterArray.at(i);
            }
            return;
        }else{
            continue;
        }
    }
}