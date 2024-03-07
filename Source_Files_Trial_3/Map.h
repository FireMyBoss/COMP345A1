//
// Created by Nicholas Kamra on 3/6/24.
//

#ifndef SOURCE_FILES_TRIAL_3_MAP_H
#define SOURCE_FILES_TRIAL_3_MAP_H

#include "Cell.h"
#include <vector>
#include <iostream>
class Map {
public:
    int height;
    int width;
    std::vector<std::vector<Cell *>> map;

    Map(int height, int width);
    void to_string();
    void to_string();
    void createStart();
    void putPlayerAtStart();
    void placePerimeterWalls();
    void endPath();
    bool createTreasureChest();
    void fillMapWithChests();

};


#endif //SOURCE_FILES_TRIAL_3_MAP_H
