#include "MapCreator.h"
#include <iostream>
#include <sstream>

using namespace std;

MapCreator::MapCreator(int width, int height){
    theMap->height = height;
    theMap->width = width;
    MapCreator::createStart(); //handles all start cases
    theMap->placePerimeterWalls();
    MapCreator::createEnd();

}

void MapCreator::createStart(){
    while (true){
        cout << "Would you like to:\n1. Create a start point at a specific spot\n2. Create a random start point\n\nPlease input one of the numbers above: ";
        int selection;
        cin >> selection;
        if (selection == 1){
            while (true){
                cout << "\n\nEnter input the start index in the form of \"y,x\": ";
                vector<int> start = getCoordinates();
                if(start[0] == 0){
                    if(start[1] == (theMap->height - 1) || (start[1] == 0)){
                        cout << "\n\nError: Start must NOT be a corner.";
                    } else{
                        theMap->startY = start[0];
                        theMap->startY = start[1];
                        break;
                    }
                } else if (start[0] == (theMap->height - 1)){
                    if(start[1] == (theMap->height - 1) || (start[1] == 0)){
                        cout << "\n\nError: Start must NOT be a corner.";
                    } else {
                        theMap->startY = start[0];
                        theMap->startY = start[1];
                        break;
                    }
                } else if (start[1] == 0){ //already checked previous conditions
                    theMap->startY = start[0];
                    theMap->startY = start[1];
                    break;
                } else if (start[1] == (theMap->height - 1)){ //already checked previous conditions
                    theMap->startY = start[0];
                    theMap->startY = start[1];
                    break;
                } else {
                    cout << "\n\nError: Start must be on the exterior of the map.";
                }
            }
            break;
        } else if (selection == 2){
            theMap->createStart();
            cout << "\n\nStart point created!\n\n";
            break;
        }
        cout << "\n\nIncorrect input. Please try again.\n\n";
        
    }
}

void MapCreator::createEnd(){
    while (true){
        cout << "\n\nWould you like to:\n1.Choose an end point and make the path\n2. Auto create and end point and a path\n\nPlease input one of the numbers above: ";
        int selection;
        cin >> selection;
        if(selection == 1){
            while (true){
                cout << "\n\nEnter input the end index in the form of \"y,x\": ";
                vector<int> end = getCoordinates();
                if(end[0] == 0){
                    if(end[0] == theMap->startY && end[1] == theMap->startX){
                        cout << "\n\nError: End must NOT be the same as the start.";
                    } else if(end[1] == (theMap->height - 1) || (end[1] == 0)){
                        cout << "\n\nError: End must NOT be a corner.";
                    } else{
                        theMap->startY = end[0];
                        theMap->startY = end[1];
                        break;
                    }
                } else if (end[0] == (theMap->height - 1)){
                    if(end[1] == (theMap->height - 1) || (end[1] == 0)){
                        cout << "\n\nError: End must NOT be a corner.";
                    } else {
                        theMap->startY = end[0];
                        theMap->startY = end[1];
                        break;
                    }
                } else if (end[1] == 0){ //already checked previous conditions
                    theMap->startY = end[0];
                    theMap->startY = end[1];
                    break;
                } else if (end[1] == (theMap->height - 1)){ //already checked previous conditions
                    theMap->startY = end[0];
                    theMap->startY = end[1];
                    break;
                } else {
                    cout << "\n\nError: End must be on the exterior of the map.";
                }
            }
            MapCreator::createPath();
            break;
        } else if (selection == 2){
            theMap->snakeEndPath();
            break;
        }
        cout << "\n\nIncorrect input. Please try again.\n\n";
    }
    
    
}

void createPath(){

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