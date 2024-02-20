//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_FIGHTER_H
#define COMP_345_ASSIGNMENT_ONE_FIGHTER_H

#include "Character.h"
#include <string>

class Fighter : public Character {
public:
    explicit Fighter(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;

};


#endif //COMP_345_ASSIGNMENT_ONE_FIGHTER_H
