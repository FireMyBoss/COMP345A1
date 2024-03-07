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
    int startX;
    int startY;
    int endX;
    int endY;
    int numPathCells = 0;

    std::vector<std::vector<Cell *>> map;

    Map(int height, int width);

    void createStart();
    void putPlayerAtStart(Character * player);
    void placePerimeterWalls();
    void snakeEndPath();
    void createTreasureChest();
    void fillMapWithChests();
    void fillMapWithRooms();
    void fillMapWithWalls();


};


#endif //SOURCE_FILES_TRIAL_3_MAP_H
