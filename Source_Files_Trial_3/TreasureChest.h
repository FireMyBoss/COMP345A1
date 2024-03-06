#ifndef TreasureChest_h
#define TreasureChest_h

#include <string>
#include <stdio.h>
#include "Item.h"

using namespace std;

class TreasureChest : public Item
{
private:
    int space;
    vector<Item> contents;
public:
    TreasureChest(int spc, vector<Item> & preExistingContent) : space(spc), contents(preExistingContent){};
    explicit TreasureChest(vector<Item> & preExistingContent) : contents(preExistingContent){};
    explicit TreasureChest(int spc) : space(spc){};

    int getSpace() const {return space;};
    void setSpace(int value){space = value;};

    vector<Item> getContents(){return contents;};
    void addContent(Item itm){contents.push_back(itm);};

};

#endif