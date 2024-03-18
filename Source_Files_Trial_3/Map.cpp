//
// Created by Nicholas Kamra on 3/6/24.
//

#include "Map.h"


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

using namespace std;

Map::Map() {

  height = 0;
 	width = 0;
	startX = 0;
	startY = 0;
	endX = 0;
  endY = 0;
    std::vector<Character *> players;
    this->playersInGame = players;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::vector<Cell *> newVector;
            map.push_back(newVector);
            Cell * newCell = new Cell();
            map.at(i).push_back(newCell);
        }
    }
    
}

Map::Map(int height, int width){

    this->height = height;
    this->width = width;
    this->startX = 0;
    this->startY = 0;
    this->endX = 0;
    this->endY = 0;
    std::vector<Character *> players;
    this->playersInGame = players;

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

Map::Map(std::vector<std::vector<std::string> > mapAsVectorOfStrings){

    this->height = mapAsVectorOfStrings.size();
    this->width = mapAsVectorOfStrings.at(0).size();
    std::vector<Character *> players;
    this->playersInGame = players;

    /* Need to initialize
    this->startX = 0;
    this->startY = 0;
    this->endX = 0;
    this->endY = 0;
     */
    // states: TreasureChest 'C', EmptySpot '.', Wall 'X', Door 'D', StartSpot 'S', EndSpot 'E'
    // isPath = '!'
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::vector<Cell *> newVector;
            map.push_back(newVector);
            Cell * newCell = new Cell(); // need to add characteristics to the cell before pushing to the newVector

            std::string currentString = mapAsVectorOfStrings.at(i).at(j);
            if(currentString.find('.') != std::string::npos){
                State * newState = new EmptySpot();
                newCell->state = newState;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }else if(currentString.find('C') != std::string::npos){
                State * newState = new TreasureChest();
                newCell->state = newState;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }else if(currentString.find('X') != std::string::npos){
                State * newState = new Wall();
                newCell->state = newState;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }else if(currentString.find('D') != std::string::npos){
                State * newState = new Door();
                newCell->state = newState;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }else if(currentString.find('S') != std::string::npos){
                State * newState = new StartSpot();
                newCell->state = newState;
                this->startX = j;
                this->startY = i;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }else if(currentString.find('E') != std::string::npos){
                State * newState = new EndSpot();
                newCell->state = newState;
                this->endX = j;
                this->endX = i;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }else{
                State * newState = nullptr;
                newCell->state = newState;
                if(currentString.find('!') != std::string::npos){
                    newCell->isPath = true;
                }
            }

            map.at(i).push_back(newCell);
        }
    }
}


Map::~Map() {
    // Deallocate memory for each Cell object
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            delete map[i][j];
        }
    }

    // Clear the map vector
    map.clear();

    // Deallocate memory for each Character object in playersInGame vector
    for (size_t i = 0; i < playersInGame.size(); ++i) {
        delete playersInGame[i];
    }

    // Clear the playersInGame vector
    playersInGame.clear();
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
}
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
}

Map* Map::generateInitialMapInfo() {

   int retVal = 0;
	int runMainLoop = 1;
	int runInnerLoop = 1;
	
	int sizeInput = 0;
	int inputWidth = 0;
	int inputLength = 0;
	
	Map* retMap;
	MapObserver retObserver;
	
	char* generalMapOptionsInput;
	int generalMapOptionsMenuSelector = 0;
	const char* generalMapOptions[2] = {
  
		">> Create a map\n Exit the map generation screen\n\nPress W to navigate up, S to navigate down, C to select option\n\n",
		"Create a map\n>> Exit the map generation screen\n\nPress W to navigate up, S to navigate down, C to select option\n\n"
        
  };
  
  char* printMapOptionInput;
  int  printMapOptionsMenuSelector = 0;
	const char* printMapOption[2] = {
  
		">> Yes \n No\n\nPress W to navigate up, S to navigate down, C to select option / stop viewing map\n\n",
		"Yes \n>> No\n\nPress W to navigate up, S to navigate down, C to select option / stop viewing map\n\n"
        
  };
  
  char* stopViewingMap;
  
  
  do {
    	
				cout << generalMapOptions[generalMapOptionsMenuSelector];			
				generalMapOptionsInput = userInput(10);
							
				switch(userInputCase(generalMapOptionsInput)) {
							
					case 0: //W key (Up)
								
						generalMapOptionsMenuSelector--;
						generalMapOptionsMenuSelector = generalMapOptionsMenuSelector - 2*floor(generalMapOptionsMenuSelector/2.0);
									
					break;
					case 2: //S key (Down)
								
						generalMapOptionsMenuSelector++;
						generalMapOptionsMenuSelector = generalMapOptionsMenuSelector - 2*floor(generalMapOptionsMenuSelector/2.0);
							
					break;
					case 10: //C key (Select)
								
						switch(generalMapOptionsMenuSelector) {
									
							case 0: //Random Map generation part
								
								while(true) { //Get width of map
								
									clearConsole();	
									cout << "Input the desired width of the map: ";
								
									cin >> inputWidth;
								
									if(inputWidth < 1) {
										
										cout << "Error: The width of the map must be a positive number!\n";

										pause(1000);
										cin.clear(); // Clear the fail state
       							cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
										continue;
										
									}
									
									break;
								
								}
								
								while(true) { //Get length of map
								
									clearConsole();	
									cout << "Input the desired length of the map: ";
								
									cin >> inputLength;
								
									if(inputLength < 1) {
										
										cout << "Error: The length of the map must be a positive number!\n";
										
										pause(1000);
										cin.clear(); // Clear the fail state
       							cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
										continue;
										
									}
									
									break;
								
								}
								
								clearConsole();	
								
								retMap = new Map(inputWidth, inputLength); //Generate the map
								
								//Offer to display the map
								cout << "The map has been successfully generated! Would you like to see the map?\n";
								pause(2000);
								
								do {
								
									cout << printMapOption[printMapOptionsMenuSelector];			
									printMapOptionInput = userInput(10);
									
									switch(userInputCase(printMapOptionInput)) {
									
										case 0: //W key (Up)
									
											printMapOptionsMenuSelector--;
											printMapOptionsMenuSelector = printMapOptionsMenuSelector - 2*floor(printMapOptionsMenuSelector/2.0);
														
										break;
										case 2: //S key (Down)
													
											printMapOptionsMenuSelector++;
											printMapOptionsMenuSelector = printMapOptionsMenuSelector - 2*floor(printMapOptionsMenuSelector/2.0);
												
										break;
										case 10: //C key (Select)
										
											switch(printMapOptionsMenuSelector) {
												
												case 0: //User wants to see the map
													
													clearConsole();
													
													cout << retObserver.to_string(retMap);
													
													while(true) {
													
														stopViewingMap = userInput(10);
														
														if(stopViewingMap[0] == 'c') {
															
															delete[] stopViewingMap;
															break;
														
														}
														
														delete[] stopViewingMap;
													
													}
													
													runInnerLoop = 0;
													runMainLoop = 0;
													
												break;
												case 1: //User doesn't want to see the map
												
													runInnerLoop = 0;
													
												break;
												
											}
									
									}
								
									if(runInnerLoop != 0) {
					
										delete[] printMapOptionInput;
									
									}
									
									clearConsole();	
								
								} while (runInnerLoop);
								
								retVal = 1;
								runMainLoop = 0;

											
							break;
							case 1: //Quit Game
								
								retVal = 0;
								runMainLoop = 0;
											
							break;
									
						}
							
				}
				
				if(runMainLoop != 0) {
					
					delete[] generalMapOptionsInput;
				
				}
				
				clearConsole();	
    	
    	} while(runMainLoop);
    	
    	delete[] generalMapOptionsInput;
    	
    	return retMap;

}

std::string Map::toString(Map* currentMap) {
	
    std::string returnString = "";

    for(int i = 0; i < currentMap->height; i++){
        for(int j = 0; j < currentMap->width; j++) {

            returnString += currentMap->map.at(i).at(j)->state->letter;

        }
        returnString += "\n";
    }
    return returnString;
	
}

void Map::loadCharactersIntoMap(std::vector<Character *> players){

    players.at(0)->x = this->startX;
    players.at(0)->y = this->startY;

    this->map.at(startY).at(startX)->characterInSpot = players.at(0);

}

bool Map::pauseMenuUIandExitGame(){

    clearConsole();

    std::cout << "Pause Menu" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter '1' to unpause" << std::endl;
    std::cout << "Enter '2' to exit game" << std::endl;

    char playerInputChar;

    for (;;){
        try {
            std::cin >> playerInputChar;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter a character.");
                continue;
            }else if(playerInputChar != '1' && playerInputChar != '2'){
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }
    switch(playerInputChar){
        case '1':{
            return false;
        }
        case '2':{

            return true;
        }
        default:{
            break;
        }
    }
    return false;
}

bool Map::getUserInput(Character * player){

    std::cout << "Please enter a direction to move ('w', 'a', 's', 'd') or pause ('p'):";
    std::cout << "" << std::endl;
    char playerInputChar;

    for (;;){
        try {
            std::cin >> playerInputChar;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter a character.");
                continue;
            }else if(playerInputChar != 'w' && playerInputChar != 'a' && playerInputChar != 's'
            && playerInputChar != 'd' && playerInputChar != 'p'){
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    State * stateToCheck;
    int movementX = 0;
    int movementY = 0;

    switch(playerInputChar){
        case 'w':{
            // must first check if out of bounds
            movementX = player->x;
            movementY = player->y - 1;
            try {
                stateToCheck = getStateOfCell(movementX, movementY);
            }catch(...){
                return false;
            }
            break;
        }
        case 'a':{
            // must first check if out of bounds
            movementX = player->x - 1;
            movementY = player->y;
            try {
                stateToCheck = getStateOfCell(movementX, movementY);
            }catch(...){
                return false;
            }
            break;
        }
        case 's':{
            // must first check if out of bounds
            movementX = player->x;
            movementY = player->y + 1;
            try {
                stateToCheck = getStateOfCell(movementX, movementY);
            }catch(...){
                return false;
            }
            break;
        }
        case 'd':{
            // must first check if out of bounds
            movementX = player->x + 1;
            movementY = player->y;
            try {
                stateToCheck = getStateOfCell(movementX, movementY);
            }catch(...){
                return false;
            }
            break;
        }
        case 'p':{
            stateToCheck = nullptr;
            bool exitGame;
            exitGame = pauseMenuUIandExitGame();
            return exitGame;
        }
        default: {
            stateToCheck = nullptr;
            break;
        }
    }
    if(stateToCheck == nullptr){
        return false;
    }

    switch(stateToCheck->letter){
        case '.':{
            this->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            this->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'X':{
            std::cout << "--- A wall obstructs your way. ---" << std::endl;
            std::cout << "" << std::endl;
            break;
        }
        case 'D':{
            this->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            this->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'S':{
            this->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            this->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'E':{
            this->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            this->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'C':{
            std::cout << "--- A chest is before you... open it? ('y' or 'n'):" << std::endl;
            std::cout << "" << std::endl;
            char openChestDecision;

            for (;;){
                try {
                    std::cin >> openChestDecision;
                    if(cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore();
                        throw std::runtime_error("Invalid input. Please enter a character.");
                        continue;
                    }else if(openChestDecision != 'n' && openChestDecision != 'y'){
                        std::cin.clear();
                        std::cin.ignore();
                        continue;
                    }
                    break;
                } catch (...) {
                    std::cin.clear();
                    std::cin.ignore();
                }
            }

            if(openChestDecision == 'y'){
                std::cout << "--- Chest Contents ---" << std::endl;
                std::cout << "" << std::endl;
                TreasureChest * newChest;
                newChest = (TreasureChest *)this->map.at(movementX).at(movementY)->state;
                std::vector<Item> itemVector = newChest->getContents();
                if(itemVector.empty()){
                    newChest = nullptr;
                    break;
                }
                for(int i = 0; i < itemVector.size(); i++){
                    std::cout << "inside chest" << std::endl;
                    std::cout << "" << std::endl;
                }
                newChest = nullptr;
                break;
            }else{
                break;
            }
            break;
        }
        default:{
            break;
        }
    }

    stateToCheck = nullptr;
    return false;
}

State * Map::getStateOfCell(int x, int y){
    return this->map.at(y).at(x)->state;
}
	
 std::string MapObserver::to_string(Map * currentMap){ // this should be the map observer class
    std::string returnString = "";
    for(int i = 0; i < currentMap->height; i++){
        for(int j = 0; j < currentMap->width; j++) {

            if(currentMap->map.at(i).at(j)->characterInSpot!=nullptr){
                returnString += 'P';
            }else {
                returnString += currentMap->map.at(i).at(j)->state->letter;
            }
        }
        returnString += "\n";
    }
    return returnString;
}

std::vector<std::vector<std::string> > mapToVectorForCSV(Map * theMap){

    std::vector<std::vector<std::string> > mapVector;

    for(int i = 0; i < theMap->height; i++){
        std::vector<std::string> newVec;
        for(int j = 0; j < theMap->width; j++) {


                std::string currString = "";
                currString += theMap->map.at(i).at(j)->state->letter;

                if(theMap->map.at(i).at(j)->isPath){
                    currString += "!";
                }
                newVec.push_back(currString);
        }

        mapVector.push_back(newVec);
    }
    return mapVector;
}
