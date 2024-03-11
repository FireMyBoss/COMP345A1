#ifndef MapCreator_h
#define MapCreator_h

#include <string>
#include <stdio.h>
#include "Map.h"

using namespace std;

class MapCreator{
private:
   
public:
    //these should (and will) be added to the map class once Nick is done touching it
    void CreateAMap(); 
    void SetCustomEndPoint(int OriginX, int OriginY); //or let the the map auto generate one
    //all add path functions would only be created if custom end point is made
    void AddSingularCustomPath(int OriginX, int OriginY);
    void AddHorizontalCustomPath(int OriginX, int OriginY, int endX);
    void AddVerticalCustomPath(int OriginX, int OriginY, int endY);

    void AddSingularWall(int OriginX, int OriginY);
    void AddHorizontalWall(int OriginX, int OriginY, int endX);
    void AddVerticalWall(int OriginX, int OriginY, int endY);
    

};

#endif