#ifndef Backback_h
#define Backback_h

#include <string>
#include <vector>
#include <stdio.h>
#include "Item.h"

using namespace std;

class Backback : public Item{
private:
   int space;
   vector<Item> contents;
public:
    Backback(bool equippedValue, int spc) : Item(equippedValue), space(spc){};
    Backback(int spc) : space(spc){};
    Backback();
    ~Backback();

    int getSpace(){return space;};
    void setSpace(int value){space = value;};

    vector<Item> getContents(){return contents;};
    void addContent(Item itm){contents.push_back(itm);};
};


#endif