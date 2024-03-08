#ifndef Backback_h
#define Backback_h

#include <string>
#include <vector>
#include <stdio.h>
#include "Item.h"

using namespace std;

class Backpack : public Item{
private:
   int space;
   vector<Item*> contents;
public:
    Backpack(bool equippedValue, int spc) : Item(equippedValue), space(spc){};
    explicit Backpack(int spc) : space(spc){};

    int getSpace(){return space;};
    void setSpace(int value){space = value;};

    vector<Item*> getContents(){return contents;};
    void addContent(Item * itm){contents.push_back(itm);};

    void printItem();// prints the item to the screen

};


#endif
