//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Barbarian.h"

Barbarian::Barbarian(int levelToSet, std::string & name) : Character(levelToSet, name){
    Barbarian::setHitPoints();
    Barbarian::setAttackBonus();
    this->characterClass = "Barbarian";
}
void Barbarian::setHitPoints() {this->hitPoints = getConstitutionModifier() + 12;} // Based off constitution and max roll from class hit die
void Barbarian::setAttackBonus() {this->attackBonus = getStrengthModifier();}
