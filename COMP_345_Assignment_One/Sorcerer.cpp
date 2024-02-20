//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Sorcerer.h"

Sorcerer::Sorcerer(int levelToSet, std::string & name) : Character(levelToSet, name){
    Sorcerer::setHitPoints();
    Sorcerer::setAttackBonus();
    this->characterClass = "Sorcerer";
}
void Sorcerer::setHitPoints() {this->hitPoints = getConstitutionModifier() + 6;} // Based off constitution and max roll from class hit die
void Sorcerer::setAttackBonus() {this->attackBonus = getStrengthModifier();}