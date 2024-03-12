#include "MapCreator.h"

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
                cout << "\n\nWhat side would you like to create it on?\n1. The top\n2. The left\n3. The right\n4. The bottom\n\nPlease input one of the numbers above: ";
                int side;
                cin >> side;
                if (side == 1 || side == 4){ //top / bottom
                    theMap->startX = side == 1 ? 0 : theMap->width-1;
                    while (true){
                        cout << "\n\nPlease input a number for the starting index between 0 and " << theMap->height-1;
                        int point;
                        cin >> point;
                        if(point > 0 && point < theMap->height-1){
                            theMap->startY = point;
                            break;
                        }
                        cout << "\n\nIncorrect input. Please try again.\n\n";
                    }   
                    break;
                } else if (side == 2 || side == 3){ //left / right
                    theMap->startY = side == 2 ? 0 : theMap->height-1;
                    while (true){
                        cout << "\n\nPlease input a number for the starting index between 0 and " << theMap->width-1;
                        int point;
                        cin >> point;
                        if(point > 0 && point < theMap->width-1){
                            theMap->startX = point;
                            break;
                        }
                        cout << "\n\nIncorrect input. Please try again.\n\n";
                    } 
                    break;
                } else {
                    cout << "\n\nIncorrect input. Please try again.\n\n";
                }
            }
            break;
        } else if (selection == 2){
            theMap->createStart();
            cout << "/n\nStart point created!\n\n";
            break;
        } else {
            cout << "\n\nIncorrect input. Please try again.\n\n";
        }
    }
}

void MapCreator::createEnd(){
    while (true){
        cout << "\n\nWould you like to:\n1.Choose an end point and make the path\n2. Auto create and end point and a path\n\nPlease input one of the numbers above: ";
        int selection;
        cin >> selection;
        if(selection == 1){
            
            break;
        } else if (selection == 2){
            theMap->snakeEndPath();
            break;
        }
        cout << "\n\nIncorrect input. Please try again.\n\n";
    }
    
    
}
