#pragma once

#include <string>
#include <stdio.h>
#include "TreasureChest.h"


using namespace std;

class State{

private:

public:
    char letter;
    string colour;
   

    State(): colour("white"), letter('.') {};
    void setColour(string color);
    void setLetter(char let);
    

};
