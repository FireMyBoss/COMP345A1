#ifndef TreasureChest_h
#define TreasureChest_h

#include <string>
#include <stdio.h>
#include "Item.h"
#include "State.h"
#include <vector>

using namespace std;

class TreasureChest : public Item, public State
{
private:
    int space;
    vector<Item> contents;
public:
    TreasureChest(int spc, vector<Item> & preExistingContent) : space(spc), contents(preExistingContent){this->letter = 'C'; this->colour = "orange";};
    explicit TreasureChest(vector<Item> & preExistingContent) : contents(preExistingContent){this->letter = 'C'; this->colour = "orange";};
    explicit TreasureChest(int spc) : space(spc){this->letter = 'C'; this->colour = "orange";};
    TreasureChest(){time_t t; srand((unsigned) time(&t)); this->space = rand() % 11 + 1; this->letter = 'C'; this->colour = "orange";}

    int getSpace() const {return space;};
    void setSpace(int value){space = value;};

    vector<Item> getContents(){return contents;};
    void addContent(Item itm){contents.push_back(itm);};

    void printItem();// prints the item to the screen

};

#endif
