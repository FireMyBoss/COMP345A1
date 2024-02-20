//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_ROGUE_H
#define COMP_345_ASSIGNMENT_ONE_ROGUE_H

#include "Character.h"
#include <string>

class Rogue : public Character {
public:
    explicit Rogue(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;

};


#endif //COMP_345_ASSIGNMENT_ONE_ROGUE_H
