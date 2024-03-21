/**
 * @file Boots.cpp
 * @brief Implementation file for the Boots class.
 */

#include "Boots.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "misc.h"


/**
 * @brief List of possible enchantments for boots.
 * 
 * This array holds the possible enchantments that can be applied to boots.
 */

string Boots::listOfEnchantments[] = {"Armor class", "Dexterity"};


/**
 * @brief Default constructor for the Boots class.
 * 
 * Constructs a Boots object with a random enchantment and a random bonus.
 */

Boots::Boots(){

    Boots::getRandomEnchantment();
    setRandBonus();
    itmName = "Boots";
    
}


/**
 * @brief Sets a random enchantment for the boots.
 * 
 * This function randomly selects an enchantment from the list of available enchantments
 * and sets it for the boots.
 */

void Boots::getRandomEnchantment(){

    setEnchantment(listOfEnchantments[getCurrentTime() % 2]);
    
}
