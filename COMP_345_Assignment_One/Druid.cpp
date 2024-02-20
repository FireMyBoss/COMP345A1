//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Druid.h"

Druid::Druid(int levelToSet, std::string & name) : Character(levelToSet, name){
    Druid::setHitPoints();
    Druid::setAttackBonus();
    this->characterClass = "Druid";
}
void Druid::setHitPoints() {this->hitPoints = getConstitutionModifier() + 8;} // Based off constitution and max roll from class hit die
void Druid::setAttackBonus() {this->attackBonus = getStrengthModifier();}