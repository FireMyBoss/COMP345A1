//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Ranger.h"

Ranger::Ranger(int levelToSet, std::string & name) : Character(levelToSet, name){
    Ranger::setHitPoints();
    Ranger::setAttackBonus();
    this->characterClass = "Ranger";
}
void Ranger::setHitPoints() {this->hitPoints = getConstitutionModifier() + 10;} // Based off constitution and max roll from class hit die
void Ranger::setAttackBonus() {this->attackBonus = getStrengthModifier();}