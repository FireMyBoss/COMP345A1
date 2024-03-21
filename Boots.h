#pragma once

/**
 * @file Boots.h
 * @brief Contains the declaration of the Boots class.
 */


#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

/**
 * @brief Represents a boots item.
 * 
 * This class inherits from the Equipment class and provides functionality specific to boots.
 */

class Boots : public Equipment{

	public:
		
		 /**
     * @brief Default constructor for the Boots class.
     * 
     * Constructs a Boots object with a random enchantment.
     */
		
		Boots();
		
		 /**
     * @brief Sets a random enchantment for the boots.
     * 
     * This function randomly selects an enchantment from the list of available enchantments
     * and sets it for the boots.
     */
		
		void getRandomEnchantment();

	private:

		 static string listOfEnchantments[2]; /**< An array containing the list of enchantments available for boots. */

};
