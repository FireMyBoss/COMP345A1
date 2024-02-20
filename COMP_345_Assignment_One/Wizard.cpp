//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Wizard.h"

Wizard::Wizard(int levelToSet, std::string & name) : Character(levelToSet, name){
    Wizard::setHitPoints();
    Wizard::setAttackBonus();
    this->characterClass = "Wizard";
}
void Wizard::setHitPoints() {this->hitPoints = getConstitutionModifier() + 6;} // Based off constitution and max roll from class hit die
void Wizard::setAttackBonus() {this->attackBonus = getStrengthModifier();}