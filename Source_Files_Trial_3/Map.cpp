//
// Created by Nicholas Kamra on 3/6/24.
//

#include "Map.h"
#include "Rooms.h"


/*
 * IMPORTANT!!!!!!!!!!!!!
 * When getting coords on the board with map.at().at() to get into 2D array
 * the first at() holds the Y coord and the second at() holds the X coord
 *  |
 *  |
 *  |     Down is the first at()
 *  |
 *  v
 *
 *  -------------> Right is the second at()
 */

Map::Map(int height, int width){

    this->height = height;
    this->width = width;
    this->startX = 0;
    this->startY = 0;
    this->endX = 0;
    this->endY = 0;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::vector<Cell *> newVector;
            map.push_back(newVector);
            Cell * newCell = new Cell();
            map.at(i).push_back(newCell);
        }
    }
    Map::createStart();
    Map::placePerimeterWalls();
    Map::snakeEndPath();
    Map::fillMapWithWalls();
    Map::fillMapWithRooms();
}
void Map::createStart(){ // finds a starting point on the perimeter
    // if 1 -> left side, if 2 -> top, if 3 -> right side, if 4 -> bottom
    time_t t;
    srand((unsigned) time(&t));
    int side = rand() % 4 + 1;

    int X;
    int Y;

    switch(side){
        case 1: // left side
            X = 0; // isn't random
            Y = rand() % (height - 2) + 1;
            break;
        case 2: // top
            X = rand() % (width - 2) + 1;
            Y = 0; // isn't random
            break;
        case 3: // right side
            X = width - 1; // isn't random
            Y = rand() % (height - 2) + 1;
            break;
        case 4: // bottom
            X = rand() % (width - 2) + 1;
            Y = height - 1; // isn't random
            break;
        default:
            X = 0;
            Y = 0;
            break;
    }
    State * newStartSpot = new StartSpot();
    map.at(Y).at(X)->state = newStartSpot;
    this->startX = X;
    this->startY = Y;
}
void Map::putPlayerAtStart(Character * player){ // sets the player coordinates to the start
    player->x = this->startX;
    player->y = this->startY;
}
void Map::placePerimeterWalls(){

    for(int i = 0; i < this->height; i++){
        if(this->map.at(i).at(0)->state->letter == 'S'){
            continue;
        }else {
            State * newSpot = new Wall();
            this->map.at(i).at(0)->state = newSpot;
        }
    }

    for(int i = 0; i < this->width; i++){
        if(this->map.at(0).at(i)->state->letter == 'S'){
            continue;
        }else {
            State * newSpot = new Wall();
            this->map.at(0).at(i)->state = newSpot;
        }
    }

    for(int i = 0; i < this->height; i++){
        if(this->map.at(i).at(width-1)->state->letter == 'S'){
            continue;
        }else {
            State * newSpot = new Wall();
            this->map.at(i).at(width-1)->state = newSpot;
        }
    }

    for(int i = 0; i < this->width; i++){
        if(this->map.at(height-1).at(i)->state->letter == 'S'){
            continue;
        }else {
            State * newSpot = new Wall();
            this->map.at(height-1).at(i)->state = newSpot;
        }
    }
}
void Map::snakeEndPath(){ // There's a snake in my boot
    // 25%, 25%, 50% for chances of going in particular direction.
    // One direction will have a strong bias.

    Cell * currentCell = nullptr;
    currentCell = map.at(startY).at(startX);
    int currentX = startX;
    int currentY = startY;
    time_t t;
    srand((unsigned) time(&t));

    // Every movement sets the cell to isPath. Must start one step into map from start. Otherwise if
    // we start at the start spot on the left and go up. This cell will be a wall and will be considered
    // the end.

    if(this->startX == 0){ // start on left
        currentX++;
        currentCell = map.at(currentY).at(currentX);
        currentCell->isPath = true;
        bool endIsFound = false;
        while(!endIsFound){
            int direction = rand() % 100; // 0 to 99
            if(direction < 33){ // Go Up
                currentY--;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else if(direction >= 33 && direction < 66){ // Go down
                currentY++;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else{ // Go right
                currentX++;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }
            // Check to see if cell is a wall. If it is, endIsFound is true and we make the cell have an EndSpot state
            // and set the Map's endX and endY to the coordinates.
            if(currentCell->isEmptyCell(currentCell)){
                continue;
            }else{
                endIsFound = true;
            }
        }
    }else if(this->startX == width - 1){ // start on right
        currentX--;
        currentCell = map.at(currentY).at(currentX);
        currentCell->isPath = true;
        bool endIsFound = false;
        while(!endIsFound){
            int direction = rand() % 100; // 0 to 99
            if(direction < 33){ // Go Up
                currentY--;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else if(direction >= 33 && direction < 66){ // Go down
                currentY++;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else{ // Go left
                currentX--;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }
            if(currentCell->isEmptyCell(currentCell)){
                continue;
            }else{
                endIsFound = true;
            }
        }
    }else if(this->startY == 0){ // start on top
        currentY++;
        currentCell = map.at(currentY).at(currentX);
        currentCell->isPath = true;
        bool endIsFound = false;
        while(!endIsFound){
            int direction = rand() % 100; // 0 to 99
            if(direction < 33){ // Go right
                currentX++;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else if(direction >= 33 && direction < 66){ // Go left
                currentX--;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else{ // Go down
                currentY++;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }
            if(currentCell->isEmptyCell(currentCell)){
                continue;
            }else{
                endIsFound = true;
            }
        }
    }else{ // start on bottom
        currentY--;
        currentCell = map.at(currentY).at(currentX);
        currentCell->isPath = true;
        bool endIsFound = false;
        while(!endIsFound){
            int direction = rand() % 100; // 0 to 99
            if(direction < 33){ // Go right
                currentX++;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else if(direction >= 33 && direction < 66){ // Go left
                currentX--;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }else{ // Go down
                currentY--;
                currentCell = map.at(currentY).at(currentX);
                currentCell->isPath = true;
            }
            if(currentCell->isEmptyCell(currentCell)){
                continue;
            }else{
                endIsFound = true;
            }
        }
    }

    this->endX = currentX;
    this->endY = currentY;
    State * newEndSpot = new EndSpot();
    currentCell->state = newEndSpot;

}

void Map::fillMapWithWalls(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(map.at(i).at(j)->isEmptyCell(map.at(i).at(j)) &&
             !map.at(i).at(j)->isPath){
                State * newWall = new Wall();
                map.at(i).at(j)->state = newWall;
            }else{
                numPathCells++;
            }
        }
    }
}

void Map::fillMapWithRooms(){
 // We want around 25% of the map area to be rooms, so we take the mapWidth*mapHeight*0.5 and this
 // will give us the amount of area we can reserve for rooms. We can calculate how many rooms we are going to have
 // by randomly selecting a room (on frequency, the treasure room will have a very low chance, dungeon high chance)
 // and we will take the area of the room and subtract it from the reserved area for rooms. This will then
 // be generated onto the map. We will look for spots where the area of the room does not collide with walls and player
 // paths.

    int mapArea = (width-1) * (height-1) - numPathCells;
    int roomReserved = mapArea/6;

    int areaOfBiggestRoom = 500;

    time_t t;
    srand((unsigned) time(&t));


    int numberOfRoomTypes = Rooms::roomVector.size();


    while(roomReserved > areaOfBiggestRoom){

        int roomSelection = rand() % numberOfRoomTypes;

        if(roomSelection == 0){ // Prison

            Rooms * newRoom = new Prison();
            if(foundCellForRoomAndAdded(newRoom)){
                roomReserved -= (newRoom->xDimension * newRoom->yDimension);
                continue;
            }else{
                delete newRoom;
                newRoom = nullptr;
            }

        }else if(roomSelection == 1){ // TreasureRoom

            Rooms * newRoom = new TreasureRoom();
            if(foundCellForRoomAndAdded(newRoom)){
                roomReserved -= (newRoom->xDimension * newRoom->yDimension);
                continue;
            }else{
                delete newRoom;
                newRoom = nullptr;
            }

        }else if(roomSelection == 2){ // Dungeon

            Rooms * newRoom = new Dungeon();
            if(foundCellForRoomAndAdded(newRoom)){
                roomReserved -= (newRoom->xDimension * newRoom->yDimension);
                continue;
            }else{
                delete newRoom;
                newRoom = nullptr;
            }

        }else if(roomSelection == 3){ // Cave

            Rooms * newRoom = new Cave();
            if(foundCellForRoomAndAdded(newRoom)){
                roomReserved -= (newRoom->xDimension * newRoom->yDimension);
                continue;
            }else{
                delete newRoom;
                newRoom = nullptr;
            }

        }
    }
}
bool Map::foundCellForRoomAndAdded(Rooms * room){

    time_t t;
    srand((unsigned) time(&t));

    int possibleXRange = width - room->xDimension - 4;
    int possibleYRange = height - room->yDimension - 4;

    int xToTest;
    int yToTest;

   for(;;) {
       xToTest = rand() % possibleXRange + 2;
       yToTest = rand() % possibleYRange + 2;
       bool findNewTest = false;
       for (int i = 0; i < room->xDimension; i++) {
           for (int j = 0; j < room->yDimension; j++) {

               if (map.at(yToTest + j).at(xToTest + i)->isPath) {
                   findNewTest = true;
                   break;
               }
           }
           if(findNewTest){
               break;
           }
       }
       if(findNewTest){
           continue;
       }else{
           break;
       }
   }
    // Put the room into the map
    int k = 0;
    for(int i = 0; i < room->yDimension; i++){
        for(int j = 0; j < room->xDimension; j++){
            int indexInString = k;
            char charToAdd;
            charToAdd = room->bluePrint[indexInString];

            State * newCell;

            switch(charToAdd){
                case '.':
                    newCell = new EmptySpot();
                    break;
                case 'X':
                    newCell = new Wall();
                    break;
                case 'C':
                    newCell = new TreasureChest();
                     break;
                case 'D':
                    newCell = new Door();
                    break;
                default:
                    break;
            }


            map.at(i + yToTest).at(j + xToTest)->state = newCell;
            map.at(i + yToTest).at(j + xToTest)->isPath = true;
            k++;

        }
    }

    return true;
}
bool Map::createTreasureChest(){    // 1% chance this cell gets a treasure chest
    srand((unsigned) time(NULL));
    return (rand() % 100 == 69) ? true : false; //nice
};
void Map::fillMapWithChests(){ //checks if cell is path or not epmpty. if so, calls createTreasureChest
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++) {
            if (!map[i][j]->isPath && typeid(map[i][j]->state) == typeid(EmptySpot)){
                if(createTreasureChest()){
                    map[i][j]->state = new TreasureChest(5); //space in treasure chest can be added later, and contents can be added later aswell
                }
            }
        }
    }
};
