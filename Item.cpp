#include "Item.h"
#include <cstdlib>
#include <string>
#include "GroupItemH.h"

using namespace std;

Item* getRandItem(int type){
    Item* itm; //Intialize item pointer to save type of generated equipment
		switch(type) { //Switch case to generate the specific type of item
			case 1: //Armor
	            itm = new Armor();
			    break;
			case 2: //Belt
				itm = new Belt();
			    break;
			case 3: //Boots
				itm = new Boots();
				break;
			case 4: //Helmet
				itm = new Helmet();
				break;
			case 5: //Ring
				itm = new Ring();
				break;
        	case 6: //Shield
				itm = new Shield();
				break;
			case 7: //Weapon
				itm = new Weapon();
				break;
			default: //Invalid option
				break;
		}
    
    return itm;
}