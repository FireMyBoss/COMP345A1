#pragma once

#include <string>
#include <stdio.h>
#include "State.h"
#include "Character.h"


using namespace std;

class Cell{

private:

public:
    State * state;
    Character * characterInSpot;
    bool isPath;


    Cell(){this->state = new EmptySpot();this->isPath=false; characterInSpot = nullptr;}; // empty state, white space

    bool isEmptyCell(Cell * currentCell);

};


