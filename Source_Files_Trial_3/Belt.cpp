/**
 * @file Belt.cpp
 * @brief Implementation file for the Belt class.
 */

#include "Belt.h"
#include <cstdlib>
#include <string>
#include "misc.h"


/**
 * @brief List of possible enchantments for belts.
 * 
 * This array holds the possible enchantments that can be applied to belts.
 */

string Belt::listOfEnchantments[] = {"Constitution", "Strength"};


/**
 * @brief Default constructor for the Belt class.
 * 
 * Constructs a Belt object with a random enchantment and a random bonus.
 */

Belt::Belt(){

    Belt::getRandomEnchantment(); // Get a random enchantment and set a random bonus for the belt
    setRandBonus();
    itmName = "Belt"; // Set the name of the item as "Belt"
    
}


/**
 * @brief Sets a random enchantment for the belt.
 * 
 * This function randomly selects an enchantment from the list of available enchantments
 * and sets it for the belt.
 */

void Belt::getRandomEnchantment(){

	setEnchantment(listOfEnchantments[getCurrentTime() % 2]); // Set a random enchantment from the list of available enchantments
    
}
