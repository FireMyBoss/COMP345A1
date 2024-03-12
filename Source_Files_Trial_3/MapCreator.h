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

    void createAMap(); //housing func

    void veiwMapWithIndexes();

    vector<int> * getCoordiants();

    void setCustomEndPoint(int OriginX, int OriginY); //or let the the map auto generate one
    //all add path functions would only be created if custom end point is made
    void addSingularCustomPath(int OriginX, int OriginY);
    void addHorizontalCustomPath(int OriginX, int OriginY, int endX);
    void addVerticalCustomPath(int OriginX, int OriginY, int endY);

    void addSingularWall(int OriginX, int OriginY);
    void addHorizontalWall(int OriginX, int OriginY, int endX);
    void addVerticalWall(int OriginX, int OriginY, int endY);

    void addTreasureChest(int x, int y);

    void addDoor(int x, int y);
    
    Map * returnMap(){return theMap;}; //returns the map and deletes this class from memory
};

#endif