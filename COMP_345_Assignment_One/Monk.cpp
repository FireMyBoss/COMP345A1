//
// Created by Nicholas Kamra on 2/7/24.
//

#include "Monk.h"

Monk::Monk(int levelToSet, std::string & name) : Character(levelToSet, name){
    Monk::setHitPoints();
    Monk::setAttackBonus();
    this->characterClass = "Monk";
}
void Monk::setHitPoints() {this->hitPoints = getConstitutionModifier() + 8;} // Based off constitution and max roll from class hit die
void Monk::setAttackBonus() {this->attackBonus = getStrengthModifier();}