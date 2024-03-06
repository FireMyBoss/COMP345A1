//
// Created by Nicholas Kamra on 3/6/24.
//

#ifndef SOURCE_FILES_TRIAL_3_DICE_H
#define SOURCE_FILES_TRIAL_3_DICE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

class Dice {
public:
    int roll(const std::string & expression);

private:
    int rollDie(int sides);
};



#endif //SOURCE_FILES_TRIAL_3_DICE_H
