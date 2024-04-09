#include "TreasureChest.h"
#include <cstdlib>
#include <string>
#include "GroupItemH.h"

using namespace std;

void TreasureChest::fillEmptyChestsWthItems(){
    srand(time(0));
    for(int iterator = 0; iterator < 5; iterator++){
        addContent(getRandItem(((iterator + rand()) % 7) + 1));
    }
}