/**
 * @file
 * @brief Implementation file for Armor class.
 * 
 * This file contains the implementation of the Armor class, which represents a type of equipment
 * used in a role-playing game. Armor provides protection to characters and may have enchantments
 * that provide additional bonuses.
 */

#include "Armor.h"
#include <cstdlib>
#include <string>


/**
 * @brief Static array containing the list of possible enchantments for Armor.
 * 
 * This array stores the possible enchantments that can be applied to Armor objects.
 */
 
string Armor::listOfEnchantments[] = {"Armor class"};


/**
 * @brief Default constructor for Armor class.
 * 
 * Initializes an Armor object with a random enchantment and bonus.
 */

Armor::Armor(){

    Armor::getRandomEnchantment();
    setRandBonus();
    itmName = "Armor";
    
}


/**
 * @brief Sets a random enchantment for the Armor.
 * 
 * This method sets a random enchantment from the listOfEnchantments array for the Armor object.
 */

void Armor::getRandomEnchantment(){

    setEnchantment(listOfEnchantments[0]);
    
}
