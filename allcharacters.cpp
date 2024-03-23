/**
 * @file
 * @brief Implementation file for character classes.
 * 
 * This file defines the implementations of various character classes.
 * Each class has its own set of hit points and attack bonuses based on
 * certain criteria.
 */


#include "allcharacters.h"

/**
 * @brief Constructor for the Barbarian class.
 * 
 * Initializes a Barbarian character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Barbarian.
 * @param name Reference to the name of the Barbarian.
 */

Barbarian::Barbarian(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Barbarian::setHitPoints();
    Barbarian::setAttackBonus();
    isEnemy = false;
    
    this->characterClass = "Barbarian";
    
}


/**
 * @brief Sets the hit points for the Barbarian.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Barbarian::setHitPoints() {
	
	this->hitPoints = getConstitutionModifier() + 12; 
	
}


/**
 * @brief Sets the attack bonus for the Barbarian.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */
 
void Barbarian::setAttackBonus() { 
	
	this->attackBonus = getStrengthModifier(); 
	
}


/**
 * @brief Constructor for the Cleric class.
 * 
 * Initializes a Cleric character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Cleric.
 * @param name Reference to the name of the Cleric.
 */

Cleric::Cleric(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Cleric::setHitPoints();
    Cleric::setAttackBonus();
    isEnemy = false;
    
    this->characterClass = "Cleric";
    
}


/**
 * @brief Sets the hit points for the Cleric.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Cleric::setHitPoints() { 

	this->hitPoints = getConstitutionModifier() + 8; 

}


/**
 * @brief Sets the attack bonus for the Cleric.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Cleric::setAttackBonus() {

	this->attackBonus = getStrengthModifier(); 
	
}


/**
 * @brief Constructor for the Druid class.
 * 
 * Initializes a Druid character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Druid.
 * @param name Reference to the name of the Druid.
 */

Druid::Druid(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Druid::setHitPoints();
    Druid::setAttackBonus();
    isEnemy = false;
    
    this->characterClass = "Druid";
    
}


/**
 * @brief Sets the hit points for the Druid.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Druid::setHitPoints() {
	
	this->hitPoints = getConstitutionModifier() + 8;

}


/**
 * @brief Sets the attack bonus for the Druid.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Druid::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Fighter class.
 * 
 * Initializes a Fighter character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Fighter.
 * @param name Reference to the name of the Fighter.
 */

Fighter::Fighter(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Fighter::setHitPoints();
    Fighter::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Fighter";
    
}


/**
 * @brief Sets the hit points for the Fighter.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Fighter::setHitPoints() {

	this->hitPoints = getConstitutionModifier() + 10;
	
}


/**
 * @brief Sets the attack bonus for the Fighter.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Fighter::setAttackBonus() { 

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Monk class.
 * 
 * Initializes a Monk character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Monk.
 * @param name Reference to the name of the Monk.
 */

Monk::Monk(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Monk::setHitPoints();
    Monk::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Monk";
    
}


/**
 * @brief Sets the hit points for the Monk.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Monk::setHitPoints() {
	
	this->hitPoints = getConstitutionModifier() + 8;

}


/**
 * @brief Sets the attack bonus for the Monk.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Monk::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Paladin class.
 * 
 * Initializes a Paladin character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Paladin.
 * @param name Reference to the name of the Paladin.
 */

Paladin::Paladin(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Paladin::setHitPoints();
    Paladin::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Paladin";
    
}


/**
 * @brief Sets the hit points for the Paladin.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Paladin::setHitPoints() {

	this->hitPoints = getConstitutionModifier() + 10;
	
}


/**
 * @brief Sets the attack bonus for the Paladin.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Paladin::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Ranger class.
 * 
 * Initializes a Ranger character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Ranger.
 * @param name Reference to the name of the Ranger.
 */

Ranger::Ranger(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Ranger::setHitPoints();
    Ranger::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Ranger";
    
}


/**
 * @brief Sets the hit points for the Ranger.
 *
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Ranger::setHitPoints() {
	
	this->hitPoints = getConstitutionModifier() + 10;
	
}


/**
 * @brief Sets the attack bonus for the Ranger.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Ranger::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Rogue class.
 * 
 * Initializes a Rogue character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Rogue.
 * @param name Reference to the name of the Rogue.
 */

Rogue::Rogue(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Rogue::setHitPoints();
    Rogue::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Rogue";
    
}


/**
 * @brief Sets the hit points for the Rogue.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Rogue::setHitPoints() { 
	
	this->hitPoints = getConstitutionModifier() + 8;
	
}


/**
 * @brief Sets the attack bonus for the Rogue.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Rogue::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Sorcerer class.
 * 
 * Initializes a Sorcerer character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Sorcerer.
 * @param name Reference to the name of the Sorcerer.
 */

Sorcerer::Sorcerer(int levelToSet, std::string &name) : Character(levelToSet, name) {

    Sorcerer::setHitPoints();
    Sorcerer::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Sorcerer";
    
}


/**
 * @brief Sets the hit points for the Sorcerer.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Sorcerer::setHitPoints() {

	this->hitPoints = getConstitutionModifier() + 6;
	
}


/**
 * @brief Sets the attack bonus for the Sorcerer.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Sorcerer::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Wizard class.
 * 
 * Initializes a Wizard character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Wizard.
 * @param name Reference to the name of the Wizard.
 */

Wizard::Wizard(int levelToSet, std::string &name) : Character(levelToSet, name) {

	Wizard::setHitPoints();
	Wizard::setAttackBonus();
  isEnemy = false;

	this->characterClass = "Wizard";
    
}


/**
 * @brief Sets the hit points for the Wizard.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Wizard::setHitPoints() {

	this->hitPoints = getConstitutionModifier() + 6;
	
}


/**
 * @brief Sets the attack bonus for the Wizard.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Wizard::setAttackBonus() {

	this->attackBonus = getStrengthModifier();
	
}


/**
 * @brief Constructor for the Bard class.
 * 
 * Initializes a Bard character with the specified level and name.
 * Sets hit points and attack bonus accordingly.
 * 
 * @param levelToSet The level of the Bard.
 * @param name Reference to the name of the Bard.
 */

Bard::Bard(int levelToSet, std::string &name) : Character(levelToSet, name) {

	Bard::setHitPoints();
	Bard::setAttackBonus();
	isEnemy = false;

	this->characterClass = "Bard";
}


/**
 * @brief Sets the hit points for the Bard.
 * 
 * Hit points are calculated based on the Constitution modifier and a base value.
 */

void Bard::setHitPoints() {

	this->hitPoints = getConstitutionModifier() + 8; 
	
}


/**
 * @brief Sets the attack bonus for the Bard.
 * 
 * Attack bonus is calculated based on the Strength modifier.
 */

void Bard::setAttackBonus() {
	
	this->attackBonus = getStrengthModifier();
	
}
