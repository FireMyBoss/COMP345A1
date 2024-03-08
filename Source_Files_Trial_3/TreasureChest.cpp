#include "GroupItemH.h"
#include <iostream>

void TreasureChest::printItem(){
    std::cout << "Would you like to create an item? Type yes or no: ";
    string create;
    std::cin >> create;
    if (create == 'yes'){
        std::cout << "What type of item would you like to make? \n1. Armor\n2. Belt\n3. Boots\n4. Helmet\n5. Ring\n6. Shield\n7. Weapon\n\nPlease input the number youd like";
    } 
    


}