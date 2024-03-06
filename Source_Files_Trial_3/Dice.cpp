//
// Created by Nicholas Kamra on 3/6/24.
//

#include "Dice.h"
int Dice::roll(const std::string & expression) {
    std::istringstream iss(expression);
    char d;
    int numDice, sides, modifier;
    iss >> numDice >> d >> sides;


    if (iss.peek() == '+' || iss.peek() == '-') {
        iss >> modifier;
    }
    else {
        modifier = 0; // Default
    }

    int total = 0;
    for (int i = 0; i < numDice; ++i) {
        total += rollDie(sides);
    }

    return total + modifier;
}
int Dice::rollDie(int sides) {
    return rand() % sides + 1;
}