#ifndef MapCreator_h
#define MapCreator_h

#include <string>
#include <stdio.h>
#include "Map.h"

using namespace std;

class MapCreator{
private:
   Map * theMap;
public:
    MapCreator(int width, int height, vector<int> start); //every time after the first
    MapCreator(int width, int height); //first time
    
    void createStart();
    void createEnd();

    void createPath();

    void createAMap(); //housing func

    void veiwMapWithIndexes();

    vector<int> getCoordinates(); // y,x

    void addHorizontalState(int OriginX, int OriginY, int endX, State & stt);
    void addVerticalState(int OriginX, int OriginY, int endY, State & stt);

    void addState(int x, int y, State & stt);
    
    Map * returnMap(){return theMap;}; //returns the map and deletes this class from memory
};

#endif