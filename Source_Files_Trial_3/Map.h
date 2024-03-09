//
// Created by Nicholas Kamra on 3/6/24.
//

#ifndef SOURCE_FILES_TRIAL_3_MAP_H
#define SOURCE_FILES_TRIAL_3_MAP_H

#include "Cell.h"
#include <vector>
#include <iostream>
#include <utility>
#include "Rooms.h"
#include <termios.h>
#include <cstring>
#include "Character.h"
#include "allcharacters.h"
#include <cmath>
#include <vector>
#include "userInput.h"
#include "misc.h"


class Map {
public:
    int height;
    int width;
    int startX;
    int startY;
    int endX;
    int endY;
    int numPathCells = 0;

    std::vector<std::vector<Cell *> > map;
		
		Map();
    Map(int height, int width);

    void createStart();
    void putPlayerAtStart(Character * player);
    void placePerimeterWalls();
    void snakeEndPath();
    bool createTreasureChest();
    void fillMapWithChests();
    void fillMapWithRooms();
    void fillMapWithWalls();
    bool foundCellForRoomAndAdded(Rooms * room);
    Map* generateInitialMapInfo();
    std::string toString(Map* currentMap);


};
class MapObserver {
public:
    std::string to_string(Map * currentMap);
};

#endif //SOURCE_FILES_TRIAL_3_MAP_H
