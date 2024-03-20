#include "allcharacters.h"


Barbarian::Barbarian(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Barbarian::setHitPoints();
    Barbarian::setAttackBonus();
    isEnemy = false;
    this->characterClass = "Barbarian";
}

void Barbarian::setHitPoints() { this->hitPoints = getConstitutionModifier() + 12; }

void Barbarian::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Cleric::Cleric(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Cleric::setHitPoints();
    Cleric::setAttackBonus();
    isEnemy = false;
    this->characterClass = "Cleric";
}

void Cleric::setHitPoints() { this->hitPoints = getConstitutionModifier() + 8; }

void Cleric::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Druid::Druid(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Druid::setHitPoints();
    Druid::setAttackBonus();
    isEnemy = false;
    this->characterClass = "Druid";
}

void Druid::setHitPoints() { this->hitPoints = getConstitutionModifier() + 8; }

void Druid::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Fighter::Fighter(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Fighter::setHitPoints();
    Fighter::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Fighter";
}

void Fighter::setHitPoints() { this->hitPoints = getConstitutionModifier() + 10; }

void Fighter::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Monk::Monk(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Monk::setHitPoints();
    Monk::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Monk";
}

void Monk::setHitPoints() { this->hitPoints = getConstitutionModifier() + 8; }

void Monk::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Paladin::Paladin(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Paladin::setHitPoints();
    Paladin::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Paladin";
}

void Paladin::setHitPoints() { this->hitPoints = getConstitutionModifier() + 10; }

void Paladin::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Ranger::Ranger(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Ranger::setHitPoints();
    Ranger::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Ranger";
}

void Ranger::setHitPoints() { this->hitPoints = getConstitutionModifier() + 10; }

void Ranger::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Rogue::Rogue(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Rogue::setHitPoints();
    Rogue::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Rogue";
}

void Rogue::setHitPoints() { this->hitPoints = getConstitutionModifier() + 8; }

void Rogue::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Sorcerer::Sorcerer(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Sorcerer::setHitPoints();
    Sorcerer::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Sorcerer";
}

void Sorcerer::setHitPoints() { this->hitPoints = getConstitutionModifier() + 6; }

void Sorcerer::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Wizard::Wizard(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Wizard::setHitPoints();
    Wizard::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Wizard";
}

void Wizard::setHitPoints() { this->hitPoints = getConstitutionModifier() + 6; }

void Wizard::setAttackBonus() { this->attackBonus = getStrengthModifier(); }

Bard::Bard(int levelToSet, std::string &name) : Character(levelToSet, name) {
    Bard::setHitPoints();
    Bard::setAttackBonus();
    isEnemy = false;

    this->characterClass = "Bard";
}

void Bard::setHitPoints() { this->hitPoints = getConstitutionModifier() + 8; }

void Bard::setAttackBonus() { this->attackBonus = getStrengthModifier(); }
