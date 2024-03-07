#pragma once

#include <string>
#include <stdio.h>


using namespace std;

class State{ // we need to make treasure chest a child of State

public:

    char letter;
    string colour;

};

class EmptySpot : public State{
public:
    EmptySpot(){this->letter = '.'; this->colour = "white";};
};

class Wall : public State{
public:
    Wall(){this->letter = 'X'; this->colour = "black";};
};

class Door : public State{
public:
    Door(){this->letter = 'D'; this->colour = "brown";};
};

class StartSpot : public State{ // isPath set to true
public:
    StartSpot(){this->letter = 'S'; this->colour = "blue";};
};

class EndSpot : public State{ // isPath set to true
public:
    EndSpot(){this->letter = 'E'; this->colour = "red";};
};