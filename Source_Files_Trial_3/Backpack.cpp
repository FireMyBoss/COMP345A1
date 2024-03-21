/**
 * @file
 * @brief Implementation file for the Backpack class.
 * 
 * This file contains the implementation of the Backpack class, which represents a container for storing various items.
 */

#include "GroupItemH.h"
#include <iostream>


/**
 * @brief Prints items in the backpack and allows users to interact with the backpack.
 */
 
void Backpack::printItem(){
	
	while(true){ //Ensures that the user either creates an item, views the contents of a backpack, or exits the menu
		
		while(true){ //Ensures that the user selects an option that creates an item, views the contents of a backpack, or exits the menu
           
			std::cout << "\n\nWould you like to: \n1. Create an item  \n2.See the contents of the backpack\n3.Exit this menu\nPlease input the number you would like: ";
			int create; //User input
            
			try {
            
				std::cin >> create;
                
					if(cin.fail()) { //If the option was invalid
                
						std::cin.clear();
				    std::cin.ignore(); //Clear buffer input
                    
						throw std::runtime_error("Invalid input. Please enter an integer.");    
				    continue;
                    
					} else if (create == 1){ //User selects option 1
                
						break;
                    
					} else if(create == 2) { //User selects option 2
                
		      	printContents(getContents());
						return;
                	
					} else if(create == 3) { //User selects option 3 (exit the method)
					
						return;
					
					}
                
				std::cout <<"\nError on input, please try again:";
                
			} catch (...) {
				
				std::cin.clear();
				std::cin.ignore();
				std::cout <<"\nError on input, please try again:";
				
			}   
        
		}
    
    //This section continues only if the user has decided to generate a new item
    
		int type;
		
		while(true){ //Ensures that the user correctly selects an item that they want to create
			
			try {
				
				std::cout << "\n\nWhat type of item would you like to make? \n1. Armor\n2. Belt\n3. Boots\n4. Helmet\n5. Ring\n6. Shield\n7. Weapon\n\nPlease input the number youd like: ";
				std::cin >> type; //Accepts user input for equipment type
				
				if(cin.fail()) { //Checks to see if the user input failed
				
					std::cin.clear(); //Clear input buffer
          std::cin.ignore();
          
          throw std::runtime_error("Invalid input. Please enter an integer.");
          
          continue;
          
      	}
      	
     		break;
     		
			} catch (...) {
  			
				std::cin.clear();
			  std::cin.ignore();
		    
			}
				
		}
		
		Item* itm; //Intialize item pointer to save type of generated equipment
		
		switch(type) { //Switch case to generate the specific type of item
		
			case 1: //Armor
      
	      std::cout << "\n\nCreating Armor: ";
	      itm = new Armor();
	      std::cout << "\nArmor's enchantment: " << itm->getEnchantment();
	      std::cout << "\nArmor's bonus: " << itm->getBonus();
			
			break;
			case 2: //Belt

	      std::cout << "\n\nCreating Belt: ";
				itm = new Belt();
				std::cout << "\nBelt's enchantment: " << itm->getEnchantment();
				std::cout << "\nBelt's bonus: " << itm->getBonus();
			
			break;
			case 3: //Boots
				
				std::cout << "\n\nCreating Boots: ";
				itm = new Boots();
				std::cout << "\nBoots's enchantment: " << itm->getEnchantment();
				std::cout << "\nBoots's bonus: " << itm->getBonus();
			
			break;
			case 4: //Helmet
			
				std::cout << "\n\nCreating Helmet: ";
				itm = new Helmet();
				std::cout << "\nHelmet's enchantment: " << itm->getEnchantment();
				std::cout << "\nHelmet's bonus: " << itm->getBonus();
			
			break;
			case 5: //Ring
			
				std::cout << "\n\nCreating Ring: ";
				itm = new Ring();
				std::cout << "\nRing's enchantment: " << itm->getEnchantment();
				std::cout << "\nRing's bonus: " << itm->getBonus();
			
			break;
      case 6: //Shield
				
				std::cout << "\n\nCreating Shield: ";
				itm = new Shield();
				std::cout << "\nShield's enchantment: " << itm->getEnchantment();
				std::cout << "\nShield's bonus: " << itm->getBonus();
			
			break;
			case 7: //Weapon
				
				std::cout << "\n\nCreating Weapon: ";
				itm = new Weapon();
				std::cout << "\nWeapon's enchantment: " << itm->getEnchantment();
				std::cout << "\nWeapon's bonus: " << itm->getBonus();
			
			break;
			default: //Invalid option
				
				std::cout <<"\nError on input, please try again:";
				break;
        
		}
    
    addContent(itm); //Add item 
    
	} 
    
};

/**
 * @brief Prints the contents of the backpack.
 * @param itms Vector containing pointers to items in the backpack.
 */

void Backpack::printContents(vector<Item*> itms){
	
	for(int i = 0; i < itms.size(); i ++){
		
		std::cout <<"\nThe " << i+1 << "'s item is a " << itms[i]->itmName << endl;
		std::cout << "Its enchantment is: " << itms[i]->getEnchantment() << endl;
		std::cout << "Its bonus is: " << itms[i]->getBonus() << endl;
		
	}
	
};
