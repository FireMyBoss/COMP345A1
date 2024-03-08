#include <iostream>
#include "Character.h"
#include "Map.h"
#include "CharacterObserver.h"

// Driver code

int main() {

    Map * newMap = new Map(50, 50);
    Map * myMap = newMap->generateInitialMapInfo();
    MapObserver * newMapObserver = new MapObserver();
    std::cout << newMapObserver->to_string(myMap) << std::endl;

    Backpack backpk(4);
    backpk.printItem();

    return 0;
}
