#include <iostream>
#include "GameUI.h"
#include "Character.h"
#include "GroupItemH.h"




// Driver code

int main() {
	displayStartingMenu();
	
	//Check that enemy contains an item
	//createEnemyCharacter();


	/* check if TreasureChest generates items
	TreasureChest tc;
	std::vector <Item*> cont = tc.getContents();
	for(Item* i : cont){
		std::cout <<"\nThe item is a " << i->itmName << endl;
		std::cout << "Its enchantment is: " << i->getEnchantment() << endl;
		std::cout << "Its bonus is: " << i->getBonus() << endl;
	}
    */
}
