//
// Created by Nicholas Kamra on 2/7/24.
//
#include "Character.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <utility>

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