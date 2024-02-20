//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Cleric.h"

Cleric::Cleric(int levelToSet, std::string & name) : Character(levelToSet, name){
    Cleric::setHitPoints();
    Cleric::setAttackBonus();
    this->characterClass = "Cleric";
}
void Cleric::setHitPoints() {this->hitPoints = getConstitutionModifier() + 8;} // Based off constitution and max roll from class hit die
void Cleric::setAttackBonus() {this->attackBonus = getStrengthModifier();}