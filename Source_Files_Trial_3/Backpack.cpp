#include "GroupItemH.h"
#include <iostream>

void Backpack::printItem(){
    while(true){
        std::cout << "Would you like to: \n1. Create an item  \n2.See the contents of the backpack\n: Please input the number you would like: ";
        int create;
        std::cin >> create;
        if(create == 2){
            break;
        }
        std::cout << "\n\nWhat type of item would you like to make? \n1. Armor\n2. Belt\n3. Boots\n4. Helmet\n5. Ring\n6. Shield\n7. Weapon\n\nPlease input the number youd like: ";
        int type;
        std::cin >> type;
        Item * itm;
        switch (type)
        {
        case 1:
            std::cout << "\n\nCreating Armor: ";
            itm = new Armor();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        case 2:
            std::cout << "\n\nCreating Belt: ";
            itm = new Belt();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        case 3:
            std::cout << "\n\nCreating Boots: ";
            itm = new Boots();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        case 4:
            std::cout << "\n\nCreating Helmet: ";
            itm = new Helmet();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        case 5:
            std::cout << "\n\nCreating Ring: ";
            itm = new Ring();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        case 6:
            std::cout << "\n\nCreating Shield: ";
            itm = new Shield();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        case 7:
            std::cout << "\n\nCreating Weapon: ";
            itm = new Weapon();
            std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
            std::cout << "\nArmor's bonus: " << itm->getBonus();
            break;
        
        default:
            break;
        }
        addContent(itm);
    } 
    printContents(getContents());
}