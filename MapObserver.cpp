//
// Created by Nicholas Kamra on 3/18/24.
//

#include "MapObserver.h"

MapObserver::MapObserver(Map * map){
    this->map = map;
}
void MapObserver::update(Observable * observable){
    std::cout << MapObserver::to_string();
}
std::string MapObserver::to_string(){ // this should be the map observer class
    std::string returnString = "";
    for(int i = 0; i < this->map->height; i++){
        for(int j = 0; j < this->map->width; j++) {

            if(this->map->map.at(i).at(j)->characterInSpot!=nullptr && !this->map->map.at(i).at(j)->characterInSpot->isEnemy){
                returnString += "😃";
            }else if(this->map->map.at(i).at(j)->characterInSpot!=nullptr){
                returnString += "😡";
            }else {
                    returnString += this->map->map.at(i).at(j)->state->colour;

            }
        }
        returnString += "\n";
    }
    return returnString;
}
