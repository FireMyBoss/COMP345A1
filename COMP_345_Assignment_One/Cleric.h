//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_CLERIC_H
#define COMP_345_ASSIGNMENT_ONE_CLERIC_H

#include "Character.h"
#include <string>

class Cleric : public Character {
public:
    explicit Cleric(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;
};


#endif //COMP_345_ASSIGNMENT_ONE_CLERIC_H
