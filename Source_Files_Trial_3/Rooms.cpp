//
// Created by Nicholas Kamra on 3/7/24.
//

#include "Rooms.h"

std::vector<std::string> Rooms::roomVector = {"Prison", "TreasureRoom", "Dungeon", "Cave"};

Rooms::Rooms(){
    this->xDimension = 0;
    this->yDimension = 0;
    this->bluePrint = "";
}

Prison::Prison(){
    this->xDimension = 9;
    this->yDimension = 7;
    this->bluePrint =
            "........."
            ".XXXXXXX."
            ".X.X.X.X."
            ".XDXDXDX."
            ".X.....X."
            ".XXDXXXX."
            ".........";
}

TreasureRoom::TreasureRoom(){
    this->xDimension = 17;
    this->yDimension = 8;
    this->bluePrint =
            "................."
            ".XXXXXXXXXXXXXXX."
            ".XC.D.X.....X.CX."
            ".XXXXDXC.CX.X..X."
            ".XCX..XXXXXDX.XX."
            ".X.............X."
            ".XXXXXXDDXXXXXXX."
            ".................";

}

Dungeon::Dungeon(){
    this->xDimension = 23;
    this->yDimension = 9;
    this->bluePrint =
            "......................."
            ".XXXXXXXXXXXXXXXXXXXDX."
            ".XC..........X.....X.X."
            ".XXXXXXXX.XXXXDXXXXX.X."
            ".X.....D.....X...X...X."
            ".XX.XXXXXXXXXXX.XXX.XX."
            ".X...................X."
            ".XXXXXXXXXXXXXXXXXXXXX."
            ".......................";

}

Cave::Cave(){
    this->xDimension = 16;
    this->yDimension = 8;
    this->bluePrint =
            "XXXXXX....XXXXXX"
            "XXXXX......XXXXX"
            "XXX..........XXX"
            "XX............XX"
            "XX............XX"
            "XXX..........XXX"
            "XXXXX..C...XXXXX"
            "XXXXXXXXXXXXXXXX";

}