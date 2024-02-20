//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Rogue.h"

Rogue::Rogue(int levelToSet, std::string & name) : Character(levelToSet, name){
    Rogue::setHitPoints();
    Rogue::setAttackBonus();
    this->characterClass = "Rogue";
}
void Rogue::setHitPoints() {this->hitPoints = getConstitutionModifier() + 8;} // Based off constitution and max roll from class hit die
void Rogue::setAttackBonus() {this->attackBonus = getStrengthModifier();}