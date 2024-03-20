#include "Equipment.h"
#include<cstdlib>

void Equipment::setRandBonus(){
    srand((unsigned) time(NULL));
    enchantmentBonus = rand() % 6;

}