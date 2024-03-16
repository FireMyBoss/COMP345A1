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
    bool createEnd();

    void createThePath();

    State* getInput();

    vector<int> getCoordinates(); // y,x

    void printMapWithPathAndIndex();    //prints the map with the path, purely to help make the path
    void printMapWithIndex();   //prints the map with indexes, to help make the map (fill with walls, treasure chests, etc)

    //will be added later
    void addHorizontalPath(int OriginX, int OriginY, int endX); //only replace the inside
    void addVerticalPath(int OriginX, int OriginY, int endY);   //only replace the inside

    void createAMap(); //housing func

    void addHorizontalState(int OriginX, int OriginY, int endX, State & stt);
    void addVerticalState(int OriginX, int OriginY, int endY, State & stt);

    void addState(int x, int y, State & stt);
    
    Map * returnMap(){return theMap;}; //returns the map and deletes this class from memory
};

#endif