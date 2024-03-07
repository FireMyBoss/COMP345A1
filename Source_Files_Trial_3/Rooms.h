//
// Created by Nicholas Kamra on 3/7/24.
//

#ifndef SOURCE_FILES_TRIAL_3_ROOMS_H
#define SOURCE_FILES_TRIAL_3_ROOMS_H

#include "Cell.h"
#include <vector>

class Rooms {
public:
    static std::vector<std::string> roomVector;
    int xDimension;
    int yDimension;
    std::string bluePrint;
    Rooms();
};

class Prison : public Rooms{
public:
    Prison();
};

class TreasureRoom : public Rooms{
public:
    TreasureRoom();

};

class Dungeon : public Rooms{
public:
    Dungeon();

};

class Cave : public Rooms{
public:
    Cave();

};


#endif //SOURCE_FILES_TRIAL_3_ROOMS_H
