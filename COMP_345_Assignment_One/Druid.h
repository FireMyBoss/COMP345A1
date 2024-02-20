//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_DRUID_H
#define COMP_345_ASSIGNMENT_ONE_DRUID_H

#include "Character.h"
#include <string>

class Druid : public Character {
public:
    explicit Druid(int levelToSet, std::string & name);
    void setHitPoints() override;
    void setAttackBonus() override;
};


#endif //COMP_345_ASSIGNMENT_ONE_DRUID_H
