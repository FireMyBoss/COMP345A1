#include "MapCreator.h"
#include "Map.h"
#include <iostream>
#include <sstream>
#include "misc.h"



using namespace std;

MapCreator::MapCreator(int width, int height){
    Map thisMap(height, width, true);
    theMap = &thisMap;
    theMap->height = height;
    theMap->width = width;
    theMap->placePerimeterWalls();
    MapCreator::createStart(); //handles all start cases
    if (!MapCreator::createEnd()){
        MapCreator::createThePath();
    }
    MapCreator::createAMap();
}

MapCreator::MapCreator(int width, int height, vector<int> prevMapEnd){
    Map thisMap(height, width, true);
    theMap = &thisMap;
    theMap->height = height;
    theMap->width = width;
    MapCreator::setStartBasedOnPrev(prevMapEnd);
    theMap->placePerimeterWalls();
    if (!MapCreator::createEnd()){
        MapCreator::createThePath();
    }
    MapCreator::createAMap();
}

void MapCreator::setStartBasedOnPrev(vector<int> prevMapEnd){
    if(prevMapEnd[0] == 0){ //top
        theMap -> startY = theMap -> height -1;
        if(prevMapEnd[1] < theMap->width-1){
            theMap -> startX = prevMapEnd[1];
        } else{
            theMap -> startX = theMap->width/2;
        }
    } else if (prevMapEnd[0] == theMap->height-1){ //bottom
        theMap -> startY = 0;
        if(prevMapEnd[1] < theMap->width-1){
            theMap -> startX = prevMapEnd[1];
        } else{
            theMap -> startX = theMap->width/2;
        }
    } else if (prevMapEnd[1] == 0){ //left
       theMap -> startX = theMap -> width -1;
        if(prevMapEnd[0] < theMap->height-1){
            theMap -> startY = prevMapEnd[0];
        } else{
            theMap -> startY = theMap->height/2;
        }
    } else { //right
        theMap -> startX = 0;
        if(prevMapEnd[0] < theMap->height-1){
            theMap -> startY = prevMapEnd[0];
        } else{
            theMap -> startY = theMap->height/2;
        }
    }
    State * newStartSpot = new StartSpot();
    theMap->map[theMap->startY][theMap->startX]->state = newStartSpot;
    
}

void MapCreator::createStart(){
    int thisIn;
    while (true){
        cout << "Would you like to:\n1. Create a start point at a specific spot\n2. Create a random start point\n\nPlease input one of the numbers above: ";
       
        for (;;) {
            try {
                cin >> thisIn;
                if (cin.fail()) {
                    throw runtime_error("Invalid input. Please enter 1 or 2.");
                } else if (thisIn != 1 && thisIn != 2) {
                    throw runtime_error("Invalid input. Please enter 1 or 2.");
                }
                break;
            } catch (const runtime_error& e) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << e.what() << endl;
            }
        }
        if (thisIn == 1){
            while (true){
                cout << "\n\nEnter input the start index in the form of \"y,x\": ";
                vector<int> start = getCoordinates();
                if(start[0] == 0){
                    if(start[1] == (theMap->height - 1) || (start[1] == 0)){
                        cout << "\n\nError: Start must NOT be a corner.";
                    } else{
                        theMap->startY = start[0];
                        theMap->startX = start[1];
                        break;
                    }
                } else if (start[0] == (theMap->height - 1)){
                    if(start[1] == (theMap->height - 1) || (start[1] == 0)){
                        cout << "\n\nError: Start must NOT be a corner.";
                    } else {
                        theMap->startY = start[0];
                        theMap->startX = start[1];
                        break;
                    }
                } else if (start[1] == 0){ //already checked previous conditions
                    theMap->startY = start[0];
                    theMap->startX = start[1];
                    break;
                } else if (start[1] == (theMap->height - 1)){ //already checked previous conditions
                    theMap->startY = start[0];
                    theMap->startX = start[1];
                    break;
                } else {
                    cout << "\n\nError: Start must be on the exterior of the map.";
                }
            }
            State * newStartSpot = new StartSpot();
            theMap->map[theMap->startY][theMap->startX]->state = newStartSpot;
            break;
        } else if (thisIn == 2){
            theMap->createStart();
            break;
        }
        cout << "\n\nIncorrect input. Please try again.\n\n";
        
    }
    cout << "\n\nStart point created!\n\n";
}

bool MapCreator::createEnd(){
    while (true){
        cout << "\n\nWould you like to:\n1.Choose an end point and make the path\n2. Auto create and end point and a path\n\nPlease input one of the numbers above: ";
        int selection;
        cin >> selection;
        if(selection == 1){
            while (true){
                cout << "\n\nEnter input the end index in the form of \"y,x\": ";
                vector<int> end = getCoordinates();
                if(end[0] == 0){
                    if(end[0] == theMap->endY && end[1] == theMap->endX){
                        cout << "\n\nError: End must NOT be the same as the start.";
                    } else if(end[1] == (theMap->height - 1) || (end[1] == 0)){
                        cout << "\n\nError: End must NOT be a corner.";
                    } else{
                        theMap->endY = end[0];
                        theMap->endX = end[1];
                        break;
                    }
                } else if (end[0] == (theMap->height - 1)){
                    if(end[1] == (theMap->height - 1) || (end[1] == 0)){
                        cout << "\n\nError: End must NOT be a corner.";
                    } else {
                        theMap->endY = end[0];
                        theMap->endX = end[1];
                        break;
                    }
                } else if (end[1] == 0){ //already checked previous conditions
                    theMap->endY = end[0];
                    theMap->endX = end[1];
                    break;
                } else if (end[1] == (theMap->height - 1)){ //already checked previous conditions
                    theMap->endY = end[0];
                    theMap->endX = end[1];
                    break;
                } else {
                    cout << "\n\nError: End must be on the exterior of the map.";
                }
            }
            State * newEndSpot = new EndSpot();
            cout << theMap->endY << theMap->endX;
            theMap->map[theMap->endY][theMap->endX]->state = newEndSpot;
            cout << "\n\nEnd point created.\n\n";
            return false;
        } else if (selection == 2){
            theMap->snakeEndPath();
            return true;
        }
        cout << "\n\nIncorrect input. Please try again.\n\n";
    }
    
    
}

void MapCreator::createThePath(){
    int curX = theMap -> startX, curY = theMap -> startY;
    while (true){
        clearConsole();
        cout << "\nHere is the current map\n\n";
        MapCreator::printMapWithPathAndIndex();
        cout << "\nYour previous coordniate is \"" << curY << ',' << curX << "\".\n";
        cout << "In the form of \"y,x\", write a new coordniate on the same Y or X plane as the previous coordinate, and the program will create a path there.\nNote, the new coordniate NEEDS to be on the same Y or X plane: ";
        vector <int> pathCoords =  MapCreator::getCoordinates();
        if(pathCoords[0] == curY || pathCoords[1] == curX){ //check to see if its on the same plane
            if(pathCoords[0] > 0 && pathCoords[0] < theMap->height-1 && pathCoords[1] > 0 && pathCoords[1] < theMap->width-1){ //inside the constrains of the Map
                if (pathCoords[0] == curY){ //going horizontal
                    MapCreator::addHorizontalPath(curX, curY, pathCoords[1]);
                } else { // pathCoords[1] == curX , going vertical
                    MapCreator::addVerticalPath(curX, curY, pathCoords[0]);
                }
                curX = pathCoords[1]; 
                curY = pathCoords[0];
            } else if(pathCoords[0] == theMap ->endY || pathCoords[1] == theMap ->endX){ //reached the end
                if (pathCoords[0] == curY){ //going horizontal
                    MapCreator::addHorizontalPath(curX, curY, pathCoords[1]);
                } else { // pathCoords[1] == curX , going vertical
                    MapCreator::addVerticalPath(curX, curY, pathCoords[0]);
                }
                break; //done creating path
            } else {
                cout << "One or both coordinates may be outside of the length or width of the map, or touching the outer walls.\n";
            }
        } else{
            cout << "Neither coordinate is on the same plane as the previous coordinates.\n";
        }
    }
    
    

}

vector<int>  MapCreator::getCoordinates(){
    vector<int>  coordinates;
    string input;
    int y, x;
    while(true){
        cin >> input;
        char comma;
        std::istringstream in(input);

        if (!(in >> y >> comma >> x) || comma != ',') {
            std::cerr << "Invalid input format. Please provide input in the form of \"y,x\"" << std::endl;
        } else{
            coordinates.push_back(y);
            coordinates.push_back(x);
            return coordinates;
        }
    }
}

void MapCreator::printMapWithPathAndIndex(){
    std::string returnString = "";
    cout << "\n";
    for(int i = 0; i < theMap->height; i++){
        for(int j = 0; j < theMap->width; j++) {

            if(theMap->map.at(i).at(j)->isPath && theMap->map.at(i).at(j)->state->letter != 'S' && theMap->map.at(i).at(j)->state->letter != 'E'){
                returnString += "🟨";
            }else {
                returnString +=theMap->map.at(i).at(j)->state->colour;
            }
        }
        returnString += "\n";
    }
    cout << returnString << endl;
}

void MapCreator::printMapWithIndex(){
    std::string returnString = "";
    for (int i = 0; i < theMap->height; i++){
        if (i > 9){
            cout << i << " ";
        } else {
            cout << " " << i << " ";
        }
    }
    cout << "\n";
    for(int i = 0; i < theMap->height; i++){
        if (i > 9){
            cout << i << " ";
        } else {
            cout << " " << i << " ";
        }
        for(int j = 0; j < theMap->width; j++) {
            returnString += ' ' + theMap->map.at(i).at(j)->state->letter + ' ';
        }
        returnString += "\n";
    }
    cout << returnString << endl;
}

void MapCreator::addHorizontalPath(int OriginX, int OriginY, int endX){
    int higher = OriginX > endX ? OriginX : endX;
    int lower = OriginX > endX ? endX : OriginX;
    for (int i = lower; i <= higher; i++){
        theMap->map[OriginY][i]->isPath = true;
    }
}

void MapCreator::addVerticalPath(int OriginX, int OriginY, int endY){
    int higher = OriginY > endY ? OriginY : endY;
    int lower = OriginY > endY ? endY : OriginY;
    for (int i = lower; i <= higher; i++){
        theMap->map[i][OriginX]->isPath = true;
    }
}

void MapCreator::createAMap(){
    cout << "\nWelcome to the Map editing screen.\n\n";
    bool roomsCreated = false;
    while (true){
        MapCreator::printMapWithPathAndIndex();
        int input;
        bool isValidInput = false;
        do {
            cout << "\nWould you like to:\n1. Select a coordinate to add a specific state\n2. Exit\n";
            if(!roomsCreated){
                cout << "3. Randomly generate rooms around the map\n";
            }
            cout << "\nPlease input one of the numbers above: ";
            
            std::cin >> input;

            // Check if the input is valid
            if (std::cin.fail() || (input != 1 && input != 2 && input != 3)) {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Invalid input. Please enter 1, 2, or 3." << std::endl;
            } else if (input == 3 && roomsCreated) {
                std::cout << "You've already selected '3'. Please choose another number." << std::endl;
            } else {
                isValidInput = true;
            }
        } while (!isValidInput);
        
        if(input == 1){
            cout << "In the form of \"y,x\", please input a coordinate: ";
            vector<int> coords = MapCreator::getCoordinates();
            State * theType = MapCreator::getInput();
            if(theType->letter == 'X'){ //is a wall
                cout << "In the form of \"y,x\", please input a coordinate for the end of the wall: ";
                vector<int> pathCoords = MapCreator::getCoordinates();          
                if(pathCoords[0] == coords[0] || pathCoords[1] == coords[1]){ //check to see if its on the same plane
                    if(pathCoords[0] > 0 && pathCoords[0] < theMap->height-1 && pathCoords[1] > 0 && pathCoords[1] < theMap->width-1){ //inside the constrains of the Map
                        if (pathCoords[0] == coords[0]){ //going horizontal
                            MapCreator::addHorizontalWall(coords[1], coords[0], pathCoords[1]);
                        } else { // pathCoords[1] == curX , going vertical
                            MapCreator::addVerticalWall(coords[1], coords[0], pathCoords[0]);
                        }
                    } else {
                        cout << "One or both coordinates may be outside of the length or width of the map, or touching the outer walls.\n";
                    }
                } else {
                    cout << "One or both coordinates may be outside of the length or width of the map, or touching the outer walls.\n";
                }
            }else {MapCreator::addState(coords[1], coords[0], *theType);}
        } else if (input == 2){
            break;
        } else { //input == 3
           theMap ->fillMapWithRooms();
           roomsCreated = true;
        }
           
    
}
}
State* MapCreator::getInput(){
    char input;
    bool isValid = false;

    do {
        std::cout << "Please enter 'D' for door, 'C' for treasure chest, or 'W' for wall: ";
        std::cin >> input;

        input = toupper(input);

        if (input == 'D' || input == 'C' || input == 'W') {
            isValid = true;
        } else {
            std::cout << "Invalid input. Please try again.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!isValid);
    switch (input) {
        case 'D':
            return new Door();
        case 'C':
            return new TreasureChest();
        case 'W':
            return new Wall();
        default:
            return nullptr;
    }
}


void MapCreator::addState(int x, int y, State & stt){
    if(!theMap->map[y][x]->isPath)theMap->map[y][x]->state = &stt;  //if it's not a path
}

void MapCreator::addHorizontalWall(int OriginX, int OriginY, int endX){
    int higher = OriginX > endX ? OriginX : endX;
    int lower = OriginX > endX ? endX : OriginX;
    for (int i = lower; i <= higher; i++){
        if(!theMap->map[OriginY][i]->isPath) theMap->map[OriginY][i]->state = new Wall; //if it's not a path
    }
}
void MapCreator::addVerticalWall(int OriginX, int OriginY, int endY){
    int higher = OriginY > endY ? OriginY : endY;
    int lower = OriginY > endY ? endY : OriginY;
    for (int i = lower; i <= higher; i++){
        if(!theMap->map[i][OriginX]->isPath) theMap->map[i][OriginX]->state = new Wall; //if it's not a path
    }
}
