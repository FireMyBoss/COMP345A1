//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_RANGER_H
#define COMP_345_ASSIGNMENT_ONE_RANGER_H

#include "Character.h"
#include <string>

class Ranger : public Character {
public:
    explicit Ranger(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;
};


#endif //COMP_345_ASSIGNMENT_ONE_RANGER_H
