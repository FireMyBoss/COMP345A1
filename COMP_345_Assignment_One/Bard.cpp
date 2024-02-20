//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Bard.h"

Bard::Bard(int levelToSet, std::string & name) : Character(levelToSet, name){
    Bard::setHitPoints();
    Bard::setAttackBonus();
    this->characterClass = "Bard";
}
void Bard::setHitPoints() {this->hitPoints = getConstitutionModifier() + 8;} // Based off constitution and max roll from class hit die
void Bard::setAttackBonus() {this->attackBonus = getStrengthModifier();}