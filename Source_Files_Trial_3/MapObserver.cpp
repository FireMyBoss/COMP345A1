//
// Created by Nicholas Kamra on 3/6/24.
//

#include "MapObserver.h"

void MapObserver::to_string(Map * currentMap){ // this should be the map observer class
    for(int i = 0; i < currentMap->height; i++){
        for(int j = 0; j < currentMap->width; j++) {

            if(currentMap->map.at(i).at(j)->isPath && currentMap->map.at(i).at(j)->state->letter != 'S'
               && currentMap->map.at(i).at(j)->state->letter != 'E'){
                std::cout << " ";
            }else {
                std::cout << currentMap->map.at(i).at(j)->state->letter;
            }

        }
        std::cout << "" << std::endl;
    }
}