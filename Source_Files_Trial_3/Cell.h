#pragma once

#include <string>
#include <stdio.h>
#include "State.h"
#include "Character.h"


using namespace std;

class Cell{

private:

public:
    State state;
    Character *hasCharacter;
    bool isPath;

    Cell(State st): state(st){};
    Cell(){}; // empty state, white space

};


