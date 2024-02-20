//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_MONK_H
#define COMP_345_ASSIGNMENT_ONE_MONK_H

#include "Character.h"
#include <string>

class Monk : public Character {
public:
    explicit Monk(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;

};


#endif //COMP_345_ASSIGNMENT_ONE_MONK_H
