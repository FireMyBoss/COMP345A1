//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Fighter.h"

Fighter::Fighter(int levelToSet, std::string & name) : Character(levelToSet, name){
    Fighter::setHitPoints();
    Fighter::setAttackBonus();
    this->characterClass = "Fighter";
}
void Fighter::setHitPoints() {this->hitPoints = getConstitutionModifier() + 10;} // Based off constitution and max roll from class hit die
void Fighter::setAttackBonus() {this->attackBonus = getStrengthModifier();}