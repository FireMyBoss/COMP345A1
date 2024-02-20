//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Paladin.h"

Paladin::Paladin(int levelToSet, std::string & name) : Character(levelToSet, name){
    Paladin::setHitPoints();
    Paladin::setAttackBonus();
    this->characterClass = "Paladin";
}
void Paladin::setHitPoints() {this->hitPoints = getConstitutionModifier() + 10;} // Based off constitution and max roll from class hit die
void Paladin::setAttackBonus() {this->attackBonus = getStrengthModifier();}