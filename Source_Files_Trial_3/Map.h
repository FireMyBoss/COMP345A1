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
#include "Item.h"
#include <queue>

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
    std::vector<Character *> playersInGame;
		
    Map();
    Map(int height, int width);
    Map(int height, int width, bool nothing); //for Shai
    Map(std::vector<std::vector<std::string> > mapAsVectorOfStrings);
    ~Map();

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
    void loadCharactersIntoMap(std::vector<Character *> players);
    bool getUserInput(Character * player);
    State * getStateOfCell(int x, int y);
    bool pauseMenuUIandExitGame();

};
class MapObserver {
public:
    std::string to_string(Map * currentMap);
};

std::vector<std::vector<std::string> > mapToVectorForCSV(Map * theMap);

#endif //SOURCE_FILES_TRIAL_3_MAP_H
