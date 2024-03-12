#include "MapCreator.h"

using namespace std;

MapCreator::MapCreator(int width, int height){
    theMap->height = height;
    theMap->width = width;
    while (true){
        cout << "Would you like to:\n1. Create a start point at a specific spot\n2. Create a random start point\n\nPlease input one of the numbers above: ";
        int selection;
        cin >> selection;
        if (selection == 1){
            while (true){
                cout << "What side would you like to create it on?\n1. The top\n2. The left\n3. The right\n4. The bottom\n\nPlease input one of the numbers above: ";
                int side;
                cin >> side;
                if (side == 1){ //top
                    theMap->startX = 0;
                } else if (side == 2){ //left
                    theMap->startY = 0
                } else if (side == 3){ //right
                    theMap->start
                } else if (side == 4){ //bottom
                    /* code */
                } else {

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

