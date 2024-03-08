//
// Created by Nicholas Kamra on 3/6/24.
//

#include "MapObserver.h"

std::string MapObserver::to_string(Map * currentMap){ // this should be the map observer class
    std::string returnString = "";
    for(int i = 0; i < currentMap->height; i++){
        for(int j = 0; j < currentMap->width; j++) {

                returnString += currentMap->map.at(i).at(j)->state->letter;

        }
        returnString += "\n";
    }
    return returnString;
}
