#include "GroupItemH.h"
#include <iostream>

void Backpack::printItem(){
    while(true){
        while(true){
            std::cout << "\n\nWould you like to: \n1. Create an item  \n2.See the contents of the backpack\nPlease input the number you would like: ";
            int create;
            std::cin >> create;
            if(create == 2){
               printContents(getContents());
               return;
            } else if (create == 1){
                break;
            }
            std::cout <<"\nError on input, please try again:";
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
            std::cout << "\nBelt's enchantment: " << itm->getEnchantment();
            std::cout << "\nBelt's bonus: " << itm->getBonus();
            break;
        case 3:
            std::cout << "\n\nCreating Boots: ";
            itm = new Boots();
            std::cout << "\nBoots's enchantment: " << itm->getEnchantment();
            std::cout << "\nBoots's bonus: " << itm->getBonus();
            break;
        case 4:
            std::cout << "\n\nCreating Helmet: ";
            itm = new Helmet();
            std::cout << "\nHelmet's enchantment: " << itm->getEnchantment();
            std::cout << "\nHelmet's bonus: " << itm->getBonus();
            break;
        case 5:
            std::cout << "\n\nCreating Ring: ";
            itm = new Ring();
            std::cout << "\nRing's enchantment: " << itm->getEnchantment();
            std::cout << "\nRing's bonus: " << itm->getBonus();
            break;
        case 6:
            std::cout << "\n\nCreating Shield: ";
            itm = new Shield();
            std::cout << "\nShield's enchantment: " << itm->getEnchantment();
            std::cout << "\nShield's bonus: " << itm->getBonus();
            break;
        case 7:
            std::cout << "\n\nCreating Weapon: ";
            itm = new Weapon();
            std::cout << "\nWeapon's enchantment: " << itm->getEnchantment();
            std::cout << "\nWeapon's bonus: " << itm->getBonus();
            break;
        
        default:
            std::cout <<"\nError on input, please try again:";
            break;
        }
        addContent(itm);
    } 
    
};

void Backpack::printContents(vector<Item*> itms){
    for(int i = 0; i < itms.size(); i ++){
        std::cout <<"\nThe " << i+1 << "'s item is a " << itms[i]->name << endl;
        std::cout << "Its enchantment is: " << itms[i]->getEnchantment() << endl;
        std::cout << "Its bonus is: " << itms[i]->getBonus() << endl;
    }
};