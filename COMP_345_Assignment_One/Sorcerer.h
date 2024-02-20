//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_SORCERER_H
#define COMP_345_ASSIGNMENT_ONE_SORCERER_H

#include "Character.h"
#include <string>

class Sorcerer : public Character {
public:
    explicit Sorcerer(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;

};


#endif //COMP_345_ASSIGNMENT_ONE_SORCERER_H
