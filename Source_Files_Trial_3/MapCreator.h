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
    
    void CreateAMap(); //housing func

    vector<int> * RandomStart(int width, int height);

    void VeiwMapWithIndexes();

    vector<int> * GetCoordiants();

    void SetCustomEndPoint(int OriginX, int OriginY); //or let the the map auto generate one
    //all add path functions would only be created if custom end point is made
    void AddSingularCustomPath(int OriginX, int OriginY);
    void AddHorizontalCustomPath(int OriginX, int OriginY, int endX);
    void AddVerticalCustomPath(int OriginX, int OriginY, int endY);

    void AddSingularWall(int OriginX, int OriginY);
    void AddHorizontalWall(int OriginX, int OriginY, int endX);
    void AddVerticalWall(int OriginX, int OriginY, int endY);

    void AddTreasureChest(int x, int y);

    void AddDoor(int x, int y);
    
    Map * ReturnMap(){return theMap;}; //returns the map and deletes this class from memory
};

#endif