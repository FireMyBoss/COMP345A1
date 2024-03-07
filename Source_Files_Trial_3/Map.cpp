//
// Created by Nicholas Kamra on 3/6/24.
//

#include "Map.h"

Map::Map(int height, int width){
    this->height = height;
    this->width = width;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::vector<Cell *> newVector;
            map.push_back(newVector);
            Cell * newCell = new Cell();
            map.at(i).push_back(newCell);
        }
    }

}
void Map::to_string(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++) {

            std::cout << this->map.at(i).at(j)->state.letter;

        }
        std::cout << "" << std::endl;
    }
}
void Map::createStart(){ // finds a starting point on the perimeter
    
}
void Map::putPlayerAtStart(){ // sets the player coordinates to the start
    
}
void Map::placePerimeterWalls(){
    
}
void Map::endPath(){
    
}
void Map::createTreasureChest(){};
void Map::fillMapWithChests(){};
