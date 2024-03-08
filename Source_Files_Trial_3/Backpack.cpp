#include "GroupItemH.h"
#include <iostream>

void Backpack::printItem(){
    std::cout << "Would you like to create an item? Type yes or no: ";
    string create;
    std::cin >> create;
    if (create == 'yes'){
        std::cout << "\n\nWhat type of item would you like to make? \n1. Armor\n2. Belt\n3. Boots\n4. Helmet\n5. Ring\n6. Shield\n7. Weapon\n\nPlease input the number youd like";
        int type;
        std::cin >> type;
        switch (type)
        {
        case 1:
            std::cout << "Creating Armor: ";
            
            break;
        case 2:
            std::cout << "Creating Belt: ";
            break;
        case 3:
            std::cout << "Creating Boots: ";
            break;
        case 4:
            std::cout << "Creating Helmet: ";
            break;
        case 5:
            std::cout << "Creating Ring: ";
            break;
        case 6:
            std::cout << "Creating Shield: ";
            break;
        case 7:
            std::cout << "Creating Weapon: ";
            break;
        
        default:
            break;
        }
    } 
    


}