#include "Equipment.h"
#include<cstdlib>

#include "misc.h"

void Equipment::setRandBonus(){
    srand((unsigned) time(NULL));
    enchantmentBonus = getCurrentTime() % 6;

}
