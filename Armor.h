#pragma once

/**
 * @file
 * @brief Header file defining the Armor class.
 * 
 * This file declares the Armor class, which represents a type of equipment used in a role-playing game.
 * Armor provides protection to characters and may have enchantments that provide additional bonuses.
 */

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;


/**
 * @brief Armor class declaration.
 * 
 * Represents a type of equipment that provides protection to characters.
 */
 
class Armor : public Equipment {

	public:
	
		  Armor(); /**< Default constructor for Armor class. */
		  void getRandomEnchantment(); /**< Method to set a random enchantment for the Armor. */

	private:
	
		  static string listOfEnchantments[1]; /**< Static array containing the list of possible enchantments for Armor. */

};



